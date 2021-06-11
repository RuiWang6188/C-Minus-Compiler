#include "code_gen.h"

llvm::Function* codeGen::getCurFunction() {
    return funStack.top();
}

void codeGen::pushFunction(llvm::Function* func) {
    funStack.push(func);
}

void codeGen::popFunction() {
    funStack.pop();
}

llvm::Value* codeGen::findValue(const std::string & name) {
    llvm::Value * result = funStack.top()->getValueSymbolTable()->lookup(name);
    if (result != nullptr) {
        return result;
    }
    result = module->getGlobalVariable(name);
    if (result == nullptr) {
        cout<<"[ERROR]Undeclared variable: " << name <<endl;
    }
    return result;
}

llvm::Function* codeGen::createPrint()
{
    std::vector<llvm::Type*> arg_types;
    arg_types.push_back(builder.getInt8PtrTy());
    auto printf_type = llvm::FunctionType::get(builder.getInt32Ty(), llvm::makeArrayRef(arg_types), true);
    auto func = llvm::Function::Create(printf_type, llvm::Function::ExternalLinkage, llvm::Twine("print"), module);
    func->setCallingConv(llvm::CallingConv::C);
    return func;
}

llvm::Function* codeGen::createScan()
{
    auto scanf_type = llvm::FunctionType::get(builder.getInt32Ty(), true);
    auto func = llvm::Function::Create(scanf_type, llvm::Function::ExternalLinkage, llvm::Twine("scan"), module);
    func->setCallingConv(llvm::CallingConv::C);
    return func;
}

void codeGen::generate(Node* root) {
    root->irBuild();
    this->module->dump();
}

codeGen::codeGen(/* args */) {
    this->module = new llvm::Module("main", context);
    this->print = this->createPrint();
    this->scan = this->createScan();
}

codeGen::~codeGen() {

}
