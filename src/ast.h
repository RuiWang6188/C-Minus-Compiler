#ifndef _AST_H_
#define _AST_H_

#include<stdio.h>
#include<stdlib.h>

#define MAX_LEN 32
#define MAX_CHILD_NUM 20

typedef struct SYNTAXTREE{
    char name[MAX_LEN];     // name of the token
    char text[MAX_LEN];     // the token for the terminal (null if nonterminal)
    int child_num;          // the number of children of this ast node
    struct SYNTAXTREE* child_ast[MAX_CHILD_NUM];   // child node array
    int line_no;      // the line number of the first child
    int is_nonterminal;    // 1 for nonterminal, 0 for terminal    
    int type;
}SyntaxTree;

SyntaxTree* create_ast(char* name, char* s, int is_nonterminal);

void add_ast_node(int child_num, SyntaxTree* node, ...);

void print_ast(SyntaxTree* root, int count);

void set_type(SyntaxTree* node, int type);

SyntaxTree* ROOT;

#endif // _AST_H_