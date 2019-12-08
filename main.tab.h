/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_MAIN_TAB_H_INCLUDED
# define YY_YY_MAIN_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 93 "main.y" /* yacc.c:1909  */

    #include "list.h"
    #include "checknode.h"

#line 49 "main.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    INTEGER = 259,
    FLOAT = 260,
    SEMICOLON = 261,
    TYPE_INT = 262,
    TYPE_FLOAT = 263,
    MAINPROG = 264,
    FUNCTION = 265,
    PROCEDURE = 266,
    BODY_BEGIN = 267,
    BODY_END = 268,
    IF = 269,
    ELIF = 270,
    THEN = 271,
    ELSE = 272,
    NOP = 273,
    WHILE = 274,
    FOR = 275,
    RETURN = 276,
    PRINT = 277,
    IN = 278,
    OP_PLUS = 279,
    OP_MINUS = 280,
    OP_MUL = 281,
    OP_DIV = 282,
    OP_EQ = 283,
    OP_NEQ = 284,
    OP_LET = 285,
    OP_GET = 286,
    OP_LT = 287,
    OP_GT = 288,
    OP_NOT = 289
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 98 "main.y" /* yacc.c:1909  */

	char name[1000];
	int intData;
	float floatData;
	//struct checkNode checkData;
	NameList nameNodeList;
	//varType typeData;

#line 105 "main.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MAIN_TAB_H_INCLUDED  */
