%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "checknode.h"

int yylex();
int yyerror(char *s);
extern int yylineno;
extern int yylex();
extern char* yytext;
char errorBuffer[10000] = {0};

NameList findVar(char *name, NameList local_list, NameList param_list);
const checkNode NULL_NODE = {0, 0, V_UNKNOWN, -1};

FILE *yyin;
int errorNum = 0;
ErrorNode* errorList = NULL;
//NameList localVarList = NULL;
NameList globalVarList = NULL;
NameList subProgramList = NULL;
//NameList parameterVarList = NULL;
%}

%token ID INTEGER FLOAT SEMICOLON
%token TYPE_INT "int"
%token TYPE_FLOAT "float"

%token MAINPROG
%token FUNCTION
%token PROCEDURE
%token BODY_BEGIN
%token BODY_END
%token IF
%token ELIF
%token THEN
%token ELSE
%token NOP
%token WHILE
%token FOR
%token RETURN
%token PRINT
%token IN

%token OP_PLUS
%token OP_MINUS
%token OP_MUL
%token OP_DIV
%token OP_EQ
%token OP_NEQ
%token OP_LET
%token OP_GET
%token OP_LT
%token OP_GT
%token OP_NOT

%type <name> ID
%type <intData> INTEGER
%type <floatData> FLOAT

%type <name> PROGRAM
%type <nameNodeList> DECLARATIONS
%type <nameNodeList> IDENTIFIER_LIST
%type <intData> TYPE
%type <intData> STANDARD_TYPE
%type <subProgList> SUBPROGRAM_DECLARATIONS
%type <subProgNodeData> SUBPROGRAM_DECLARATION
%type <subProgNodeData> SUBPROGRAM_HEAD
%type <nameNodeList> ARGUMENTS
%type <nameNodeList> PARAMETER_LIST
%type <nameNodeList> COMPOUND_STATEMENT
%type <nameNodeList> STATEMENT_LIST
%type <nameNodeList> STATEMENT
%type <nameNodeList> IF_STATEMENT
%type <nameNodeList> ELIF_STATEMENT
%type <nameNodeList> WHILE_STATEMENT
%type <nameNodeList> FOR_STATEMENT
%type <nameNodeList> PRINT_STATEMENT
%type <name> VARIABLE
%type <nameNodeList> PROCEDURE_STATEMENT
%type <nameNodeList> ACTUAL_PARAMETER_EXPRESSION
%type <nameNodeList> EXPRESSION_LIST
%type <nameNodeList> EXPRESSION
%type <nameNodeList> SIMPLE_EXPRESSION
%type <nameNodeList> TERM
%type <nameNodeList> FACTOR
%type <name> SIGN
%type <name> RELOP
%type <name> ADDOP
%type <name> MULTOP

%code requires {
    #include "list.h"
    #include "checknode.h"
}

%union{
	char name[1000];
	int intData;
	float floatData;
	NameList nameNodeList;
	SubProgList subProgList;
	SubProgNode subProgNodeData;
	//varType typeData;
}


%%
PROGRAM:
    MAINPROG ID SEMICOLON DECLARATIONS SUBPROGRAM_DECLARATIONS COMPOUND_STATEMENT {
        for(NameList ptr = $4; ptr;ptr = ptr->next) {
            if(nameNodeFind(globalVarList, ptr->name) == NULL) {
                // add Var
                //printf("전역 변수 %s 선언\n", ptr->name);
                nameListAppend(&globalVarList, ptr->name, ptr->type, ptr->dec_line);
            }
            else {
                sprintf(errorBuffer, "전역 변수\'%s\' 중복선언", ptr->name);
                yyerror2(errorBuffer, ptr->dec_line);
            }
        }

        for(NameList ptr = $6; ptr;ptr = ptr->next) {
            if(nameNodeFind(globalVarList, ptr->name) == NULL && ptr->type != V_FUNC) {
                sprintf(errorBuffer, "선언되지 않은 변수\'%s\'", ptr->name);
                yyerror2(errorBuffer, ptr->dec_line);
            }
        }

        for(SubProgList sptr = $5; sptr; sptr = sptr->next) {
            NameList cur_param = makeNameList();
            NameList cur_local = makeNameList();

            if(nameNodeFind(subProgramList, sptr->name) == NULL) {
                nameListAppend(&subProgramList, sptr->name, sptr->type, sptr->dec_line);
            }
            else {
                sprintf(errorBuffer, "힘수\'%s\' 중복선언", sptr->name);
                yyerror2(errorBuffer, sptr->dec_line);
            }

            for(NameList ptr = sptr->param_list; ptr; ptr = ptr->next) {
                if(nameNodeFind(cur_param, ptr->name) == NULL) {
                    //printf("매개 변수 %s 선언\n", ptr->name);
                    nameListAppend(&cur_param, ptr->name, ptr->type, ptr->dec_line);
                }
                else {
                    sprintf(errorBuffer, "매개 변수\'%s\' 중복선언", ptr->name);
                    yyerror2(errorBuffer, ptr->dec_line);
                }
            }

            for(NameList ptr = sptr->local_list; ptr; ptr = ptr->next) {
                if(nameNodeFind(cur_local, ptr->name) == NULL && nameNodeFind(cur_param, ptr->name) == NULL) {
                    //printf("지역 변수 %s 선언\n", ptr->name);
                    nameListAppend(&cur_local, ptr->name, ptr->type, ptr->dec_line);
                }
                else {
                    sprintf(errorBuffer, "지역 변수\'%s\' 중복선언", ptr->name);
                    yyerror2(errorBuffer, ptr->dec_line);
                }
            }

            for(NameList ptr = sptr->used_var_list; ptr;ptr = ptr->next) {
                if(findVar(ptr->name, cur_local, cur_param) == NULL && ptr->type != V_FUNC) {
                    sprintf(errorBuffer, "선언되지 않은 변수\'%s\'", ptr->name);
                    yyerror2(errorBuffer, ptr->dec_line);
                }
            }
        }

        for(NameList ptr = $6; ptr;ptr = ptr->next) {
            if(nameNodeFind(subProgramList, ptr->name) == NULL && ptr->type == V_FUNC) {
                sprintf(errorBuffer, "선언되지 않은 함수\'%s\'", ptr->name);
                yyerror2(errorBuffer, ptr->dec_line);
            }
        }

        for(SubProgList sptr = $5; sptr; sptr = sptr->next) {
            for(NameList ptr = sptr->used_var_list; ptr;ptr = ptr->next) {
                if(nameNodeFind(subProgramList, ptr->name) == NULL && ptr->type == V_FUNC) {
                    sprintf(errorBuffer, "선언되지 않은 함수\'%s\'", ptr->name);
                    yyerror2(errorBuffer, ptr->dec_line);
                }
            }
        }
    }

DECLARATIONS:
    TYPE IDENTIFIER_LIST SEMICOLON DECLARATIONS {
        $$ = $2;
        // list 저장된 각 배열에 대하여 type 지정
        for(NameList ptr = $2; ptr; ptr = ptr->next) {
            ptr->type = $1;
        }
        nameNodeConcat(($$), ($4));
    }
    | {
        $$ = makeNameList();
    }


IDENTIFIER_LIST:
    ID {
        $$ = makeNameList();
        nameListAppend(&($$), $1, V_UNKNOWN, yylineno);
    }
    | ID ',' IDENTIFIER_LIST {
        $$ = makeNameList();
        nameListAppend(&($$), $1, V_UNKNOWN, yylineno);
        nameNodeConcat(($$), ($3));
    }


TYPE:
    STANDARD_TYPE {
        $$ = $1;
    }
    | STANDARD_TYPE '[' INTEGER ']' {
        if($1 == V_INT)
            $$ = V_INT_ARY;
        else
            $$ = V_FLOAT_ARY;
    }


STANDARD_TYPE:
    TYPE_INT {
        $$ = V_INT;
    }
    | TYPE_FLOAT {
        $$ = V_FLOAT;
    }


SUBPROGRAM_DECLARATIONS:
    SUBPROGRAM_DECLARATION SUBPROGRAM_DECLARATIONS {
        $$ = $2;
        subProgListAppend(&($$), ($1).name, ($1).type, ($1).param_list, ($1).local_list, ($1).used_var_list, ($1).dec_line);
    }
    | {
        $$ = makeSubProgList();
    }


SUBPROGRAM_DECLARATION:
    SUBPROGRAM_HEAD DECLARATIONS COMPOUND_STATEMENT {
        SubProgNode temp = $1;
        temp.local_list = $2;
        temp.used_var_list = $3;
        $$ = temp;
    }


SUBPROGRAM_HEAD:
    FUNCTION ID ARGUMENTS ':' STANDARD_TYPE SEMICOLON {
        SubProgNode temp;
        //printf("%s\n", ($2));
        strcpy(temp.name, $2);
        temp.param_list = $3;
        temp.type = FUNC;
        $$ = temp;
    }
    | PROCEDURE ID ARGUMENTS SEMICOLON {
        SubProgNode temp;
        strcpy(temp.name, $2);
        temp.param_list = $3;
        temp.type = PROC;
        $$ = temp;
    }


ARGUMENTS:
    '(' PARAMETER_LIST ')' {
        $$ = $2;
    }
    | {
        $$ = makeNameList();
    }


PARAMETER_LIST:
    IDENTIFIER_LIST ':' TYPE {
        $$ = $1;
        // list 저장된 각 배열에 대하여 type 지정
        for(NameList ptr = $1; ptr; ptr = ptr->next) {
            ptr->type = $3;
        }
    }
    | IDENTIFIER_LIST ':' TYPE SEMICOLON PARAMETER_LIST {
        $$ = $1;
        // list 저장된 각 배열에 대하여 type 지정
        for(NameList ptr = $1; ptr; ptr = ptr->next) {
            ptr->type = $3;
        }
        nameNodeConcat(($$), ($5));
    }


COMPOUND_STATEMENT:
    BODY_BEGIN STATEMENT_LIST BODY_END {
        $$ = $2;
    }


STATEMENT_LIST:
    STATEMENT {
        $$ = $1;
    }
    | STATEMENT SEMICOLON STATEMENT_LIST {
        $$ = $1;
        nameNodeConcat($$, $3);
    }


STATEMENT:
    VARIABLE '=' EXPRESSION {
        $$ = $3;
        nameListAppend(&($$), $1, V_UNKNOWN, yylineno);
    }
    | PRINT_STATEMENT {
        $$ = $1;
    }
    | PROCEDURE_STATEMENT {
        $$ = $1;
    }
    | COMPOUND_STATEMENT {
        $$ = $1;
    }
    | IF_STATEMENT {
        $$ = $1;
    }
    | WHILE_STATEMENT {
        $$ = $1;
    }
    | FOR_STATEMENT {
        $$ = $1;
    }
    | RETURN EXPRESSION {
        $$ = $2;
    }
    | NOP {
        $$ = makeNameList();
    }


IF_STATEMENT:
    IF EXPRESSION ':' STATEMENT {
        $$ = $2;
        nameNodeConcat($$, $4);
    }
    | IF EXPRESSION ':' STATEMENT ELIF_STATEMENT {
        $$ = $2;
        nameNodeConcat($$, $4);
        nameNodeConcat($$, $5);
    }
    | IF EXPRESSION ':' STATEMENT ELIF_STATEMENT ELSE ':' STATEMENT {
        $$ = $2;
        nameNodeConcat($$, $4);
        nameNodeConcat($$, $5);
        nameNodeConcat($$, $8);
    }
    | IF EXPRESSION ':' STATEMENT ELSE ':' STATEMENT {
        $$ = $2;
        nameNodeConcat($$, $4);
        nameNodeConcat($$, $7);
    }


ELIF_STATEMENT:
    ELIF EXPRESSION ':' STATEMENT {
        $$ = $2;
        nameNodeConcat($$, $4);
    }
    | ELIF EXPRESSION ':' STATEMENT ELIF_STATEMENT {
        $$ = $2;
        nameNodeConcat($$, $4);
        nameNodeConcat($$, $5);
    }


WHILE_STATEMENT:
    WHILE EXPRESSION ':' STATEMENT {
        $$ = $2;
        nameNodeConcat($$, $4);
    }
    | WHILE EXPRESSION ':' STATEMENT ELSE ':' STATEMENT {
        $$ = $2;
        nameNodeConcat($$, $4);
        nameNodeConcat($$, $7);
    }


FOR_STATEMENT:
    FOR EXPRESSION IN EXPRESSION ':' STATEMENT {
        $$ = $2;
        nameNodeConcat($$, $4);
        nameNodeConcat($$, $6);
    }
    | FOR EXPRESSION IN EXPRESSION ':' STATEMENT ELSE ':' STATEMENT {
        $$ = $2;
        nameNodeConcat($$, $4);
        nameNodeConcat($$, $6);
        nameNodeConcat($$, $9);
    }


PRINT_STATEMENT:
    PRINT {
        $$ = makeNameList();
    }
    | PRINT '(' EXPRESSION ')' {
        $$ = $3;
    }


VARIABLE:
    ID {
        strcpy($$, $1);
    }
    | ID '[' EXPRESSION ']' {
        strcpy($$, $1);
    }


PROCEDURE_STATEMENT:
    ID '(' ACTUAL_PARAMETER_EXPRESSION ')' {
        $$ = $3;
        nameListAppend(&($$), $1, V_FUNC, yylineno);
    }


ACTUAL_PARAMETER_EXPRESSION:
    EXPRESSION_LIST {
        $$ = $1;
    }
    | {
        $$ = makeNameList();
    }


EXPRESSION_LIST:
    EXPRESSION {
        $$ = $1;
    }
    | EXPRESSION ',' EXPRESSION_LIST {
        $$ = $1;
        nameNodeConcat(($$), ($3));
    }


EXPRESSION:
    SIMPLE_EXPRESSION {
        $$ = $1;
    }
    | SIMPLE_EXPRESSION RELOP SIMPLE_EXPRESSION {
        $$ = $1;
        nameNodeConcat(($$), ($3));
    }


SIMPLE_EXPRESSION:
    TERM {
    $$ = $1;
    }
    | TERM ADDOP SIMPLE_EXPRESSION {
    $$ = $1;
    nameNodeConcat(($$), ($3));
    }


TERM:
    FACTOR {
        $$ = $1;
    }
    | FACTOR MULTOP TERM {
        $$ = $1;
        nameNodeConcat(($$), ($3));
    }


FACTOR:
    INTEGER {
        $$ = makeNameList();
    }
    | FLOAT {
        $$ = makeNameList();
    }
    | VARIABLE {
        $$ = makeNameList();
        nameListAppend(&($$), $1, V_UNKNOWN, yylineno);
    }
    | PROCEDURE_STATEMENT {
        $$ = $1;
    }
    | OP_NOT FACTOR {
        $$ = $2;
    }
    | SIGN FACTOR {
        $$ = $2;
    }


SIGN:
    OP_PLUS {}
    | OP_MINUS {}


RELOP:
    OP_LET {}
    | OP_GET {}
    | OP_LT {}
    | OP_GT {}
    | OP_EQ {}
    | OP_NEQ {}
    //| IN {} 수정


ADDOP:
    OP_PLUS {}
    | OP_MINUS {}


MULTOP:
    OP_MUL {}
    | OP_DIV {}

%%

int yyerror(char *s){
    return yyerror2(s, yylineno);
}

int yyerror2(char *s, int yylineno){
    errorNodeAppend(&errorList, s, yylineno);
    errorNum++;
    return 0;
}

int main(int argc, char *argv[]) {
    if(argc == 2){
        yyin= fopen(argv[1], "r");
        if(yyin){
            int result = yyparse();
            if(result == 0){
                if(errorNum == 0){
                    printf("Compile Success\n");
                } else{
                    errorListPrint(&errorList);
                    printf("Compile Fail\n");
                }
            } else if(result == 1){
                printf("Compile Fail\n");
            }
            fclose(yyin);
        }
        else {
            printf("[Error] Can't open file \"%s\"\n", argv[1]);
        }
    }
    else {
        printf("[Error] Incorrect input argument\n");
    }
	return 0;
}

NameList findVar(char *name, NameList local_list, NameList param_list) {
    NameList res = NULL;
    if((res = nameNodeFind(local_list, name)) != NULL)
        return res;
    if((res = nameNodeFind(param_list, name)) != NULL)
        return res;
    if((res = nameNodeFind(globalVarList, name)) != NULL)
        return res;
    return res;
}
