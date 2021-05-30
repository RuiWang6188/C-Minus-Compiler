/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "./parse.y" /* yacc.c:339  */

    #include<stdio.h>
    #include "lex.yy.c"
    #include"ast.h"
    void yyerror(char* msg);
    extern SyntaxTree* ROOT;
    int mistakeRecord[4096]={0};

#line 75 "./syntax.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "syntax.tab.h".  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    ID = 260,
    SEMI = 261,
    COMMA = 262,
    ASSIGNOP = 263,
    RELOP = 264,
    PLUS = 265,
    MINUS = 266,
    STAR = 267,
    DIV = 268,
    AND = 269,
    OR = 270,
    NOT = 271,
    DOT = 272,
    TYPE = 273,
    LP = 274,
    RP = 275,
    LB = 276,
    RB = 277,
    LC = 278,
    RC = 279,
    STRUCT = 280,
    RETURN = 281,
    IF = 282,
    ELSE = 283,
    WHILE = 284,
    LCOM = 285,
    RCOM = 286,
    LOWER_THAN_ELSE = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "./parse.y" /* yacc.c:355  */

    struct SYNTAXTREE* label_tree;

#line 152 "./syntax.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 183 "./syntax.tab.c" /* yacc.c:358  */

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
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
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
#  define YYSIZE_T unsigned int
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   418

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    56,    57,    60,    61,    62,    65,    66,
      69,    70,    73,    74,    75,    82,    91,    92,    95,    98,
      99,   100,   109,   110,   111,   118,   127,   128,   131,   134,
     135,   142,   151,   152,   155,   156,   157,   158,   160,   161,
     168,   169,   176,   183,   190,   197,   206,   207,   210,   211,
     218,   225,   234,   235,   238,   239,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   267,   274,   281,   288,   295,
     302,   309,   316,   323,   332,   333
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "ID", "SEMI", "COMMA",
  "ASSIGNOP", "RELOP", "PLUS", "MINUS", "STAR", "DIV", "AND", "OR", "NOT",
  "DOT", "TYPE", "LP", "RP", "LB", "RB", "LC", "RC", "STRUCT", "RETURN",
  "IF", "ELSE", "WHILE", "LCOM", "RCOM", "LOWER_THAN_ELSE", "$accept",
  "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "OptTag", "Tag", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", YY_NULLPTR
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
     285,   286,   287
};
# endif

#define YYPACT_NINF -105

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-105)))

#define YYTABLE_NINF -47

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      62,    10,  -105,     4,    14,  -105,    62,   131,  -105,  -105,
      -3,    25,    34,    56,  -105,  -105,  -105,   126,  -105,    76,
       0,     5,    92,  -105,    92,    65,    63,  -105,   104,    53,
      70,    42,  -105,   109,    17,   124,    42,   130,  -105,    39,
    -105,   104,   106,   153,  -105,  -105,   140,   141,  -105,    73,
      34,     3,   166,   164,   167,   168,  -105,  -105,  -105,  -105,
     159,  -105,    94,  -105,  -105,     2,  -105,  -105,   163,   247,
     247,   247,   247,    85,    89,  -105,   162,    73,   259,   247,
    -105,   104,  -105,  -105,  -105,  -105,   119,   144,    31,   317,
     273,   155,   247,    91,   247,  -105,  -105,  -105,   139,   148,
     165,   174,   191,   200,   217,   226,   182,   243,   359,  -105,
     183,  -105,   288,   171,  -105,  -105,   102,   331,  -105,  -105,
     345,   192,   359,   193,   397,   194,   144,   202,   144,   203,
      31,   206,    31,   207,   385,   208,   372,  -105,   175,   302,
    -105,   247,  -105,  -105,   102,   102,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,   160,  -105,   102,
    -105
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    16,    10,     0,     0,     2,     0,     0,    11,    17,
       0,     0,    18,     0,    13,     1,     3,     0,     6,     0,
       8,     0,     0,    14,     0,     0,     0,     5,     0,     0,
       0,     0,     7,    16,     0,     0,     0,     0,    25,    16,
      23,     0,     0,    27,    19,     9,     0,     0,    31,     0,
      19,    54,     0,    52,     0,    51,    15,    47,    12,    24,
      28,    22,     0,    21,    20,     0,    72,    73,    71,     0,
       0,     0,     0,     0,     0,    35,    30,     0,    44,     0,
      50,     0,    49,    48,    26,    43,     0,    65,    66,     0,
      45,     0,     0,     0,     0,    29,    33,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,    53,
       0,    68,    85,     0,    64,    36,     0,     0,    41,    42,
       0,     0,    56,     0,    59,     0,    60,     0,    61,     0,
      62,     0,    63,     0,    57,     0,    58,    70,     0,     0,
      82,     0,    67,    39,     0,     0,    74,    77,    78,    79,
      80,    81,    75,    76,    83,    69,    84,    37,    40,     0,
      38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -105,  -105,   209,  -105,   178,    13,  -105,   214,  -105,     9,
    -105,   161,  -105,   204,   147,  -104,   110,  -105,   -30,  -105,
     -69,    93
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    19,    34,     8,    10,    14,    51,
      21,    42,    43,    75,    76,    77,    35,    36,    52,    53,
      78,   113
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      87,    88,    89,    90,    55,    11,    30,    28,    85,    12,
     108,    79,   143,     7,    15,     9,    20,   112,    54,     7,
      22,    29,    44,   117,    29,   120,    48,   -16,    31,   122,
     124,   126,   128,   130,   132,   134,   136,    20,   139,    41,
     157,   158,   -46,    33,     9,   -46,   -46,   -46,   106,    23,
      60,   109,   107,   -46,    46,   160,    47,   -17,   -46,    59,
       2,   -46,    -4,     1,    39,   -46,   -46,     3,   -46,   -46,
     -46,   -46,   112,   -32,    65,    41,    66,    67,    68,    24,
       2,     2,    27,    40,    69,    38,    91,     3,     3,    70,
      93,   -32,    71,    33,    48,     1,    31,   -32,   -32,    72,
      73,   -32,    74,    65,    92,    66,    67,    68,    94,    44,
       2,   118,     2,    69,    50,   119,   -46,     3,    70,     3,
     110,    71,    66,    67,    68,    31,    61,    25,    72,    73,
      69,    74,   -19,   -19,    37,    70,    17,    18,    71,   111,
     121,    49,    66,    67,    68,    26,    57,   -19,    56,   123,
      69,    66,    67,    68,    58,    70,   102,   103,    71,    69,
      62,   106,    63,    64,    70,   107,   125,    71,    66,    67,
      68,    81,    80,    82,    83,   127,    69,    66,    67,    68,
      29,    70,    86,   116,    71,    69,    95,   137,   159,   140,
      70,   142,   129,    71,    66,    67,    68,   154,   146,   147,
     148,   131,    69,    66,    67,    68,    45,    70,   149,   150,
      71,    69,   151,   152,   153,    16,    70,    13,   133,    71,
      66,    67,    68,    84,    96,    32,     0,   135,    69,    66,
      67,    68,     0,    70,   156,     0,    71,    69,     0,     0,
       0,     0,    70,     0,   138,    71,    66,    67,    68,     0,
      66,    67,    68,     0,    69,     0,     0,     0,    69,    70,
       0,     0,    71,    70,     0,    97,    71,    98,    99,   100,
     101,   102,   103,   104,   105,     0,   106,     0,     0,   115,
     107,    98,    99,   100,   101,   102,   103,   104,   105,     0,
     106,     0,     0,     0,   107,   141,    98,    99,   100,   101,
     102,   103,   104,   105,     0,   106,     0,     0,     0,   107,
      98,    99,   100,   101,   102,   103,   104,   105,     0,   106,
       0,     0,     0,   107,   155,    98,    99,   100,   101,   102,
     103,   104,   105,     0,   106,     0,     0,   114,   107,    98,
      99,   100,   101,   102,   103,   104,   105,     0,   106,     0,
       0,   144,   107,    98,    99,   100,   101,   102,   103,   104,
     105,     0,   106,     0,     0,   145,   107,    98,    99,   100,
     101,   102,   103,   104,   105,     0,   106,     0,     0,     0,
     107,    99,   100,   101,   102,   103,   104,     0,     0,   106,
       0,     0,     0,   107,    99,   100,   101,   102,   103,     0,
       0,     0,   106,     0,     0,     0,   107,   100,   101,   102,
     103,     0,     0,     0,   106,     0,     0,     0,   107
};

static const yytype_int16 yycheck[] =
{
      69,    70,    71,    72,    34,     1,     1,     7,     6,     5,
      79,     8,   116,     0,     0,     5,     7,    86,     1,     6,
      23,    21,     5,    92,    21,    94,    24,    23,    23,    98,
      99,   100,   101,   102,   103,   104,   105,    28,   107,    26,
     144,   145,     0,     1,     5,     3,     4,     5,    17,    24,
      41,    81,    21,    11,     1,   159,     3,    23,    16,    20,
      18,    19,     0,     1,     1,    23,    24,    25,    26,    27,
      28,    29,   141,     0,     1,    62,     3,     4,     5,    23,
      18,    18,     6,    20,    11,    20,     1,    25,    25,    16,
       1,    18,    19,     1,    24,     1,    23,    24,    25,    26,
      27,    28,    29,     1,    19,     3,     4,     5,    19,     5,
      18,    20,    18,    11,     5,    24,    24,    25,    16,    25,
       1,    19,     3,     4,     5,    23,    20,     1,    26,    27,
      11,    29,     6,     7,    24,    16,     5,     6,    19,    20,
       1,    31,     3,     4,     5,    19,    36,    21,    24,     1,
      11,     3,     4,     5,    24,    16,    12,    13,    19,    11,
       7,    17,    22,    22,    16,    21,     1,    19,     3,     4,
       5,     7,     6,     6,     6,     1,    11,     3,     4,     5,
      21,    16,    19,    28,    19,    11,    24,     5,    28,     6,
      16,    20,     1,    19,     3,     4,     5,    22,     6,     6,
       6,     1,    11,     3,     4,     5,    28,    16,     6,     6,
      19,    11,     6,     6,     6,     6,    16,     3,     1,    19,
       3,     4,     5,    62,    77,    21,    -1,     1,    11,     3,
       4,     5,    -1,    16,   141,    -1,    19,    11,    -1,    -1,
      -1,    -1,    16,    -1,     1,    19,     3,     4,     5,    -1,
       3,     4,     5,    -1,    11,    -1,    -1,    -1,    11,    16,
      -1,    -1,    19,    16,    -1,     6,    19,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    -1,    -1,     6,
      21,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    -1,    -1,    -1,    21,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    -1,    -1,    -1,    21,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      -1,    -1,    -1,    21,    22,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    -1,    -1,    20,    21,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    -1,
      -1,    20,    21,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    -1,    -1,    20,    21,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    -1,    -1,    -1,
      21,     9,    10,    11,    12,    13,    14,    -1,    -1,    17,
      -1,    -1,    -1,    21,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    21,    10,    11,    12,
      13,    -1,    -1,    -1,    17,    -1,    -1,    -1,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    18,    25,    34,    35,    36,    38,    39,     5,
      40,     1,     5,    40,    41,     0,    35,     5,     6,    37,
      42,    43,    23,    24,    23,     1,    19,     6,     7,    21,
       1,    23,    46,     1,    38,    49,    50,    49,    20,     1,
      20,    38,    44,    45,     5,    37,     1,     3,    24,    49,
       5,    42,    51,    52,     1,    51,    24,    49,    24,    20,
      42,    20,     7,    22,    22,     1,     3,     4,     5,    11,
      16,    19,    26,    27,    29,    46,    47,    48,    53,     8,
       6,     7,     6,     6,    44,     6,    19,    53,    53,    53,
      53,     1,    19,     1,    19,    24,    47,     6,     8,     9,
      10,    11,    12,    13,    14,    15,    17,    21,    53,    51,
       1,    20,    53,    54,    20,     6,    28,    53,    20,    24,
      53,     1,    53,     1,    53,     1,    53,     1,    53,     1,
      53,     1,    53,     1,    53,     1,    53,     5,     1,    53,
       6,     7,    20,    48,    20,    20,     6,     6,     6,     6,
       6,     6,     6,     6,    22,    22,    54,    48,    48,    28,
      48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    35,    35,    36,    36,    36,    37,    37,
      38,    38,    39,    39,    39,    39,    40,    40,    41,    42,
      42,    42,    43,    43,    43,    43,    44,    44,    45,    46,
      46,    46,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    49,    49,    50,    50,
      50,    50,    51,    51,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    54,    54
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     1,     3,
       1,     1,     5,     2,     3,     5,     0,     1,     1,     1,
       4,     4,     4,     3,     4,     3,     3,     1,     2,     4,
       3,     2,     0,     2,     2,     1,     3,     5,     7,     4,
       5,     3,     3,     2,     1,     2,     0,     2,     3,     3,
       3,     2,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     4,     3,     4,
       3,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
            /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
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
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

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
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 54 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Program", "", 1), add_ast_node(1, (yyval.label_tree), (yyvsp[0].label_tree)); ROOT=(yyval.label_tree);}
#line 1513 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 56 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("ExtDefList","",1), add_ast_node(2,(yyval.label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1519 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 57 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=NULL;}
#line 1525 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 60 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("ExtDef", "", 1), add_ast_node(3, (yyval.label_tree), (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));}
#line 1531 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 61 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("ExtDef", "", 1), add_ast_node(2, (yyval.label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));}
#line 1537 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 62 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("ExtDef", "", 1), add_ast_node(3, (yyval.label_tree), (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));}
#line 1543 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 65 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("ExtDecList", "", 1), add_ast_node(1, (yyval.label_tree), (yyvsp[0].label_tree));}
#line 1549 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 66 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("ExtDecList","",1), add_ast_node(3,(yyval.label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1555 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 69 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Specifier","",1);add_ast_node(1,(yyval.label_tree),(yyvsp[0].label_tree));}
#line 1561 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 70 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Specifier","",1);add_ast_node(1,(yyval.label_tree),(yyvsp[0].label_tree));}
#line 1567 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 73 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("StructSpecifier","",1),add_ast_node(5,(yyval.label_tree),(yyvsp[-4].label_tree),(yyvsp[-3].label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1573 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 74 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("StructSpecifier","",1),add_ast_node(2,(yyval.label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1579 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 75 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[-1]).first_line-1]==0){
                        mistakeRecord[(yylsp[-1]).first_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
                }
    }
#line 1591 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 82 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[-4]).first_line-1]==0){
                        mistakeRecord[(yylsp[-4]).first_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-4]).first_line);
                }
    }
#line 1603 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 91 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=NULL;}
#line 1609 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 92 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("OptTag","",1),add_ast_node(1,(yyval.label_tree),(yyvsp[0].label_tree));}
#line 1615 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 95 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Tag","",1),add_ast_node(1,(yyval.label_tree),(yyvsp[0].label_tree));}
#line 1621 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 98 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("VarDec","",1),add_ast_node(1,(yyval.label_tree),(yyvsp[0].label_tree));}
#line 1627 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 99 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("VarDec","",1),add_ast_node(4,(yyval.label_tree),(yyvsp[-3].label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1633 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 100 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[-1]).first_line-1]==0){
                        mistakeRecord[(yylsp[-1]).first_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
            }
    }
#line 1645 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 109 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("FunDec","",1),add_ast_node(4,(yyval.label_tree),(yyvsp[-3].label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1651 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 110 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("FunDec","",1),add_ast_node(3,(yyval.label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1657 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 111 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[-1]).first_line-1]==0){
                        mistakeRecord[(yylsp[-1]).first_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
            }
    }
#line 1669 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 118 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[-1]).first_line-1]==0){
                        mistakeRecord[(yylsp[-1]).first_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
            }
    }
#line 1681 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 127 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("VarList","",1),add_ast_node(3,(yyval.label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1687 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 128 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("VarList","",1),add_ast_node(1,(yyval.label_tree),(yyvsp[0].label_tree));}
#line 1693 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 131 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("ParamDec","",1),add_ast_node(2,(yyval.label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1699 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 134 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("CompSt","",1),add_ast_node(4,(yyval.label_tree),(yyvsp[-3].label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1705 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 135 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[0]).last_line-1]==0){
                        mistakeRecord[(yylsp[0]).last_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[0]).last_line);
            }
    }
#line 1717 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 142 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[-1]).first_line-1]==0){
                        mistakeRecord[(yylsp[-1]).first_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
            }
    }
#line 1729 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 151 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=NULL;}
#line 1735 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 152 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("StmtList","",1),add_ast_node(2,(yyval.label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1741 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 155 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Stmt","",1),add_ast_node(2,(yyval.label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1747 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 156 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Stmt","",1),add_ast_node(1,(yyval.label_tree),(yyvsp[0].label_tree));}
#line 1753 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 157 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Stmt","",1),add_ast_node(3,(yyval.label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1759 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 159 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Stmt","",1),add_ast_node(5,(yyval.label_tree),(yyvsp[-4].label_tree),(yyvsp[-3].label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1765 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 160 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Stmt","",1),add_ast_node(7,(yyval.label_tree),(yyvsp[-6].label_tree),(yyvsp[-5].label_tree),(yyvsp[-4].label_tree),(yyvsp[-3].label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1771 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 161 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[-2]).first_line-1]==0){
                        mistakeRecord[(yylsp[-2]).first_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-2]).first_line);
            }
    }
#line 1783 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 168 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Stmt","",1),add_ast_node(5,(yyval.label_tree),(yyvsp[-4].label_tree),(yyvsp[-3].label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1789 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 169 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[-1]).first_line-1]==0){
                        mistakeRecord[(yylsp[-1]).first_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
            }
    }
#line 1801 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 176 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[-1]).first_line-1]==0){
                        mistakeRecord[(yylsp[-1]).first_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
            }
    }
#line 1813 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 183 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[-1]).first_line-1]==0){
                        mistakeRecord[(yylsp[-1]).first_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
            }
    }
#line 1825 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 190 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[0]).last_line-1]==0){
                        mistakeRecord[(yylsp[0]).last_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[0]).last_line);
            }
    }
#line 1837 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 197 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[0]).last_line-1]==0){
                        mistakeRecord[(yylsp[0]).last_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[0]).last_line);
            }
    }
#line 1849 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 206 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=NULL;}
#line 1855 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 207 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("DefList","",1),add_ast_node(2,(yyval.label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1861 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 210 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Def","",1),add_ast_node(3,(yyval.label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1867 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 211 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[-1]).first_line-1]==0){
                        mistakeRecord[(yylsp[-1]).first_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
            }
    }
#line 1879 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 218 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[-2]).first_line-1]==0){
                        mistakeRecord[(yylsp[-2]).first_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-2]).first_line);
            }
    }
#line 1891 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 225 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[0]).last_line-1]==0){
                        mistakeRecord[(yylsp[0]).last_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[0]).last_line);
            }
    }
#line 1903 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 234 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("DecList","",1),add_ast_node(1,(yyval.label_tree),(yyvsp[0].label_tree));}
#line 1909 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 235 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("DecList","",1),add_ast_node(3,(yyval.label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1915 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 238 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Dec","",1),add_ast_node(1,(yyval.label_tree),(yyvsp[0].label_tree));}
#line 1921 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 239 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Dec","",1),add_ast_node(3,(yyval.label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1927 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 242 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Exp","",1),add_ast_node(3,(yyval.label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1933 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 243 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Exp","",1),add_ast_node(3,(yyval.label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1939 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 244 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Exp","",1),add_ast_node(3,(yyval.label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1945 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 245 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Exp","",1),add_ast_node(3,(yyval.label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1951 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 246 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Exp","",1),add_ast_node(3,(yyval.label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1957 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 247 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Exp","",1),add_ast_node(3,(yyval.label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1963 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 248 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Exp","",1),add_ast_node(3,(yyval.label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1969 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 249 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Exp","",1),add_ast_node(3,(yyval.label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1975 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 250 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Exp","",1),add_ast_node(3,(yyval.label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1981 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 251 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Exp","",1),add_ast_node(2,(yyval.label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1987 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 252 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Exp","",1),add_ast_node(2,(yyval.label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1993 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 253 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Exp","",1),add_ast_node(4,(yyval.label_tree),(yyvsp[-3].label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 1999 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 254 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Exp","",1),add_ast_node(3,(yyval.label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 2005 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 255 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Exp","",1),add_ast_node(4,(yyval.label_tree),(yyvsp[-3].label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 2011 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 256 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Exp","",1),add_ast_node(3,(yyval.label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 2017 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 257 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Exp","",1),add_ast_node(1,(yyval.label_tree),(yyvsp[0].label_tree));}
#line 2023 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 258 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Exp","",1),add_ast_node(1,(yyval.label_tree),(yyvsp[0].label_tree));}
#line 2029 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 259 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Exp","",1),add_ast_node(1,(yyval.label_tree),(yyvsp[0].label_tree));}
#line 2035 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 260 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[-1]).first_line-1]==0){
                        mistakeRecord[(yylsp[-1]).first_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
                }
    }
#line 2047 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 267 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[-1]).first_line-1]==0){
                        mistakeRecord[(yylsp[-1]).first_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
                }
    }
#line 2059 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 274 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[-1]).first_line-1]==0){
                        mistakeRecord[(yylsp[-1]).first_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
                }
    }
#line 2071 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 281 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[-1]).first_line-1]==0){
                        mistakeRecord[(yylsp[-1]).first_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
                }
    }
#line 2083 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 288 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[-1]).first_line-1]==0){
                        mistakeRecord[(yylsp[-1]).first_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
                }
    }
#line 2095 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 295 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[-1]).first_line-1]==0){
                        mistakeRecord[(yylsp[-1]).first_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
                }
    }
#line 2107 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 302 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[-1]).first_line-1]==0){
                        mistakeRecord[(yylsp[-1]).first_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
                }
    }
#line 2119 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 309 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[-1]).first_line-1]==0){
                        mistakeRecord[(yylsp[-1]).first_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
                }
    }
#line 2131 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 316 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[-1]).first_line-1]==0){
                        mistakeRecord[(yylsp[-1]).first_line-1]=1;
                        mistake++;
                        printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
                }
    }
#line 2143 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 323 "./parse.y" /* yacc.c:1646  */
    {
            if(mistakeRecord[(yylsp[-1]).first_line-1]==0){
                mistakeRecord[(yylsp[-1]).first_line-1]=1;
                mistake++;
                printf("Error Occur at Line %d: wrong expression between \"[\" and \"]\".\n", (yylsp[-1]).first_line);
            }
    }
#line 2155 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 332 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Args","",1),add_ast_node(3,(yyval.label_tree),(yyvsp[-2].label_tree),(yyvsp[-1].label_tree),(yyvsp[0].label_tree));}
#line 2161 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 333 "./parse.y" /* yacc.c:1646  */
    {(yyval.label_tree)=create_ast("Args","",1),add_ast_node(1,(yyval.label_tree),(yyvsp[0].label_tree));}
#line 2167 "./syntax.tab.c" /* yacc.c:1646  */
    break;


#line 2171 "./syntax.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 336 "./parse.y" /* yacc.c:1906  */

void yyerror(char* msg)
{
        ;
}
