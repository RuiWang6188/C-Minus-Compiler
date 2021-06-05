#include "symbol_table.h"

char *append_domain(char *name, char *domain) {
    char *temp = (char *)malloc(sizeof(char) * (strlen(domain) + 1 + strlen(name) + 1));
    strcat(temp, domain);
    strcat(temp, ".");
    strcat(temp, name);
    return temp;
}

int get_struct_num() {
    static int struct_num = STRUCT_BASE - 1;
    struct_num += 2;
    return struct_num;
}

void init_domain_stack(int size) {
    domainstack = (domain_stack *)malloc(sizeof(domain_stack));
    domainstack->domain = (char **)malloc(sizeof(char *) * size);
    domainstack->size = size;
    char *temp = (char *)malloc(sizeof(char) * 7);
    strcpy(temp, GLOBAL);
    domainstack->domain[0] = temp;
    domainstack->index = 0;
}

char * get_current_domain() {
    return domainstack->domain[domainstack->index];
}

void entry_domain(char * domain) {
    char **temp;
    char *temp_domain = (char *)malloc(sizeof(char) * (strlen(domain) + 1));
    if ((++(domainstack->index)) >= domainstack->size) {
        temp = (char **)malloc(sizeof(char *) * domainstack->size * 2);
        memcpy(temp, domainstack->domain, domainstack->size * sizeof(char *));
        domainstack->domain = temp;
        domainstack->size *= 2;
    }
    strcpy(temp_domain, domain);
    domainstack->domain[domainstack->index] = temp_domain;
}

void exit_domain() {
    free(domainstack->domain[domainstack->index --]);
}

void init_symbol_table(int size) {
    symboltable = (symbol_table *)malloc(sizeof(symbol_table));
    symboltable->table_size = size;
    init_hash_table(symboltable->table, symboltable->table_size);
    structtable = (struct_table *)malloc(sizeof(struct_table));
    structtable->size = size;
    structtable->struct_array = (struct_type *)malloc(sizeof(struct_type) * size);
}

void add_struct_type(char *name, int type, char *domain) {
    int index = (type - STRUCT_BASE - 1) % 2;
    if (index >= structtable->size) {
        struct_type * temp = (struct_type *)malloc(sizeof(struct_type) * structtable->size * 2);
        memcpy(temp, structtable->struct_array, structtable->size * sizeof(char *) * 2);
        free(structtable->struct_array);
        structtable->struct_array = temp;
    }
    structtable->struct_array[index].domain = domain;
    structtable->struct_array[index].struct_name = name;
}

void clear_symbol_table() {
    free_hashtable(symboltable->table, symboltable->table_size);
}

// input: VarDec, output: Var with name and array or not
symbol* get_var(SyntaxTree *node) {
    symbol *temp = (symbol *)malloc(sizeof(symbol));
    temp->next = NULL;
    temp->args = NULL;
    temp->ir_name = NULL;
    temp->domain = NULL;
    temp->return_type = VOID;
    // VarDec-->ID
    if (node->child_num == 1) {
        temp->name = (char *)malloc(sizeof(char) * (strlen(node->child_ast[0]->text) + 1));
        strcpy(temp->name, node->child_ast[0]->text);
        temp->type = VAR;
        temp->array_size = 0;
        return temp;
    }
    // VarDec-->ID LB INT RB
    if (node->child_num == 4) {
        temp->name = (char *)malloc(sizeof(char) * (strlen(node->child_ast[0]->text) + 1));
        strcpy(temp->name, node->child_ast[0]->text);
        temp->type = ARRAY;
        temp->array_size = atoi(node->child_ast[2]->text);
        return temp;
    }
}

// get the member of struct
symbol* get_member_list(SyntaxTree *node, int type, symbol* head, symbol* tail) {
    if (node->child_num > 0) {
        int i = 0;
        if (strcmp(node->child_ast[0]->name, "Specifier") == 0) {
            type = get_type(node->child_ast[0]);
            i ++;
        }
        for (; i < node->child_num; i++) {
            if (strcmp(node->child_ast[i]->name, "VarDec") == 0) {
                symbol *temp_arg = get_var(node->child_ast[0]);
                temp_arg->type += type;
                temp_arg->next = NULL;
                if (tail == NULL) {
                    tail = temp_arg;
                } else {
                    tail->next = temp_arg;
                    tail = tail->next;
                }
                //int flag = insert_symbol(temp_arg->name, temp_arg->type, NULL, -1);
                int flag = 1;
                temp_arg = head;
                while ((temp_arg != tail)) {
                    if (strcmp(temp_arg->name, tail->name) == 0) {
                        flag = 0;
                        break;
                    }
                    temp_arg = temp_arg->next;
                }
                if (flag == 0) {
                    print_error(node->child_ast[1]->child_ast[0]->text, 0, REDEFINED_FIELDS_IN_STRUCT);
                }
            } 
            else if (strcmp(node->child_ast[i]->name, "FunDec") == 0) {
                //no fun in struct
                //arg *temp_arg = get_fun(node->child_ast[0]);
                //insert_symbol(temp_arg->name, -1, temp_arg->next, type);
            }
            else {
                // reduce branche
                if ((node->child_ast[i]->name, "StmtList") != 0) {
                    tail = get_member_list(node->child_ast[i], type, head, tail);
                }   
            }
        }
    }
    return tail;
}

// input: Spedidier, output: type
int get_type(SyntaxTree* node) {
    if (strcmp(node->child_ast[0]->text, "int") == 0) {
        return INT_TYPE;
    } 
    else if (strcmp(node->child_ast[0]->text, "float") == 0) {
        return FLOAT_TYPE;
    } else {
        // Spedidier --> StructSpecifier
        node = node->child_ast[0];
        // StructSpecifier --> STRUCT OptTag LC DefList RC
        if (node->child_num == 5) {
            int struct_type = get_struct_num();
            symbol* temp = NULL;
            get_member_list(node->child_ast[3], -1, temp, temp);
            int flag = insert_symbol(node->child_ast[1]->child_ast[0]->text, struct_type, temp, -1);
            if (flag == 0) {
                print_error(node->child_ast[1]->child_ast[0]->text, 0, REDEFINED_VAR);
            }
            add_struct_type(node->child_ast[1]->child_ast[0]->text, struct_type, get_current_domain());
            return struct_type;
        } 
        // StructSpecifier --> STRUCT Tag
        else if (node->child_num == 2){
            hash_node *temp_node = lookup(node->child_ast[1]->text, STRUCT_TYPE, GLOBAL);
            if (temp_node->sym->type != -1) {
                return temp_node->sym->type;
            } else {
                temp_node = lookup(node->child_ast[1]->text, STRUCT_TYPE, get_current_domain());
                if (temp_node->sym->type != -1) {
                    return temp_node->sym->type;
                } else {
                    // error handle
                    //print_error();
                }
            }
        }
        else {
            // error 
        }
    }
}

// input: VarList, output args
symbol * get_args(SyntaxTree* node) {
    // VarList-->ParamDec-->VarDec
    symbol *temp_arg = get_var(node->child_ast[0]->child_ast[1]);
    // VarList-->ParamDec-->Specifier
    int type = get_type(node->child_ast[0]->child_ast[0]);
    // VarDec --> ID [INT]
    temp_arg->type = type + temp_arg->type;
    insert_symbol(temp_arg->name, temp_arg->type, temp_arg->args, temp_arg->return_type);
    if (node->child_num == 3) {
        temp_arg->next = get_args(node->child_ast[2]);
    }
    return temp_arg;
}

// input: FunDec
symbol* get_fun(SyntaxTree *node) {
    symbol *temp = (symbol *)malloc(sizeof(symbol));    
    temp->next = NULL;
    temp->ir_name = NULL;
    temp->domain = NULL;
    temp->return_type = VOID;
    temp->name = (char *)malloc(sizeof(char *) * (strlen(node->child_ast[0]->text) + 1));
    strcpy(temp->name, node->child_ast[0]->text);
    // FunDec-->ID LP VarList RP
    if (node->child_num == 4) {
        temp->args = get_args(node->child_ast[2]);
    }
    else if (node->child_num == 3) {
        temp->args = NULL;
    } 
    else {
        // Error Handle
    }
}

void get_symbol_list(SyntaxTree *node, int type) {
    if (node->child_num > 0) {
        int i = 0;
        if (strcmp(node->child_ast[0]->name, "Specifier") == 0) {
            type = get_type(node->child_ast[0]);
            i ++;
        }
        for (; i < node->child_num; i++) {
            if (strcmp(node->child_ast[i]->name, "VarDec") == 0) {
                symbol *temp_arg = get_var(node->child_ast[0]);
                temp_arg->type += type;
                int flag = insert_symbol(temp_arg->name, temp_arg->type, NULL, -1);
                if (flag == 0) {
                    print_error(temp_arg->name, 0, REDEFINED_VAR);
                }
            } 
            else if (strcmp(node->child_ast[i]->name, "FunDec") == 0) {
                symbol *temp_arg = get_fun(node->child_ast[0]);
                temp_arg->return_type = type;
                int flag = insert_symbol(temp_arg->name, FUN_TYPE, temp_arg->next, type);
                if (flag == 0) {
                    print_error(temp_arg->name, 0, REDEFINED_FUN);
                } else {
                    temp_arg = temp_arg->args;
                    while (temp_arg) {
                        insert_symbol(temp_arg->name, temp_arg->type, NULL, -1);
                        temp_arg = temp_arg->next;
                    }
                }
            }
            else {
                // reduce branche
                if ((node->child_ast[i]->name, "StmtList") != 0) {
                    get_symbol_list(node->child_ast[i], type);
                }   
            }
        }
    }
}

void set_fun_return_type(char *name, int return_type) {
    unsigned int hash = BKDRHash(name);
    hash_node *temp = lookup_hash(symboltable->table, symboltable->table_size, hash);
    if (temp != NULL) {
        temp->sym->return_type = return_type;
    } else {
        // ERROR HANDLE
    }
}


//int get_return_type(SyntaxTree* node) {
//    // don't consider arrays
//    if (strcmp(node->child_ast[0]->text, "int") == 0) {
//        return INT_TYPE;
//    } 
//    else if (strcmp(node->child_ast[0]->text, "float") == 0) {
//        return FLOAT_TYPE;
//    } 
//    else {
//        // todo: handle struct
//        // Spedidier --> StructSpecifier
//        node = node->child_ast[0];
//        if (node->child_num != 2) {
//            // todo error handle
//            return STRUCT_TYPE;
//        }
//        hash_node *temp_node = lookup(node->child_ast[1]->text, STRUCT_TYPE, get_current_domain());
//        return temp_node->sym->return_type;
//    }
//}

// Args --> Exp COMMA Args 
void check_args(hash_node * fun_node, SyntaxTree* args) {
    symbol * fun_arg = fun_node->sym->args;
    while (fun_arg) {
        if (args->child_num == 3) {
            if (fun_arg->type != args->child_ast[0]->type) {
                print_error(fun_arg->name, 0, MISMATCHED_TYPE_PARAMETER);
            }
            args = args->child_ast[2];
            fun_arg = fun_arg->next;
        }
        if (args->child_num == 1) {
            if (fun_arg->type != args->child_ast[0]->type) {
                print_error(fun_arg->name, 0, MISMATCHED_TYPE_PARAMETER);
            }
            fun_arg = fun_arg->next;
            args = NULL;
            break;
        }
    }
    if (fun_arg) {
        print_error(fun_arg->name, 0, MISMATCHED_TYPE_PARAMETER);
    }
    if (args) {
        print_error("", 0, MISMATCHED_TYPE_PARAMETER);
    }
}

int insert_symbol(char *name, int type, symbol* args, int return_type) {
    int hash;
    symbol * sym = (symbol *)malloc(sizeof(symbol));
    sym->name = (char *)malloc(sizeof(char));
    strcpy(sym->name, name);
    sym->type = type;
    sym->args = args;
    if (type == FUN_TYPE) {
        sym->domain = GLOBAL;
        hash = BKDRHash(sym->name);
        sym->return_type = return_type;
    } else {
        sym->domain = (char *)malloc(sizeof(char) * (strlen(get_current_domain()) + 1));
        strcpy(sym->domain, get_current_domain());
        //temp = (char *)malloc(sizeof(char) * (strlen(sym->domain) + 1 + strlen(sym->name) + 1));
        //strcat(temp, sym->domain);
        //strcat(temp, ".");
        //strcat(temp, sym->name);
        char *temp = append_domain(sym->name, sym->domain);
        hash = BKDRHash(temp);
        free(temp);
        sym->args = NULL;
    }
    return insert_hash(symboltable->table, symboltable->table_size, hash, sym);
}

hash_node * lookup(char *name, int type, char *domain) {
    int hash;
    if (type == FUN_TYPE) {
        hash = BKDRHash(name);
    } else {
        char *temp = append_domain(name, domain);
        hash = BKDRHash(temp); 
        free(temp);
    }
    hash_node *temp = lookup_hash(symboltable->table, symboltable->table_size, hash);
    return temp;
}

unsigned int BKDRHash(char *str) {
    unsigned int seed = 131;
    unsigned int hash = 0;
    while (*str) {
        hash = hash * seed + (*str++);
    }
    return (hash & 0x7FFFFFFF);
}

void init_hash_table(hash_node * hash_table[], int size) {
    int i = 0;
    hash_table = (hash_node **)malloc(sizeof(hash_node *) * size);
    for (i = 0; i < size; i++) {
        hash_table[i] = NULL;
    }
}

void free_hash_node(hash_node *node) {
    if (node == NULL) {
        return ;
    } else {
        if (node->next != NULL) {
            free_hash_node(node->next);
        }
        free(node);
    }
}

void free_hashtable(hash_node * hash_table[], int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        free_hash_node(hash_table[i]);
        hash_table[i] = NULL;
    }
}

int insert_hash(hash_node * hash_table[], int size, int hashvalue, symbol* sym) {
    int index;
    hash_node *temp = lookup_hash(hash_table, size, hashvalue);
    if (temp != NULL) {
        // HANDLE ERROR
        return 0;
    }
    index = hashvalue % size;
    temp = hash_table[index];
    while (temp) {
        temp = temp->next;
    }
    temp = (hash_node *)malloc(sizeof(hash_node));
    temp->hash = hashvalue;
    temp->sym = sym;
    temp->next = NULL;
    return 1;
}

hash_node *lookup_hash(hash_node * hash_table[], int size, int hashvalue) {
    int index;
    hash_node *temp;
    index = hashvalue % size;
    temp = hash_table[index];
    if (temp == NULL) {
        return NULL;
    } else {
        while (temp != NULL) {
            if (temp->hash = hashvalue) 
                return temp;
            temp = temp->next;
        } 
    }
    return NULL;
}