## 序言
1. 项目概述
    本项目是基于flex，bison以及LLVM，使用c++11实现的C-语法编译器，使用flex结合yacc对源代码进行词法、语法分析；在语法分析阶段生成整个源代码相应的抽象语法树后，根据LLVM IR（Intermediate Representation）模块中定义的中间代码语法输出符合LLVM中间语言语法、机器无关的中间代码；最后，本项目通过调用LLVM后端接口，将中间代码编译生成可执行文件。同时我们也利用D3.js实现了AST可视化。

    本项目解析的语法与是C语言的一个子集，目前已支持的数据类型包括：
    - void
    - int
    - float
    - char
    - bool
    - 数组 （包括int, float, char, bool类型）
    支持的语法包括：
    - 变量的声明、初始化（声明与初始化必须分离）
    - 函数声明和调用（参数类型可以是任意已支持类型）
    - 控制流语句if-else，while及任意层级嵌套使用（支持break）
    - 单行注释（// 或 /* */）
    - 二元运算符、赋值、隐式类型转换
    - 全局变量的使用
    - ...
2. 文件说明

3. 开发环境
- 操作系统：Linux
- 编译环境：
    - Flex
    - Bison
    - LLVM 13.0

## 第一章 词法分析
### 1.1 flex介绍
我们使用了flex来完成词法分析过程。flex（快速词法分析产生器，fast lexical analyzer generator）是一种词法分析程序。它是lex的开放源代码版本，以BSD许可证发布。通常与GNU bison一同运作，但是它本身不是GNU计划的一部分。

Lex读入lex文件中定义的词法分析规则，输出C语言词法分析器源码。

标准lex文件由三部分组成，分别是定义区、规则区和用户子过程区。在定义区，用户可以编写C语言中的声明语句，导入需要的头文件或声明变量。在规则区，用户需要编写以正则表达式和对应的动作的形式的代码。在用户子过程区，用户可以定义函数。

### 1.2 具体实现
词法分析是编译器实现中相对简单的一步。想好所需要实现的语法后，需要将输入转化为一系列的内部标记token。本项目定义的token包括：C语言关键字if、else、return、while、int、float等每个关键字对应的token，加减乘除、位运算、括号、逗号、取地址等符号token，以及表示用户自定义的标志符（identifier）的token、数字常量token（整型和浮点数）、字符串常量token等。

我们需要先在yacc源文件grammar.y中声明这些token，并在lex源文件lexical.l中定义这些token对应的操作。

token大致分为如下几种情况：
- C Minus语言关键字
``` lex
RETURN return
IF if
ELSE else
WHILE while
BREAK break
BOOL "true"|"false"
TYPE "int"|"float"|"boolean"|"char"
... 
%% 
...
{IF}   {yylval.label_tree = new Node(yytext, "IF", 0); return IF;}
{ELSE}   {yylval.label_tree = new Node(yytext, "ELSE", 0); return ELSE;}
{WHILE}   {yylval.label_tree = new Node(yytext, "WHILE", 0); return WHILE;}
{BREAK}   {yylval.label_tree = new Node(yytext, "BREAK", 0); return BREAK;}
{RETURN}   {yylval.label_tree = new Node(yytext, "RETURN", 0); return RETURN;}
{BOOL}  {yylval.label_tree = new Node(yytext, "BOOL", 0); return BOOL;}
{TYPE}   {yylval.label_tree = new Node(yytext, "TYPE", 0); return TYPE;}
```
C Minus语言操作符

``` lex
LP \(
RP \)
LB \[
RB \]
LC \{
RC \}
ASSIGNOP =
RELOP  ">"|"<"|">="|"<="|"=="|"!="
PLUS \+
MINUS -
STAR \*
DIV \/
AND &&
OR "||"
NOT !
...
%%
...
{LP}   {yylval.label_tree = new Node(yytext, "LP", 0); return LP;}
{RP}   {yylval.label_tree = new Node(yytext, "RP", 0); return RP;}
{LB}   {yylval.label_tree = new Node(yytext, "LB", 0); return LB;}
{RB}   {yylval.label_tree = new Node(yytext, "RB", 0); return RB;}
{LC}   {yylval.label_tree = new Node(yytext, "LC", 0); return LC;}
{RC}   {yylval.label_tree = new Node(yytext, "RC", 0); return RC;}
{ASSIGNOP}   {yylval.label_tree = new Node(yytext, "ASSIGNOP", 0); return ASSIGNOP;}
{RELOP}   {yylval.label_tree = new Node(yytext, "RELOP",0); return RELOP;}
{PLUS}  {yylval.label_tree = new Node(yytext, "PLUS", 0); return PLUS;}
{MINUS}   {yylval.label_tree = new Node(yytext, "MINUS", 0); return MINUS;}
{STAR}   {yylval.label_tree = new Node(yytext, "STAR", 0); return STAR;}
{DIV}   {yylval.label_tree = new Node(yytext, "DIV", 0); return DIV;}
{AND}   {yylval.label_tree = new Node(yytext, "AND", 0); return AND;}
{OR}   {yylval.label_tree = new Node(yytext, "OR", 0); return OR;}
{NOT}   {yylval.label_tree = new Node(yytext, "NOT", 0); return NOT;}
{AND}   {yylval.label_tree = new Node(yytext, "AND", 0); return AND;}
{OR}   {yylval.label_tree = new Node(yytext, "OR", 0); return OR;}
{NOT}   {yylval.label_tree = new Node(yytext, "NOT", 0); return NOT;}
```

- C Minus语言标识符和其他标记
```lex
digit  [0-9]
digits [0-9]+
CHAR  \'.\'|\'\\.\'
STRING \"(\\.|[^"\\])*\"
INT 0|[1-9]{digit}*
FLOAT {digits}\.{digits}
ID [_a-zA-Z][_0-9a-zA-Z]*
CR \r
LF \n
TAB \t|" "
...
%%
...
{CHAR}  {yylval.label_tree = new Node(yytext, "CHAR", 0); return CHAR;}
{INT}   {yylval.label_tree = new Node(yytext, "INT", 0); return INT;}
{FLOAT} {yylval.label_tree = new Node(yytext, "FLOAT", 0); return FLOAT;}   
{STRING}    {yylval.label_tree = new Node(yytext, "STRING", 0); return STRING;}
{ID}  {yylval.label_tree = new Node(yytext, "ID", 0); return ID;}

{CR}  {;}
{LF} {yycolumn=1;}
{TAB}  {;}
```

- C Minus语言注释
```lex
COMMENTMULTILINE \/\*([^\*]|(\*)*[^\*/])*(\*)*\*\/ 
COMMENTLINE \/\/[^\n]*
...
%%
...
{COMMENTMULTILINE} {}
{COMMENTLINE} {}
```
## 第二章 语法分析

## 第三章 语义分析

## 第四章 代码生成