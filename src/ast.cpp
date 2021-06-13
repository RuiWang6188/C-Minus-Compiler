#include "ast.h"
#include "code_gen.h"
#include <cstdarg>

Node *ROOT;
extern codeGen *generator;

Node::Node(char * nodeName, string nodeType, int lineNo) {
    this->nodeName = new string(nodeName);
    this->nodeType = new string(nodeType);
    this->lineNo = lineNo;
    this->childNum = 0;
    cout<<nodeName<<" "<<nodeType<<endl;
}

Node::Node(string nodeName, string nodeType, int childNum, ...) {
    this->nodeName = new string(nodeName);
    this->nodeType = new string(nodeType);

    this->childNum = childNum;
    this->childNode = new Node * [childNum];

    va_list l;
    va_start(l, childNum);
    for (int i = 0; i < childNum; i++) {
        Node* node;
        node = va_arg(l, Node *);
        this->childNode[i] = node;
    }
    this->lineNo = this->childNode[0]->lineNo;
    va_end(l);
    cout<<nodeName<<" "<<nodeType<<endl;
} 

void Node::setValueType(int type) {
    this->valueType = type;
}

int Node::getValueType() {
    return getValueType(this);
}

int Node::getValueType(Node *node) {
    if (node->nodeType->compare("Specifier") == 0) {
        // Specifier --> Type
        if (node->childNode[0]->nodeName->compare("int") == 0) {
            return TYPE_INT;
        } 
        else if (node->childNode[0]->nodeName->compare("float") == 0) {
            return TYPE_FLOAT;
        } 
        else if (node->childNode[0]->nodeName->compare("char") == 0) {
            return TYPE_CHAR;
        } 
        else if (node->childNode[0]->nodeName->compare("boolean") == 0) {
            return TYPE_BOOL;
        } 
        else {

        }
    } else if (node->nodeType->compare("Exp") == 0) {
        return node->valueType;
    }
    // Error
    return -1;
}

llvm::Type* Node::getLlvmType(int type, int arraySize) {
    switch (type) {
        case TYPE_INT:
            return llvm::Type::getInt32Ty(context);
            break;
        case TYPE_INT_ARRAY:
            if (arraySize > 0) {
                return llvm::ArrayType::get(llvm::Type::getInt32Ty(context), arraySize);
            } else {
                return llvm::Type::getInt32PtrTy(context);
            }
            break;
        case TYPE_FLOAT:
            return llvm::Type::getFloatTy(context);
            break;
        case TYPE_FLOAT_ARRAY:
            if (arraySize > 0) {
                return llvm::ArrayType::get(llvm::Type::getFloatTy(context), arraySize);
            } else {
                return llvm::Type::getFloatPtrTy(context);
            }
            break;
        case TYPE_BOOL:
            return llvm::Type::getInt1Ty(context);
            break;
        case TYPE_BOOL_ARRAY:
            if (arraySize > 0) {
                return llvm::ArrayType::get(llvm::Type::getInt1Ty(context), arraySize);
            } else {
                return llvm::Type::getInt1PtrTy(context);
            }
            break;
        case TYPE_CHAR:
            return llvm::Type::getInt8Ty(context);
            break;
        case TYPE_CHAR_ARRAY:
            if (arraySize > 0) {
                return llvm::ArrayType::get(llvm::Type::getInt8Ty(context), arraySize);
            } else {
                return llvm::Type::getInt8PtrTy(context);
            }
            break;
        default:
            break;
    }
    return llvm::Type::getVoidTy(context);
}


// ExtDecList --> VarDec
// ExtDecList --> VarDec COMMA ExtDecList
// DecList --> VarDec
// DecList --> VarDec COMMA DecList
vector<pair<string, int>> *Node::getNameList(int type) {
    if (this->nodeType->compare("ExtDecList") != 0 && this->nodeType->compare("DecList") != 0) {
        cout<<"Wrong function call : getNameList ."<<endl;
    }
    Node *temp = this;
    vector<pair<string, int>> *nameList = new vector<pair<string, int>>;
    while (true) {
        // VarDec --> ID[INT]
        if (temp->childNode[0]->childNum == 4) {
            int arraySize = stoi(*temp->childNode[0]->childNode[2]->nodeName);
            nameList->push_back(make_pair(*temp->childNode[0]->childNode[0]->nodeName, ARRAY + arraySize));
            temp->childNode[0]->childNode[0]->setValueType(type + ARRAY);
        }
        // VarDec --> ID
        else if (temp->childNode[0]->childNum == 1) {
            nameList->push_back(make_pair(*temp->childNode[0]->childNode[0]->nodeName, VAR));
            temp->childNode[0]->childNode[0]->setValueType(type);
        }
        else if (temp->childNode[0]->childNum == 3) {
            nameList->push_back(make_pair(*temp->childNode[0]->childNode[0]->nodeName, ARRAY));
            temp->childNode[0]->childNode[0]->setValueType(type + ARRAY);
        }
        else {
            cout<<"Error:"<<endl;
            return nameList;
        } 
        // ExtDecList --> VarDec COMMA ExtDecList
        // DecList --> VarDec COMMA DecList
        if (temp->childNum == 3)
            temp = temp->childNode[2];
        // ExtDecList --> VarDec
        // DecList --> VarDec
        else
            break;        
    }
    return nameList;
}

// VarList --> ParamDec COMMA VarList
// VarList --> ParamDec
// ParamDec --> Specifier VarDec
vector<pair<string, llvm::Type*>> *Node::getParam() {
    if (this->nodeType->compare("VarList") != 0) {
        cout<<"Wrong function call : getParam ."<<endl;
        return NULL;
    }
    Node *temp0 = this;
    // ParamDec
    Node *temp1 = this->childNode[0];
    vector<pair<string, llvm::Type*>> *paramList = new vector<pair<string, llvm::Type*>>;
    while (true) {
        temp1 = temp0->childNode[0];
        // ParamDec --> Specifier VarDec
        // VarDec --> ID[] 
        if (temp1->childNode[1]->childNum == 3) {
            paramList->push_back(make_pair(*temp1->childNode[1]->childNode[0]->nodeName, getLlvmType(ARRAY + getValueType(temp1->childNode[0]), 0)));
        }
        // VarDec --> ID
        else if (temp1->childNode[1]->childNum == 1) {
            paramList->push_back(make_pair(*temp1->childNode[1]->childNode[0]->nodeName, getLlvmType(VAR + getValueType(temp1->childNode[0]), 0)));
        }
        else {
            cout<<"Error:"<<endl;
            return paramList;
        } 
        // VarList --> ParamDec COMMA VarList
        if (temp0->childNum == 3)
            temp0 = temp0->childNode[2];
        // VarList --> ParamDec
        else
            break;        
    }
    return paramList;
}

// Args --> Exp COMMA Args
// Args --> Exp
vector<llvm::Value *> *Node::getArgs() {
    vector<llvm::Value *> * args = new vector<llvm::Value *>;
    Node *node = this;
    while (true) {
        if (node->childNum == 1) {
            args->push_back(node->childNode[0]->irBuildExp());
            break;
        }
        else {
            args->push_back(node->childNode[0]->irBuildExp());
            node = node->childNode[2];
        }
    }
    return args;
}

vector<llvm::Value *> *Node::getArgsAddr() {
    vector<llvm::Value *> * args = new vector<llvm::Value *>;
    Node *node = this;
    while (true) {
        if (node->childNum == 1) {
            args->push_back(node->childNode[0]->irBuildAddr());
            break;
        }
        else {
            args->push_back(node->childNode[0]->irBuildAddr());
            node = node->childNode[2];
        }
    }
    return args;
}

llvm::Value * Node::irBuild() {
    cout<<*this->nodeType<<" "<<*this->nodeName<<endl;
    if (this->nodeType->compare("ExtDef") == 0) {
        if (this->childNode[1]->nodeType->compare("ExtDecList") == 0) {
            return this->irBuildVar();
        } else {
            return this->irBuildFun();
        }
    } else if (this->nodeType->compare("Def") == 0) {
        return this->irBuildVar();
    }
    for ( int i = 0; i < this->childNum; i++) {
        if (this->childNode[i] != nullptr)
            this->childNode[i]->irBuild();
    }
    return NULL;
} 

// Exp --> ID
// Exp --> ID[Exp]
llvm::Value * Node::irBuildAddr() {
    if (this->childNum == 1) {
        return generator->findValue(*this->childNode[0]->nodeName);
    } else if (this->childNum == 4) {
        llvm::Value * arrayValue = generator->findValue(*this->childNode[0]->nodeName);
        llvm::Value * indexValue = this->childNode[2]->irBuildExp();
        vector<llvm::Value*> indexList;
        indexList.push_back(builder.getInt32(0));
        indexList.push_back(indexValue);
        // var value
        return builder.CreateInBoundsGEP(arrayValue, llvm::ArrayRef<llvm::Value*>(indexList));
    } else {
        //ERROR
    }
    return NULL;
}

llvm::Value * Node::irBuildExp() {
    cout<<"irBuildExp: "<<*this->nodeType<<" "<<*this->nodeName<<endl;
    if (this->childNode[0]->nodeType->compare("INT") == 0) {
        return builder.getInt32(stoi(*this->childNode[0]->nodeName));
    } 
    else if (this->childNode[0]->nodeType->compare("FLOAT") == 0) {
        return llvm::ConstantFP::get(builder.getFloatTy(), llvm::APFloat(stof(*this->childNode[0]->nodeName)));
    }
    else if (this->childNode[0]->nodeType->compare("BOOL") == 0) {
        if (this->childNode[0]->nodeName->compare("true") == 0) {
            return builder.getInt1(true);
        } else {
            return builder.getInt1(false);
        }
    }
    else if (this->childNode[0]->nodeType->compare("CHAR") == 0) {
        // char --> '$ch'
        return builder.getInt8(this->childNode[0]->nodeName->at(1));
    }
    else if (this->childNode[0]->nodeType->compare("STRING") == 0) {
        // string --> "$ch"
        string str = this->childNode[0]->nodeName->substr(1, this->childNode[0]->nodeName->length() - 2);
        llvm::Constant *strConst = llvm::ConstantDataArray::getString(context, str);
        llvm::Value *globalVar = new llvm::GlobalVariable(*generator->module, strConst->getType(), true, llvm::GlobalValue::PrivateLinkage, strConst, "_Const_String_");
        vector<llvm::Value*> indexList;
        indexList.push_back(builder.getInt32(0));
        indexList.push_back(builder.getInt32(0));
        // var value
        llvm::Value * varPtr = builder.CreateInBoundsGEP(globalVar, llvm::ArrayRef<llvm::Value*>(indexList));
        return varPtr;
        //return builder.getInt8(this->childNode[0]->nodeName->at(1));
    }
    else if (this->childNode[0]->nodeType->compare("ID") == 0) {
        if (this->childNum == 1) {
            // always return var value
            llvm::Value * varPtr = generator->findValue(*this->childNode[0]->nodeName);
            if (varPtr->getType()->isPointerTy()) {
                return builder.CreateLoad(varPtr->getType()->getPointerElementType(), varPtr, "tmpvar");
            }
            else {
                return varPtr;
            }
            
        }
        // ID() function
        // ID[] array or point
        else if (this->childNum == 3) {
            if (this->childNode[1]->nodeType->compare("LP") == 0) {
                llvm::Function *fun = generator->module->getFunction(*this->childNode[0]->nodeName);
                if (fun == nullptr) {
                    cout<<"[ERROR] Funtion not defined: "<<*this->childNode[0]->nodeName<<endl;
                }
                return builder.CreateCall(fun, nullptr, "calltmp");
            }
            else {
                // var addr
                return generator->findValue(*this->childNode[0]->nodeName);
            }
        }
        else if (this->childNum == 4) {
            // ID LP Args RP
            if (this->childNode[1]->nodeType->compare("LP") == 0) {
                if (this->childNode[0]->nodeName->compare("print") == 0) {
                    return this->irBuildPrint();
                }
                if (this->childNode[0]->nodeName->compare("scan") == 0) {
                    return this->irBuildScan();
                }
                llvm::Function *fun = generator->module->getFunction(*this->childNode[0]->nodeName);
                if (fun == nullptr) {
                    cout<<"[ERROR] Funtion not defined: "<<*this->childNode[0]->nodeName<<endl;
                }
                vector<llvm::Value*> *args = this->childNode[2]->getArgs();
                return builder.CreateCall(fun, *args, "calltmp");
            }
            else {
                llvm::Value * arrayValue = generator->findValue(*this->childNode[0]->nodeName);
                llvm::Value * indexValue = this->childNode[2]->irBuildExp();
                vector<llvm::Value*> indexList;
                indexList.push_back(builder.getInt32(0));
                indexList.push_back(indexValue);
                // var value
                llvm::Value * varPtr = builder.CreateInBoundsGEP(arrayValue, llvm::ArrayRef<llvm::Value*>(indexList));
                return builder.CreateLoad(varPtr->getType()->getPointerElementType(), varPtr, "tmpvar");
                //return builder.CreateLoad(builder.CreateInBoundsGEP(arrayValue, llvm::ArrayRef<llvm::Value*>(indexList)), "tmpvar");
            }
        }
    }
    else if (this->childNode[0]->nodeType->compare("LP") == 0) {
        return this->childNode[1]->irBuildExp();
    }
    else if (this->childNode[0]->nodeType->compare("MINUS") == 0) {
        return builder.CreateNeg(this->childNode[1]->irBuildExp(), "tmpNeg");
        //int type = this->childNode[1]->getValueType();
        //return type == TYPE_INT ? builder.CreateSub(builder.getInt32(0), this->childNode[1]->irBuildExp()) : builder.CreateFSub(llvm::ConstantFP::get(builder.getFloatTy(), llvm::APFloat(0.0)), this->childNode[1]->irBuildExp());
    }
    else if (this->childNode[0]->nodeType->compare("NOT") == 0) {
        return builder.CreateNot(this->childNode[1]->irBuildExp(), "tmpNot");
    }
    // Exp op Exp
    else {
        if (this->childNode[1]->nodeType->compare("ASSIGNOP") == 0) {
            return builder.CreateStore(this->childNode[2]->irBuildExp(), this->childNode[0]->irBuildAddr());
        }
        else if (this->childNode[1]->nodeType->compare("RELOP") == 0) {
            return this->irBuildRELOP();
        }
        else {
            llvm::Value *left = this->childNode[0]->irBuildExp();
            llvm::Value *right = this->childNode[2]->irBuildExp();
            if (this->childNode[1]->nodeType->compare("AND") == 0) {
                return builder.CreateAnd(left, right, "tmpAnd");
            }
            else if (this->childNode[1]->nodeType->compare("OR") == 0) {
                return builder.CreateOr(left, right, "tmpOR");
            }
            else if (this->childNode[1]->nodeType->compare("PLUS") == 0) {
                return (left->getType() == llvm::Type::getFloatTy(context)) ? builder.CreateFAdd(left, right, "addtmpf") : builder.CreateAdd(left, right, "addtmpi");
            }
            else if (this->childNode[1]->nodeType->compare("MINUS") == 0) {
                return (left->getType() == llvm::Type::getFloatTy(context)) ? builder.CreateFSub(left, right, "subtmpf") : builder.CreateSub(left, right, "subtmpi");
            }
            else if (this->childNode[1]->nodeType->compare("STAR") == 0) {
                return (left->getType() == llvm::Type::getFloatTy(context)) ? builder.CreateFMul(left, right, "multmpf") : builder.CreateMul(left, right, "multmpi");
            }
            else if (this->childNode[1]->nodeType->compare("DIV") == 0) {
                return (left->getType() == llvm::Type::getFloatTy(context)) ? builder.CreateFDiv(left, right, "divtmpf") : builder.CreateSDiv(left, right, "divtmpi");
            }
        }
    }
    return NULL;
}

// Exp RELOP Exp
llvm::Value * Node::irBuildRELOP() {
    cout<<*this->nodeType<<" "<<*this->nodeName<<endl;
    llvm::Value * left = this->childNode[0]->irBuildExp();
    llvm::Value * right = this->childNode[2]->irBuildExp();
    if (this->childNode[1]->nodeName->compare("==") == 0) {
        return (left->getType() == llvm::Type::getFloatTy(context)) ? builder.CreateFCmpOEQ(left, right, "fcmptmp") : builder.CreateICmpEQ(left, right, "icmptmp");
    }
    else if (this->childNode[1]->nodeName->compare(">=") == 0) {
        return (left->getType() == llvm::Type::getFloatTy(context)) ? builder.CreateFCmpOGE(left, right, "fcmptmp") : builder.CreateICmpSGE(left, right, "icmptmp");
    }
    else if (this->childNode[1]->nodeName->compare("<=") == 0) {
        return (left->getType() == llvm::Type::getFloatTy(context)) ? builder.CreateFCmpOLE(left, right, "fcmptmp") : builder.CreateICmpSLE(left, right, "icmptmp");
    }
    else if (this->childNode[1]->nodeName->compare(">") == 0) {
        return (left->getType() == llvm::Type::getFloatTy(context)) ? builder.CreateFCmpOGT(left, right, "fcmptmp") : builder.CreateICmpSGT(left, right, "icmptmp");
    }
    else if (this->childNode[1]->nodeName->compare("<") == 0) {
        return (left->getType() == llvm::Type::getFloatTy(context)) ? builder.CreateFCmpOLT(left, right, "fcmptmp") : builder.CreateICmpSLT(left, right, "icmptmp");
    }
    else if (this->childNode[1]->nodeName->compare("!=") == 0) {
        return (left->getType() == llvm::Type::getFloatTy(context)) ? builder.CreateFCmpONE(left, right, "fcmptmp") : builder.CreateICmpNE(left, right, "icmptmp");
    }
    return NULL;
}

// CompSt --> LC DefList StmtList RC
// DefList --> Def DefList
// Def --> Specifier DecList SEMI
// StmtList --> Stmt StmtList
llvm::Value * Node::irBuildCompSt() {
    cout<<"irBuildCompSt: "<<*this->nodeType<<" "<<*this->nodeName<<endl;
    Node * defNodes = this->childNode[1];
    Node * stmtNodes = this->childNode[2];
    while (true) {
        if (defNodes != nullptr && defNodes->childNum == 2) {
            defNodes->childNode[0]->irBuildVar();
            defNodes = defNodes->childNode[1];
        }
        else {
            break;
        }
    } 
    while (true) {
        if (stmtNodes != nullptr && stmtNodes->childNum == 2) {
            stmtNodes->childNode[0]->irBuildStmt();
            stmtNodes = stmtNodes->childNode[1];
        }
        else {
            break;
        }
    }
    return NULL;
}

// ExtDef --> Specifier ExtDecList SEMI
// Def --> Specifier DecList SEMI
llvm::Value * Node::irBuildVar() {
    cout<<"irBuildVar: "<<*this->nodeType<<" "<<*this->nodeName<<endl;
    int type = this->childNode[0]->getValueType();
    vector<pair<string, int>> *nameList = this->childNode[1]->getNameList(type);
    llvm::Type *llvmType;
    for (auto it : *nameList) {
        if (it.second == VAR) {
            llvmType = getLlvmType(type, 0);
        } else {
            llvmType = getLlvmType(type + ARRAY, it.second - ARRAY);
        }
        if (generator->funStack.empty()) {
            llvm::GlobalVariable* globalVar = new llvm::GlobalVariable(*generator->module, llvmType, false, llvm::GlobalValue::PrivateLinkage, 0, it.first);
            globalVar->setInitializer(llvm::ConstantInt::get(llvmType, 0));
            //if (generator->module->getGlobalVariable(it.first, true) == nullptr) {
            //    cout<<"ERROR"<<endl;
            //}
        }
        else {
            llvm::Value* alloc = CreateEntryBlockAlloca(generator->getCurFunction(), it.first, llvmType);
        }
    }
    return NULL;
}

// Specifier FunDec CompSt
llvm::Value * Node::irBuildFun() {
    cout<<"irBuildFun: "<<*this->nodeType<<" "<<*this->nodeName<<endl;
    vector<pair<string, llvm::Type*>> *params = nullptr;
    vector<llvm::Type*> argTypes;
    // FunDec --> ID LP VarList RP
    if (this->childNode[1]->childNum == 4) {
        params = this->childNode[1]->childNode[2]->getParam();
        for (auto it : *params) {
            argTypes.push_back(it.second);
        }
    }

    llvm::FunctionType *funcType = llvm::FunctionType::get(getLlvmType(getValueType(this->childNode[0]), 0), argTypes, false);
    llvm::Function *function = llvm::Function::Create(funcType, llvm::GlobalValue::ExternalLinkage, *this->childNode[1]->childNode[0]->nodeName, generator->module);
    generator->pushFunction(function);

    //Block
    llvm::BasicBlock *newBlock = llvm::BasicBlock::Create(context, "entrypoint", function);
    builder.SetInsertPoint(newBlock);
    
    //Parameters
    if(params != nullptr) {
        //llvm::Function::arg_iterator argIt = function->arg_begin();
        //int index = 1;
        //llvm::Value *alloc = nullptr;
        //for (auto para : *params) {
        //    function->addAttribute(index, llvm::Attribute::NonNull);
        //    alloc = builder.CreateGEP(argIt++, builder.getInt32(0), para.first);
        //    index ++;
        //}   
        int index = 0;
        for (auto &Arg : function->args()) {
            Arg.setName(params->at(index++).first);
        }
    }
    
    //Sub routine
    this->childNode[2]->irBuildCompSt();

    //Pop back
    generator->popFunction();
    return function;
}

// Stmt
llvm::Value *Node::irBuildStmt() {
    cout<<"irBuildStmt: "<<*this->nodeType<<" "<<*this->nodeName<<endl;
    if (this->childNode[0]->nodeType->compare("Exp") == 0) {
        return this->childNode[0]->irBuildExp();
    } else if (this->childNode[0]->nodeType->compare("IF") == 0) {
        return this->irBuildIf();
    } else if (this->childNode[0]->nodeType->compare("WHILE") == 0) {
        return this->irBuildWhile();
    } else if (this->childNode[0]->nodeType->compare("RETURN") == 0) {
        return this->irBuildReturn();
    } else if (this->childNode[0]->nodeType->compare("CompSt") == 0) {
        return this->childNode[0]->irBuildCompSt();
    }
    return NULL;
}

// WHILE LP Exp RP Stmt
llvm::Value *Node::irBuildWhile() {
    //this->forward(generator);
    cout<<"irBuildWhile: "<<*this->nodeType<<" "<<*this->nodeName<<endl;
    llvm::Function *TheFunction = generator->getCurFunction();
    llvm::BasicBlock *condBB = llvm::BasicBlock::Create(context, "cond", TheFunction);
    llvm::BasicBlock *loopBB = llvm::BasicBlock::Create(context, "loop", TheFunction);
    llvm::BasicBlock *afterBB = llvm::BasicBlock::Create(context, "afterLoop", TheFunction);
    
    //Cond
    builder.CreateBr(condBB);
    builder.SetInsertPoint(condBB);
    // WHILE LP Exp RP Stmt
    llvm::Value *condValue = this->childNode[2]->irBuildExp();
    condValue = builder.CreateICmpNE(condValue, llvm::ConstantInt::get(llvm::Type::getInt1Ty(context), 0, true), "whileCond");
    auto branch = builder.CreateCondBr(condValue, loopBB, afterBB);
    condBB = builder.GetInsertBlock();
    
    //Loop
    builder.SetInsertPoint(loopBB);
    this->childNode[4]->irBuildStmt();
    builder.CreateBr(condBB);
    
    //After
    builder.SetInsertPoint(afterBB);
    //this->backward(generator);
    return branch;
}

// IF LP Exp RP Stmt %prec LOWER_THAN_ELSE
// IF LP Exp RP Stmt ELSE Stmt
llvm::Value *Node::irBuildIf() {
    //this->forward(generator);
    cout<<*this->nodeType<<" "<<*this->nodeName<<endl;
    llvm::Value *condValue = this->childNode[2]->irBuildExp(), *thenValue = nullptr, *elseValue = nullptr;
    condValue = builder.CreateICmpNE(condValue, llvm::ConstantInt::get(llvm::Type::getInt1Ty(context), 0, true), "ifCond");

    llvm::Function *TheFunction = generator->getCurFunction();
    llvm::BasicBlock *thenBB = llvm::BasicBlock::Create(context, "then", TheFunction);
    llvm::BasicBlock *elseBB = llvm::BasicBlock::Create(context, "else", TheFunction);
    llvm::BasicBlock *mergeBB = llvm::BasicBlock::Create(context, "merge", TheFunction);

    // Then
    auto branch = builder.CreateCondBr(condValue, thenBB, elseBB);
    builder.SetInsertPoint(thenBB);
    thenValue = this->childNode[4]->irBuildStmt();
    builder.CreateBr(mergeBB);
    thenBB = builder.GetInsertBlock();

    // else
    builder.SetInsertPoint(elseBB);
    if (this->childNum == 7) {
        elseValue = this->childNode[6]->irBuildStmt();
    }
    builder.CreateBr(mergeBB);
    elseBB = builder.GetInsertBlock();

    builder.SetInsertPoint(mergeBB);    
    //this->backward(generator);
    return branch;
}

// RETURN Exp SEMI
// RETURN SEMI
llvm::Value *Node::irBuildReturn() {
    cout<<"irBuildReturn: "<<*this->nodeType<<*this->nodeName<<endl;
    if (this->childNum == 3) {
        auto returnInst = this->childNode[1]->irBuildExp();
        return builder.CreateRet(returnInst);
    }
    return builder.CreateRetVoid();
}

// Exp --> ID LP Args RP
llvm::Value *Node::irBuildPrint() {
    string formatStr = "";
    vector<llvm::Value *> *args = this->childNode[2]->getArgs();
    for (auto & arg : *args) {
        if (arg->getType() == builder.getInt32Ty()) {
            formatStr += "%d";
        }
        else if (arg->getType() == builder.getInt8Ty()) {
            formatStr += "%c";
        }
        else if (arg->getType() == builder.getInt1Ty()) {
            formatStr += "%d";
        }
        else if (arg->getType() == builder.getFloatTy()) {
            formatStr += "%f";
        }
        else if (arg->getType() == builder.getInt8PtrTy()) {
            formatStr += "%s";
        }
        else {
            throw logic_error("[ERROR]Invalid type to write.");
        }
    }
    formatStr += "\n";
    auto formatConst = llvm::ConstantDataArray::getString(context, formatStr.c_str());
    auto formatStrVar = new llvm::GlobalVariable(*(generator->module), llvm::ArrayType::get(builder.getInt8Ty(), formatStr.size() + 1), true, llvm::GlobalValue::ExternalLinkage, formatConst, ".str");
    auto zero = llvm::Constant::getNullValue(builder.getInt32Ty());
    llvm::Constant* indices[] = {zero, zero};
    auto varRef = llvm::ConstantExpr::getGetElementPtr(formatStrVar->getType()->getElementType(), formatStrVar, indices);
    args->insert(args->begin(), varRef);
    return builder.CreateCall(generator->printf, *args, "printf");
}

// Args --> Exp COMMA Args
// Args --> Exp
llvm::Value *Node::irBuildScan() {
    string formatStr = "";
    vector<llvm::Value*> *args = this->childNode[2]->getArgsAddr();
    //Just common variable
    for (auto arg : *args) {
        if (arg->getType()->getPointerElementType() == builder.getInt32Ty()) {
            formatStr += "%d";
        }
        else if (arg->getType()->getPointerElementType() == builder.getInt8Ty()) {
            formatStr += "%c";
        }
        else if (arg->getType()->getPointerElementType() == builder.getInt1Ty()) {
            formatStr += "%d";
        }
        else if (arg->getType()->getPointerElementType() == builder.getFloatTy()) {
            formatStr += "%f";
        }
        else {
            throw logic_error("[ERROR]Invalid type to read.");
        }
    }
    args->insert(args->begin(), builder.CreateGlobalStringPtr(formatStr));
    return builder.CreateCall(generator->scanf, *args, "scanf");
}



llvm::AllocaInst *CreateEntryBlockAlloca(llvm::Function *TheFunction, llvm::StringRef VarName, llvm::Type* type) {
  llvm::IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
  return TmpB.CreateAlloca(type, nullptr, VarName);
}