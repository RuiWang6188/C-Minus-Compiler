#include "type.h"
#include "code_gen.h"
#include "ast.h"
#include "grammar.hpp"

extern Node *ROOT;
extern codeGen *generator;
extern int yyparse();

int main() {
    yyparse();
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();
    generator = new codeGen();
    generator->generate(ROOT);

    return 0;
}