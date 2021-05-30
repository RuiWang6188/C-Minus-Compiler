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
letter [a-zA-Z]
STRUCT struct
RELOP  >|<|>=|<=|==|!=

INT 0|[1-9]{digit}*
FLOAT {digits}\.{digits}
TYPE "int"|"float"

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
{INT}  {yylval.label_tree = create_ast("INT",yytext,0); return INT;}
{FLOAT}  {yylval.label_tree = create_ast("FLOAT",yytext,0); return FLOAT;}   

{STRUCT}   {yylval.label_tree = create_ast("STRUCT","",0); return STRUCT;}
{TYPE}   {yylval.label_tree = create_ast("TYPE",yytext,0); return TYPE;}

{IF}   {yylval.label_tree = create_ast("IF","",0); return IF;}
{ELSE}   {yylval.label_tree = create_ast("ELSE","",0); return ELSE;}
{WHILE}   {yylval.label_tree = create_ast("WHILE","",0); return WHILE;}
{RETURN}   {yylval.label_tree = create_ast("RETURN","",0); return RETURN;}

{LP}   {yylval.label_tree = create_ast("LP","",0); return LP;}
{RP}   {yylval.label_tree = create_ast("RP","",0); return RP;}
{LB}   {yylval.label_tree = create_ast("LB","",0); return LB;}
{RB}   {yylval.label_tree = create_ast("RB","",0); return RB;}
{LC}   {yylval.label_tree = create_ast("LC","",0); return LC;}
{RC}   {yylval.label_tree = create_ast("RC","",0); return RC;}

{ID}  {yylval.label_tree = create_ast("ID",yytext,0); return ID;}

{SEMI}   {yylval.label_tree = create_ast("SEMI","",0); return SEMI;}
{COMMA}   {yylval.label_tree = create_ast("COMMA","",0); return COMMA;}
{ASSIGNOP}   {yylval.label_tree = create_ast("ASSIGNOP","",0); return ASSIGNOP;}
{RELOP}   {yylval.label_tree = create_ast("RELOP",yytext,0);; return RELOP;}
{PLUS}   {yylval.label_tree = create_ast("PLUS","",0); return PLUS;}
{MINUS}   {yylval.label_tree = create_ast("MINUS","",0); return MINUS;}
{STAR}   {yylval.label_tree = create_ast("STAR","",0); return STAR;}
{DIV}   {yylval.label_tree = create_ast("DIV","",0); return DIV;}

{AND}   {yylval.label_tree = create_ast("AND","",0); return AND;}
{OR}   {yylval.label_tree = create_ast("OR","",0); return OR;}
{DOT}   {yylval.label_tree = create_ast("DOT","",0); return DOT;}
{NOT}   {yylval.label_tree = create_ast("NOT","",0); return NOT;}

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
        printf("Error Occurs at Line %d: Unknown characters\n", yylineno);
    }

%%