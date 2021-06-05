#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "ast.h"

#define VOID -1
#define VAR 0
#define ARRAY 1
#define FUN_TYPE 2
#define STRUCT_TYPE 3
#define INT_TYPE 4
#define FLOAT_TYPE 6 
// use even to identify arrays
#define INT_ARRAY 5
#define FLOAT_ARRAY 7
// Larger numbers are reserved for struct
#define STRUCT_BASE 15

#define GLOBAL "global"

typedef struct _symbol {
    char *name;
    char *domain;
    char *ir_name;
    int type;
    int return_type;
    int array_size;
    struct _symbol *args;
    struct _symbol *next;
} symbol;

// implement symbol table by hash table 
typedef struct _hash_node {
    int hash;
    struct _symbol *sym;
    struct _hash_node *next;
} hash_node;

typedef struct _symbol_table {
    hash_node **table;
    int table_size;
} symbol_table;

typedef struct _stack {
    char **domain;
    int size;
    int index;
} domain_stack;

typedef struct _struct_type {
    char * struct_name;
    char * domain;
} struct_type;

typedef struct _struct_table {
    struct_type * struct_array;
    int size;
} struct_table;

symbol_table * symboltable;
domain_stack * domainstack;
struct_table * structtable;

void init_domain_stack(int size);
char * get_current_domain();
void entry_domain(char * domain);
void exit_domain();

unsigned int BKDRHash(char *str);
void init_hash_table(hash_node * hash_table[], int size);
void free_hash_node(hash_node * node);
void free_hashtable(hash_node * hash_table[], int size);
int insert_hash(hash_node * hash_table[], int size, int hashvalue, symbol* sym);
hash_node * lookup_hash(hash_node * hash_table[], int size, int hashvalue);

void init_symbol_table(int size);
void clear_symbol_table();
int insert_symbol(char *name, int type, symbol* args, int return_type);
void add_struct_type(char *name, int type, char *domain);
// -1 is not found, other num is type of the var / fun;
hash_node * lookup(char *name, int type, char *domain);

symbol * get_args(SyntaxTree* node);
symbol * get_var(SyntaxTree *node);
int get_type(SyntaxTree* node);
symbol * get_var(SyntaxTree *node);
symbol * get_fun(SyntaxTree *node);
void get_symbol_list(SyntaxTree *node, int type);
symbol* get_member_list(SyntaxTree *node, int type, symbol* head, symbol* tail);

// VarDec
char *append_domain(char *name, char *domain);
int get_struct_num();
void set_fun_return_type(char *name, int return_type);
void check_args(hash_node * fun_node, SyntaxTree* args);


#endif