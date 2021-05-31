#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "ast.h"

#define FUN 1
#define VAR 2
#define STRUCT 3
#define INT 5
#define FLOAT 7 
// use even to identify arrays
#define INT_ARRAY 6
#define FLOAT_ARRAY 8
// Larger numbers are reserved for struct

#define GLOBAL "global"

typedef struct _arg {
    char *name;
    int type;
    struct _arg *next;
} arg;

typedef struct _symbol {
    char *name;
    char *domain;
    int type;
    int return_type;
    struct _arg *args;
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

symbol_table * symboltable;
domain_stack * domainstack;

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
int insert_symbol(char *name, int type, arg* args, int return_type);
// -1 is not found, other num is type of the var / fun;
int lookup(char *name, int type);
arg * get_args(SyntaxTree* node);
char *get_name(SyntaxTree* node);
int get_type(SyntaxTree* node);
int get_return_type(SyntaxTree* node);

char *append_domain(char *name, char *domain);
int get_struct_num();


#endif