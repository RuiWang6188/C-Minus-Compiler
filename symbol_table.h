#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

#define FUN 0
#define STRUCT 1
#define INT 2
#define FLOAT 3 

struct arg {
    char *name;
    int type;
    struct arg *next;
};

struct symbol {
    char *name;
    int type;
    struct arg *arg;
};

void init_symbol_table();
void clear_symbol_table();
int insert_symbol(char *name, int type, struct arg* arg);
int lookup(char *name);





#endif