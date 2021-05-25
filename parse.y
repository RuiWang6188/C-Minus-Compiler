
%{
    #include<stdio.h>
    #include "lex.yy.c"
    #include"ast.h"
    void yyerror(char* msg);
    extern SyntacxTree* ROOT;
%}

/*declared types*/
%union
{
    struct SYNTAXTREE* type_tree;
}
%token <type_tree> INT
%token <type_tree> FLOAT
%token <type_tree> ID
%token <type_tree> SEMI
%token <type_tree> COMMA
%token <type_tree> ASSIGNOP
%token <type_tree> RELOP
%token <type_tree> PLUS MINUS STAR DIV
%token <type_tree> AND OR 
%token <type_tree> NOT
%token <type_tree> DOT
%token <type_tree> TYPE
%token <type_tree> LP RP LB RB LC RC
%token <type_tree> STRUCT
%token <type_tree> RETURN
%token <type_tree> IF
%token <type_tree> ELSE
%token <type_tree> WHILE
%token <type_tree> LCOM
%token <type_tree> RCOM


%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT
%left LP RP LB RB DOT

%type <type_tree> Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier OptTag Tag
%type <type_tree> VarDec FunDec VarList ParamDec CompSt StmtList Stmt DefList Def DecList Dec Exp Args

%%

%%
void yyerror(char* msg)
{
        ;
}