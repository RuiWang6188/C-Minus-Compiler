#include<stdio.h>
#include"syntax.tab.h"
#include"ast.h"
int mistake=0;
extern SyntaxTree* ROOT;
extern void yyrestart  (FILE * input_file );
extern int yyparse (void);
int main(int argc,char** argv)
{
    if(argc<=1)
        return 1;
    FILE* f=fopen(argv[1],"r");
    if(!f)
    {
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);
    //yydebug=1;
    yyparse();
    if(mistake==0)
        print_ast(ROOT,0);
    
    return 0;
}