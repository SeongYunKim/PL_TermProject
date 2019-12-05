%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex();
int yyerror(char *s);
extern int yylineno;
extern int yylex();
extern char* yytext;

FILE *yyin;
%}

%token ID INTEGER FLOAT SEMICOLON
%token TYPE_INT "int"
%token TYPE_FLOAT "float"

%token MAINPROG "mainprog"
%token FUNCTION "function"
%token PROCEDURE "procedure"
%token BODY_BEGIN "begin"
%token BODY_END "end"
%token IF "if"
%token THEN "then"
%token ELSE "else"
%token NOP "nop"
%token WHILE "while"
%token RETURN "return"
%token PRINT "print"
%token IN "in"

%token OP_PLUS "+"
%token OP_MINUS "-"
%token OP_MUL "*"
%token OP_DIV "/"
%token OP_EQ "=="
%token OP_NEQ "!="
%token OP_LET "<="
%token OP_GET ">="
%token OP_LT "<"
%token OP_GT ">"
%token OP_NOT "!"

%type <name> ID
%type <intData> INTEGER
%type <floatData> FLOAT
%type <name> ASSIGNMENT
%type <name> PROG

%union{
	char name[1000];
	int intData;
	float floatData;
}

%%
PROG:
    ASSIGNMENT ASSIGNMENT   {printf("PROG\n");}


ASSIGNMENT:
   ID '=' INTEGER  {printf("Assignment\n");}
%%

int yyerror(char *s){
	printf("Syntax Error on line %d : %s\n", yylineno, s);
	return 0;
}

int main(int argc, char *argv[]){
    if(argc == 2){
        yyin= fopen(argv[1], "r");
        if(yyin){
            int result = yyparse();
            if(result == 0){
                printf("Compile Success\n");
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
