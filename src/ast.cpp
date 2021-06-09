#include "ast.h"

Node::Node(string nodeName, string nodeType, int lineNo) {
    this->nodeName = new string(nodeName);
    this->nodeType = new string(nodeType);
    this->lineNo = lineNo;
    this->childNum = 0;
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
} 

int Node::getValueType() {
    return getValueType(this);
}

int Node::getValueType(Node *node) {
    if (node->nodeType->compare("Specifier")) {
        // Specifier --> Type
        if (node->childNode[0]->nodeName->compare("int")) {
            return TYPE_INT;
        } 
        else if (node->childNode[0]->nodeName->compare("float")) {
            return TYPE_FLOAT;
        } 
        else if (node->childNode[0]->nodeName->compare("char")) {
            return TYPE_CHAR;
        } 
        else if (node->childNode[0]->nodeName->compare("boolean")) {
            return TYPE_BOOL;
        } 
        else {

        }
    }
}


// ExtDecList --> VarDec
// ExtDecList --> VarDec COMMA ExtDecList
// DecList --> VarDec
// DecList --> VarDec COMMA DecList
vector<pair<string, int>> *Node::getNameList() {
    if (this->nodeType->compare("ExtDecList") != 0 && this->nodeType->compare("DecList") != 0) {
        cout<<"Wrong function call : getNameList ."<<endl;
    }
    Node *temp = this;
    vector<pair<string, int>> *nameList = new vector<pair<string, int>>;
    while (true) {
        // VarDec --> ID[INT]
        if (temp->childNode[0]->childNum == 4) {
            nameList->push_back(make_pair(*temp->childNode[0]->childNode[0]->nodeName, ARRAY));
        }
        // VarDec --> ID
        else if (temp->childNode[0]->childNum == 1) {
            nameList->push_back(make_pair(*temp->childNode[0]->childNode[0]->nodeName, VAR));
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
vector<pair<string, int>> *Node::getParam() {
    if (this->nodeType->compare("VarList") != 0) {
        cout<<"Wrong function call : getParam ."<<endl;
    }
    Node *temp0 = this;
    // ParamDec
    Node *temp1 = this->childNode[0];
    vector<pair<string, int>> *paramList = new vector<pair<string, int>>;
    while (true) {
        temp1 = this->childNode[0];
        // ParamDec --> Specifier VarDec
        // VarDec --> ID[] 
        if (temp1->childNode[1]->childNum == 3) {
            paramList->push_back(make_pair(*temp1->childNode[1]->childNode[0]->nodeName, ARRAY + getValueType(temp1->childNode[0])));
        }
        // VarDec --> ID
        else if (temp1->childNode[1]->childNum == 1) {
            paramList->push_back(make_pair(*temp1->childNode[1]->childNode[0]->nodeName, VAR + getValueType(temp1->childNode[0])));
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

bool Node::insertSymbol() {
    // ExtDef --> Specifier ExtDecList SEMI;
    // Def --> Specifier DecList SEMI;
    // ExtDef --> Specifier FunDec CompSt;
    if (this->nodeType->compare("ExtDef") != 0 && this->nodeType->compare("Def") != 0) {
        cout<<"Wrong function call : insertSymbol ."<<endl;
    }
    else if (this->childNode[1]->nodeType->compare("FunDec") == 0) {
        return insertFunSymbol();
    }
    else {
        vector<pair<string, int>> *nameList = this->childNode[1]->getNameList();
        int type = this->childNode[0]->getValueType();
        bool flag;
        for (auto it = nameList->begin(); it != nameList->end(); it++) {
            flag = symbolTable->insertSymbol(it->first, scopeStack->getCurrentScope(), type + it->second, NULL);
            if (flag == false) {
                return false;
            }
        }
    }
    return true;
} 

// ExtDef --> Specifier FunDec CompSt
bool Node::insertFunSymbol() {
    vector<pair<string, int>> * paramList;
    Symbol *varList, *tail = NULL;
    // FunDec --> ID LP VarList RP
    if (this->childNode[1]->childNum == 4) {
        paramList = this->childNode[1]->childNode[3]->getParam();
        for (auto it = paramList->begin(); it != paramList->end(); it++) {
            Symbol * temp = new Symbol(it->first, it->second, scopeStack->getCurrentScope(), NULL);
            if (tail == NULL) {
                tail = temp;
                varList = temp;
            } else {
                tail->next = temp;
                tail = temp; 
            }
        }
        bool flag = symbolTable->insertSymbol(*this->childNode[1]->childNode[0]->nodeName, scopeStack->getCurrentScope(), this->childNode[0]->getValueType(), varList);       
        if (flag == false) {
            return false;
        }
        scopeStack->enterScope(*this->childNode[1]->childNode[0]->nodeName);
        while (varList) {
            flag = symbolTable->insertSymbol(varList);
            if (flag == false) {
                return false;
            }
            varList = varList->next;
        }
        return true;
    }
    // FunDec --> ID LP RP
    else if (this->childNode[1]->childNum == 3) {
        paramList = NULL;
        varList = NULL;
        bool flag = symbolTable->insertSymbol(*this->childNode[1]->childNode[0]->nodeName, scopeStack->getCurrentScope(), this->childNode[0]->getValueType(), varList);       
        if (flag == false) {
            return false;
        }
        return true;
    } 
    else {
        return false;
    }

    // ExtDef --> Specifier FunDec CompSt
    // CompSt --> LC DefList StmtList RC
    Node * temp = this->childNode[2]->childNode[1];
    bool flag;
    // DefList --> Def DefList
    while (temp) {
        flag = temp->childNode[0]->insertSymbol();
        if (flag == false) {
            return false;
        }
    }
    return true;
}

void semanticAnalysis() {
    
}


// Args --> Exp COMMA Args
// Args --> Exp
vector<pair<string, int>> *Node::getArgs() {

}

llvm::Value * Node::irBuild() {
    
}