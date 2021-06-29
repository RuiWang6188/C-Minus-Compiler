
%{
    #include <stdio.h>
    #include "ast.h"
    #include "type.h"
    int yylex(void);
    int mistakeRecord[4096]={0};
    int mistake = 0;
    extern Node *ROOT;
    void yyerror (char const *s) {
        fprintf (stderr, "%s\n", s);
    }
%}

/*declared types*/
%union
{
    struct Node* label_tree;
}
%token <label_tree> INT
%token <label_tree> FLOAT
%token <label_tree> CHAR
%token <label_tree> BOOL
%token <label_tree> STRING
%token <label_tree> ID
%token <label_tree> SEMI
%token <label_tree> COMMA
%token <label_tree> ASSIGNOP
%token <label_tree> RELOP
%token <label_tree> PLUS MINUS STAR DIV
%token <label_tree> AND OR 
%token <label_tree> NOT
%token <label_tree> TYPE
%token <label_tree> LP RP LB RB LC RC
%token <label_tree> RETURN
%token <label_tree> IF
%token <label_tree> ELSE
%token <label_tree> WHILE
%token <label_tree> BREAK


%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT
%left LP RP LB RB

%type <label_tree> Program ExtDefList ExtDef ExtDecList Specifier
%type <label_tree> VarDec FunDec VarList ParamDec CompSt StmtList Stmt DefList Def DecList Exp Args

%%
Program: 
	ExtDefList {
		$$ = new Node("", "Program", 1, $1);
		ROOT = $$;
	};

ExtDefList: 
	ExtDef ExtDefList {
		$$ = new Node("", "ExtDefList", 2, $1, $2);
	}
    | %empty {
		$$ = nullptr;
	}    
    ;

ExtDef: 
	Specifier ExtDecList SEMI {
        $$ = new Node("", "ExtDef", 3, $1, $2, $3);
	}
    | Specifier FunDec CompSt {
        $$ = new Node("", "ExtDef", 3, $1, $2, $3);
	}
    ;

ExtDecList: 
	VarDec {
		$$ = new Node("", "ExtDecList", 1, $1);
	}
    | VarDec COMMA ExtDecList {
		$$ = new Node("", "ExtDecList", 3, $1, $2, $3);
	}
    ;

Specifier: 
	TYPE {
        $$ = new Node("", "Specifier", 1, $1);
	}
    ;

VarDec:  
	ID {
        $$ = new Node("", "VarDec", 1, $1);
	}
    // only support one-dimensional array
    | ID LB INT RB {
        $$ = new Node("", "VarDec", 4, $1, $2, $3, $4);
	}
    // used in function definition
    | ID LB RB {
        $$ = new Node("", "VarDec", 3, $1, $2, $3);
	}
    | ID LB error RB {
        if(mistakeRecord[@3.first_line-1] == 0){
            mistakeRecord[@3.first_line-1] = 1;
            mistake++;
        	printf("Error Occur at Line %d: Syntax Error.\n", @3.first_line);
        }
    }
    ;

FunDec:  
	ID LP VarList RP {
        $$ = new Node("", "FunDec", 4, $1, $2, $3, $4);
	}
    | ID LP RP {
        $$ = new Node("", "FunDec", 3, $1, $2, $3);
	}
    | ID LP error RP {
        if(mistakeRecord[@3.first_line-1] == 0){
            mistakeRecord[@3.first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @3.first_line);
        }
    }
    | ID error RP {
        if(mistakeRecord[@2.first_line-1] == 0){
            mistakeRecord[@2.first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @2.first_line);
        }
    }
    ;

VarList: 
	ParamDec COMMA VarList {
        $$ = new Node("", "VarList", 3, $1, $2, $3);
	}
    | ParamDec {
        $$ = new Node("", "VarList", 1, $1);
	}
    ;

ParamDec: 
	Specifier VarDec {
        $$ = new Node("", "ParamDec", 2, $1, $2);
	}
    ;

CompSt:  
	LC DefList StmtList RC {	
		$$ = new Node("", "CompSt", 4, $1, $2, $3, $4);
	}
    | LC DefList StmtList{
        if(mistakeRecord[@3.last_line-1] == 0){
            mistakeRecord[@3.last_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @3.last_line);
        }
    }
    | error RC{
        if(mistakeRecord[@1.first_line-1] == 0){
            mistakeRecord[@1.first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @1.first_line);
        }
    }
    ;

StmtList:  
	%empty {
		$$ = nullptr;
	}
    | Stmt StmtList {
		$$ = new Node("", "CompSt", 2, $1, $2);
	}
    ;

Stmt:  
	Exp SEMI {
		$$ = new Node("", "Stmt", 2, $1, $2);
	}
    | CompSt {
		$$ = new Node("", "Stmt", 1, $1);
	}
    | RETURN Exp SEMI {
		$$ = new Node("", "Stmt", 3, $1, $2, $3);
	}
    | RETURN SEMI {
        $$ = new Node("", "Stmt", 2, $1, $2);
    }
    | BREAK SEMI {
        $$ = new Node("", "Stmt", 2, $1, $2);
    }
    | IF LP Exp RP Stmt %prec LOWER_THAN_ELSE {
		$$ = new Node("", "Stmt", 5, $1, $2, $3, $4, $5);
	}
    | IF LP Exp RP Stmt ELSE Stmt {
		$$ = new Node("", "Stmt", 7, $1, $2, $3, $4, $5, $6, $7);
	}
    | IF error ELSE Stmt {
        if(mistakeRecord[@2.first_line-1] == 0){
            mistakeRecord[@2.first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @2.first_line);
        }
    }
    | WHILE LP Exp RP Stmt {
		$$ = new Node("", "Stmt", 5, $1, $2, $3, $4, $5);
	}
    | WHILE error RP {
        if(mistakeRecord[@2.first_line-1] == 0){
            mistakeRecord[@2.first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @2.first_line);
        }
    }
    | WHILE error RC {
        if(mistakeRecord[@2.first_line-1] == 0){
            mistakeRecord[@2.first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @2.first_line);
        }
    }
    | error SEMI {
    	if(mistakeRecord[@1.first_line-1] == 0){
    	    mistakeRecord[@1.first_line-1] = 1;
    	    mistake++;
    	    printf("Error Occur at Line %d: Syntax Error.\n", @1.first_line);
    	}
    }
    | Exp {
        if(mistakeRecord[@1.last_line-1] == 0){
            mistakeRecord[@1.last_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @1.last_line);
        }
    }
    | RETURN Exp {
        if(mistakeRecord[@2.last_line-1] == 0){
            mistakeRecord[@2.last_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @2.last_line);
        }
    }
    ;

DefList:  
	%empty {
		$$ = nullptr;
	}
    | Def DefList {
		$$ = new Node("", "DefList", 2, $1, $2);
	}
    ;

Def:  
	Specifier DecList SEMI {
		$$ = new Node("", "Def", 3, $1, $2, $3);
    }
    | Specifier error SEMI {
        if(mistakeRecord[@2.first_line-1] == 0){
            mistakeRecord[@2.first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @2.first_line);
        }
    }
    | error DecList SEMI {
        if(mistakeRecord[@1.first_line-1] == 0){
            mistakeRecord[@1.first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @1.first_line);
        }
    }
    | Specifier DecList {
        if(mistakeRecord[@2.last_line-1] == 0){
            mistakeRecord[@2.last_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @2.last_line);
        }
    }
    ;

DecList:  
	VarDec {
		$$ = new Node("", "DecList", 1, $1);
	}
    | VarDec COMMA DecList {
		$$ = new Node("", "DecList", 3, $1, $2, $3);
	}
    ;

Exp:  
	Exp ASSIGNOP Exp {
		$$ = new Node("", "Exp", 3, $1, $2, $3);
        $$->setValueType($3->getValueType());
	}
    | Exp AND Exp {
		$$ = new Node("", "Exp", 3, $1, $2, $3);
        $$->setValueType($1->getValueType());
	}
    | Exp OR Exp {
        $$ = new Node("", "Exp", 3, $1, $2, $3);
        $$->setValueType($1->getValueType());
    }
    | Exp RELOP Exp {
        $$ = new Node("", "Exp", 3, $1, $2, $3);
        $$->setValueType($1->getValueType());
    }
    | Exp PLUS Exp {
        $$ = new Node("", "Exp", 3, $1, $2, $3);
        $$->setValueType($1->getValueType());
    }
    | Exp MINUS Exp {
        $$ = new Node("", "Exp", 3, $1, $2, $3);
        $$->setValueType($1->getValueType());
    }
    | Exp STAR Exp {
        $$ = new Node("", "Exp", 3, $1, $2, $3);
        $$->setValueType($1->getValueType());
    }
    | Exp DIV Exp {
        $$ = new Node("", "Exp", 3, $1, $2, $3);
        $$->setValueType($1->getValueType());
    }
    | LP Exp RP {
        $$ = new Node("", "Exp", 3, $1, $2, $3);
        $$->setValueType($2->getValueType());
    }
    | MINUS Exp {
        $$ = new Node("", "Exp", 2, $1, $2);
        $$->setValueType($2->getValueType());
    }
    | NOT Exp {
        $$ = new Node("", "Exp", 2, $1, $2);
        $$->setValueType(TYPE_BOOL);
    }
    | ID LP Args RP {
        $$ = new Node("", "Exp", 4, $1, $2, $3, $4);
        $$->setValueType($1->getValueType());
    }
    | ID LP RP {
        $$ = new Node("", "Exp", 3, $1, $2, $3);
        $$->setValueType($1->getValueType());
    }
    // 
    | ID LB Exp RB {
        $$ = new Node("", "Exp", 4, $1, $2, $3, $4);
        $$->setValueType($1->getValueType() - ARRAY);
    }
    | ID LB RB {
        $$ = new Node("", "Exp", 3, $1, $2, $3);
        $$->setValueType($1->getValueType() + ARRAY);
    }
    | ID {
        $$ = new Node("", "Exp", 1, $1);
        $$->setValueType($1->getValueType());
    }
    | INT {
        $$ = new Node("", "Exp", 1, $1);
        $$->setValueType(TYPE_INT);
    }
    | FLOAT {
        $$ = new Node("", "Exp", 1, $1);
        $$->setValueType(TYPE_FLOAT);
    }
    | BOOL {
        $$ = new Node("", "Exp", 1, $1);
        $$->setValueType(TYPE_BOOL);
    }
    // '$ch'
    | CHAR {
        $$ = new Node("", "Exp", 1, $1);
        $$->setValueType(TYPE_CHAR);
    }
    | STRING {
        $$ = new Node("", "Exp", 1, $1);
        $$->setValueType(TYPE_CHAR_ARRAY);
    }
    | Exp ASSIGNOP error SEMI {
        if(mistakeRecord[@3.first_line-1] == 0){
            mistakeRecord[@3.first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @3.first_line);
        }
    }
    | Exp AND error SEMI  {
        if(mistakeRecord[@3.first_line-1] == 0){
            mistakeRecord[@3.first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @3.first_line);
        }
    }
    | Exp OR error SEMI  {
        if(mistakeRecord[@3.first_line-1] == 0){
            mistakeRecord[@3.first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @3.first_line);
        }
    }
    | Exp RELOP error SEMI  {
        if(mistakeRecord[@3.first_line-1] == 0){
            mistakeRecord[@3.first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @3.first_line);
        }
    }
    | Exp PLUS error SEMI  {
        if(mistakeRecord[@3.first_line-1] == 0){
            mistakeRecord[@3.first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @3.first_line);
        }
    }
    | Exp MINUS error SEMI  {
        if(mistakeRecord[@3.first_line-1] == 0){
            mistakeRecord[@3.first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @3.first_line);
        }
    }
    | Exp STAR error SEMI  {
        if(mistakeRecord[@3.first_line-1] == 0){
            mistakeRecord[@3.first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @3.first_line);
        }
    }
    | Exp DIV error SEMI  {
        if(mistakeRecord[@3.first_line-1] == 0){
            mistakeRecord[@3.first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @3.first_line);
        }
    }
    | ID LP error SEMI {
        if(mistakeRecord[@3.first_line-1] == 0){
            mistakeRecord[@3.first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @3.first_line);
        }
    }
    | Exp LB error RB {
        if(mistakeRecord[@3.first_line-1] == 0){
            mistakeRecord[@3.first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: wrong expression between \"[\" and \"]\".\n", @3.first_line);
        }
    }
    ;

Args:  
    Exp COMMA Args {
        $$ = new Node("", "Args", 3, $1, $2, $3);
    }
    | Exp {
        $$ = new Node("", "Args", 1, $1);
    }
    ;

%%
