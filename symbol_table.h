#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

#include <stdio.h>
#include<stdlib.h>

#define FUN 1
#define STRUCT 3
#define INT 5
#define FLOAT 7 
// use even to identify arrays
#define INT_ARRAY 6
#define FLOAT_ARRAY 8 

typedef struct _arg {
    char *name;
    int type;
    struct _arg *next;
} arg;

typedef struct _symbol {
    char *name;
    int type;
    struct _arg *arg;
} symbol;

// implement symbol table by hash table 
typedef struct _hash_node {
    int hash;
    struct _symbol *sym;
    struct _hash_node *next;
} hash_node;

unsigned int BKDRHash(char *str);
void init_hash_table(hash_node * hash_table[], int size);
void free_hash_node(hash_node * node);
void free_hashtable(hash_node * hash_table[], int size);
hash_node *insert_hash(hash_node * hash_table[], int size, int hashvalue, symbol* sym);
hash_node *lookup_hash(hash_node * hash_table[], int size, int hashvalue);

void init_symbol_table();
void clear_symbol_table();
int insert_symbol(char *name, int type, arg* arg);
int lookup(char *name);





#endif