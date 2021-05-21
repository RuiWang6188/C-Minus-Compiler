%option yylineno
%option noyywrap

%{
    #include<stdio.h>
    #include<math.h>

%}

%x COMMENT

COMMENTBEGIN [/\*]
COMMENTEND [\*/]
COMMENTLINE [//]

OCT 0[0-7]*? 
HEX 0[Xx][0-9a-fA-F]+?
FLOAT [0-9]*[.]?[0-9]+([eE][+-]?[0-9]*|[0])?f?
INT [1-9][0-9]*|[0]

VAR (_|[a-zA-Z])([a-zA-Z]|[0-9]|_)*
SEMICOLON [;]
COMMA [,]
PLUS [+]
MINUS [-]
STAR [*]
DIV [/]
AND [&][&]
OR [|][|]

IF if
ELSE else
WHILE while
STRUCT struct
RETURN return

%%
{COMMENTBEGIN} {

}
{COMMENTEND} {

}
{COMMENTLINE} {

}
{OCT} {

}
{HEX} {

}


%%

