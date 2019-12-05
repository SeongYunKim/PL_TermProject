%{
#include <stdio.h>

int yylex();
int yyerror(char *s);
extern int yylineno;
extern int yylex();
extern char* yytext;
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

%union{
	char name[1000];
	int intData;
	float floatData;
}

%%
ASSIGNMENT:
   ID '=' INTEGER  {printf("Assignment\n");}
%%

int yyerror(char *s){
	printf("Syntax Error on line :%s\n", s);
	return 0;
}

int main(){
	yyparse();
	return 0;
}
