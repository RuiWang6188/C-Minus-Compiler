#ifndef _AST_H_
#define _AST_H_

#include <llvm/IR/Value.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/GlobalVariable.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ostream>

#include "symbol_table.h"

using namespace std;

class Node {
public:
    // Value or name of node, if type of node is int, the value of nodeName is the value of the integer, float, bool, char are similar
    // if type is var, the value is the name of this variable
    string *nodeName;
    // The type of the node
    string *nodeType;
    // The type of exp, var or const
    int valueType;
    // The number of child of the node
    int childNum;
    // Child nodes of this node
    Node **childNode;
    // The number of rows of the node in the file 
    int lineNo;

    void semanticAnalysis();
    llvm::Value *irBuild();
    int getValueType();
    int getValueType(Node *node);
    bool insertSymbol();
    bool insertFunSymbol();
    vector<pair<string, int>> *getNameList();
    vector<pair<string, int>> *getArgs();
    vector<pair<string, int>> *getParam();
    Node(string nodeName, string nodeType, int lineNo);
    Node(string nodeName, string nodeType, int childNum, ...);

    ~Node();
};



#endif