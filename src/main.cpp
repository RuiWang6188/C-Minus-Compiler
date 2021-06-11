#include "type.h"
#include "code_gen.h"
#include "ast.h"

extern int yyparse();
extern Node *root;

int main() {
    yyparse();
    generator = new codeGen();
    generator->generate(root);

    return 0;
}