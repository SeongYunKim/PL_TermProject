%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int yylex();
int yyerror(char *s);
extern int yylineno;
extern int yylex();
extern char* yytext;

FILE *yyin;
int errorNum = 0;
ErrorNode* errorList = NULL;
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
%type <name> DECLARATIONS
%type <name> IDENTIFIER_LIST
%type <name> TYPE
%type <name> STANDARD_TYPE
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


%union{
	char name[1000];
	int intData;
	float floatData;
}


%%
PROGRAM:
    MAINPROG ID SEMICOLON DECLARATIONS SUBPROGRAM_DECLARATIONS COMPOUND_STATEMENT {}


DECLARATIONS:
    TYPE IDENTIFIER_LIST SEMICOLON DECLARATIONS {}
    | {}


IDENTIFIER_LIST:
    ID {}
    | ID ',' IDENTIFIER_LIST {}


TYPE:
    STANDARD_TYPE {}
    | STANDARD_TYPE '[' INTEGER ']' {}


STANDARD_TYPE:
    TYPE_INT {}
    | TYPE_FLOAT {}


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
    //| {}


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
    SIMPLE_EXPRESSION {}
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
    appendErrorList(&errorList, s, yylineno);
    errorNum++;
    return 0;
}

int main(int argc, char *argv[]){
    if(argc == 2){
        yyin= fopen(argv[1], "r");
        if(yyin){
            int result = yyparse();
            if(result == 0){
                if(errorNum == 0){
                    printf("Compile Success\n");
                } else{
                    printf("Compile Fail\n");
                    printErrorList(&errorList);
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
