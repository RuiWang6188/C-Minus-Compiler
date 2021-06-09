%option yylineno
%{
    #include "syntax.tab.h"
    #include <string.h>
    #include "ast.h"
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
RELOP  ">" | "<" | ">=" | "<=" | "==" | "!="

CHAR  \'.\'
INT 0 | [1-9]{digit}*
FLOAT {digits}\.{digits}
BOOL "true" | "false"
TYPE "int" | "float" | "boolean" | "char"

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

ID [_a-zA-Z][_0-9a-zA-Z]*

SEMI ;
COMMA ,
ASSIGNOP =

PLUS \+
MINUS -
STAR \*
DIV \/
COMMENTBEGIN \/\* 
COMMENTEND "*/"
COMMENTLINE \/\/

AND &&
OR "||"
DOT \.
NOT !

CR \r
LF \n
TAB \t|" "



%%
{CHAR} {}
{INT}  {yylval.label_tree = new Node(yytext, "INT", 0); return INT;}
{FLOAT}  {yylval.label_tree = new Node(yytext, "FLOAT", 0); return FLOAT;}   
{BOOL} {}

{TYPE}   {yylval.label_tree = new Node(yytext, "TYPE", 0); return TYPE;}

{IF}   {yylval.label_tree = new Node("", "IF", 0); return IF;}
{ELSE}   {yylval.label_tree = new Node("", "ELSE", 0); return ELSE;}
{WHILE}   {yylval.label_tree = new Node("", "WHILE", 0); return WHILE;}
{RETURN}   {yylval.label_tree = new Node("", "RETURN", 0); return RETURN;}

{LP}   {yylval.label_tree = new Node("", "LP", 0); return LP;}
{RP}   {yylval.label_tree = new Node("", "RP", 0); return RP;}
{LB}   {yylval.label_tree = new Node("", "LB", 0); return LB;}
{RB}   {yylval.label_tree = new Node("", "RB", 0); return RB;}
{LC}   {yylval.label_tree = new Node("", "LC", 0); return LC;}
{RC}   {yylval.label_tree = new Node("", "RC", 0); return RC;}

{ID}  {yylval.label_tree = new Node(yytext, "ID", 0); return ID;}

{SEMI}   {yylval.label_tree = new Node("", "SEMI", 0); return SEMI;}
{COMMA}   {yylval.label_tree = new Node("", "COMMA", 0); return COMMA;}
{ASSIGNOP}   {yylval.label_tree = new Node("=", "ASSIGNOP", 0); return ASSIGNOP;}
{RELOP}   {yylval.label_tree = new Node(yytext, "RELOP",0);; return RELOP;}
{PLUS}   {yylval.label_tree = new Node("+", "PLUS", 0); return PLUS;}
{MINUS}   {yylval.label_tree = new Node("-", "MINUS", 0); return MINUS;}
{STAR}   {yylval.label_tree = new Node("*", "STAR", 0); return STAR;}
{DIV}   {yylval.label_tree = new Node("/", "DIV", 0); return DIV;}

{AND}   {yylval.label_tree = new Node("&&", "AND", 0); return AND;}
{OR}   {yylval.label_tree = new Node("||", "OR", 0); return OR;}
{DOT}   {yylval.label_tree = new Node(".", "DOT", 0); return DOT;}
{NOT}   {yylval.label_tree = new Node("!", "NOT", 0); return NOT;}

{COMMENTBEGIN}    {
            int line=yylineno;
            char c = input();
            int flag=0;
            while(c){
                if(flag == 1){
                    if(c == '/'){
                        flag=2;
                        break;
                    }
                    else{
                        if(c != '*')
                            flag = 0;
                    }
                }
                else{
                    if(c == '*')
                        flag = 1;
                }
                c = input();
            }
            if(flag != 2){
                mistake++;
                printf("Error occured in Line %d: Found \\\*, but cannot find any comment operator compatible with that!\n", line);
            }
        }  
{COMMENTEND} {  mistake++;
                printf("Error Occurs at Line %d: Syntax Error.\n", yylineno);
            }

{COMMENTLINE} { char c;
                while((c = input())!='\n')
                    ;
            }

{CR}  {;}
{LF} {yycolumn=1;}
{TAB}  {;}

.   {
        mistake++;
        printf("Error Occurs at Line %d: Unknown characters \'%s\'\n", yylineno, yytext);
    }

%%