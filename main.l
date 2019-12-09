%{
#include <stdio.h>
#include "main.tab.h"
void showError();
%}

%option	yylineno
%option	noyywrap

letter		[a-zA-Z]
digit		[0-9]
integer		{digit}+
float 		{digit}*\.{digit}+
id		    {letter}({letter}|{digit})*


%%
"int"		{return (TYPE_INT);}
"float"		{return (TYPE_FLOAT);}

"mainprog"	{return (MAINPROG);}
"function"	{return (FUNCTION);}
"procedure"	{return (PROCEDURE);}
"begin"		{return (BODY_BEGIN);}
"end"		{return (BODY_END);}
"if"		{return (IF);}
"elif"      {return (ELIF);}
"then"		{return (THEN);}
"else"		{return (ELSE);}
"nop"		{return (NOP);}
"while"		{return (WHILE);}
"for"       {return (FOR);}
"return"	{return (RETURN);}
"print"		{return (PRINT);}
"in"		{return (IN);}

"+"		    {return (OP_PLUS);}
"-"		    {return (OP_MINUS);}
"*"		    {return (OP_MUL);}
"/"		    {return (OP_DIV);}
"=="		{return (OP_EQ);}
"!="		{return (OP_NEQ);}
"<="		{return (OP_LET);}
"<" 		{return (OP_LT);}
">="    	{return (OP_GET);}
">"		    {return (OP_GT);}
"!"		    {return (OP_NOT);}

{integer}	{yylval.intData = atoi(yytext); return (INTEGER);}
{float}		{yylval.floatData = atof(yytext); return (FLOAT);}
{id}		{sscanf(yytext, "%s", yylval.name); return (ID);}

[ \r\n\t]+	{}
";"		    {return (SEMICOLON);}
.			{return *yytext;}
%%

void showError(){
	printf("Input Error");
}