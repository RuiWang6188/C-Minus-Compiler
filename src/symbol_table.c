#include "symbol_table.h"

char *append_domain(char *name, char *domain) {
    char *temp = (char *)malloc(sizeof(char) * (strlen(domain) + 1 + strlen(name) + 1));
    strcat(temp, domain);
    strcat(temp, ".");
    strcat(temp, name);
    return temp;
}

int get_struct_num() {
    static int struct_num = 16;
    return struct_num ++;
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
}

void clear_symbol_table() {
    free_hashtable(symboltable->table, symboltable->table_size);
}

arg * get_args(SyntaxTree* node) {
    arg *temp_arg = (arg *)malloc(sizeof(arg));
    SyntaxTree *arg_type, *arg_name;
    // VarList-->ParamDec-->VarDec
    arg_name = node->child_ast[0]->child_ast[1];
    // VarList-->ParamDec-->Specifier
    arg_type = node->child_ast[0]->child_ast[0];
    // VarDec-->ID 
    temp_arg->name = arg_name->child_ast[0]->text;
    // VarDec --> ID [INT]
    if (arg_name->child_num == 4) {
        if (strcmp(arg_type->child_ast[0]->text, "int") == 0) {
            temp_arg->type = INT_ARRAY;
        } 
        else if (strcmp(arg_type->child_ast[0]->text, "float") == 0) {
            temp_arg->type = FLOAT_ARRAY;
        } else {
            // handle struct 
        }
    } else {
        if (strcmp(arg_type->child_ast[0]->text, "int") == 0) {
            temp_arg->type = INT;
        } 
        else if (strcmp(arg_type->child_ast[0]->text, "float") == 0) {
            temp_arg->type = FLOAT;
        } else {
            // handle struct 
            temp_arg->type = STRUCT;
        }
    }
    if (args->child_num == 3) {
        temp_arg->next = get_args(node->child_ast[2]);
    }
    return temp_arg;
}

char *get_name(SyntaxTree* node) {
    // FunDec-->ID
    return node->child_ast[0]->text;
}

int get_type(SyntaxTree* node) {
    if (strcmp(node->child_ast[0]->text, "int") == 0) {
        return INT;
    } 
    else if (strcmp(node->child_ast[0]->text, "float") == 0) {
        return FLOAT;
    } else {
        // Spedidier --> StructSpecifier
        node = node->child_ast[0];
        if (node->child_num == 5) {
            int struct_type = get_struct_num();
            //insert_symbol( , struct_type, , -1);
            return struct_type;
        } 
        else if (node->child_num == 2){
            char *temp0 = append_domain(node->child_ast[1]->text, "struct");
            char *temp1 = append_domain(temp0, get_current_domain());
            int flag = lookup(temp1, STRUCT);
            free(temp1);
            if (flag != -1) {
                return flag;
            } else {
                flag = lookup(temp0, STRUCT);
                free(temp0);
                if (flag != -1) {
                    return flag;
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

int get_return_type(SyntaxTree* node) {
    // don't consider arrays
    if (strcmp(node->child_ast[0]->text, "int") == 0) {
        return INT;
    } 
    else if (strcmp(node->child_ast[0]->text, "float") == 0) {
        return FLOAT;
    } 
    else {
        // todo: handle struct
        // Spedidier --> StructSpecifier
        node = node->child_ast[0];
        if (node->child_num != 2) {
            // todo error handle
            return STRUCT;
        }
        char *temp = append_domain(node->child_ast[1]->text, "struct");
        int flag = lookup(temp, STRUCT);
        free(temp);
        return flag;
    }
}

int insert_symbol(char *name, int type, arg* args, int return_type) {
    int hash;
    symbol * sym = (symbol *)malloc(sizeof(symbol));
    sym->name = (char *)malloc(sizeof(char));
    strcpy(sym->name, name);
    sym->type = type;
    sym->args = args;
    if (type == FUN) {
        sym->domain = GLOBAL;
        hash = BKDRHash(sym->name);
        sym->return_type = return_type;
    } else {
        sym->domain = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
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

int lookup(char *name, int type) {
    int hash;
    if (type == FUN) {
        hash = BKDRHash(name);
    } else {
        //char *temp = (char *)malloc(sizeof(char) * (strlen(get_current_domain()) + 1 + strlen(name) + 1));
        //strcat(temp, get_current_domain());
        //strcat(temp, ".");
        //strcat(temp, name);
        char *temp = append_domain(name, get_current_domain());
        hash = BKDRHash(temp); 
        free(temp);
    }
    char *domain = get_current_domain();
    hash_node *temp = lookup_hash(symboltable->table, symboltable->table_size, hash);
    if (temp == NULL) {
        return -1;
    }
    return temp->sym->type;
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