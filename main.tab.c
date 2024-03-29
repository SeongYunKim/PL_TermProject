/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "main.y" /* yacc.c:337  */

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

#line 96 "main.tab.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "main.tab.h".  */
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
#line 94 "main.y" /* yacc.c:352  */

    #include "list.h"
    #include "checknode.h"

#line 134 "main.tab.c" /* yacc.c:352  */

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
#line 99 "main.y" /* yacc.c:352  */

	char name[1000];
	int intData;
	float floatData;
	NameList nameNodeList;
	SubProgList subProgList;
	SubProgNode subProgNodeData;
	//varType typeData;

#line 191 "main.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MAIN_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   137

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  139

#define YYUNDEFTOK  2
#define YYMAXUTOK   289

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,    40,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,     2,
       2,    41,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   112,   112,   192,   200,   206,   210,   218,   221,   230,
     233,   239,   243,   249,   259,   267,   277,   280,   286,   293,
     304,   310,   313,   320,   324,   327,   330,   333,   336,   339,
     342,   345,   351,   355,   360,   366,   374,   378,   386,   390,
     398,   403,   412,   415,   421,   424,   430,   437,   440,   446,
     449,   456,   459,   466,   469,   476,   479,   486,   489,   492,
     496,   499,   502,   508,   509,   513,   514,   515,   516,   517,
     518,   523,   524,   528,   529
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INTEGER", "FLOAT", "SEMICOLON",
  "\"int\"", "\"float\"", "MAINPROG", "FUNCTION", "PROCEDURE",
  "BODY_BEGIN", "BODY_END", "IF", "ELIF", "THEN", "ELSE", "NOP", "WHILE",
  "FOR", "RETURN", "PRINT", "IN", "OP_PLUS", "OP_MINUS", "OP_MUL",
  "OP_DIV", "OP_EQ", "OP_NEQ", "OP_LET", "OP_GET", "OP_LT", "OP_GT",
  "OP_NOT", "','", "'['", "']'", "':'", "'('", "')'", "'='", "$accept",
  "PROGRAM", "DECLARATIONS", "IDENTIFIER_LIST", "TYPE", "STANDARD_TYPE",
  "SUBPROGRAM_DECLARATIONS", "SUBPROGRAM_DECLARATION", "SUBPROGRAM_HEAD",
  "ARGUMENTS", "PARAMETER_LIST", "COMPOUND_STATEMENT", "STATEMENT_LIST",
  "STATEMENT", "IF_STATEMENT", "ELIF_STATEMENT", "WHILE_STATEMENT",
  "FOR_STATEMENT", "PRINT_STATEMENT", "VARIABLE", "PROCEDURE_STATEMENT",
  "ACTUAL_PARAMETER_EXPRESSION", "EXPRESSION_LIST", "EXPRESSION",
  "SIMPLE_EXPRESSION", "TERM", "FACTOR", "SIGN", "RELOP", "ADDOP",
  "MULTOP", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    44,    91,    93,    58,    40,
      41,    61
};
# endif

#define YYPACT_NINF -82

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-82)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      13,    33,    43,    56,   -82,    32,   -82,   -82,    41,    44,
      29,    46,    65,    57,    41,    32,    38,    68,    71,    37,
      37,    12,   -82,   -82,    57,    44,    32,    40,    44,    47,
      74,   -22,     4,   -82,     4,     4,     4,    48,   -82,    69,
      75,   -82,   -82,   -82,   -82,    49,   -82,   -82,   -82,   -82,
     -82,    51,    52,    32,   -82,     4,     4,   -82,   -82,   -82,
     -82,     4,   -82,   -82,    53,    28,    42,    45,     4,    55,
      60,   -82,     4,   -82,    12,     4,    32,   -82,    78,    58,
      54,   -82,    61,   -82,    12,   -82,   -82,   -82,   -82,   -82,
     -82,     4,   -82,   -82,     4,   -82,   -82,     4,   -82,    12,
       4,    59,   -82,   -82,    80,   -82,   -82,   -82,     4,    20,
     -82,   -82,   -82,    81,    62,   -82,    44,   -82,     4,    76,
      86,    79,    12,   -82,    82,    12,    83,    12,    95,    12,
     -82,    12,   -82,    84,    98,   -82,    12,   -82,   -82
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     9,    10,    12,     0,
       7,     0,     0,     0,    12,     4,     5,     0,     0,    17,
      17,     0,     2,    11,     0,     0,     4,     0,     0,     0,
       0,    44,     0,    31,     0,     0,     0,    42,    26,     0,
      21,    27,    28,    29,    24,     0,    25,    13,     6,     3,
       8,     0,     0,     0,    15,     0,    48,    57,    58,    63,
      64,     0,    59,    60,     0,    51,    53,    55,     0,     0,
       0,    30,     0,    20,     0,     0,     0,    16,     0,     0,
       0,    47,    49,    61,     0,    69,    70,    65,    66,    67,
      68,     0,    71,    72,     0,    73,    74,     0,    62,     0,
       0,     0,    22,    23,    18,    14,    45,    46,     0,    32,
      52,    54,    56,    38,     0,    43,     0,    50,     0,     0,
      33,     0,     0,    19,     0,     0,     0,     0,    40,     0,
      35,     0,    39,     0,    36,    34,     0,    37,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -82,   -82,    -5,     2,    21,    66,   104,   -82,   -82,   103,
       8,    -1,    63,   -81,   -82,    -9,   -82,   -82,   -82,   -21,
     -20,   -82,    18,   -30,   -75,    30,   -48,   -82,   -82,   -82,
     -82
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     8,    51,     9,    10,    13,    14,    15,    29,
      52,    38,    39,    40,    41,   120,    42,    43,    44,    62,
      63,    80,    81,    82,    65,    66,    67,    68,    91,    94,
      97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      45,    46,    64,   109,    69,    70,    71,    31,    57,    58,
      24,    17,    22,    83,    55,    31,   110,    56,   113,   111,
      98,    49,     1,    47,    21,    79,    32,    48,    59,    60,
      33,    34,    35,    36,    37,   118,     3,   119,    61,     6,
       7,   128,   101,     4,   130,   103,   132,    16,   134,    19,
     135,    11,    12,    45,    46,   138,    85,    86,    87,    88,
      89,    90,     5,    45,    46,    18,    92,    93,    20,    21,
     114,    95,    96,    25,    26,    27,    28,    50,    45,    46,
      54,    74,    73,   100,   105,    53,   116,    72,   124,    76,
      75,    84,    77,    99,   107,   106,   108,   104,   121,   115,
     122,    45,    46,   126,    45,    46,    45,    46,    45,    46,
      45,    46,   133,   118,   125,    45,    46,   127,    23,    78,
     129,   131,   136,    30,   123,   137,   117,   112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102
};

static const yytype_int16 yycheck[] =
{
      21,    21,    32,    84,    34,    35,    36,     3,     4,     5,
      15,     9,    13,    61,    36,     3,    91,    39,    99,    94,
      68,    26,     9,    24,    12,    55,    14,    25,    24,    25,
      18,    19,    20,    21,    22,    15,     3,    17,    34,     7,
       8,   122,    72,     0,   125,    75,   127,     3,   129,     3,
     131,    10,    11,    74,    74,   136,    28,    29,    30,    31,
      32,    33,     6,    84,    84,    36,    24,    25,     3,    12,
     100,    26,    27,    35,     6,     4,    39,    37,    99,    99,
       6,     6,    13,    23,     6,    38,     6,    39,   118,    38,
      41,    38,    40,    38,    40,    37,    35,    76,    17,    40,
      38,   122,   122,    17,   125,   125,   127,   127,   129,   129,
     131,   131,    17,    15,    38,   136,   136,    38,    14,    53,
      38,    38,    38,    20,   116,   134,   108,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    43,     3,     0,     6,     7,     8,    44,    46,
      47,    10,    11,    48,    49,    50,     3,    45,    36,     3,
       3,    12,    53,    48,    44,    35,     6,     4,    39,    51,
      51,     3,    14,    18,    19,    20,    21,    22,    53,    54,
      55,    56,    58,    59,    60,    61,    62,    53,    45,    44,
      37,    45,    52,    38,     6,    36,    39,     4,     5,    24,
      25,    34,    61,    62,    65,    66,    67,    68,    69,    65,
      65,    65,    39,    13,     6,    41,    38,    40,    47,    65,
      63,    64,    65,    68,    38,    28,    29,    30,    31,    32,
      33,    70,    24,    25,    71,    26,    27,    72,    68,    38,
      23,    65,    54,    65,    46,     6,    37,    40,    35,    55,
      66,    66,    67,    55,    65,    40,     6,    64,    15,    17,
      57,    17,    38,    52,    65,    38,    17,    38,    55,    38,
      55,    38,    55,    17,    55,    55,    38,    57,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    46,    46,    47,
      47,    48,    48,    49,    50,    50,    51,    51,    52,    52,
      53,    54,    54,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    56,    56,    56,    56,    57,    57,    58,    58,
      59,    59,    60,    60,    61,    61,    62,    63,    63,    64,
      64,    65,    65,    66,    66,    67,    67,    68,    68,    68,
      68,    68,    68,    69,    69,    70,    70,    70,    70,    70,
      70,    71,    71,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     4,     0,     1,     3,     1,     4,     1,
       1,     2,     0,     3,     6,     4,     3,     0,     3,     5,
       3,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       2,     1,     4,     5,     8,     7,     4,     5,     4,     7,
       6,     9,     1,     4,     1,     4,     4,     1,     0,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 112 "main.y" /* yacc.c:1652  */
    {
        for(NameList ptr = (yyvsp[-2].nameNodeList); ptr;ptr = ptr->next) {
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

        for(NameList ptr = (yyvsp[0].nameNodeList); ptr;ptr = ptr->next) {
            if(nameNodeFind(globalVarList, ptr->name) == NULL && ptr->type != V_FUNC) {
                sprintf(errorBuffer, "선언되지 않은 변수\'%s\'", ptr->name);
                yyerror2(errorBuffer, ptr->dec_line);
            }
        }

        for(SubProgList sptr = (yyvsp[-1].subProgList); sptr; sptr = sptr->next) {
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

        for(NameList ptr = (yyvsp[0].nameNodeList); ptr;ptr = ptr->next) {
            if(nameNodeFind(subProgramList, ptr->name) == NULL && ptr->type == V_FUNC) {
                sprintf(errorBuffer, "선언되지 않은 함수\'%s\'", ptr->name);
                yyerror2(errorBuffer, ptr->dec_line);
            }
        }

        for(SubProgList sptr = (yyvsp[-1].subProgList); sptr; sptr = sptr->next) {
            for(NameList ptr = sptr->used_var_list; ptr;ptr = ptr->next) {
                if(nameNodeFind(subProgramList, ptr->name) == NULL && ptr->type == V_FUNC) {
                    sprintf(errorBuffer, "선언되지 않은 함수\'%s\'", ptr->name);
                    yyerror2(errorBuffer, ptr->dec_line);
                }
            }
        }
    }
#line 1459 "main.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 192 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[-2].nameNodeList);
        // list 저장된 각 배열에 대하여 type 지정
        for(NameList ptr = (yyvsp[-2].nameNodeList); ptr; ptr = ptr->next) {
            ptr->type = (yyvsp[-3].intData);
        }
        nameNodeConcat(((yyval.nameNodeList)), ((yyvsp[0].nameNodeList)));
    }
#line 1472 "main.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 200 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = makeNameList();
    }
#line 1480 "main.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 206 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = makeNameList();
        nameListAppend(&((yyval.nameNodeList)), (yyvsp[0].name), V_UNKNOWN, yylineno);
    }
#line 1489 "main.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 210 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = makeNameList();
        nameListAppend(&((yyval.nameNodeList)), (yyvsp[-2].name), V_UNKNOWN, yylineno);
        nameNodeConcat(((yyval.nameNodeList)), ((yyvsp[0].nameNodeList)));
    }
#line 1499 "main.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 218 "main.y" /* yacc.c:1652  */
    {
        (yyval.intData) = (yyvsp[0].intData);
    }
#line 1507 "main.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 221 "main.y" /* yacc.c:1652  */
    {
        if((yyvsp[-3].intData) == V_INT)
            (yyval.intData) = V_INT_ARY;
        else
            (yyval.intData) = V_FLOAT_ARY;
    }
#line 1518 "main.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 230 "main.y" /* yacc.c:1652  */
    {
        (yyval.intData) = V_INT;
    }
#line 1526 "main.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 233 "main.y" /* yacc.c:1652  */
    {
        (yyval.intData) = V_FLOAT;
    }
#line 1534 "main.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 239 "main.y" /* yacc.c:1652  */
    {
        (yyval.subProgList) = (yyvsp[0].subProgList);
        subProgListAppend(&((yyval.subProgList)), ((yyvsp[-1].subProgNodeData)).name, ((yyvsp[-1].subProgNodeData)).type, ((yyvsp[-1].subProgNodeData)).param_list, ((yyvsp[-1].subProgNodeData)).local_list, ((yyvsp[-1].subProgNodeData)).used_var_list, ((yyvsp[-1].subProgNodeData)).dec_line);
    }
#line 1543 "main.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 243 "main.y" /* yacc.c:1652  */
    {
        (yyval.subProgList) = makeSubProgList();
    }
#line 1551 "main.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 249 "main.y" /* yacc.c:1652  */
    {
        SubProgNode temp = (yyvsp[-2].subProgNodeData);
        temp.local_list = (yyvsp[-1].nameNodeList);
        temp.used_var_list = (yyvsp[0].nameNodeList);
        temp.dec_line = yylineno;
        (yyval.subProgNodeData) = temp;
    }
#line 1563 "main.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 259 "main.y" /* yacc.c:1652  */
    {
        SubProgNode temp;
        //printf("%s\n", ($2));
        strcpy(temp.name, (yyvsp[-4].name));
        temp.param_list = (yyvsp[-3].nameNodeList);
        temp.type = FUNC;
        (yyval.subProgNodeData) = temp;
    }
#line 1576 "main.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 267 "main.y" /* yacc.c:1652  */
    {
        SubProgNode temp;
        strcpy(temp.name, (yyvsp[-2].name));
        temp.param_list = (yyvsp[-1].nameNodeList);
        temp.type = PROC;
        (yyval.subProgNodeData) = temp;
    }
#line 1588 "main.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 277 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[-1].nameNodeList);
    }
#line 1596 "main.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 280 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = makeNameList();
    }
#line 1604 "main.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 286 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[-2].nameNodeList);
        // list 저장된 각 배열에 대하여 type 지정
        for(NameList ptr = (yyvsp[-2].nameNodeList); ptr; ptr = ptr->next) {
            ptr->type = (yyvsp[0].intData);
        }
    }
#line 1616 "main.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 293 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[-4].nameNodeList);
        // list 저장된 각 배열에 대하여 type 지정
        for(NameList ptr = (yyvsp[-4].nameNodeList); ptr; ptr = ptr->next) {
            ptr->type = (yyvsp[-2].intData);
        }
        nameNodeConcat(((yyval.nameNodeList)), ((yyvsp[0].nameNodeList)));
    }
#line 1629 "main.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 304 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[-1].nameNodeList);
    }
#line 1637 "main.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 310 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[0].nameNodeList);
    }
#line 1645 "main.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 313 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[-2].nameNodeList);
        nameNodeConcat((yyval.nameNodeList), (yyvsp[0].nameNodeList));
    }
#line 1654 "main.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 320 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[0].nameNodeList);
        nameListAppend(&((yyval.nameNodeList)), (yyvsp[-2].name), V_UNKNOWN, yylineno);
    }
#line 1663 "main.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 324 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[0].nameNodeList);
    }
#line 1671 "main.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 327 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[0].nameNodeList);
    }
#line 1679 "main.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 330 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[0].nameNodeList);
    }
#line 1687 "main.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 333 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[0].nameNodeList);
    }
#line 1695 "main.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 336 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[0].nameNodeList);
    }
#line 1703 "main.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 339 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[0].nameNodeList);
    }
#line 1711 "main.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 342 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[0].nameNodeList);
    }
#line 1719 "main.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 345 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = makeNameList();
    }
#line 1727 "main.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 351 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[-2].nameNodeList);
        nameNodeConcat((yyval.nameNodeList), (yyvsp[0].nameNodeList));
    }
#line 1736 "main.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 355 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[-3].nameNodeList);
        nameNodeConcat((yyval.nameNodeList), (yyvsp[-1].nameNodeList));
        nameNodeConcat((yyval.nameNodeList), (yyvsp[0].nameNodeList));
    }
#line 1746 "main.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 360 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[-6].nameNodeList);
        nameNodeConcat((yyval.nameNodeList), (yyvsp[-4].nameNodeList));
        nameNodeConcat((yyval.nameNodeList), (yyvsp[-3].nameNodeList));
        nameNodeConcat((yyval.nameNodeList), (yyvsp[0].nameNodeList));
    }
#line 1757 "main.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 366 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[-5].nameNodeList);
        nameNodeConcat((yyval.nameNodeList), (yyvsp[-3].nameNodeList));
        nameNodeConcat((yyval.nameNodeList), (yyvsp[0].nameNodeList));
    }
#line 1767 "main.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 374 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[-2].nameNodeList);
        nameNodeConcat((yyval.nameNodeList), (yyvsp[0].nameNodeList));
    }
#line 1776 "main.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 378 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[-3].nameNodeList);
        nameNodeConcat((yyval.nameNodeList), (yyvsp[-1].nameNodeList));
        nameNodeConcat((yyval.nameNodeList), (yyvsp[0].nameNodeList));
    }
#line 1786 "main.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 386 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[-2].nameNodeList);
        nameNodeConcat((yyval.nameNodeList), (yyvsp[0].nameNodeList));
    }
#line 1795 "main.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 390 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[-5].nameNodeList);
        nameNodeConcat((yyval.nameNodeList), (yyvsp[-3].nameNodeList));
        nameNodeConcat((yyval.nameNodeList), (yyvsp[0].nameNodeList));
    }
#line 1805 "main.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 398 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[-4].nameNodeList);
        nameNodeConcat((yyval.nameNodeList), (yyvsp[-2].nameNodeList));
        nameNodeConcat((yyval.nameNodeList), (yyvsp[0].nameNodeList));
    }
#line 1815 "main.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 403 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[-7].nameNodeList);
        nameNodeConcat((yyval.nameNodeList), (yyvsp[-5].nameNodeList));
        nameNodeConcat((yyval.nameNodeList), (yyvsp[-3].nameNodeList));
        nameNodeConcat((yyval.nameNodeList), (yyvsp[0].nameNodeList));
    }
#line 1826 "main.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 412 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = makeNameList();
    }
#line 1834 "main.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 415 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[-1].nameNodeList);
    }
#line 1842 "main.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 421 "main.y" /* yacc.c:1652  */
    {
        strcpy((yyval.name), (yyvsp[0].name));
    }
#line 1850 "main.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 424 "main.y" /* yacc.c:1652  */
    {
        strcpy((yyval.name), (yyvsp[-3].name));
    }
#line 1858 "main.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 430 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[-1].nameNodeList);
        nameListAppend(&((yyval.nameNodeList)), (yyvsp[-3].name), V_FUNC, yylineno);
    }
#line 1867 "main.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 437 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[0].nameNodeList);
    }
#line 1875 "main.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 440 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = makeNameList();
    }
#line 1883 "main.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 446 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[0].nameNodeList);
    }
#line 1891 "main.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 449 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[-2].nameNodeList);
        nameNodeConcat(((yyval.nameNodeList)), ((yyvsp[0].nameNodeList)));
    }
#line 1900 "main.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 456 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[0].nameNodeList);
    }
#line 1908 "main.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 459 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[-2].nameNodeList);
        nameNodeConcat(((yyval.nameNodeList)), ((yyvsp[0].nameNodeList)));
    }
#line 1917 "main.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 466 "main.y" /* yacc.c:1652  */
    {
    (yyval.nameNodeList) = (yyvsp[0].nameNodeList);
    }
#line 1925 "main.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 469 "main.y" /* yacc.c:1652  */
    {
    (yyval.nameNodeList) = (yyvsp[-2].nameNodeList);
    nameNodeConcat(((yyval.nameNodeList)), ((yyvsp[0].nameNodeList)));
    }
#line 1934 "main.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 476 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[0].nameNodeList);
    }
#line 1942 "main.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 479 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[-2].nameNodeList);
        nameNodeConcat(((yyval.nameNodeList)), ((yyvsp[0].nameNodeList)));
    }
#line 1951 "main.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 486 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = makeNameList();
    }
#line 1959 "main.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 489 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = makeNameList();
    }
#line 1967 "main.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 492 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = makeNameList();
        nameListAppend(&((yyval.nameNodeList)), (yyvsp[0].name), V_UNKNOWN, yylineno);
    }
#line 1976 "main.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 496 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[0].nameNodeList);
    }
#line 1984 "main.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 499 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[0].nameNodeList);
    }
#line 1992 "main.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 502 "main.y" /* yacc.c:1652  */
    {
        (yyval.nameNodeList) = (yyvsp[0].nameNodeList);
    }
#line 2000 "main.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 508 "main.y" /* yacc.c:1652  */
    {}
#line 2006 "main.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 509 "main.y" /* yacc.c:1652  */
    {}
#line 2012 "main.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 513 "main.y" /* yacc.c:1652  */
    {}
#line 2018 "main.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 514 "main.y" /* yacc.c:1652  */
    {}
#line 2024 "main.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 515 "main.y" /* yacc.c:1652  */
    {}
#line 2030 "main.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 516 "main.y" /* yacc.c:1652  */
    {}
#line 2036 "main.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 517 "main.y" /* yacc.c:1652  */
    {}
#line 2042 "main.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 518 "main.y" /* yacc.c:1652  */
    {}
#line 2048 "main.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 523 "main.y" /* yacc.c:1652  */
    {}
#line 2054 "main.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 524 "main.y" /* yacc.c:1652  */
    {}
#line 2060 "main.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 528 "main.y" /* yacc.c:1652  */
    {}
#line 2066 "main.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 529 "main.y" /* yacc.c:1652  */
    {}
#line 2072 "main.tab.c" /* yacc.c:1652  */
    break;


#line 2076 "main.tab.c" /* yacc.c:1652  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 531 "main.y" /* yacc.c:1918  */


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
