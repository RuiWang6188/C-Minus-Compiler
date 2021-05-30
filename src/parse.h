#ifndef _PARSE_H_
#define _PARSE_H_


#define IF "IF"
#define WHILE "WHILE"
#define RETURN "RETURN"
#define FunDec "FunDec"
#define VarDec "VarDec"
#define Exp "Exp"

#define LABEL "label"
#define CMP "cmp"
#define JNE "jne"
#define JE "je"
#define MOV "mov"
#define JMP "jmp"
#define PUSH "push"
#define POP "pop"
#define ADD "add"
#define SUB "sub"
#define IMUL "imul"
#define IDIV "idiv"
#define LEA "lea"
#define LEAVE "leave"
#define RET "ret"
#define SAR "sar"
#define CMP "cmp"
#define SETE "sete"
#define SETNE "setne"
#define SETG "setg"
#define SETL "setl"
#define SETGE "setge"
#define SETLE "setle"
#define MOVZX "movzx"
#define CALLF "call"

#define EAX "eax"
#define EBX "ebx"
#define ECX "ecx"
#define EDX "edx"
#define EBP "ebp"
#define ESP "esp"
#define AL "al"

#include "ast.h"
#include "symbol_table.h"
#include "error.h"
#include <stdio.h>
#include <stdlib.h>

FILE *IR, *ASM;

void traverse_ast(SyntaxTree *node);
void ir_bulid_fundec(SyntaxTree *node);
void ir_bulid_vardec(SyntaxTree *node);
void ir_build_while(SyntaxTree *node);
int get_label();

#endif
