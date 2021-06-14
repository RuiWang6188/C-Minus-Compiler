#include "code_gen.h"

codeGen *generator;

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
    result = module->getGlobalVariable(name, true);
    if (result == nullptr) {
        cout<<"[ERROR]Undeclared variable: " << name <<endl;
    }
    return result;
}

llvm::Function* codeGen::createPrintf()
{
    std::vector<llvm::Type*> arg_types;
    arg_types.push_back(builder.getInt8PtrTy());
    auto printf_type = llvm::FunctionType::get(builder.getInt32Ty(), llvm::makeArrayRef(arg_types), true);
    auto func = llvm::Function::Create(printf_type, llvm::Function::ExternalLinkage, llvm::Twine("printf"), this->module);
    func->setCallingConv(llvm::CallingConv::C);
    return func;
}

llvm::Function* codeGen::createScanf()
{
    auto scanf_type = llvm::FunctionType::get(builder.getInt32Ty(), true);
    auto func = llvm::Function::Create(scanf_type, llvm::Function::ExternalLinkage, llvm::Twine("scanf"), this->module);
    func->setCallingConv(llvm::CallingConv::C);
    return func;
}

void codeGen::generate(Node* root) {
    root->irBuild();
    this->module->print(llvm::outs(), nullptr);
}

codeGen::codeGen(/* args */) {
    this->module = new llvm::Module("main", context);
    this->printf = this->createPrintf();
    this->scanf = this->createScanf();
}

codeGen::~codeGen() {

}
