#include "symbol_table.h"


void init_domain_stack(int size) {
    domainstack = (domain_stack *)malloc(sizeof(domain_stack));
    domainstack->domain = (char **)malloc(sizeof(char *) * size);
    domainstack->size = size;
    char *temp = (char *)malloc(sizeof(char) * 7);
    strcpy(temp, GLOBAL);
    domainstack->domain[0] = temp;
    domainstack->index = 0;
}
char * get_current_domain() {
    return domainstack->domain[domainstack->index];
}
void entry_domain(char * domain) {
    char **temp;
    char *temp_domain = (char *)malloc(sizeof(char) * (strlen(domain) + 1));
    if ((++(domainstack->index)) >= domainstack->size) {
        temp = (char **)malloc(sizeof(char *) * domainstack->size * 2);
        memcpy(temp, domainstack->domain, domainstack->size * sizeof(char *));
        domainstack->domain = temp;
        domainstack->size *= 2;
    }
    strcpy(temp_domain, domain);
    domainstack->domain[domainstack->index] = temp_domain;
}
void exit_domain() {
    free(domainstack->domain[domainstack->index --]);
}

void init_symbol_table(int size) {
    symboltable = (symbol_table *)malloc(sizeof(symbol_table));
    symboltable->table_size = size;
    init_hash_table(symboltable->table, symboltable->table_size);
}

void clear_symbol_table() {
    free_hashtable(symboltable->table, symboltable->table_size);
}

int insert_symbol(char *name, int type, arg* args) {
    int hash;
    symbol * sym = (symbol *)malloc(sizeof(symbol));
    sym->name = (char *)malloc(sizeof(char));
    strcpy(sym->name, name);
    sym->type = type;
    sym->args = args;
    if (type == FUN) {
        sym->domain = GLOBAL;
        hash = BKDRHash(sym->name);
    } else {
        sym->domain = get_current_domain();
        char *temp = (char *)malloc(sizeof(char) * (strlen(sym->domain) + 1 + strlen(sym->name) + 1));
        strcat(temp, sym->domain);
        strcat(temp, ".");
        strcat(temp, sym->name);
        hash = BKDRHash(temp);
    }
    insert_hash(symboltable->table, symboltable->table_size, hash, sym);
    
    return 0;
}

int lookup(char *name, int type) {
    int hash;
    if (type == FUN) {
        hash = BKDRHash(name);
    } else {
        char *temp = (char *)malloc(sizeof(char) * (strlen(get_current_domain()) + 1 + strlen(name) + 1));
        strcat(temp, get_current_domain());
        strcat(temp, ".");
        strcat(temp, name);
        hash = BKDRHash(temp); 
    }
    char *domain = get_current_domain();
    hash_node *temp = lookup_hash(symboltable->table, symboltable->table_size, hash);
    if (temp == NULL || (!(temp->sym->type == type || temp->sym->type != FUN))) {
        return 0;
    }
    return 1;
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