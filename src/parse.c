#include "parse.h"

int get_label() {
    static int label_num = 0;
    return label_num ++;
}

// this function is not in c standard lib on linux
char* itoa(int num,char* str,int radix)
{
    char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";//索引表
    unsigned unum;//存放要转换的整数的绝对值,转换的整数可能是负数
    int i=0,j,k;//i用来指示设置字符串相应位，转换之后i其实就是字符串的长度；转换后顺序是逆序的，有正负的情况，k用来指示调整顺序的开始位置;j用来指示调整顺序时的交换。
 
    //获取要转换的整数的绝对值
    if(radix==10&&num<0)//要转换成十进制数并且是负数
    {
        unum=(unsigned)-num;//将num的绝对值赋给unum
        str[i++]='-';//在字符串最前面设置为'-'号，并且索引加1
    }
    else unum=(unsigned)num;//若是num为正，直接赋值给unum
 
    //转换部分，注意转换后是逆序的
    do
    {
        str[i++]=index[unum%(unsigned)radix];//取unum的最后一位，并设置为str对应位，指示索引加1
        unum/=radix;//unum去掉最后一位
 
    }while(unum);//直至unum为0退出循环
 
    str[i]='\0';//在字符串最后添加'\0'字符，c语言字符串以'\0'结束。
 
    //将顺序调整过来
    if(str[0]=='-') k=1;//如果是负数，符号不用调整，从符号后面开始调整
    else k=0;//不是负数，全部都要调整
 
    char temp;//临时变量，交换两个值时用到
    for(j=k;j<=(i-1)/2;j++)//头尾一一对称交换，i其实就是字符串的长度，索引最大值比长度少1
    {
        temp=str[j];//头部赋值给临时变量
        str[j]=str[i-1+k-j];//尾部赋值给头部
        str[i-1+k-j]=temp;//将临时变量的值(其实就是之前的头部值)赋给尾部
    }
 
    return str;//返回转换后的字符串
 
}

char * get_var_name(char * domain) {
    char *var_name = (char *)malloc(sizeof(char) * 11);
    if (strcmp(domain, GLOBAL) == 0) {
        var_name[0] = '@';
        return itoa(ir_var_number ++, var_name + 1, 10);
    } else {
        var_name[0] = '%';
        return itoa(ir_var_number ++, var_name + 1, 10);
    }
}

void reset_var_name() {
    ir_var_number = 0;
}

char * ir_get_type_name(int type) {
    char * return_type;
    switch (type){
        case VOID:
            return_type = "void";
        case INT_TYPE:
            return_type = "i32";
            break;
        case INT_ARRAY:
            return_type = "i32*";
            break;
        case FLOAT_TYPE:
            return_type = "float";
            break;
        case FLOAT_ARRAY:
            return_type = "float*";
            break;
        default:

            break;
    }
    return return_type;
}

// this function is used to get address of var in expression "var = exp"
char * ir_build_exp_addr(SyntaxTree *node) {
    hash_node * var;
    if (strcmp(node->child_ast[0]->name, "ID") == 0) {
        if (node->child_num == 1) {
            var = lookup(node->child_ast[0]->text, VAR, get_current_domain());
            return var->sym->ir_name;
        } else {
            var = lookup(node->child_ast[0]->text, VAR, get_current_domain());
            char * ir_temp_var_addr = ir_build_exp_addr(node->child_ast[2]);
            char * ir_temp_var = get_var_name(get_current_domain());
            fprintf(IR, "store i32 %s, i32* %s, align 8\n", ir_temp_var, ir_temp_var_addr);
            char * ir_temp_var_1 = get_var_name(get_current_domain());
            fprintf(IR, "%s = getelementptr [%d x %s], [%d x %s]* %s, i32, %s", ir_temp_var_1, var->sym->array_size, ir_get_type_name(var->sym->type - 1), var->sym->array_size, ir_get_type_name(var->sym->type - 1), var->sym->ir_name, ir_temp_var);
            return ir_temp_var_1;
        }
    } 
    // Exp.ID
    else if (strcmp(node->child_ast[0]->name, "Exp") == 0) {
        char * ir_temp_var_addr = ir_build_exp_addr(node->child_ast[1]);
        char * ir_temp_var = get_var_name(get_current_domain());
        int index = get_index_in_struct(node->child_ast[0]->type, node->child_ast[2]->text);
        node = node->child_ast[0];
        fprintf(IR, "%s = getelementptr %s, %s* %s, i32, %s", ir_temp_var, ir_get_type_name(node->type), ir_get_type_name(node->type), ir_temp_var_addr, index);
    }
}



char * ir_build_compst(SyntaxTree *node) {
    fprintf(IR, "{\n");
    for (int i = 0; i < node->child_num; i++) {
        ir_build(node->child_ast[i]);
    }
    fprintf(IR, "}\n");
}

// Stmt
char * ir_build_stmt(SyntaxTree *node) {
    char *ir_var_name;
    // Stmt --> CompSt
    if (strcmp(node->child_ast[0]->name, "Compst") == 0) {
        char * var_value = ir_build_compst(node->child_ast[0]);
        return var_value;
    }
    else if (strcmp(node->child_ast[0]->name, "RETURN") == 0) {
        char *temp = ir_build_exp(node->child_ast[1]);
        if (node->child_ast[1]->type == INT_TYPE) {
            fprintf(IR, "ret i32 %s \n", temp);
            return temp;
        }
        else if (node->child_ast[1]->type == FLOAT_TYPE) {
            fprintf(IR, "ret float %s \n", temp);
            return temp;
        }
        else {
            // Error
        }
        return NULL;
    }
    else if (strcmp(node->child_ast[0]->name, "Exp") == 0) {
        ir_build_exp(node->child_ast[0]);
    }
    // Stmt --> IF LP Exp RP Stmt %prec LOWER_THAN_ELSE
    // Stmt --> IF LP Exp RP Stmt ELSE Stmt
    else if (strcmp(node->child_ast[0]->name, "IF") == 0) {
        if (node->child_num == 7) {
            int label = get_label();
            ir_var_name = ir_build_exp(node->child_ast[2]);
            fprintf(IR, "br i1 %s, label %%if%d.then, label %%if%d.else \n", ir_var_name, label);
            fprintf(IR, "if%d.then: \n", label);
            ir_build_stmt(node->child_ast[4]);
            fprintf(IR, "br label %%if%d.end \n", label);

            fprintf(IR, "if%d.else: \n", label);
            ir_build_stmt(node->child_ast[6]);
            fprintf(IR, "br label %%if%d.end \n", label);
            
            fprintf(IR, "if%d.end: \n", label);
        }
        else if (node->child_num == 5) {
            int label = get_label();
            ir_var_name = ir_build_exp(node->child_ast[2]);
            fprintf(IR, "br i1 %s, label %%if%d.then, label %%if%d.end \n", ir_var_name, label);
            fprintf(IR, "if%d.then: \n", label);
            ir_build_stmt(node->child_ast[4]);
            fprintf(IR, "if%d.end: \n", label);
        }
        else {

        }
    }
    // Stmt --> WHILE LP Exp RP Stmt
    else if (strcmp(node->child_ast[0]->name, "WHILE") == 0) {
        int label = get_label();
        fprintf(IR, "while%d.begin: \n", label);
        ir_var_name = ir_build_exp(node->child_ast[2]);
        fprintf(IR, "br i1 %s, label %%while%d.then, label %%while%d.end \n", ir_var_name, label);
        fprintf(IR, "while%d.then: \n", label);
        ir_build_stmt(node->child_ast[4]);
        fprintf(IR, "br label %%while%d.begin \n", label);
        fprintf(IR, "while%d.end: \n", label);
    }    
    return NULL;
}

// Exp
char * ir_build_exp(SyntaxTree *node) {
    char *ir_var_name;
    // Exp --> (Exp)
    if (strcmp(node->child_ast[0]->name, "LP") == 0) {
        return ir_build_exp(node->child_ast[1]);
    }
    // Exp --> - Exp
    else if (strcmp(node->child_ast[0]->name, "MINUX") == 0) {
        char *temp = ir_build_exp(node->child_ast[1]);
        ir_var_name = get_var_name(get_current_domain());
        if (node->child_ast[1]->type == INT_TYPE) {
            fprintf(IR, "%s = sub i32 0, %s \n", ir_var_name, temp);
            return ir_var_name;
        }
        else if (node->child_ast[1]->type == FLOAT_TYPE) {
            fprintf(IR, "%s = fsub float 0.0, %s \n", ir_var_name, temp);
            return ir_var_name;
        }
        else {
            // Error
        }
        return NULL;
    }
    // Exp --> ! Exp
    else if (strcmp(node->child_ast[0]->name, "NOT") == 0) {
        char *temp = ir_build_exp(node->child_ast[1]);
        ir_var_name = get_var_name(get_current_domain());  
        //fprintf(IR, "%s = fsub float 0.0, %s \n", ir_var_name, temp);
        return ir_var_name;
    }
    else if (strcmp(node->child_ast[0]->name, "ID") == 0) {
        hash_node* var;
        // Exp --> ID
        if (node->child_num == 1) {
            var = lookup(node->child_ast[0]->text, VAR, get_current_domain());
            ir_var_name = get_var_name(get_current_domain());
            if (var->sym->type == INT_TYPE) {
                fprintf(IR, "%s = load i32, i32* %s, align 4 \n", ir_var_name, var->sym->ir_name);
                return ir_var_name;
            }
            else if (var->sym->type == INT_TYPE) {
                fprintf(IR, "%s = load float, float* %s, align 4 \n", ir_var_name, var->sym->ir_name);
                return ir_var_name;
            }
            else {

            }
            return ir_var_name;
        }
        // Exp --> ID LP Args RP
        else if (node->child_num == 4 && (strcmp(node->child_ast[1]->name, "LP") == 0)) {
            var = lookup(node->child_ast[0]->text, FUN_TYPE, GLOBAL);
            ir_var_name = get_var_name(get_current_domain());
            char *args = ir_build_args(node->child_ast[2]);
            char * return_type = ir_get_type_name(var->sym->return_type);
            fprintf(IR, "%s = call %s @%s(%s) \n", ir_var_name, return_type, var->sym->name, args);
            return ir_var_name;
        }
        // Exp --> ID LP RP
        else if (node->child_num == 3) {
            var = lookup(node->child_ast[0]->text, FUN_TYPE, GLOBAL);
            ir_var_name = get_var_name(get_current_domain());
            char * return_type = ir_get_type_name(var->sym->return_type);
            fprintf(IR, "%s = call %s @%s() \n", ir_var_name, return_type, var->sym->name);
            return ir_var_name;
        }
        // Exp --> ID LB Exp RB
        else if (node->child_num == 4 && (strcmp(node->child_ast[1]->name, "LB") == 0)) {
            char * ir_var_addr = ir_build_exp_addr(node->child_ast[0]);
            ir_var_name = get_var_name(get_current_domain());
            if (node->child_ast[0]->type == INT_TYPE) {
                fprintf(IR, "%s = load i32, i32* %s, align 4 \n", ir_var_name, ir_var_addr);
                return ir_var_name;
            }
            else if (node->child_ast[0]->type == FLOAT_TYPE) {
                fprintf(IR, "%s = load float, float* %s, align 4 \n", ir_var_name, ir_var_addr);
                return ir_var_name;
            }
            return ir_var_name;
        }

    }
    else if (strcmp(node->child_ast[0]->name, "INT") == 0) {
        return node->child_ast[0]->text;
    }
    else if (strcmp(node->child_ast[0]->name, "FLOAT") == 0) {
        return node->child_ast[0]->text;
    }
    else if (strcmp(node->child_ast[0]->name, "Exp") == 0) {
        // Exp --> Exp = Exp (the first Exp must be a var)
        if (strcmp(node->child_ast[1]->name, "ASSIGNOP") == 0) {
            char * var = ir_build_exp_addr(node->child_ast[0]);
            char * var_value = ir_build_exp(node->child_ast[2]);
            if (node->child_ast[0]->type == INT_TYPE) {
                fprintf(IR, "store i32 %s, i32* %s, align 4 \n", var_value, var);
            }
            else if (node->child_ast[0]->type == FLOAT_TYPE) {
                fprintf(IR, "store float %s, float* %s, align 4 \n", var_value, var);
            }
            return var_value;
        }
        else if (strcmp(node->child_ast[1]->name, "AND") == 0) {
            char * left = ir_build_exp(node->child_ast[0]);
            char * right = ir_build_exp(node->child_ast[2]);
            ir_var_name = get_var_name(get_current_domain());
            fprintf(IR, "%s = add i32 %s, %s \n", ir_var_name, left, right);
            return ir_var_name;
        }
        else if (strcmp(node->child_ast[1]->name, "OR") == 0) {
            char * left = ir_build_exp(node->child_ast[0]);
            char * right = ir_build_exp(node->child_ast[2]);
            ir_var_name = get_var_name(get_current_domain());
            fprintf(IR, "%s = or i32 %s, %s \n", ir_var_name, left, right);
            return ir_var_name;
        }
        else if (strcmp(node->child_ast[1]->name, "RELOP") == 0) {
            char * left = ir_build_exp(node->child_ast[0]);
            char * right = ir_build_exp(node->child_ast[2]);
            ir_var_name = get_var_name(get_current_domain());
            char * instruction, type;
            char * op;
            if (node->child_ast[0]->type == INT_TYPE) {
                instruction = "icmp";
                type = "i32";
                if (strcmp(node->child_ast[1]->text, "==") == 0) {
                    op = "eq";
                }
                else if (strcmp(node->child_ast[1]->text, "!=") == 0) {
                    op = "ne";
                }
                else if (strcmp(node->child_ast[1]->text, ">=") == 0) {
                    op = "sge";
                }
                else if (strcmp(node->child_ast[1]->text, "<=") == 0) {
                    op = "sle";
                }
                else if (strcmp(node->child_ast[1]->text, ">") == 0) {
                    op = "sgt";
                }
                else if (strcmp(node->child_ast[1]->text, "<") == 0) {
                    op = "slt";
                }
                else {
                    // ERROR 
                }
            }
            else if (node->child_ast[0]->type == FLOAT_TYPE) {
                instruction = "fcmp";
                type = "float";
                if (strcmp(node->child_ast[1]->text, "==") == 0) {
                    op = "oeq";
                }
                else if (strcmp(node->child_ast[1]->text, "!=") == 0) {
                    op = "one";
                }
                else if (strcmp(node->child_ast[1]->text, ">=") == 0) {
                    op = "oge";
                }
                else if (strcmp(node->child_ast[1]->text, "<=") == 0) {
                    op = "ole";
                }
                else if (strcmp(node->child_ast[1]->text, ">") == 0) {
                    op = "ogt";
                }
                else if (strcmp(node->child_ast[1]->text, "<") == 0) {
                    op = "olt";
                }
                else {
                    // ERROR 
                }
            }
            else {
                // ERROR HANDLE
            }
            fprintf(IR, "%s = %s %s %s %s, %s \n", ir_var_name, instruction, op, type, left, right);
            return ir_var_name;
        }
        else if (strcmp(node->child_ast[1]->name, "PLUS") == 0) {
            char * left = ir_build_exp(node->child_ast[0]);
            char * right = ir_build_exp(node->child_ast[2]);
            ir_var_name = get_var_name(get_current_domain());
            if (node->child_ast[1]->type == INT_TYPE) {
                fprintf(IR, "%s = add i32 %s, %s \n", ir_var_name, left, right);
            }
            else if (node->child_ast[1]->type == FLOAT_TYPE) {
                fprintf(IR, "%s = fadd float %s, %s \n", ir_var_name, left, right);
            }
            else {
                // ERROR
            }
            return ir_var_name;
        }
        else if (strcmp(node->child_ast[1]->name, "MINUS") == 0) {
            char * left = ir_build_exp(node->child_ast[0]);
            char * right = ir_build_exp(node->child_ast[2]);
            ir_var_name = get_var_name(get_current_domain());
            if (node->child_ast[1]->type == INT_TYPE) {
                fprintf(IR, "%s = sub i32 %s, %s \n", ir_var_name, left, right);
            }
            else if (node->child_ast[1]->type == FLOAT_TYPE) {
                fprintf(IR, "%s = fsub float %s, %s \n", ir_var_name, left, right);
            }
            else {
                // ERROR
            }
            return ir_var_name;
        }
        else if (strcmp(node->child_ast[1]->name, "STAR") == 0) {
            char * left = ir_build_exp(node->child_ast[0]);
            char * right = ir_build_exp(node->child_ast[2]);
            ir_var_name = get_var_name(get_current_domain());
            if (node->child_ast[1]->type == INT_TYPE) {
                fprintf(IR, "%s = mul i32 %s, %s \n", ir_var_name, left, right);
            }
            else if (node->child_ast[1]->type == FLOAT_TYPE) {
                fprintf(IR, "%s = fmul float %s, %s \n", ir_var_name, left, right);
            }
            else {
                // ERROR
            }
            return ir_var_name;
        }
        else if (strcmp(node->child_ast[1]->name, "DIV") == 0) {
            char * left = ir_build_exp(node->child_ast[0]);
            char * right = ir_build_exp(node->child_ast[2]);
            ir_var_name = get_var_name(get_current_domain());
            if (node->child_ast[1]->type == INT_TYPE) {
                fprintf(IR, "%s = sdib i32 %s, %s \n", ir_var_name, left, right);
            }
            else if (node->child_ast[1]->type == FLOAT_TYPE) {
                fprintf(IR, "%s = fdiv float %s, %s \n", ir_var_name, left, right);
            }
            else {
                // ERROR
            }
            return ir_var_name;
        }
        // Exp --> Exp.ID
        else if (strcmp(node->child_ast[1]->name, "DOT") == 0) {

        }
    }

}

// Args --> Exp COMMA Args
// Args --> Exp
char * ir_build_args(SyntaxTree *node) {
    char * arg = NULL;
    char * name = ir_build_exp(node->child_ast[0]);
    char * type = ir_get_type_name(node->child_ast[0]->type);
    char * temp_arg = (char *)malloc((strlen(type) + strlen(name) + 2) * sizeof(char));
    sprintf(temp_arg, "%s %s", type, name);
    arg = temp_arg;
    if (node->child_num == 3) {
        char * temp = ir_build_args(node->child_ast[2]);
        if (temp != NULL) {
            arg = (char *)malloc((strlen(temp_arg) + strlen(temp) + 3) * sizeof(char));
            sprintf(arg, "%s, %s", temp_arg, temp);
        }
    }
    return arg;
}


char * ir_build_para(hash_node *node) {
    symbol * para = node->sym->args;
    int size = 32, index = 0, num = 0;
    char * paras = (char *)malloc(sizeof(char) * size);
    while (para) {
        if (index + strlen(para->name) + strlen(para->type) >= size) {
            char * temp = (char *)malloc(sizeof(char) * size * 2);
            strcpy(temp, paras);
            free(paras);
            paras = temp;
            size *= 2;
        }
        if (num == 0)
            index = sprintf(paras + index, "%s %%%s", ir_get_type_name(para->type), para->name);
        else
            index = sprintf(paras + index, ", %s %%%s", ir_get_type_name(para->type), para->name);
        num ++;
        char * temp_str = (char *)malloc((strlen(para->name) + 3) * sizeof(char));
        temp_str = "%";
        strcat(temp_str, para->name);
        para->ir_name = temp_str;
        para = para->next;
    }
    return paras;
}

// ExtDef --> Specifier FunDec CompSt
char * ir_build_fundec(SyntaxTree *node) {
    hash_node * fun_node = lookup(node->child_ast[1]->child_ast[0]->text, FUN_TYPE, GLOBAL);
    fprintf(IR, "define dso_local %s @%s(%s) #0", ir_get_type_name(fun_node->sym->return_type), fun_node->sym->name, ir_build_para(fun_node));
    ir_build_compst(node->child_ast[2]);
    //fprintf(IR, "}\n");
}

// VarDec --> ID
// VarDec --> ID LB INT RB
char * ir_build_vardec(SyntaxTree *node) {
    char *name = node->child_ast[0]->text;
    hash_node* var = lookup(name, VAR, get_current_domain());
    int type = var->sym->type;
    char *ir_var_name = get_var_name(get_current_domain());
    var->sym->ir_name = ir_var_name;
    // int or int array
    if (type / 2 == 2) {
        // int
        if (type % 2) {
            fprintf(IR, "%s = alloca i32, align 4 \n", ir_var_name);
        }
        // int array 
        else {
            int num = atoi(node->child_ast[2]->text);
            var->sym->array_size = num;
            fprintf(IR, "%s = alloca [%d x i32] \n", ir_var_name, num);
        }
    } 
    // float or float array
    else if (type / 2 == 3) {
        // float
        if (type % 2) {
            fprintf(IR, "%s = alloca float, align 4 \n", ir_var_name);
        }
        // flaot array 
        else {
            int num = atoi(node->child_ast[2]->text);
            var->sym->array_size = num;
            fprintf(IR, "%s = alloca [%d x float] \n", ir_var_name, num);
        }
    }
    // struct
    else if (type / 2 >= 8) {

    }

}

char * ir_build(SyntaxTree *node) {
    for (int i = 0; i < node->child_num; i++) {
        if (strcmp(node->child_ast[i]->name, "VarDec") == 0) {
            ir_build_vardec(node->child_ast[i]);
        }
        else if (strcmp(node->child_ast[i]->name, "FunDec") == 0) {
            ir_build_fundec(node->child_ast[i]);
        }
        else if (strcmp(node->child_ast[i]->name, "Exp") == 0) {
            ir_build_exp(node->child_ast[i]);
        }
        else if (strcmp(node->child_ast[i]->name, "Stmt") == 0) {
            ir_build_stmt(node->child_ast[i]);
        }
        else if (strcmp(node->child_ast[i]->name, "CompSt") == 0) {
            ir_build_compst(node->child_ast[i]);
        }
        else {
            ir_build(node->child_ast[i]);
        }
    }
    return NULL;
}

void traverse_ast(SyntaxTree *node) {
    if (strcmp(node->name, FUNDEC) == 0) {

    }
    else if (strcmp(node->name, VARDEC) == 0) {

    }
} 