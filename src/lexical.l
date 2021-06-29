%option yylineno
%{
    #include <string.h>
    #include "ast.h"
    #include "grammar.hpp"
    int yycolumn=1;
    #define YY_USER_ACTION \
        yylloc.first_line=yylineno;\
        yylloc.last_line=yylineno;\
        yylloc.first_column=yycolumn;\
        yylloc.last_column=yylloc.first_column+yyleng-1;\
        yycolumn+=yyleng;
    extern int mistakeRecord[4096];
    extern int mistake;
%}
digit  [0-9]
digits [0-9]+
RELOP  ">"|"<"|">="|"<="|"=="|"!="

CHAR  \'.\'|\'\\.\'
STRING \"(\\.|[^"\\])*\"
INT 0|[1-9]{digit}*
FLOAT {digits}\.{digits}
BOOL "true"|"false"
TYPE "int"|"float"|"boolean"|"char"

LP \(
RP \)
LB \[
RB \]
LC \{
RC \}

RETURN return
IF if
ELSE else
WHILE while
BREAK break

ID [_a-zA-Z][_0-9a-zA-Z]*

SEMI ;
COMMA ,
ASSIGNOP =

PLUS \+
MINUS -
STAR \*
DIV \/
COMMENTMULTILINE \/\*([^\*]|(\*)*[^\*/])*(\*)*\*\/ 
COMMENTLINE \/\/[^\n]*

AND &&
OR "||"
NOT !

CR \r
LF \n
TAB \t|" "



%%
{CHAR}  {yylval.label_tree = new Node(yytext, "CHAR", 0); return CHAR;}
{INT}   {yylval.label_tree = new Node(yytext, "INT", 0); return INT;}
{FLOAT} {yylval.label_tree = new Node(yytext, "FLOAT", 0); return FLOAT;}   
{BOOL}  {yylval.label_tree = new Node(yytext, "BOOL", 0); return BOOL;}
{STRING}    {yylval.label_tree = new Node(yytext, "STRING", 0); return STRING;}

{TYPE}   {yylval.label_tree = new Node(yytext, "TYPE", 0); return TYPE;}

{IF}   {yylval.label_tree = new Node(yytext, "IF", 0); return IF;}
{ELSE}   {yylval.label_tree = new Node(yytext, "ELSE", 0); return ELSE;}
{WHILE}   {yylval.label_tree = new Node(yytext, "WHILE", 0); return WHILE;}
{BREAK}   {yylval.label_tree = new Node(yytext, "BREAK", 0); return BREAK;}
{RETURN}   {yylval.label_tree = new Node(yytext, "RETURN", 0); return RETURN;}

{LP}   {yylval.label_tree = new Node(yytext, "LP", 0); return LP;}
{RP}   {yylval.label_tree = new Node(yytext, "RP", 0); return RP;}
{LB}   {yylval.label_tree = new Node(yytext, "LB", 0); return LB;}
{RB}   {yylval.label_tree = new Node(yytext, "RB", 0); return RB;}
{LC}   {yylval.label_tree = new Node(yytext, "LC", 0); return LC;}
{RC}   {yylval.label_tree = new Node(yytext, "RC", 0); return RC;}

{ID}  {yylval.label_tree = new Node(yytext, "ID", 0); return ID;}

{SEMI}   {yylval.label_tree = new Node(yytext, "SEMI", 0); return SEMI;}
{COMMA}   {yylval.label_tree = new Node(yytext, "COMMA", 0); return COMMA;}
{ASSIGNOP}   {yylval.label_tree = new Node(yytext, "ASSIGNOP", 0); return ASSIGNOP;}
{RELOP}   {yylval.label_tree = new Node(yytext, "RELOP",0); return RELOP;}
{PLUS}  {yylval.label_tree = new Node(yytext, "PLUS", 0); return PLUS;}
{MINUS}   {yylval.label_tree = new Node(yytext, "MINUS", 0); return MINUS;}
{STAR}   {yylval.label_tree = new Node(yytext, "STAR", 0); return STAR;}
{DIV}   {yylval.label_tree = new Node(yytext, "DIV", 0); return DIV;}

{AND}   {yylval.label_tree = new Node(yytext, "AND", 0); return AND;}
{OR}   {yylval.label_tree = new Node(yytext, "OR", 0); return OR;}
{NOT}   {yylval.label_tree = new Node(yytext, "NOT", 0); return NOT;}

{COMMENTMULTILINE} {}

{COMMENTLINE} {}

{CR}  {;}
{LF} {yycolumn=1;}
{TAB}  {;}

.   {
        mistake++;
        printf("Error Occurs at Line %d: Unknown characters \'%s\'\n", yylineno, yytext);
    }

%%
int yywrap(void) {
    return 1;
}