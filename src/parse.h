#ifndef _PARSE_H_
#define _PARSE_H_


#define IF "IF"
#define WHILE "WHILE"
#define RETURN "RETURN"
#define FUNDEC "FunDec"
#define VARDEC "VarDec"
#define EXP "Exp"

#define IR_FUN_DEFINE "define"
#define IR_GLOBAL "@"
#define IR_LOCAL "%"
#define IR_VOID "void"

#define IR_BOOL "i1"
#define IR_INT "i32"
#define IR_FLOAT "float"
#define IR_STRUCT "type"

// <result> = alloca [inalloca] <type> [, <ty> <NumElements>] [, align <alignment>] [, addrspace(<num>)]     ; yields type addrspace(num)*:result
#define IR_ALLOCATE "alloca"
#define IR_ALIGN "align"

#define IR_VAR_INT_ALLOCATE "alloca i32, align 4"
#define IR_VAR_FLOAT_ALLOCATE "alloca float, align 4"

// <result> = phi <ty> [<val0>, <label0>], [<val1>, <label1>] …
#define IR_PHI "phi"

#define IR_LOAD "load"
#define IR_STORE "store"

#define IR_AND "and"
#define IR_OR "or"

#define IR_ADD "add"
#define IR_FADD "fadd"
#define IR_SUB "sub"
#define IR_FSUB "fsub"
#define IR_MUL "mul"
#define IR_FMUL "fmul"
// Signed integer division
#define IR_SDIB "sdib"
#define IR_FDIV "fdiv"

#define IR_ICMP "icmp"
#define IR_FCMP "fcmp"

#define IR_ICMP_EQ "eq"
//not equal
#define IR_ICMP_NE "ne"
// unsigned greater than 
#define IR_ICMP_UGT "ugt"
// unsigned greater or equal
#define IR_ICMP_UGE "uge"
// unsigned less than
#define IR_ICMP_ULT "ult"
// unsigned less or equal
#define IR_ICMP_ULE "ule"
// signed greater than
#define IR_ICMP_SGT "sgt"
// signed greater or equal
#define IR_ICMP_SEG "sge"
// signed less than
#define IR_ICMP_SLT "slt"
// signed less or equal
#define IR_ICMP_SLE "sle"

// always yields false, regardless of operands.
#define IR_FCMP_FALSE "false"
// yields true if both operands are not a QNAN and op1 is equal to op2.
#define IR_FCMP_OEQ "oeq" 
// yields true if both operands are not a QNAN and op1 is greater than op2.
#define IR_FCMP_OGT "ogt" 
// yields true if both operands are not a QNAN and op1 is greater than or equal to op2.
#define IR_FCMP_OGE "oge" 
// yields true if both operands are not a QNAN and op1 is less than op2.
#define IR_FCMP_OLT "olt" 
// yields true if both operands are not a QNAN and op1 is less than or equal to op2.
#define IR_FCMP_OLE "ole" 
// yields true if both operands are not a QNAN and op1 is not equal to op2.
#define IR_FCMP_ONE "one" 
// yields true if both operands are not a QNAN.
#define IR_FCMP_ORD "ord" 
// yields true if either operand is a QNAN or op1 is equal to op2.
#define IR_FCMP_UEQ "ueq" 
// yields true if either operand is a QNAN or op1 is greater than op2.
#define IR_FCMP_UGT "ugt" 
// yields true if either operand is a QNAN or op1 is greater than or equal to op2.
#define IR_FCMP_UGE "uge" 
// yields true if either operand is a QNAN or op1 is less than op2.
#define IR_FCMP_ULT "ult" 
// yields true if either operand is a QNAN or op1 is less than or equal to op2.
#define IR_FCMP_ULE "ule" 
// yields true if either operand is a QNAN or op1 is not equal to op2.
#define IR_FCMP_UNE "une" 
// yields true if either operand is a QNAN.
#define IR_FCMP_UNO "uno" 
// always yields true, regardless of operands.
#define IR_FCMP_TRUE "true"

// br i1 <cond>, label <iftrue>, label <iffalse>
// br label <dest>          ; Unconditional branch
#define IR_BR "br"


#define IR_CALL "call"
// ret <type> <value>       ; Return a value from a non-void function
// ret void                 ; Return from void function
#define IR_RET "ret"



#include "ast.h"
#include "symbol_table.h"
#include "error.h"
#include <stdlib.h>
#include <stdio.h>

FILE *IR, *ASM;

int ir_var_number = 0;

void traverse_ast(SyntaxTree *node);
char * ir_bulid_fundec(SyntaxTree *node);
char * ir_bulid_vardec(SyntaxTree *node);
char * ir_build_while(SyntaxTree *node);
char * ir_build_if(SyntaxTree *node);
char * ir_build_exp(SyntaxTree *node);
char * ir_build_assignop_left(SyntaxTree *node);
char * ir_build_args(SyntaxTree *node);
char * ir_get_type_name(SyntaxTree *node);
char * ir_get_return_type_name(int type);
char * ir_build_stmt(SyntaxTree *node);
int get_label();

char * get_var_name(char * domain);
void reset_var_name();

#endif
