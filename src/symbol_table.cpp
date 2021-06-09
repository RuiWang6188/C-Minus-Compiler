#include "symbol_table.h"

ScopeStack::ScopeStack(/* args */) {
    this->scopeStack = new stack<string>;
}

ScopeStack::~ScopeStack() {
    delete this->scopeStack;
}

void ScopeStack::enterScope(string scope) {
    this->scopeStack->push(scope);
}

string ScopeStack::getCurrentScope() {
    this->scopeStack->top();
}

void ScopeStack::exitScope() {
    this->scopeStack->pop();
}

Symbol::Symbol(string name, int type, string scope, Symbol *argList) {
    this->name = name;
    this->type = type;
    this->scope = scope;
    this->argList = argList;
    this->next = NULL;
}

Symbol::Symbol(string name, string scope) {
    this->name = name;
    this->scope = scope;
}

Symbol::Symbol() {
    
}

Symbol::~Symbol() {

}

HashNode::HashNode() {

}

HashNode::HashNode(Symbol *symbol, unsigned int hash) {
    this->symbol = symbol;
    this->hash = hash;
    this->next = NULL;
    this->localNext = NULL;
}

HashNode::~HashNode() {
    delete this->symbol;
}

HashNode::HashNode(Symbol *symbol, unsigned int hash) {
    this->symbol = symbol;
    this->hash = hash;
    this->next = NULL;
    this->localNext = NULL;
}


bool HashTable::insertSymbol(Symbol *symbol) {
    unsigned int hash = this->hash(symbol->name);
    HashNode *temp = this->lookup(symbol->name, symbol->scope);
    if (temp != NULL) {
        return false;
    }
    int index = hash / this->size;
    temp = this->table[index];
    if (temp == NULL) {
        temp = new HashNode(symbol, hash);
    } else {
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new HashNode(symbol, hash);
    }
    if (symbol->scope.compare(GLOBAL)) {
        if (loaclTail) {
            this->loaclTail->next = temp;
            this->loaclTail = temp;
        } else {
            this->localHead = temp;
            this->loaclTail = temp;
        }
    }
    return true;
}

bool HashTable::deleteLocal() {
    HashNode *temp = localHead;
    while (this->localHead) {
        temp = localHead->next;
        delete localHead;
        localHead = temp;        
    }
    return true;
}

HashNode * HashTable::lookup(string name) {
    unsigned int hash = this->hash(name);
    int index = hash / this->size;
    HashNode *temp = this->table[index];
    HashNode *globalTemp = NULL;
    while (temp) {
        if (temp->symbol->name.compare(name) == 0) {
            if (temp->symbol->scope.compare(GLOBAL) == 0) {
                globalTemp = temp;
            } else {
                // local var
                return temp;
            }
        } 
        temp = temp->next;
    }
    return globalTemp;

}

HashNode * HashTable:: lookup(string name, string scope) {
    unsigned int hash = this->hash(name);
    int index = hash / this->size;
    HashNode *temp = this->table[index];
    while (temp) {
        if (temp->symbol->name.compare(name) == 0 && temp->symbol->scope.compare(scope) == 0) {
            return temp;
        } 
        temp = temp->next;
    }
    return NULL;
}

unsigned int HashTable::hash(string str) {
    return BKDRHash(str);
}

unsigned int HashTable::BKDRHash(string str) {
    unsigned int seed = 131;
    unsigned int hash = 0;
    for (int i = 0; i < str.length(); i++) {
        hash = hash * seed + static_cast<unsigned int>(str.at(i));    
    }
    return (hash & 0x7FFFFFFF);
}

HashTable::HashTable(/* args */) {
    this->size = 64;
    this->table = new HashNode* [size]; 
}

HashTable::HashTable(int size) {
    this->size = size;
    this->table = new HashNode* [size]; 
}

HashTable::~HashTable() {
    delete this->table; 
}

bool SymbolTable::insertSymbol(Symbol *symbol) {
    return table->insertSymbol(symbol); 
}

bool SymbolTable::insertSymbol(string name, string scope, int type, Symbol *varlist) {
    Symbol *symbol = new Symbol(name, type, scope, varlist);
    return table->insertSymbol(symbol);
}

void SymbolTable::deleteLocalSymbol() {
    table->deleteLocal();
}

Symbol *SymbolTable::lookup(string name) {
    return table->lookup(name)->symbol;
}

SymbolTable::SymbolTable(/* args */) {
    this->table = new HashTable();
}

SymbolTable::~SymbolTable() {
    delete this->table;
}


