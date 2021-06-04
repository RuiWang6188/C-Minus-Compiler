#include "parse.h"

int get_label() {
    static int label_num = 0;
    return label_num ++;
}

char * get_var_name(char * domain) {

}

void reset_var_name() {

}

char * ir_get_return_type_name(int type) {
    char * return_type;
    switch (type){
        case VOID:
            return_type = "void";
        case INT:
            return_type = "i32";
            break;
        case INT_ARRAY:
            return_type = "i32*";
            break;
        case FLOAT:
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
char * ir_build_assignop_left(SyntaxTree *node) {

}

char * ir_build_compst(SyntaxTree *node) {

}

// Stmt
char * ir_build_stmt(SyntaxTree *node) {
    char *ir_var_name;
    // Stmt --> CompSt
    if (strcmp(node->child_ast[0]->name, "Compst") == 0) {
        char * var_value = ir_build_compst(node->child_ast[0]);
        // fprintf(IR, "", var_value);
    }

    else if (strcmp(node->child_ast[0]->name, "RETURN") == 0) {
        // Stmt --> RETURN Exp
        if (node->child_num==2) {    
            char *temp = ir_build_exp(node->child_ast[1]);
            *ir_var_name = get_var_name(get_current_domain());
            if (node->child_ast[1]->type == INT) {
                fprintf(IR, "%s = ret i32 %s \n", ir_var_name, temp);
                return ir_var_name;
            }
            else if (node->child_ast[1]->type == FLOAT) {
                fprintf(IR, "%s = ret float %s \n", ir_var_name, temp);
                return ir_var_name;
            }
            else {
                // Error
            }
            return NULL;
        }
        // Stmt --> RETURN Exp SEMI
        else if (node->child_num==3) {
            
        }
    }
    
    else if (strcmp(node->child_ast[0]->name, "Exp") == 0) {
        // Stmt --> Exp
        if (node->child_num==1) {
            return ir_build_exp(node->child_ast[0]);
        }

        // Stmt --> Exp SEMI
        else if (node->child_num==2) {

        }
    }

    // Stmt --> IF LP Exp RP Stmt %prec LOWER_THAN_ELSE
    // Stmt --> IF LP Exp RP Stmt ELSE Stmt
    else if (strcmp(node->child_ast[0]->name, "IF") == 0) {
        
    }


    // Stmt --> WHILE LP Exp RP Stmt
    else if (strcmp(node->child_ast[0]->name, "WHILE") == 0) {
        
    }

    
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
        *ir_var_name = get_var_name(get_current_domain());
        if (node->child_ast[1]->type == INT) {
            fprintf(IR, "%s = sub i32 0, %s \n", ir_var_name, temp);
            return ir_var_name;
        }
        else if (node->child_ast[1]->type == FLOAT) {
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
        *ir_var_name = get_var_name(get_current_domain());  
        //fprintf(IR, "%s = fsub float 0.0, %s \n", ir_var_name, temp);
        return ir_var_name;
    }
    else if (strcmp(node->child_ast[0]->name, "ID") == 0) {
        hash_node* var;
        // Exp --> ID
        if (node->child_num == 1) {
            var = lookup(node->child_ast[0]->text, VAR);
            ir_var_name = get_var_name(get_current_domain());
            fprintf(IR, "store i32 %s, i32* %s, align 8", ir_var_name, var->sym->ir_name);
            return ir_var_name;
        }
        // Exp --> ID LP Args RP
        else if (node->child_num == 4) {
            var = lookup(node->child_ast[0]->text, FUN);
            ir_var_name = get_var_name(get_current_domain());
            char *args = ir_build_args(node->child_ast[2]);
            char * return_type = ir_get_return_type_name(var->sym->return_type);
            fprintf(IR, "%s = call %s @%s(%s) \n", ir_var_name, return_type, var->sym->name, args);
        }
        // Exp --> ID LP RP
        else if (node->child_num == 3) {
            var = lookup(node->child_ast[0]->text, FUN);
            ir_var_name = get_var_name(get_current_domain());
            char * return_type = ir_get_return_type_name(var->sym->return_type);
            fprintf(IR, "%s = call %s @%s() \n", ir_var_name, return_type, var->sym->name);
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
            char * var = ir_build_assignop_left(node->child_ast[0]);
            char * var_value = ir_build_exp(node->child_ast[2]);
            fprintf(IR, "store i32 %s, i32* %s, align 8", var_value, var);
        }
        else if (strcmp(node->child_ast[1]->name, "AND") == 0) {
            char * left = ir_build_exp(node->child_ast[0]);
            char * right = ir_build_exp(node->child_ast[2]);
            ir_var_name = get_var_name(get_current_domain());
            fprintf(IR, "%s = add i32 %s, %s", ir_var_name, left, right);
        }
        else if (strcmp(node->child_ast[1]->name, "OR") == 0) {
            char * left = ir_build_exp(node->child_ast[0]);
            char * right = ir_build_exp(node->child_ast[2]);
            ir_var_name = get_var_name(get_current_domain());
            fprintf(IR, "%s = or i32 %s, %s", ir_var_name, left, right);
        }
        else if (strcmp(node->child_ast[1]->name, "RELOP") == 0) {
            char * left = ir_build_exp(node->child_ast[0]);
            char * right = ir_build_exp(node->child_ast[2]);
            ir_var_name = get_var_name(get_current_domain());
            char * instruction, type;
            char * op;
            if (node->child_ast[0]->type == INT) {
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
            else if (node->child_ast[0]->type == FLOAT) {
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
            fprintf(IR, "%s = %s %s %s %s, %s", ir_var_name, instruction, op, type, left, right);
        }
        else if (strcmp(node->child_ast[1]->name, "PLUS") == 0) {
            char * left = ir_build_exp(node->child_ast[0]);
            char * right = ir_build_exp(node->child_ast[2]);
            ir_var_name = get_var_name(get_current_domain());
            if (node->child_ast[1]->type == INT) {
                fprintf(IR, "%s = add i32 %s, %s", ir_var_name, left, right);
            }
            else if (node->child_ast[1]->type == FLOAT) {
                fprintf(IR, "%s = fadd float %s, %s", ir_var_name, left, right);
            }
            else {
                // ERROR
            }
        }
        else if (strcmp(node->child_ast[1]->name, "MINUS") == 0) {
            char * left = ir_build_exp(node->child_ast[0]);
            char * right = ir_build_exp(node->child_ast[2]);
            ir_var_name = get_var_name(get_current_domain());
            if (node->child_ast[1]->type == INT) {
                fprintf(IR, "%s = sub i32 %s, %s", ir_var_name, left, right);
            }
            else if (node->child_ast[1]->type == FLOAT) {
                fprintf(IR, "%s = fsub float %s, %s", ir_var_name, left, right);
            }
            else {
                // ERROR
            }
        }
        else if (strcmp(node->child_ast[1]->name, "STAR") == 0) {
            char * left = ir_build_exp(node->child_ast[0]);
            char * right = ir_build_exp(node->child_ast[2]);
            ir_var_name = get_var_name(get_current_domain());
            if (node->child_ast[1]->type == INT) {
                fprintf(IR, "%s = mul i32 %s, %s", ir_var_name, left, right);
            }
            else if (node->child_ast[1]->type == FLOAT) {
                fprintf(IR, "%s = fmul float %s, %s", ir_var_name, left, right);
            }
            else {
                // ERROR
            }
        }
        else if (strcmp(node->child_ast[1]->name, "DIV") == 0) {
            char * left = ir_build_exp(node->child_ast[0]);
            char * right = ir_build_exp(node->child_ast[2]);
            ir_var_name = get_var_name(get_current_domain());
            if (node->child_ast[1]->type == INT) {
                fprintf(IR, "%s = sdib i32 %s, %s", ir_var_name, left, right);
            }
            else if (node->child_ast[1]->type == FLOAT) {
                fprintf(IR, "%s = fdiv float %s, %s", ir_var_name, left, right);
            }
            else {
                // ERROR
            }
        }
        // Exp --> Exp(Exp) ???? what's meaning of this expression
        else if (strcmp(node->child_ast[1]->name, "LB") == 0) {

        }
        // Exp --> Exp.ID
        else if (strcmp(node->child_ast[1]->name, "DOT") == 0) {
            //char * var = ir_build_assignop_left(node->child_ast[0]);
            //char * element = ir_build_exp(node->child_ast[2]);
            //fprintf(IR, "store i32 %s, i32* %s, align 8", var_value, var);
        }
    }

}

// ExtDef --> Specifier FunDec CompSt
char * ir_bulid_fundec(SyntaxTree *node) {
    char * fun, temp;
    char * type_name = ir_get_type_name(node->child_ast[0]);
    
    
}

// VarDec --> ID
// VarDec --> ID LB INT RB
char * ir_bulid_vardec(SyntaxTree *node) {
    char *name = node->child_ast[0]->text;
    hash_node* var = lookup(name, VAR);
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
            fprintf(IR, "%s = alloca [%d x i32] \n", ir_var_name, num);
        }
    } 
    // float or float array
    else if (type / 2 == 3) {

    }
    // struct
    else if (type / 2 >= 8) {

    }

}

void traverse_ast(SyntaxTree *node) {
    if (strcmp(node->name, FUNDEC) == 0) {

    }
    else if (strcmp(node->name, VARDEC) == 0) {

    }
} 