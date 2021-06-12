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
#line 2 "grammar.y" /* yacc.c:337  */

    #include <stdio.h>
    #include "ast.h"
    #include "type.h"
    int yylex(void);
    int mistakeRecord[4096]={0};
    int mistake = 0;
    extern Node *ROOT;
    void yyerror (char const *s) {
        fprintf (stderr, "%s\n", s);
    }

#line 83 "grammar.cpp" /* yacc.c:337  */
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
   by #include "grammar.hpp".  */
#ifndef YY_YY_GRAMMAR_HPP_INCLUDED
# define YY_YY_GRAMMAR_HPP_INCLUDED
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
    CHAR = 260,
    BOOL = 261,
    STRING = 262,
    ID = 263,
    SEMI = 264,
    COMMA = 265,
    ASSIGNOP = 266,
    RELOP = 267,
    PLUS = 268,
    MINUS = 269,
    STAR = 270,
    DIV = 271,
    AND = 272,
    OR = 273,
    NOT = 274,
    TYPE = 275,
    LP = 276,
    RP = 277,
    LB = 278,
    RB = 279,
    LC = 280,
    RC = 281,
    RETURN = 282,
    IF = 283,
    ELSE = 284,
    WHILE = 285,
    LOWER_THAN_ELSE = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 17 "grammar.y" /* yacc.c:352  */

    struct Node* label_tree;

#line 162 "grammar.cpp" /* yacc.c:352  */
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

#endif /* !YY_YY_GRAMMAR_HPP_INCLUDED  */



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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   475

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

#define YYUNDEFTOK  2
#define YYMAXUTOK   286

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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    58,    58,    64,    67,    73,    76,    82,    85,    91,
      97,   101,   105,   108,   118,   121,   124,   131,   141,   144,
     150,   156,   159,   166,   176,   179,   185,   188,   191,   194,
     197,   200,   203,   210,   213,   220,   227,   234,   241,   251,
     254,   260,   263,   270,   277,   287,   290,   296,   300,   304,
     308,   312,   316,   320,   324,   328,   332,   336,   340,   344,
     349,   353,   357,   361,   365,   370,   374,   378,   385,   392,
     399,   406,   413,   420,   427,   434,   441,   451,   454
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "CHAR", "BOOL", "STRING",
  "ID", "SEMI", "COMMA", "ASSIGNOP", "RELOP", "PLUS", "MINUS", "STAR",
  "DIV", "AND", "OR", "NOT", "TYPE", "LP", "RP", "LB", "RB", "LC", "RC",
  "RETURN", "IF", "ELSE", "WHILE", "LOWER_THAN_ELSE", "$accept", "Program",
  "ExtDefList", "ExtDef", "ExtDecList", "Specifier", "VarDec", "FunDec",
  "VarList", "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def",
  "DecList", "Exp", "Args", YY_NULLPTR
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
     285,   286
};
# endif

#define YYPACT_NINF -90

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-90)))

#define YYTABLE_NINF -40

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -7,   -90,    16,   -90,    -7,    11,   -90,   -90,    55,    15,
      10,     3,    23,    22,     5,   -90,    41,    25,    54,   -90,
     -90,    50,   -90,    41,    65,    57,    53,    72,   -90,    46,
     -90,   -90,    41,     6,    85,    54,   -90,   -90,   -90,    -7,
     -90,   -90,    87,    89,    91,    92,    -4,   -90,   -90,   -90,
     -90,   -90,    27,   336,   336,   336,   317,     9,    45,   -90,
      77,    85,   347,   -90,   -90,    41,   -90,   -90,   -90,   -90,
     143,   336,    79,    84,   401,   -90,   360,    80,   336,   -11,
     336,   -90,   -90,   -90,   165,   184,   203,   222,   241,   260,
     279,   298,   107,   -90,   108,   -90,   374,   109,   387,   -90,
     -90,   115,   414,   -90,   -90,   427,   121,   440,   123,   140,
     124,    79,   128,    79,   129,    84,   130,    84,   132,   112,
     149,   452,   135,   -90,   336,   -90,   -90,   -90,   115,   115,
     -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,
     131,   -90,   115,   -90
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     9,     0,     2,     4,     0,     1,     3,     0,     0,
       7,     0,     0,     0,     0,     5,     0,     0,     0,     6,
      17,     0,    15,     0,     0,    19,     0,     0,    12,    10,
       8,    23,     0,     0,     0,     0,    16,    20,    14,     0,
      13,    11,    45,     0,     0,    44,     0,    62,    63,    65,
      64,    66,    61,     0,     0,     0,     0,     0,     0,    27,
      22,     0,    37,    40,    18,     0,    43,    42,    41,    36,
       0,     0,    56,    57,     0,    29,    38,     0,     0,     0,
       0,    21,    25,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,    59,    78,     0,     0,    55,
      28,     0,     0,    34,    35,     0,     0,    47,     0,    50,
       0,    51,     0,    52,     0,    53,     0,    54,     0,    48,
       0,    49,     0,    75,     0,    58,    60,    32,     0,     0,
      67,    70,    71,    72,    73,    74,    68,    69,    76,    77,
      30,    33,     0,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -90,   -90,   148,   -90,   145,     8,    47,   -90,   136,   -90,
     156,   113,   -89,   141,   -90,   -24,   -53,    56
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     9,     5,    42,    11,    24,    25,
      59,    60,    61,    34,    35,    43,    62,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      72,    73,    74,    76,    17,    69,    26,    44,    27,    45,
      77,   103,   127,     1,    29,   104,     6,    96,    98,     8,
      16,    23,    31,    21,    15,   102,    33,   105,    18,    28,
      78,   107,   109,   111,   113,   115,   117,   119,   121,   140,
     141,    93,     1,    33,    22,    20,    79,    23,    70,    29,
      71,    31,    10,   143,   -39,    32,    12,   -39,   -39,   -39,
     -39,   -39,   -39,    10,   -10,   -10,    80,    39,   -39,    14,
      37,    96,    36,   -39,     1,   -39,    13,    40,    14,   -39,
     -39,   -39,   -39,   -39,   -39,   -24,    46,    38,    47,    48,
      49,    50,    51,    52,    88,    89,    41,    65,    66,    53,
      67,    68,    92,    81,    54,   -24,    55,    92,   122,   101,
      18,   -24,    56,    57,   -24,    58,    46,   123,    47,    48,
      49,    50,    51,    52,    85,    86,    87,    88,    89,    53,
     130,   125,   131,   132,    54,    92,    55,   133,   134,   135,
      18,   136,    56,    57,    94,    58,    47,    48,    49,    50,
      51,    52,     7,    86,    87,    88,    89,    53,   137,   138,
     142,    30,    54,    92,    55,    95,   106,    19,    47,    48,
      49,    50,    51,    52,    82,    64,    63,     0,     0,    53,
     139,     0,     0,     0,    54,   108,    55,    47,    48,    49,
      50,    51,    52,     0,     0,     0,     0,     0,    53,     0,
       0,     0,     0,    54,   110,    55,    47,    48,    49,    50,
      51,    52,     0,     0,     0,     0,     0,    53,     0,     0,
       0,     0,    54,   112,    55,    47,    48,    49,    50,    51,
      52,     0,     0,     0,     0,     0,    53,     0,     0,     0,
       0,    54,   114,    55,    47,    48,    49,    50,    51,    52,
       0,     0,     0,     0,     0,    53,     0,     0,     0,     0,
      54,   116,    55,    47,    48,    49,    50,    51,    52,     0,
       0,     0,     0,     0,    53,     0,     0,     0,     0,    54,
     118,    55,    47,    48,    49,    50,    51,    52,     0,     0,
       0,     0,     0,    53,     0,     0,     0,     0,    54,   120,
      55,    47,    48,    49,    50,    51,    52,     0,     0,     0,
       0,     0,    53,     0,     0,     0,     0,    54,     0,    55,
      47,    48,    49,    50,    51,    52,    75,     0,     0,     0,
       0,    53,     0,     0,     0,     0,    54,     0,    55,    47,
      48,    49,    50,    51,    52,     0,     0,     0,     0,     0,
      53,     0,     0,     0,     0,    54,    83,    55,    84,    85,
      86,    87,    88,    89,    90,    91,     0,     0,     0,   100,
      92,    84,    85,    86,    87,    88,    89,    90,    91,     0,
       0,     0,     0,    92,   124,    84,    85,    86,    87,    88,
      89,    90,    91,     0,     0,     0,     0,    92,    84,    85,
      86,    87,    88,    89,    90,    91,     0,     0,     0,     0,
      92,   126,    84,    85,    86,    87,    88,    89,    90,    91,
       0,     0,     0,    99,    92,    84,    85,    86,    87,    88,
      89,    90,    91,     0,     0,     0,   128,    92,    84,    85,
      86,    87,    88,    89,    90,    91,     0,     0,     0,   129,
      92,    84,    85,    86,    87,    88,    89,    90,    91,     0,
       0,     0,     0,    92,    85,    86,    87,    88,    89,    90,
       0,     0,     0,     0,     0,    92
};

static const yytype_int16 yycheck[] =
{
      53,    54,    55,    56,     1,     9,     1,     1,     3,    33,
       1,    22,   101,    20,     8,    26,     0,    70,    71,     8,
      10,    13,    26,     1,     9,    78,    18,    80,    25,    24,
      21,    84,    85,    86,    87,    88,    89,    90,    91,   128,
     129,    65,    20,    35,    22,    22,     1,    39,    21,     8,
      23,    26,     5,   142,     0,     1,     1,     3,     4,     5,
       6,     7,     8,    16,     9,    10,    21,    10,    14,    23,
      23,   124,    22,    19,    20,    21,    21,    24,    23,    25,
      26,    27,    28,    29,    30,     0,     1,    22,     3,     4,
       5,     6,     7,     8,    15,    16,    24,    10,     9,    14,
       9,     9,    23,    26,    19,    20,    21,    23,     1,    29,
      25,    26,    27,    28,    29,    30,     1,     9,     3,     4,
       5,     6,     7,     8,    12,    13,    14,    15,    16,    14,
       9,    22,     9,     9,    19,    23,    21,     9,     9,     9,
      25,     9,    27,    28,     1,    30,     3,     4,     5,     6,
       7,     8,     4,    13,    14,    15,    16,    14,     9,    24,
      29,    16,    19,    23,    21,    22,     1,    11,     3,     4,
       5,     6,     7,     8,    61,    39,    35,    -1,    -1,    14,
     124,    -1,    -1,    -1,    19,     1,    21,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    -1,    19,     1,    21,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,
      -1,    -1,    19,     1,    21,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,
      -1,    19,     1,    21,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,
      19,     1,    21,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    19,
       1,    21,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    19,     1,
      21,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    14,    -1,    -1,    -1,    -1,    19,    -1,    21,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    14,    -1,    -1,    -1,    -1,    19,    -1,    21,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      14,    -1,    -1,    -1,    -1,    19,     9,    21,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,     9,
      23,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    23,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    23,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      23,    24,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    22,    23,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    22,    23,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    22,
      23,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    23,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    33,    34,    35,    37,     0,    34,     8,    36,
      38,    39,     1,    21,    23,     9,    10,     1,    25,    42,
      22,     1,    22,    37,    40,    41,     1,     3,    24,     8,
      36,    26,     1,    37,    45,    46,    22,    38,    22,    10,
      24,    24,    38,    47,     1,    47,     1,     3,     4,     5,
       6,     7,     8,    14,    19,    21,    27,    28,    30,    42,
      43,    44,    48,    45,    40,    10,     9,     9,     9,     9,
      21,    23,    48,    48,    48,     9,    48,     1,    21,     1,
      21,    26,    43,     9,    11,    12,    13,    14,    15,    16,
      17,    18,    23,    47,     1,    22,    48,    49,    48,    22,
       9,    29,    48,    22,    26,    48,     1,    48,     1,    48,
       1,    48,     1,    48,     1,    48,     1,    48,     1,    48,
       1,    48,     1,     9,    10,    22,    24,    44,    22,    22,
       9,     9,     9,     9,     9,     9,     9,     9,    24,    49,
      44,    44,    29,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    36,    37,
      38,    38,    38,    38,    39,    39,    39,    39,    40,    40,
      41,    42,    42,    42,    43,    43,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    45,
      45,    46,    46,    46,    46,    47,    47,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    49,    49
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     1,     3,     1,
       1,     4,     3,     4,     4,     3,     4,     3,     3,     1,
       2,     4,     3,     2,     0,     2,     2,     1,     3,     2,
       5,     7,     4,     5,     3,     3,     2,     1,     2,     0,
       2,     3,     3,     3,     2,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     4,     3,
       4,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     3,     1
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
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 58 "grammar.y" /* yacc.c:1652  */
    {
		(yyval.label_tree) = new Node("", "Program", 1, (yyvsp[0].label_tree));
		ROOT = (yyval.label_tree);
	}
#line 1525 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 3:
#line 64 "grammar.y" /* yacc.c:1652  */
    {
		(yyval.label_tree) = new Node("", "ExtDefList", 2, (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
	}
#line 1533 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 4:
#line 67 "grammar.y" /* yacc.c:1652  */
    {
		(yyval.label_tree) = nullptr;
	}
#line 1541 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 5:
#line 73 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "ExtDef", 3, (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
	}
#line 1549 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 6:
#line 76 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "ExtDef", 3, (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
	}
#line 1557 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 7:
#line 82 "grammar.y" /* yacc.c:1652  */
    {
		(yyval.label_tree) = new Node("", "ExtDecList", 1, (yyvsp[0].label_tree));
	}
#line 1565 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 8:
#line 85 "grammar.y" /* yacc.c:1652  */
    {
		(yyval.label_tree) = new Node("", "ExtDecList", 3, (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
	}
#line 1573 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 9:
#line 91 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "Specifier", 1, (yyvsp[0].label_tree));
	}
#line 1581 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 10:
#line 97 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "VarDec", 1, (yyvsp[0].label_tree));
	}
#line 1589 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 11:
#line 101 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "VarDec", 4, (yyvsp[-3].label_tree), (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
	}
#line 1597 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 12:
#line 105 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "VarDec", 3, (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
	}
#line 1605 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 13:
#line 108 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[-1]).first_line-1] == 0){
            mistakeRecord[(yylsp[-1]).first_line-1] = 1;
            mistake++;
        	printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
        }
    }
#line 1617 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 14:
#line 118 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "FunDec", 4, (yyvsp[-3].label_tree), (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
	}
#line 1625 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 15:
#line 121 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "FunDec", 3, (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
	}
#line 1633 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 16:
#line 124 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[-1]).first_line-1] == 0){
            mistakeRecord[(yylsp[-1]).first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
        }
    }
#line 1645 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 17:
#line 131 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[-1]).first_line-1] == 0){
            mistakeRecord[(yylsp[-1]).first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
        }
    }
#line 1657 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 18:
#line 141 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "VarList", 3, (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
	}
#line 1665 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 19:
#line 144 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "VarList", 1, (yyvsp[0].label_tree));
	}
#line 1673 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 20:
#line 150 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "ParamDec", 2, (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
	}
#line 1681 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 21:
#line 156 "grammar.y" /* yacc.c:1652  */
    {	
		(yyval.label_tree) = new Node("", "CompSt", 4, (yyvsp[-3].label_tree), (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
	}
#line 1689 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 22:
#line 159 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[0]).last_line-1] == 0){
            mistakeRecord[(yylsp[0]).last_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[0]).last_line);
        }
    }
#line 1701 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 23:
#line 166 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[-1]).first_line-1] == 0){
            mistakeRecord[(yylsp[-1]).first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
        }
    }
#line 1713 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 24:
#line 176 "grammar.y" /* yacc.c:1652  */
    {
		(yyval.label_tree) = nullptr;
	}
#line 1721 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 25:
#line 179 "grammar.y" /* yacc.c:1652  */
    {
		(yyval.label_tree) = new Node("", "CompSt", 2, (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
	}
#line 1729 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 26:
#line 185 "grammar.y" /* yacc.c:1652  */
    {
		(yyval.label_tree) = new Node("", "Stmt", 2, (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
	}
#line 1737 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 27:
#line 188 "grammar.y" /* yacc.c:1652  */
    {
		(yyval.label_tree) = new Node("", "Stmt", 1, (yyvsp[0].label_tree));
	}
#line 1745 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 28:
#line 191 "grammar.y" /* yacc.c:1652  */
    {
		(yyval.label_tree) = new Node("", "Stmt", 3, (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
	}
#line 1753 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 29:
#line 194 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "Stmt", 2, (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
    }
#line 1761 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 30:
#line 197 "grammar.y" /* yacc.c:1652  */
    {
		(yyval.label_tree) = new Node("", "Stmt", 5, (yyvsp[-4].label_tree), (yyvsp[-3].label_tree), (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
	}
#line 1769 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 31:
#line 200 "grammar.y" /* yacc.c:1652  */
    {
		(yyval.label_tree) = new Node("", "Stmt", 7, (yyvsp[-6].label_tree), (yyvsp[-5].label_tree), (yyvsp[-4].label_tree), (yyvsp[-3].label_tree), (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
	}
#line 1777 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 32:
#line 203 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[-2]).first_line-1] == 0){
            mistakeRecord[(yylsp[-2]).first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-2]).first_line);
        }
    }
#line 1789 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 33:
#line 210 "grammar.y" /* yacc.c:1652  */
    {
		(yyval.label_tree) = new Node("", "Stmt", 5, (yyvsp[-4].label_tree), (yyvsp[-3].label_tree), (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
	}
#line 1797 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 34:
#line 213 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[-1]).first_line-1] == 0){
            mistakeRecord[(yylsp[-1]).first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
        }
    }
#line 1809 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 35:
#line 220 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[-1]).first_line-1] == 0){
            mistakeRecord[(yylsp[-1]).first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
        }
    }
#line 1821 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 36:
#line 227 "grammar.y" /* yacc.c:1652  */
    {
    	if(mistakeRecord[(yylsp[-1]).first_line-1] == 0){
    	    mistakeRecord[(yylsp[-1]).first_line-1] = 1;
    	    mistake++;
    	    printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
    	}
    }
#line 1833 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 37:
#line 234 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[0]).last_line-1] == 0){
            mistakeRecord[(yylsp[0]).last_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[0]).last_line);
        }
    }
#line 1845 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 38:
#line 241 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[0]).last_line-1] == 0){
            mistakeRecord[(yylsp[0]).last_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[0]).last_line);
        }
    }
#line 1857 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 39:
#line 251 "grammar.y" /* yacc.c:1652  */
    {
		(yyval.label_tree) = nullptr;
	}
#line 1865 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 40:
#line 254 "grammar.y" /* yacc.c:1652  */
    {
		(yyval.label_tree) = new Node("", "DefList", 2, (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
	}
#line 1873 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 41:
#line 260 "grammar.y" /* yacc.c:1652  */
    {
		(yyval.label_tree) = new Node("", "Def", 3, (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
    }
#line 1881 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 42:
#line 263 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[-1]).first_line-1] == 0){
            mistakeRecord[(yylsp[-1]).first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
        }
    }
#line 1893 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 43:
#line 270 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[-2]).first_line-1] == 0){
            mistakeRecord[(yylsp[-2]).first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-2]).first_line);
        }
    }
#line 1905 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 44:
#line 277 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[0]).last_line-1] == 0){
            mistakeRecord[(yylsp[0]).last_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[0]).last_line);
        }
    }
#line 1917 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 45:
#line 287 "grammar.y" /* yacc.c:1652  */
    {
		(yyval.label_tree) = new Node("", "DecList", 1, (yyvsp[0].label_tree));
	}
#line 1925 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 46:
#line 290 "grammar.y" /* yacc.c:1652  */
    {
		(yyval.label_tree) = new Node("", "DecList", 3, (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
	}
#line 1933 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 47:
#line 296 "grammar.y" /* yacc.c:1652  */
    {
		(yyval.label_tree) = new Node("", "Exp", 3, (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
        (yyval.label_tree)->setValueType((yyvsp[0].label_tree)->getValueType());
	}
#line 1942 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 48:
#line 300 "grammar.y" /* yacc.c:1652  */
    {
		(yyval.label_tree) = new Node("", "Exp", 3, (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
        (yyval.label_tree)->setValueType((yyvsp[-2].label_tree)->getValueType());
	}
#line 1951 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 49:
#line 304 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "Exp", 3, (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
        (yyval.label_tree)->setValueType((yyvsp[-2].label_tree)->getValueType());
    }
#line 1960 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 50:
#line 308 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "Exp", 3, (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
        (yyval.label_tree)->setValueType((yyvsp[-2].label_tree)->getValueType());
    }
#line 1969 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 51:
#line 312 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "Exp", 3, (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
        (yyval.label_tree)->setValueType((yyvsp[-2].label_tree)->getValueType());
    }
#line 1978 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 52:
#line 316 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "Exp", 3, (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
        (yyval.label_tree)->setValueType((yyvsp[-2].label_tree)->getValueType());
    }
#line 1987 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 53:
#line 320 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "Exp", 3, (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
        (yyval.label_tree)->setValueType((yyvsp[-2].label_tree)->getValueType());
    }
#line 1996 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 54:
#line 324 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "Exp", 3, (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
        (yyval.label_tree)->setValueType((yyvsp[-2].label_tree)->getValueType());
    }
#line 2005 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 55:
#line 328 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "Exp", 3, (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
        (yyval.label_tree)->setValueType((yyvsp[-1].label_tree)->getValueType());
    }
#line 2014 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 56:
#line 332 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "Exp", 2, (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
        (yyval.label_tree)->setValueType((yyvsp[0].label_tree)->getValueType());
    }
#line 2023 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 57:
#line 336 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "Exp", 2, (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
        (yyval.label_tree)->setValueType(TYPE_BOOL);
    }
#line 2032 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 58:
#line 340 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "Exp", 4, (yyvsp[-3].label_tree), (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
        (yyval.label_tree)->setValueType((yyvsp[-3].label_tree)->getValueType());
    }
#line 2041 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 59:
#line 344 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "Exp", 3, (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
        (yyval.label_tree)->setValueType((yyvsp[-2].label_tree)->getValueType());
    }
#line 2050 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 60:
#line 349 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "Exp", 4, (yyvsp[-3].label_tree), (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
        (yyval.label_tree)->setValueType((yyvsp[-3].label_tree)->getValueType() - ARRAY);
    }
#line 2059 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 61:
#line 353 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "Exp", 1, (yyvsp[0].label_tree));
        (yyval.label_tree)->setValueType((yyvsp[0].label_tree)->getValueType());
    }
#line 2068 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 62:
#line 357 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "Exp", 1, (yyvsp[0].label_tree));
        (yyval.label_tree)->setValueType(TYPE_INT);
    }
#line 2077 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 63:
#line 361 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "Exp", 1, (yyvsp[0].label_tree));
        (yyval.label_tree)->setValueType(TYPE_FLOAT);
    }
#line 2086 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 64:
#line 365 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "Exp", 1, (yyvsp[0].label_tree));
        (yyval.label_tree)->setValueType(TYPE_BOOL);
    }
#line 2095 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 65:
#line 370 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "Exp", 1, (yyvsp[0].label_tree));
        (yyval.label_tree)->setValueType(TYPE_CHAR);
    }
#line 2104 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 66:
#line 374 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "Exp", 1, (yyvsp[0].label_tree));
        (yyval.label_tree)->setValueType(TYPE_CHAR_ARRAY);
    }
#line 2113 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 67:
#line 378 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[-1]).first_line-1] == 0){
            mistakeRecord[(yylsp[-1]).first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
        }
    }
#line 2125 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 68:
#line 385 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[-1]).first_line-1] == 0){
            mistakeRecord[(yylsp[-1]).first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
        }
    }
#line 2137 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 69:
#line 392 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[-1]).first_line-1] == 0){
            mistakeRecord[(yylsp[-1]).first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
        }
    }
#line 2149 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 70:
#line 399 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[-1]).first_line-1] == 0){
            mistakeRecord[(yylsp[-1]).first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
        }
    }
#line 2161 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 71:
#line 406 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[-1]).first_line-1] == 0){
            mistakeRecord[(yylsp[-1]).first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
        }
    }
#line 2173 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 72:
#line 413 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[-1]).first_line-1] == 0){
            mistakeRecord[(yylsp[-1]).first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
        }
    }
#line 2185 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 73:
#line 420 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[-1]).first_line-1] == 0){
            mistakeRecord[(yylsp[-1]).first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
        }
    }
#line 2197 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 74:
#line 427 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[-1]).first_line-1] == 0){
            mistakeRecord[(yylsp[-1]).first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
        }
    }
#line 2209 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 75:
#line 434 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[-1]).first_line-1] == 0){
            mistakeRecord[(yylsp[-1]).first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: Syntax Error.\n", (yylsp[-1]).first_line);
        }
    }
#line 2221 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 76:
#line 441 "grammar.y" /* yacc.c:1652  */
    {
        if(mistakeRecord[(yylsp[-1]).first_line-1] == 0){
            mistakeRecord[(yylsp[-1]).first_line-1] = 1;
            mistake++;
            printf("Error Occur at Line %d: wrong expression between \"[\" and \"]\".\n", (yylsp[-1]).first_line);
        }
    }
#line 2233 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 77:
#line 451 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "Args", 3, (yyvsp[-2].label_tree), (yyvsp[-1].label_tree), (yyvsp[0].label_tree));
    }
#line 2241 "grammar.cpp" /* yacc.c:1652  */
    break;

  case 78:
#line 454 "grammar.y" /* yacc.c:1652  */
    {
        (yyval.label_tree) = new Node("", "Args", 1, (yyvsp[0].label_tree));
    }
#line 2249 "grammar.cpp" /* yacc.c:1652  */
    break;


#line 2253 "grammar.cpp" /* yacc.c:1652  */
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
#line 459 "grammar.y" /* yacc.c:1918  */

