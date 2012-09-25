/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
   2009, 2010 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse         pirparse
#define yylex           pirlex
#define yyerror         pirerror
#define yylval          pirlval
#define yychar          pirchar
#define yydebug         pirdebug
#define yynerrs         pirnerrs


/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 3 "piry.y"

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
#endif

#include "sequence.h"
#include "sequence/parse.h"
#include "sequence/piry.h"

int yylex(YYSTYPE *);
static void yyerror(sequence_t *, const char *);

sequence_t *piry_parse(FILE *);
int piry_check(FILE *);


/* Line 189 of yacc.c  */
#line 101 "sequence/piry.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CNT = 258,
     EOL = 259,
     ERR = 260,
     INT = 261,
     NUL = 262,
     NXT = 263,
     SEP = 264,
     SPC = 265,
     TXT = 266,
     EN = 267,
     ENTXT = 268,
     ENNAM = 269,
     TI = 270,
     TITXT = 271,
     AL = 272,
     CT = 273,
     OR = 274,
     DA = 275,
     AC = 276,
     ACNUM = 277,
     RE = 278,
     CO = 279,
     GE = 280,
     FU = 281,
     CX = 282,
     CL = 283,
     KE = 284,
     FE = 285,
     SU = 286,
     SE = 287,
     SN = 288,
     SEQ = 289,
     BAS = 290,
     END = 291
   };
#endif
/* Tokens.  */
#define CNT 258
#define EOL 259
#define ERR 260
#define INT 261
#define NUL 262
#define NXT 263
#define SEP 264
#define SPC 265
#define TXT 266
#define EN 267
#define ENTXT 268
#define ENNAM 269
#define TI 270
#define TITXT 271
#define AL 272
#define CT 273
#define OR 274
#define DA 275
#define AC 276
#define ACNUM 277
#define RE 278
#define CO 279
#define GE 280
#define FU 281
#define CX 282
#define CL 283
#define KE 284
#define FE 285
#define SU 286
#define SE 287
#define SN 288
#define SEQ 289
#define BAS 290
#define END 291




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 26 "piry.y"
 char *str; 


/* Line 214 of yacc.c  */
#line 213 "sequence/piry.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 225 "sequence/piry.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   160

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  96
/* YYNRULES -- Number of rules.  */
#define YYNRULES  149
/* YYNRULES -- Number of states.  */
#define YYNSTATES  231

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     9,    25,    27,    32,    34,    37,
      38,    41,    42,    45,    46,    50,    54,    57,    59,    62,
      63,    66,    67,    71,    75,    78,    80,    83,    84,    87,
      88,    92,    96,    99,   101,   104,   105,   108,   109,   113,
     117,   120,   122,   125,   126,   129,   131,   135,   139,   142,
     144,   148,   150,   151,   154,   155,   159,   164,   169,   173,
     177,   179,   182,   183,   186,   189,   191,   195,   199,   202,
     204,   207,   208,   211,   214,   215,   219,   223,   226,   228,
     231,   232,   235,   238,   240,   244,   247,   251,   254,   256,
     259,   260,   263,   266,   267,   271,   275,   278,   280,   283,
     284,   287,   290,   291,   295,   298,   302,   305,   307,   310,
     311,   314,   315,   319,   323,   326,   328,   331,   332,   335,
     336,   340,   344,   347,   349,   352,   353,   356,   358,   361,
     365,   368,   370,   373,   377,   381,   382,   385,   387,   390,
     394,   398,   400,   403,   405,   411,   415,   418,   420,   421
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      38,     0,    -1,    39,   121,   132,    -1,     7,    -1,    40,
      44,    49,    54,    59,    64,    69,    76,    82,    88,    94,
     100,   106,   111,   116,    -1,    41,    -1,    12,    42,    43,
       4,    -1,    14,    -1,    43,    13,    -1,    -1,    46,    45,
      -1,    -1,    45,    47,    -1,    -1,    15,    48,     4,    -1,
       8,    48,     4,    -1,    48,    16,    -1,    16,    -1,    51,
      50,    -1,    -1,    50,    52,    -1,    -1,    17,    53,     4,
      -1,     8,    53,     4,    -1,    53,    11,    -1,    11,    -1,
      56,    55,    -1,    -1,    55,    57,    -1,    -1,    18,    58,
       4,    -1,     8,    58,     4,    -1,    58,    11,    -1,    11,
      -1,    61,    60,    -1,    -1,    60,    62,    -1,    -1,    19,
      63,     4,    -1,     8,    63,     4,    -1,    63,    11,    -1,
      11,    -1,    66,    65,    -1,    -1,    65,    67,    -1,    67,
      -1,    20,    68,     4,    -1,     8,    68,     4,    -1,    68,
      11,    -1,    11,    -1,    72,    70,    74,    -1,    71,    -1,
      -1,    70,    73,    -1,    -1,    21,    75,     4,    -1,    21,
      75,     3,     4,    -1,     8,    75,     3,     4,    -1,     8,
      75,     4,    -1,    75,     9,    22,    -1,    22,    -1,    76,
      77,    -1,    -1,    79,    78,    -1,    78,    80,    -1,    80,
      -1,    23,    81,     4,    -1,     8,    81,     4,    -1,    81,
      11,    -1,    11,    -1,    82,    83,    -1,    -1,    85,    84,
      -1,    84,    86,    -1,    -1,    24,    87,     4,    -1,     8,
      87,     4,    -1,    87,    11,    -1,    11,    -1,    88,    89,
      -1,    -1,    91,    90,    -1,    90,    92,    -1,    92,    -1,
      25,    93,     4,    -1,    25,     4,    -1,     8,    93,     4,
      -1,    93,    11,    -1,    11,    -1,    94,    95,    -1,    -1,
      97,    96,    -1,    96,    98,    -1,    -1,    27,    99,     4,
      -1,     8,    99,     4,    -1,    99,    11,    -1,    11,    -1,
     100,   101,    -1,    -1,   103,   102,    -1,   102,   104,    -1,
      -1,    26,   105,     4,    -1,    26,     4,    -1,     8,   105,
       4,    -1,   105,    11,    -1,    11,    -1,   108,   107,    -1,
      -1,   107,   109,    -1,    -1,    28,   110,     4,    -1,     8,
     110,     4,    -1,   110,    11,    -1,    11,    -1,   113,   112,
      -1,    -1,   112,   114,    -1,    -1,    29,   115,     4,    -1,
       8,   115,     4,    -1,   115,    11,    -1,    11,    -1,   118,
     117,    -1,    -1,   117,   119,    -1,   119,    -1,    30,     4,
      -1,     8,   120,     4,    -1,   120,    11,    -1,    11,    -1,
     122,   128,    -1,   123,   125,   126,    -1,    31,   124,     4,
      -1,    -1,   124,    11,    -1,    11,    -1,    32,     4,    -1,
      33,   127,     4,    -1,   127,    10,     6,    -1,     6,    -1,
     128,   129,    -1,   129,    -1,    34,     6,   130,   131,     4,
      -1,   130,     9,    35,    -1,     9,    35,    -1,     9,    -1,
      -1,    36,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    57,    57,    58,    61,    64,    65,    66,    68,    68,
      70,    70,    71,    71,    72,    73,    74,    75,    78,    78,
      79,    79,    80,    81,    82,    82,    84,    84,    85,    85,
      86,    87,    88,    88,    90,    90,    91,    91,    92,    93,
      94,    94,    96,    96,    97,    97,    98,    99,   100,   100,
     102,   102,   102,   103,   103,   104,   105,   106,   107,   108,
     109,   112,   112,   113,   114,   114,   115,   116,   117,   117,
     119,   119,   120,   121,   121,   122,   123,   124,   124,   126,
     126,   127,   128,   128,   129,   129,   130,   131,   131,   133,
     133,   134,   135,   135,   136,   137,   138,   138,   140,   140,
     141,   142,   142,   143,   143,   144,   145,   145,   147,   147,
     148,   148,   149,   150,   151,   151,   153,   153,   154,   154,
     155,   156,   157,   157,   159,   159,   160,   160,   161,   162,
     163,   163,   165,   167,   169,   169,   170,   170,   172,   174,
     175,   175,   177,   177,   178,   179,   180,   182,   182,   184
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CNT", "EOL", "ERR", "INT", "NUL", "NXT",
  "SEP", "SPC", "TXT", "EN", "ENTXT", "ENNAM", "TI", "TITXT", "AL", "CT",
  "OR", "DA", "AC", "ACNUM", "RE", "CO", "GE", "FU", "CX", "CL", "KE",
  "FE", "SU", "SE", "SN", "SEQ", "BAS", "END", "$accept", "pir", "annots",
  "entry", "enline", "ennam", "entxt", "title", "tilines", "tiline1",
  "tiline2", "titxt", "altnam", "allines", "alline1", "alline2", "altxt",
  "contain", "ctlines", "ctline1", "ctline2", "cttxt", "organi", "orlines",
  "orline1", "orline2", "ortxt", "date", "dalines", "daline1", "daline2",
  "datxt", "access", "aclines", "acline", "acline1", "acline2", "acline3",
  "aclist", "refs", "refent", "relines", "reline1", "reline2", "retxt",
  "comms", "coment", "colines", "coline1", "coline2", "cotxt", "genetic",
  "genent", "gelines", "geline1", "geline2", "getxt", "complex", "cmpent",
  "cxlines", "cxline1", "cxline2", "cxtxt", "function", "funent",
  "fulines", "fuline1", "fuline2", "futxt", "classif", "cllines",
  "clline1", "clline2", "cltxt", "kwords", "kelines", "keline1", "keline2",
  "ketxt", "feats", "felines", "feline1", "feline2", "fetxt", "sequence",
  "seqhead", "suline", "sutxt", "seline", "snline", "snlist", "seqdata",
  "seqline", "seqlist", "seqsep", "end", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    38,    39,    40,    41,    42,    43,    43,
      44,    44,    45,    45,    46,    47,    48,    48,    49,    49,
      50,    50,    51,    52,    53,    53,    54,    54,    55,    55,
      56,    57,    58,    58,    59,    59,    60,    60,    61,    62,
      63,    63,    64,    64,    65,    65,    66,    67,    68,    68,
      69,    69,    69,    70,    70,    71,    72,    73,    74,    75,
      75,    76,    76,    77,    78,    78,    79,    80,    81,    81,
      82,    82,    83,    84,    84,    85,    86,    87,    87,    88,
      88,    89,    90,    90,    91,    91,    92,    93,    93,    94,
      94,    95,    96,    96,    97,    98,    99,    99,   100,   100,
     101,   102,   102,   103,   103,   104,   105,   105,   106,   106,
     107,   107,   108,   109,   110,   110,   111,   111,   112,   112,
     113,   114,   115,   115,   116,   116,   117,   117,   118,   119,
     120,   120,   121,   122,   123,   123,   124,   124,   125,   126,
     127,   127,   128,   128,   129,   130,   130,   131,   131,   132
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,    15,     1,     4,     1,     2,     0,
       2,     0,     2,     0,     3,     3,     2,     1,     2,     0,
       2,     0,     3,     3,     2,     1,     2,     0,     2,     0,
       3,     3,     2,     1,     2,     0,     2,     0,     3,     3,
       2,     1,     2,     0,     2,     1,     3,     3,     2,     1,
       3,     1,     0,     2,     0,     3,     4,     4,     3,     3,
       1,     2,     0,     2,     2,     1,     3,     3,     2,     1,
       2,     0,     2,     2,     0,     3,     3,     2,     1,     2,
       0,     2,     2,     1,     3,     2,     3,     2,     1,     2,
       0,     2,     2,     0,     3,     3,     2,     1,     2,     0,
       2,     2,     0,     3,     2,     3,     2,     1,     2,     0,
       2,     0,     3,     3,     2,     1,     2,     0,     2,     0,
       3,     3,     2,     1,     2,     0,     2,     1,     2,     3,
       2,     1,     2,     3,     3,     0,     2,     1,     2,     3,
       3,     1,     2,     1,     5,     3,     2,     1,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,   135,    11,     5,     7,     9,     1,
       0,     0,     0,     0,     0,    19,    13,     0,   137,     0,
       0,     2,     0,   132,   143,     0,     0,    17,     0,     0,
      27,    21,    10,     6,     8,   134,   136,   149,     0,   142,
     138,     0,   133,    14,    16,    25,     0,     0,    35,    29,
      18,     0,    12,     0,   148,   141,     0,    22,    24,    33,
       0,     0,    43,    37,    26,     0,    20,     0,   146,   147,
       0,   139,     0,    30,    32,    41,     0,     0,    52,     0,
      34,     0,    28,     0,    15,   145,   144,   140,    38,    40,
      49,     0,     0,    62,    51,    54,     0,    42,    45,     0,
      36,     0,    23,    46,    48,    60,     0,    71,     0,     0,
      44,     0,    31,     0,    55,     0,     0,    61,     0,    80,
       0,    53,    50,    47,    39,    56,    59,    69,     0,     0,
      63,    65,     0,    70,    74,    90,     0,    66,    68,     0,
      64,    78,     0,    72,     0,    79,     0,    99,     0,    58,
      67,    75,    77,     0,    73,    85,    88,     0,     0,    81,
      83,     0,    89,    93,   109,    57,     0,    84,    87,     0,
      82,    97,     0,    91,     0,     0,    98,   102,   117,   111,
      76,    86,    94,    96,     0,    92,   104,   107,     0,   115,
       0,   100,     0,   125,   119,   108,     0,   103,   106,   112,
     114,     0,   101,   123,     0,     0,     4,     0,   116,     0,
     110,    95,     0,   120,   122,   128,     0,   124,   127,     0,
     118,     0,   105,   131,     0,   126,     0,   113,   129,   130,
     121
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     8,    17,    15,    32,    16,
      52,    28,    30,    50,    31,    66,    46,    48,    64,    49,
      82,    60,    62,    80,    63,   100,    76,    78,    97,    79,
      98,    91,    93,   108,    94,    95,   121,   122,   106,   107,
     117,   130,   118,   131,   128,   119,   133,   143,   134,   154,
     142,   135,   145,   159,   146,   160,   157,   147,   162,   173,
     163,   185,   172,   164,   176,   191,   177,   202,   188,   178,
     195,   179,   210,   190,   193,   208,   194,   220,   204,   206,
     217,   207,   218,   224,    11,    12,    13,    19,    26,    42,
      56,    23,    24,    54,    70,    21
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -74
static const yytype_int8 yypact[] =
{
      63,   -74,    -9,    68,    48,    57,   -74,   -74,   -74,   -74,
      49,    37,    40,    50,    62,    59,   -74,    -2,   -74,    -1,
      73,   -74,    74,    40,   -74,    77,    51,   -74,    -4,    72,
      67,   -74,    78,   -74,   -74,   -74,   -74,   -74,    79,   -74,
     -74,    81,   -74,   -74,   -74,   -74,     3,    80,    70,   -74,
      82,    62,   -74,    64,    83,   -74,    61,   -74,   -74,   -74,
       4,    84,    76,   -74,    85,    72,   -74,    -3,   -74,    65,
      90,   -74,    91,   -74,   -74,   -74,     5,    87,    86,    93,
      94,    80,   -74,    13,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,    14,    88,   -74,   -74,   -74,    87,    93,   -74,    84,
     -74,    15,   -74,   -74,   -74,   -74,    58,    89,    95,    16,
     -74,    17,   -74,   100,   -74,    92,    97,   -74,    98,    96,
      88,   -74,   -74,   -74,   -74,   -74,   -74,   -74,    18,    97,
      98,   -74,   102,   -74,   -74,    99,    60,   -74,   -74,    19,
     -74,   -74,    27,   101,    28,   -74,   103,   104,   111,   -74,
     -74,   -74,   -74,   102,   -74,   -74,   -74,    29,   105,   103,
     -74,   106,   -74,   -74,   -22,   -74,    30,   -74,   -74,    31,
     -74,   -74,    32,   110,    33,   108,   -74,   -74,   107,   -74,
     -74,   -74,   -74,   -74,   106,   -74,   -74,   -74,    41,   -74,
      42,   113,   112,    75,   -74,   114,    43,   -74,   -74,   -74,
     -74,   115,   -74,   -74,    44,   121,   -74,   119,   120,   108,
     -74,   -74,    45,   -74,   -74,   -74,   118,   119,   -74,   112,
     -74,    46,   -74,   -74,    47,   -74,    55,   -74,   -74,   -74,
     -74
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   109,   -74,   -74,   -74,   -74,    69,   -74,   -74,   -74,
     -74,    52,   -74,   -74,   -74,   -74,    36,   -74,   -74,   -74,
      35,    34,   -74,   -74,   -74,   -74,   -74,   -74,    20,   -74,
     -74,   -74,   -74,     7,     9,   -74,   -74,   -74,   -74,   -74,
     -14,   -74,   -74,   -74,   -74,   -18,   -16,   -74,   -74,   -74,
     -74,   -74,   -41,   -74,   -74,   -74,   -74,   -74,   -57,   -74,
     -74,   -74,   -74,   -64,   -74,   -74,   -74,   -74,   -73,   -74,
     -74,   -74,   -70,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   125,   -74,   -74,   -74
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      43,    84,    33,    35,   174,     7,   175,    57,    73,    88,
      36,    34,    44,    44,    58,    74,    89,   102,   103,   112,
     123,   124,   137,   150,    58,   104,    74,   104,    89,   138,
     138,   151,   155,   167,   180,   181,   182,   186,   152,   156,
     168,   152,   168,   183,   187,   197,   199,   211,   213,   222,
     227,   228,   198,   200,   183,   214,   198,   200,   229,   230,
      18,   113,   114,   148,   149,    71,   214,   115,     9,   115,
       1,    72,    14,    20,    22,     2,    29,    37,    27,    10,
      38,    40,    25,    45,    41,    47,    51,    55,    53,    61,
      65,    59,    69,    81,    86,    75,    77,    87,    90,    68,
      85,    96,    99,   120,   125,   205,   129,    92,   127,   153,
     105,   158,   116,   141,   126,   165,   156,   171,   184,   189,
     132,   201,   209,   203,   144,   215,   187,   216,   219,   223,
     109,   161,   110,   101,    83,   111,   192,   140,   139,   166,
     136,   170,   169,   196,   212,   221,   226,   225,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67
};

static const yytype_int16 yycheck[] =
{
       4,     4,     4,     4,    26,    14,    28,     4,     4,     4,
      11,    13,    16,    16,    11,    11,    11,     4,     4,     4,
       4,     4,     4,     4,    11,    11,    11,    11,    11,    11,
      11,     4,     4,     4,     4,     4,     4,     4,    11,    11,
      11,    11,    11,    11,    11,     4,     4,     4,     4,     4,
       4,     4,    11,    11,    11,    11,    11,    11,    11,     4,
      11,     3,     4,     3,     4,     4,    11,     9,     0,     9,
       7,    10,    15,    36,    34,    12,    17,     4,    16,    31,
       6,     4,    32,    11,    33,    18,     8,     6,     9,    19,
       8,    11,     9,     8,     4,    11,    20,     6,    11,    35,
      35,     8,     8,     8,     4,    30,     8,    21,    11,     8,
      22,     8,    23,    11,    22,     4,    11,    11,     8,    11,
      24,     8,     8,    11,    25,     4,    11,     8,     8,    11,
      96,    27,    97,    81,    65,    99,    29,   130,   129,   153,
     120,   159,   158,   184,   201,   209,   219,   217,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    12,    38,    39,    40,    41,    14,    42,     0,
      31,   121,   122,   123,    15,    44,    46,    43,    11,   124,
      36,   132,    34,   128,   129,    32,   125,    16,    48,    17,
      49,    51,    45,     4,    13,     4,    11,     4,     6,   129,
       4,    33,   126,     4,    16,    11,    53,    18,    54,    56,
      50,     8,    47,     9,   130,     6,   127,     4,    11,    11,
      58,    19,    59,    61,    55,     8,    52,    48,    35,     9,
     131,     4,    10,     4,    11,    11,    63,    20,    64,    66,
      60,     8,    57,    53,     4,    35,     4,     6,     4,    11,
      11,    68,    21,    69,    71,    72,     8,    65,    67,     8,
      62,    58,     4,     4,    11,    22,    75,    76,    70,    68,
      67,    63,     4,     3,     4,     9,    23,    77,    79,    82,
       8,    73,    74,     4,     4,     4,    22,    11,    81,     8,
      78,    80,    24,    83,    85,    88,    75,     4,    11,    81,
      80,    11,    87,    84,    25,    89,    91,    94,     3,     4,
       4,     4,    11,     8,    86,     4,    11,    93,     8,    90,
      92,    27,    95,    97,   100,     4,    87,     4,    11,    93,
      92,    11,    99,    96,    26,    28,   101,   103,   106,   108,
       4,     4,     4,    11,     8,    98,     4,    11,   105,    11,
     110,   102,    29,   111,   113,   107,    99,     4,    11,     4,
      11,     8,   104,    11,   115,    30,   116,   118,   112,     8,
     109,     4,   105,     4,    11,     4,     8,   117,   119,     8,
     114,   110,     4,    11,   120,   119,   115,     4,     4,    11,
       4
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (seq, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, seq); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, sequence_t *seq)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, seq)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    sequence_t *seq;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (seq);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, sequence_t *seq)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, seq)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    sequence_t *seq;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, seq);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, sequence_t *seq)
#else
static void
yy_reduce_print (yyvsp, yyrule, seq)
    YYSTYPE *yyvsp;
    int yyrule;
    sequence_t *seq;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , seq);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, seq); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, sequence_t *seq)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, seq)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    sequence_t *seq;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (seq);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (sequence_t *seq);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */





/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (sequence_t *seq)
#else
int
yyparse (seq)
    sequence_t *seq;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1464 of yacc.c  */
#line 57 "piry.y"
    { return 0;  /*NOTREACHED*/ }
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 58 "piry.y"
    { return -1; /*NOTREACHED*/ }
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 66 "piry.y"
    { parse_namadd(seq, (yyvsp[(1) - (1)].str)); }
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 74 "piry.y"
    { parse_dscadd2(seq, (yyvsp[(2) - (2)].str)); }
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 75 "piry.y"
    { parse_dscadd1(seq, (yyvsp[(1) - (1)].str)); }
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 108 "piry.y"
    { parse_accadd(seq, (yyvsp[(3) - (3)].str)); }
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 109 "piry.y"
    { parse_accadd(seq, (yyvsp[(1) - (1)].str)); }
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 179 "piry.y"
    { parse_stradd(seq, (yyvsp[(3) - (3)].str)); }
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 180 "piry.y"
    { parse_stradd(seq, (yyvsp[(2) - (2)].str)); }
    break;



/* Line 1464 of yacc.c  */
#line 1719 "sequence/piry.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (seq, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (seq, yymsg);
	  }
	else
	  {
	    yyerror (seq, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
		      yytoken, &yylval, seq);
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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
		  yystos[yystate], yyvsp, seq);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (seq, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, seq);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, seq);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 186 "piry.y"



/* Checks PIR sequence */
int piry_check(FILE *f) {
  extern FILE *pirin;
  int i;

  pirin = f;

  i = yyparse(NULL);

  return i; }


/* Parse PIR sequence */
sequence_t *piry_parse(FILE *f) {
  extern FILE *pirin;
  int i;
  sequence_t *seq;

  pirin = f;

  if ((seq = sequence_new()) == NULL) {
    return NULL; }

  i = yyparse((void *)seq);
  if (i == 0) {
    return seq; }

  sequence_free(seq);

  return NULL; }


/* Helpers ... */

/*ARGSUSED*/
static void yyerror(sequence_t *seq, const char *s) { return; }

