#include "parse.h"

int get_label() {
    static int label_num = 0;
    return label_num ++;
}

void ir_bulid_fundec(SyntaxTree *node) {
    if (strcmp(node->text, "main") == 0) {
        
    } else {
        
    }
}

void traverse_ast(SyntaxTree *node) {
    if (strcmp(node->name, FUNDEC) == 0) {

    }
    else if (strcmp(node->name, VARDEC) == 0) {

    }
    else if (strcmp(node->name, IF) == 0) {

    }
    else if (strcmp(node->name, WHILE) == 0) {

    }
    else if (strcmp(node->name, RETURN) == 0) {

    }
    else if (strcmp(node->name, EXP) == 0) {

    }
} 