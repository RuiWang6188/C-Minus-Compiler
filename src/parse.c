#include "parse.h"

int get_label() {
    static int label_num = 0;
    return label_num ++;
}

char * get_var_name(char * domain) {

}

void reset_var_name() {

}

// ExtDef --> Specifier FunDec CompSt
char * ir_bulid_fundec(SyntaxTree *node) {
    char * fun, temp;
    char * type_name = ir_get_type_name(node->child_ast[0]);
    
    
}

// VarDec --> ID
// VarDec --> ID LB INT RB
char * ir_bulid_vardec(SyntaxTree *node) {
    char *var_name = node->child_ast[0]->text;
    hash_node* var = lookup(var_name, VAR);
    int type = var->sym->type;
    // int or int array
    if (type / 2 == 2) {
        // int
        if (type % 2) {
            fprintf(IR, "%s = alloca i32, align 4 \n", var_name);
        }
        // int array 
        else {
            int num = atoi(node->child_ast[2]->text);
            fprintf(IR, "%s = alloca [%d x i32] \n", var_name, num);
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