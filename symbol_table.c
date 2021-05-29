#include "symbol_table.h"

void init_symbol_table() {

}

void clear_symbol_table() {

}

int insert_symbol(char *name, int type, arg* arg) {
    symbol * sym = (symbol *)malloc(sizeof(symbol));
    sym->name = (char *)malloc(sizeof(char));
    strcpy(sym->name, name);
    sym->type = type;
    sym->arg = arg;
    
    return 0;
}

int lookup(char *name) {

}

unsigned int BKDRHash(char *str) {
    unsigned int seed = 131;
    unsigned int hash = 0;
    while (*str) {
        hash = hash * seed + (*str++);
    }
    return (hash & 0x7FFFFFFF);
}

void init_hash_table(hash_node * hash_table[], int size) {
    int i = 0;
    hash_table = (hash_node **)malloc(sizeof(hash_node *) * size);
    for (i = 0; i < size; i++) {
        hash_table[i] = NULL;
    }
}

void free_hash_node(hash_node *node) {
    if (node == NULL) {
        return ;
    } else {
        if (node->next != NULL) {
            free_hash_node(node->next);
        }
        free(node);
    }
}

void free_hashtable(hash_node * hash_table[], int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        free_hash_node(hash_table[i]);
        hash_table[i] = NULL;
    }
}

hash_node *insert_hash(hash_node * hash_table[], int size, int hashvalue, symbol* sym) {
    int index;
    hash_node *temp = lookup_hash(hash_table, size, hashvalue);
    if (temp != NULL) {
        // HANDLE ERROR
        return temp;
    }
    index = hashvalue % size;
    temp = hash_table[index];
    while (temp) {
        temp = temp->next;
    }
    temp = (hash_node *)malloc(sizeof(hash_node));
    temp->hash = hashvalue;
    temp->sym = sym;
    temp->next = NULL;
    return temp;
}

hash_node *lookup_hash(hash_node * hash_table[], int size, int hashvalue) {
    int index;
    hash_node *temp;
    index = hashvalue % size;
    temp = hash_table[index];
    if (temp == NULL) {
        return NULL;
    } else {
        while (temp != NULL) {
            if (temp->hash = hashvalue) 
                return temp;
            temp = temp->next;
        } 
    }
    return NULL;
}