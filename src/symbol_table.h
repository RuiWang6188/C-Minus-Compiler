#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

#define VAR 0
#define ARRAY 1

#define FUN 2

#define TYPE_INT 4
#define TYPE_INT_ARRAY 5
#define TYPE_FLOAT 6
#define TYPE_FLOAT_ARRAY 7
#define TYPE_CHAR 8
#define TYPE_CHAR_ARRAY 9
#define TYPE_BOOL 10
#define TYPE_BOOL_ARRAY 9

#define GLOBAL "global"

#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

class Symbol {
public:
    string name;
    int type;
    string scope;
    unsigned int arraySize;
    Symbol *argList;
    Symbol *next;
    Symbol(/* args */);
    Symbol(string name, int type, string scope, Symbol *argList);
    Symbol(string name, string scope);

    ~Symbol();
};

class HashNode {
private:
    unsigned int hash;
public:
    Symbol *symbol;
    HashNode *next;
    HashNode *localNext;
    HashNode(/* args */);
    HashNode(Symbol *symbol, unsigned int hash);
    ~HashNode();
};

class HashTable {
private:
    HashNode **table;
    HashNode *localHead;
    HashNode *loaclTail;
    unsigned int size;
public:
    bool insertSymbol(Symbol *symbol);
    bool deleteLocal();
    HashNode *lookup(string name);
    HashNode *lookup(string name, string scope);
    unsigned int hash(string str);
    unsigned int BKDRHash(string str);
    HashTable(/* args */);
    HashTable(int size);
    ~HashTable();
};

class SymbolTable {
private:
    HashTable *table;
public:
    bool insertSymbol(Symbol *symbol);
    bool insertSymbol(string name, string scope, int type, Symbol *varlist);
    void deleteLocalSymbol();
    Symbol *lookup(string name);
    SymbolTable(/* args */);
    ~SymbolTable();
};

class ScopeStack {
private:
    stack<string> *scopeStack;
public:
    void enterScope(string scope);
    string getCurrentScope();
    void exitScope();
    ScopeStack(/* args */);
    ~ScopeStack();
};

ScopeStack *scopeStack;
SymbolTable *symbolTable;





#endif