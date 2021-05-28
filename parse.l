%option yylineno
%option noyywrap

%{
    #include<stdio.h>
    #include<math.h>
    #include "ast.h"
    #include <string.h>

    int yycolumn = 1;
    extern mistake_num;

    #define 

%}

COMMENTBEGIN \/\*
COMMENTEND \*\/
COMMENTLINE \/\/

FLOAT [0-9]*[.]?[0-9]+([eE][+-]?[0-9]*|[0])?f?
INT [1-9][0-9]*|[0]

TYPE "int"|"float"

ID (_|[a-zA-Z])([a-zA-Z]|[0-9]|_)*
SEMI [;]
COMMA [,]
PLUS [+]
MINUS [-]
STAR [*]
DIV [/]
ASSIGNOP [=]
AND [&][&]
OR [|][|]
DOT [.]
NOT [!]
RELOP >|<|>=|<=|==|!=

LP \(
RP \)
LB \]
RB \)
LC \{
RC \}

IF if
ELSE else
WHILE while
STRUCT struct
RETURN return

%%
{COMMENTBEGIN} {
    int lineno = yylineno;
    int flag = 0;
    char c = input();

    while(c){
        if(flag == 1){
            if(c == '/'){
                flag = 2;
                break;
            }
            else{
                mistake++;
                printf("Error occured in Line %d: Found \*, but cannot find any comment operator compatible with that!\n", line);
            }
        }
        else{
            if(c == '*'){
                flag = 1;
            }
        }
        c = input();
    }
    if(flag != 2){
        mistake++;
        printf("Error occured in Line %d: Found \/\*, but cannot find compatible \*\/!\n", line);
    }
}

{COMMENTEND} {
    mistake++;
    printf("Error occured in Line %d: syntax error.\n", yylineno);
}

{COMMENTLINE} {
    while((c = input()) != '\n')
        ;
}

{FLOAT} {
    yylval.type_tree = create("FLOAT",yytext, 0);
    return FLOAT;
}

{INT} {
    yylval.type_tree = create("INT", yytext, 0);
    return INT;
}

{ID} {
    yylval.type_tree = create("ID", yytext, 0);
    return ID;
}

{TYPE} {
    yylval.type_tree = create("TYPE",yytex, 0);
    return TYPE;
}

{SEMI} {
    yylval.type_tree = create("SEMI", "", 0);
    return SEMI;
}

{COMMA} {
    yylval.type_tree = create("COMMA", "", 0);
    return COMMA;
}

{PLUS} {
    yylval.type_tree = create("PLUS", "", 0);
    return PLUS;
}

{MINUS} {
    yylval.type_tree = create("MINUS", "", 0);
    return MINUS;
}

{STAR} {
    yylval.type_tree = create("STAR", "", 0);
    return STAR;
}

{DIV} {
    yylval.type_tree = create("DIV", "", 0);
    return DIV;
}

{ASSIGNOP} {
    yylval.type_tree = create("ASSIGNOP", "", 0);
    return ASSIGNOP;
}

{AND} {
    yylval.type_tree = create("AND", "", 0);
    return AND;
}

{OR} {
    yylval.type_tree = create("OR", "", 0);
    return OR;
}

{DOT} {
    yylval.type_tree = create("DOT", "", 0);
    return DOT;
}

{NOT} {
    yylval.type_tree = create("NOT", "", 0);
    return NOT;
}

{RELOP} {
    yylval.type_tree = create("RELOP", yytext, 0);
    return RELOP;
}

{LP} {
    yylval.type_tree = create("LP". "", 0);
    return LP;
}

{RP} {
    yylval.type_tree = create("RP", "", 0);
    return RP;
}

{LB} {
    yylval.type_tree = create("LB", "", 0);
    return LB;
}

{RB} {
    yylval.type_tree = create("RB", "", 0);
    return RB;
}

{LC} {
    yylval.type_tree = create("LC", "", 0);
    return LC;
}

{RC} {
    yylval.type_tree = create("RC", "", 0);
    return RC;
}

{IF} {
    yylval.type_tree = create("IF", "", 0);
    return IF;
}

{ELSE} {
    yylval.type_tree = creaet("ELSE", "", 0);
    return ELSE;
}

{WHILE} {
    yylval.type_tree = create("WHILE", "", 0);
    return WHILE;
}

{STRUCT} {
    yylval.type_tree = create("STRUCT", "", 0);
    return STRUCT;
}

{RETURN} {
    yylval.type_tree = create("RETURN", "", 0);
    return RETURN;
}

%%

