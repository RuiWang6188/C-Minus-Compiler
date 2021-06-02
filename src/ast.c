#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<string.h>
#include"ast.h"
extern int yylineno;

SyntaxTree* create_ast(char* name, char* s, int is_nonterminal)
{
    SyntaxTree* tree = (SyntaxTree*)malloc(sizeof(struct SYNTAXTREE));
    
    strcpy(tree->name, name);
    strcpy(tree->text, s);
    tree->line_no = yylineno;
    tree->child_num = 0;
    tree->is_nonterminal = is_nonterminal;
    for(int i = 0; i < MAX_CHILD_NUM; i++)
        tree->child_ast[i] = NULL;
    
    return tree;
}

void add_ast_node(int child_num, SyntaxTree* parent, ...)
{
    va_list p;
    va_start(p,parent);
    
    for(int i = 0; i < child_num; i++){
        SyntaxTree* node; 
        node = va_arg(p, SyntaxTree*);
        parent->child_ast[i] = node;
    }
    parent->child_num=child_num;
    parent->line_no = parent->child_ast[0]->line_no;
    va_end(p);
}

void print_ast(SyntaxTree* root, int count)
{
    if(root){
        for(int i = 0; i < count; i++)
            printf("  ");
        printf("%s",root->name);
        
        if(!root->is_nonterminal){
            if(strcmp(root->name,"ID")==0)
                printf(": %s",root->text);
            else if(strcmp(root->name,"TYPE")==0)
                printf(": %s",root->text);
            else if(strcmp(root->name,"INT")==0)
                printf(": %d",atoi(root->text));   
            else if(strcmp(root->name,"FLOAT")==0)
                printf(": %f",atof(root->text));
        }
        else
            printf(" (%d)",root->line_no);
        printf("\n");
        //printf("%d\n",root->childnum);
        for(int i = 0; i < root->child_num; i++)
            print_ast(root->child_ast[i],count+1);
    }
}

void set_type(SyntaxTree* node, int type) {
    node->type = type;
}