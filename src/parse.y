
%{
    #include <stdio.h>
    #include "lex.yy.c"
    #include "ast.h"
    #include "symbol_table.h"
    void yyerror(char* msg);
    extern SyntaxTree* ROOT;
    int mistakeRecord[4096]={0};
%}

/*declared types*/
%union
{
    struct SYNTAXTREE* label_tree;
}
%token <label_tree> INT
%token <label_tree> FLOAT
%token <label_tree> ID
%token <label_tree> SEMI
%token <label_tree> COMMA
%token <label_tree> ASSIGNOP
%token <label_tree> RELOP
%token <label_tree> PLUS MINUS STAR DIV
%token <label_tree> AND OR 
%token <label_tree> NOT
%token <label_tree> DOT
%token <label_tree> TYPE
%token <label_tree> LP RP LB RB LC RC
%token <label_tree> STRUCT
%token <label_tree> RETURN
%token <label_tree> IF
%token <label_tree> ELSE
%token <label_tree> WHILE
%token <label_tree> LCOM
%token <label_tree> RCOM


%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT
%left LP RP LB RB DOT

%type <label_tree> Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier OptTag Tag
%type <label_tree> VarDec FunDec VarList ParamDec CompSt StmtList Stmt DefList Def DecList Dec Exp Args

%%
Program: 
	ExtDefList {
		$$ = create_ast("Program", "", 1);
		add_ast_node(1, $$, $1); 
		ROOT = $$;
	};

ExtDefList: 
	ExtDef ExtDefList {
		$$ = create_ast("ExtDefList", "", 1);
		add_ast_node(2, $$, $1, $2);
	}
    | %empty {
		$$ = NULL;
	}    
    ;

ExtDef: 
	Specifier ExtDecList SEMI {
		$$ = create_ast("ExtDef", "", 1);
		add_ast_node(3, $$, $1, $2, $3);
        get_symbol_list($2, get_type($1));
	}
    | Specifier SEMI {
		$$ = create_ast("ExtDef", "", 1);
		add_ast_node(2, $$, $1, $2);
	}
    | Specifier FunDec CompSt {
		$$ = create_ast("ExtDef", "", 1);
		add_ast_node(3, $$, $1, $2, $3);
        // exit fun 
        exit_domain();
        set_fun_return_type($2->child_ast[0]->text, get_type($1));
	}
    ;

ExtDecList: 
	VarDec {
		$$ = create_ast("ExtDecList", "", 1);
		add_ast_node(1, $$, $1);
	}
    | VarDec COMMA ExtDecList {
		$$ = create_ast("ExtDecList", "", 1);
		add_ast_node(3, $$, $1, $2, $3);
	}
    ;

Specifier: 
	TYPE {
		$$ = create_ast("Specifier", "", 1);
		add_ast_node(1, $$, $1);
	}
    | StructSpecifier {
		$$ = create_ast("Specifier", "", 1);
		add_ast_node(1, $$, $1);
	}
    ;

StructSpecifier:  
	STRUCT OptTag LC DefList RC {
		$$ = create_ast("StructSpecifier", "", 1);
		add_ast_node(5, $$, $1, $2, $3, $4, $5);
	}
    | STRUCT Tag {
		$$ = create_ast("StructSpecifier", "", 1);
		add_ast_node(2, $$, $1, $2);
		}
    | STRUCT  error RC {
        if(mistakeRecord[@2.first_line-1] == 0){
            mistakeRecord[@2.first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @2.first_line);
        }
    }
    | error OptTag LC DefList RC {
        if(mistakeRecord[@1.first_line-1] == 0){
            mistakeRecord[@1.first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @1.first_line);
        }
    }
    ;
        
OptTag:  
	%empty {
		$$ = NULL;
	}
    | ID {
		$$ = create_ast("OptTag", "", 1);
		add_ast_node(1, $$, $1);
	}
    ;

Tag:  
	ID {
		$$ = create_ast("Tag", "", 1);
		add_ast_node(1, $$, $1);
	}
    ;

VarDec:  
	ID {
		$$ = create_ast("VarDec", "", 1);
		add_ast_node(1, $$, $1);
	}
    // only support one-dimensional array
    | ID LB INT RB {
		$$ = create_ast("VarDec", "", 1);
		add_ast_node(4, $$, $1, $2, $3, $4);
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
		$$ = create_ast("FunDec", "", 1);
		add_ast_node(4, $$, $1, $2, $3, $4);
        entry_domain($1->text);
        symbol * args = get_args($3);
        int flag = insert_symbol($1->text, FUN_TYPE, args, -1);
        if (flag == 0) {
            print_error($1->text, 0, REDEFINED_FUN);
        }
	}
    | ID LP RP {
		$$ = create_ast("FunDec", "", 1);
		add_ast_node(3, $$, $1, $2, $3);
        entry_domain($1->text);
        int flag = insert_symbol($1->text, FUN_TYPE, NULL, -1);
        if (flag == 0) {
            print_error($1->text, 0, REDEFINED_FUN);
        }
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
		$$ = create_ast("VarList", "", 1);
		add_ast_node(3, $$, $1, $2, $3);
	}
    | ParamDec {
		$$ = create_ast("VarList", "", 1);
		add_ast_node(1, $$, $1);
	}
    ;

ParamDec: 
	Specifier VarDec {
		$$ = create_ast("ParamDec", "", 1);
		add_ast_node(2, $$, $1, $2);
	}
    ;

CompSt:  
	LC DefList StmtList RC {	
		$$ = create_ast("CompSt", "", 1);
		add_ast_node(4, $$, $1, $2, $3, $4);
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
		$$ = NULL;
	}
    | Stmt StmtList {
		$$ = create_ast("StmtList", "", 1);
		add_ast_node(2, $$, $1, $2);
	}
    ;

Stmt:  
	Exp SEMI {
		$$ = create_ast("Stmt", "", 1);
		add_ast_node(2, $$, $1, $2);
	}
    | CompSt {
		$$ = create_ast("Stmt", "", 1);
		add_ast_node(1, $$, $1);
	}
    | RETURN Exp SEMI {
		$$ = create_ast("Stmt", "", 1);
		add_ast_node(3, $$, $1, $2, $3);
        hash_node *temp = lookup(get_current_domain(), FUN_TYPE, GLOBAL);
        if ((temp == NULL) || $2->type != temp->sym->type) {
            print_error("", 0, MISMATCHED_TYPE_RETURN);
        }
	}
    | IF LP Exp RP Stmt %prec LOWER_THAN_ELSE {
		$$ = create_ast("Stmt", "", 1);
		add_ast_node(5, $$, $1, $2, $3, $4, $5);
        if ($3->type != INT_TYPE) {
            //print_error("", 0, MISMATCHED_TYPE_RETURN);
        }
	}
    | IF LP Exp RP Stmt ELSE Stmt {
		$$ = create_ast("Stmt", "", 1);
		add_ast_node(7, $$, $1, $2, $3, $4, $5, $6, $7);
        if ($3->type != INT_TYPE) {
            //print_error("", 0, MISMATCHED_TYPE_RETURN);
        }
	}
    | IF error ELSE Stmt {
        if(mistakeRecord[@2.first_line-1] == 0){
            mistakeRecord[@2.first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", @2.first_line);
        }
    }
    | WHILE LP Exp RP Stmt {
		$$ = create_ast("Stmt", "", 1);
		add_ast_node(5, $$, $1, $2, $3, $4, $5);
        if ($3->type != INT_TYPE) {
            //print_error("", 0, MISMATCHED_TYPE_RETURN);
        }
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
		$$ = NULL;
	}
    | Def DefList {
		$$ = create_ast("DefList", "", 1);
		add_ast_node(2, $$, $1, $2);
        get_symbol_list( $1, -1);
	}
    ;

Def:  
	Specifier DecList SEMI {
		$$ = create_ast("Def", "", 1);
		add_ast_node(3, $$, $1, $2, $3);
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
	Dec {
		$$ = create_ast("DecList", "", 1);
		add_ast_node(1, $$, $1);
	}
    | Dec COMMA DecList {
		$$ = create_ast("DecList", "", 1);
		add_ast_node(3, $$, $1, $2, $3);
	}
    ;

Dec:  
	VarDec {
		$$ = create_ast("Dec", "", 1);
		add_ast_node(1, $$, $1);
	}
    //| VarDec ASSIGNOP Exp {
	//	$$ = create_ast("Dec", "", 1);
	//	add_ast_node(3, $$, $1, $2, $3);
	//}
    ;

Exp:  
	Exp ASSIGNOP Exp {
		$$ = create_ast("Exp", "", 1);
		add_ast_node(3, $$, $1, $2, $3);
        if ($1->type != $2->type && ($1->type != INT_TYPE || $1->type != FLOAT_TYPE)) {
            print_error($2->text, 0, MISMATCHED_TYPE_OP);
        }
        // use INT for BOOL
        set_type($$, $3->type);
	}
    | Exp AND Exp {
		$$ = create_ast("Exp", "", 1);
		add_ast_node(3, $$, $1, $2, $3);
        if ($1->type != $2->type && ($1->type != INT_TYPE)) {
            print_error($2->text, 0, MISMATCHED_TYPE_OP);
        }
        // use INT for BOOL
        set_type($$, INT_TYPE);
	}
    | Exp OR Exp {
        $$ = create_ast("Exp", "", 1);
        add_ast_node(3, $$, $1, $2, $3);
        if ($1->type != $2->type && ($1->type != INT_TYPE)) {
            print_error($2->text, 0, MISMATCHED_TYPE_OP);
        }
        // use INT for BOOL
        set_type($$, INT_TYPE);
    }
    | Exp RELOP Exp {
        $$ = create_ast("Exp", "", 1);
        add_ast_node(3, $$, $1, $2, $3);
        if ($1->type != $2->type && ($1->type != INT_TYPE || $1->type != FLOAT_TYPE)) {
            print_error($2->text, 0, MISMATCHED_TYPE_OP);
        }
        // use INT for BOOL
        set_type($$, INT_TYPE);
    }
    | Exp PLUS Exp {
        $$ = create_ast("Exp", "", 1);
        add_ast_node(3, $$, $1, $2, $3);
        if ($1->type != $2->type && ($1->type != INT_TYPE || $1->type != FLOAT_TYPE)) {
            print_error($2->text, 0, MISMATCHED_TYPE_OP);
        }
        set_type($$, $1->type);
    }
    | Exp MINUS Exp {
        $$ = create_ast("Exp", "", 1);
        add_ast_node(3, $$, $1, $2, $3);
        if ($1->type != $2->type && ($1->type != INT_TYPE || $1->type != FLOAT_TYPE)) {
            print_error($2->text, 0, MISMATCHED_TYPE_OP);
        }
        set_type($$, $1->type);
    }
    | Exp STAR Exp {
        $$ = create_ast("Exp", "", 1);
        add_ast_node(3, $$, $1, $2, $3);
        if ($1->type != $2->type && ($1->type != INT_TYPE || $1->type != FLOAT_TYPE)) {
            print_error($2->text, 0, MISMATCHED_TYPE_OP);
        }
        set_type($$, $1->type);
    }
    | Exp DIV Exp {
        $$ = create_ast("Exp", "", 1);
        add_ast_node(3, $$, $1, $2, $3);
        if ($1->type != $2->type && ($1->type != INT_TYPE || $1->type != FLOAT_TYPE)) {
            print_error($2->text, 0, MISMATCHED_TYPE_OP);
        }
        set_type($$, $1->type);
    }
    | LP Exp RP {
        $$ = create_ast("Exp", "", 1);
        add_ast_node(3, $$, $1, $2, $3);
        set_type($$, $2->type);
    }
    | MINUS Exp {
        $$ = create_ast("Exp", "", 1);
        add_ast_node(2, $$, $1, $2);
        if ($2->type == INT_TYPE || $2->type == FLOAT_TYPE) {
            set_type($$, $2->type);
        } else {
            print_error($1->text, 0, MISMATCHED_TYPE_OP);
            set_type($$, $2->type);
        }
    }
    | NOT Exp {
        $$ = create_ast("Exp", "", 1);
        add_ast_node(2, $$, $1, $2);
        set_type($$, INT_TYPE);
    }
    | ID LP Args RP {
        $$ = create_ast("Exp", "", 1);
        add_ast_node(4, $$, $1, $2, $3, $4);
        hash_node *temp = lookup($1->text, FUN_TYPE, GLOBAL);
        if (temp == NULL) {
            print_error($1->text, 0, UNDEFINED_FUN);
            set_type($$, temp->sym->return_type);
        } else {
            set_type($$, temp->sym->return_type);
            check_args(temp, $3);
        }
    }
    | ID LP RP {
        $$ = create_ast("Exp", "", 1);
        add_ast_node(3, $$, $1, $2, $3);
        hash_node *temp = lookup($1->text, FUN_TYPE, GLOBAL);
        if (temp == NULL) {
            print_error($1->text, 0, UNDEFINED_FUN);
            set_type($$, temp->sym->return_type);
        } else {
            set_type($$, temp->sym->return_type);
            check_args(temp, NULL);
        }
    }
    // 
    | ID LB Exp RB {
        $$ = create_ast("Exp", "", 1);
        add_ast_node(4, $$, $1, $2, $3, $4);
        hash_node *temp = lookup($1->text, VAR, get_current_domain());
        set_type($$, temp->sym->type - 1);
    }
    // Needs optimization
    | Exp DOT ID {
        $$ = create_ast("Exp", "", 1);
        add_ast_node(3, $$, $1, $2, $3);
        //if ($1->type > STRUCT_BASE && (($1->type) % 2 == 0)) {
        //    //hash_node *temp = lookup($1->child_ast[0]->text, STRUCT_TYPE, );
        //    if (temp == NULL) {
        //        print_error($3->text, 0, UNDEFINED_VAR);
        //    } else {
        //        symbol * temp_arg = temp->sym->args;
        //        while (temp_arg) {
        //            if (strcmp(temp_arg->name, $3->text) == 0) {
        //                $$->type = temp_arg->type;
        //                break;
        //            }
        //        }
        //        if (!temp_arg) {
        //            print_error($3->text, 0, ACCESS_UNDEFINED_FIELDS_IN_STRUCT);
        //        }
        //    }
        //} else {
        //    print_error($3->text, 0, NONSTRUCT_VAR_USE_DOT);
        //}

    }
    | ID {
        $$ = create_ast("Exp", "", 1);
        add_ast_node(1, $$, $1);
        hash_node *temp = lookup($1->text, VAR, get_current_domain());
        if (temp == NULL) {
            print_error($1->text, 0, UNDEFINED_VAR);
        } else {
            set_type($$, temp->sym->type);
        }
    }
    | INT {
        $$ = create_ast("Exp", "", 1);
        add_ast_node(1, $$, $1);
        set_type($$, INT_TYPE);
    }
    | FLOAT {
        $$ = create_ast("Exp", "", 1);
        add_ast_node(1, $$, $1);
        set_type($$, FLOAT_TYPE);
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

Args:  Exp COMMA Args {
    $$ = create_ast("Args", "", 1);
    add_ast_node(3, $$, $1, $2, $3);
}
    | Exp {
        $$ = create_ast("Args", "", 1);
        add_ast_node(1, $$, $1);
    }
    ;

%%
void yyerror(char* msg)
{
        ;
}
