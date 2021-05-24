#ifndef _AST_H_
#define _AST_H_

#define MAX_LEN 32
#define MAX_CHILD_NUM 20

typedef enum
{
    true=1, false=0
}bool;

typedef struct SYNTAXTREE{
    char name[MAX_LEN];     // name of the token
    char text[MAX_LEN];     // the token for the terminal (null if nonterminal)
    int child_num;          // the number of children of this ast node
    struct SYNTAXTREE* child_ast[MAX_CHILD_NUM];   // child node array
    int first_line_no;      // the line number of the first child
    bool is_nonterminal;    // 1 for nonterminal, 0 for terminal    
}SyntaxTree;

SyntaxTree* create_ast(char* name, char* s, bool is_nonterminal);

void add_ast_node(int child_num, SyntaxTree* node, ...);

void print_ast(SyntaxTree* root, int count);

SyntaxTree* ROOT;

#endif // _AST_H_