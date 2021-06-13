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

#include "type.h"

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
    llvm::Value *irBuildExp();
    llvm::Value *irBuildFun();
    llvm::Value *irBuildVar();
    llvm::Value *irBuildStmt();
    llvm::Value *irBuildWhile();
    llvm::Value *irBuildIf();
    llvm::Value *irBuildReturn();
    llvm::Value *irBuildCompSt();
    llvm::Value *irBuildRELOP();
    llvm::Value *irBuildPrint();
    llvm::Value *irBuildPrintf();
    llvm::Value *irBuildScan();
    llvm::Value *irBuildAddr();
    int getValueType();
    int getValueType(Node *node);
    void setValueType(int type);
    llvm::Type* getLlvmType(int type, int arraySize); 
    vector<pair<string, int>> *getNameList(int type);
    vector<llvm::Value *> *getArgs();
    vector<llvm::Value *> *getArgsAddr();
    vector<pair<string, llvm::Type*>> *getParam();
    Node(char * nodeName, string nodeType, int lineNo);
    Node(string nodeName, string nodeType, int childNum, ...);

    ~Node();
};

llvm::AllocaInst *CreateEntryBlockAlloca(llvm::Function *TheFunction, llvm::StringRef VarName, llvm::Type* type);

#endif