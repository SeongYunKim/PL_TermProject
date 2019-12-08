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

NameList findVar(char *name);
const checkNode NULL_NODE = {0, 0, V_UNKNOWN, -1};

FILE *yyin;
int errorNum = 0;
ErrorNode* errorList = NULL;
NameList localVarList = NULL;
NameList globalVarList = NULL;
NameList subProgramList = NULL;
NameList parameterVarList = NULL;
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
%type <name> SUBPROGRAM_DECLARATIONS
%type <name> SUBPROGRAM_DECLARATION
%type <name> ARGUMENTS
%type <name> PARAMETER_LIST
%type <name> COMPOUND_STATEMENT
%type <name> STATEMENT_LIST
%type <name> STATEMENT
%type <name> IF_STATEMENT
%type <name> ELIF_STATEMENT
%type <name> WHILE_STATEMENT
%type <name> FOR_STATEMENT
%type <name> PRINT_STATEMENT
%type <name> VARIABLE
%type <name> PROCEDURE_STATEMENT
%type <name> ACTUAL_PARAMETER_EXPRESSION
%type <name> EXPRESSION_LIST
%type <name> EXPRESSION
%type <name> SIMPLE_EXPRESSION
%type <name> TERM
%type <name> FACTOR
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
	//struct checkNode checkData;
	NameList nameNodeList;
	//varType typeData;
}


%%
PROGRAM:
    MAINPROG ID SEMICOLON DECLARATIONS SUBPROGRAM_DECLARATIONS COMPOUND_STATEMENT {
        for(NameList ptr = $4; ptr;ptr = ptr->next) {
            if (findVar(ptr->name) == NULL) {
                // add Var
                //printf("변수 %s 선언\n", ptr->name);
                nameListAppend(&globalVarList, ptr->name, ptr->type, ptr->dec_line);
            }
            else {
                sprintf(errorBuffer, "변수\'%s\' 중복선언", ptr->name);
                yyerror2(errorBuffer, ptr->dec_line);
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
    SUBPROGRAM_DECLARATION SUBPROGRAM_DECLARATIONS {}
    | {}


SUBPROGRAM_DECLARATION:
    SUBPROGRAM_HEAD DECLARATIONS COMPOUND_STATEMENT {}


SUBPROGRAM_HEAD:
    FUNCTION ID ARGUMENTS ':' STANDARD_TYPE SEMICOLON {}
    | PROCEDURE ID ARGUMENTS SEMICOLON


ARGUMENTS:
    '(' PARAMETER_LIST ')' {}
    | {}


PARAMETER_LIST:
    IDENTIFIER_LIST ':' TYPE {}
    | IDENTIFIER_LIST ':' TYPE SEMICOLON PARAMETER_LIST {}


COMPOUND_STATEMENT:
    BODY_BEGIN STATEMENT_LIST BODY_END {}


STATEMENT_LIST:
    STATEMENT {}
    | STATEMENT SEMICOLON STATEMENT_LIST {}


STATEMENT:
    VARIABLE '=' EXPRESSION {}
    | PRINT_STATEMENT {}
    | PROCEDURE_STATEMENT {}
    | COMPOUND_STATEMENT {}
    | IF_STATEMENT {}
    | WHILE_STATEMENT {}
    | FOR_STATEMENT {}
    | RETURN EXPRESSION {}
    | NOP {}


IF_STATEMENT:
    IF EXPRESSION ':' STATEMENT {}
    | IF EXPRESSION ':' STATEMENT ELIF_STATEMENT {}
    | IF EXPRESSION ':' STATEMENT ELIF_STATEMENT ELSE ':' STATEMENT {}
    | IF EXPRESSION ':' STATEMENT ELSE ':' STATEMENT {}


ELIF_STATEMENT:
    ELIF EXPRESSION ':' STATEMENT {}
    | ELIF EXPRESSION ':' STATEMENT ELIF_STATEMENT {}


WHILE_STATEMENT:
    WHILE EXPRESSION ':' STATEMENT {}
    | WHILE EXPRESSION ':' STATEMENT ELSE ':' STATEMENT {}


FOR_STATEMENT:
    FOR EXPRESSION IN EXPRESSION ':' STATEMENT {}
    | FOR EXPRESSION IN EXPRESSION ':' STATEMENT ELSE ':' STATEMENT {}


PRINT_STATEMENT:
    PRINT {}
    | PRINT '(' EXPRESSION ')' {}


VARIABLE:
    ID {}
    | ID '[' EXPRESSION ']' {}


PROCEDURE_STATEMENT:
    ID '(' ACTUAL_PARAMETER_EXPRESSION ')' {}


ACTUAL_PARAMETER_EXPRESSION:
    EXPRESSION_LIST {}
    | {}


EXPRESSION_LIST:
    EXPRESSION {}
    | EXPRESSION ',' EXPRESSION_LIST {}


EXPRESSION:
    SIMPLE_EXPRESSION {
    }
    | SIMPLE_EXPRESSION RELOP SIMPLE_EXPRESSION {}


SIMPLE_EXPRESSION:
    TERM {}
    | TERM ADDOP SIMPLE_EXPRESSION {}


TERM:
    FACTOR {}
    | FACTOR MULTOP TERM {}


FACTOR:
    INTEGER {}
    | FLOAT {}
    | VARIABLE {}
    | PROCEDURE_STATEMENT {}
    | OP_NOT FACTOR {}
    | SIGN FACTOR {}


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
                    printf("Compile Fail\n");
                    errorListPrint(&errorList);
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

NameList findVar(char *name) {
    NameList res = NULL;
    if((res = nameNodeFind(localVarList, name)) != NULL)
        return res;
    if((res = nameNodeFind(parameterVarList, name)) != NULL)
        return res;
    if((res = nameNodeFind(globalVarList, name)) != NULL)
        return res;
    return res;
}
