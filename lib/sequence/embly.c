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
#define yyparse         emblparse
#define yylex           embllex
#define yyerror         emblerror
#define yylval          embllval
#define yychar          emblchar
#define yydebug         embldebug
#define yynerrs         emblnerrs


/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 3 "embly.y"

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
#endif

#include "sequence.h"
#include "sequence/parse.h"
#include "sequence/embly.h"

int yylex(YYSTYPE *);
static void yyerror(sequence_t *, const char *);

int embly_check(FILE *);
sequence_t *embly_parse(FILE *);


/* Line 189 of yacc.c  */
#line 101 "sequence/embly.c"

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
     EOL = 258,
     ERR = 259,
     INT = 260,
     MIN = 261,
     NUL = 262,
     NUM = 263,
     QUO = 264,
     SEP = 265,
     SPC = 266,
     TER = 267,
     TER2 = 268,
     TXT = 269,
     CBR = 270,
     OBR = 271,
     ID = 272,
     IDNAM = 273,
     AC = 274,
     ACNUM = 275,
     SV = 276,
     SVNUM = 277,
     PR = 278,
     PRVAL = 279,
     PRNUM = 280,
     DT = 281,
     DE = 282,
     DETXT = 283,
     KW = 284,
     KWORD = 285,
     KWOR2 = 286,
     OS = 287,
     OSTXT = 288,
     OC = 289,
     OCNOD = 290,
     OCNO2 = 291,
     OG = 292,
     RN = 293,
     RC = 294,
     RP = 295,
     RX = 296,
     RXDB = 297,
     RXID = 298,
     RG = 299,
     RA = 300,
     RAAUT = 301,
     RT = 302,
     RL = 303,
     DR = 304,
     AH = 305,
     AS = 306,
     FH = 307,
     FT = 308,
     CC = 309,
     CO = 310,
     SQ = 311,
     SEQ = 312,
     SEQBAS = 313,
     END = 314
   };
#endif
/* Tokens.  */
#define EOL 258
#define ERR 259
#define INT 260
#define MIN 261
#define NUL 262
#define NUM 263
#define QUO 264
#define SEP 265
#define SPC 266
#define TER 267
#define TER2 268
#define TXT 269
#define CBR 270
#define OBR 271
#define ID 272
#define IDNAM 273
#define AC 274
#define ACNUM 275
#define SV 276
#define SVNUM 277
#define PR 278
#define PRVAL 279
#define PRNUM 280
#define DT 281
#define DE 282
#define DETXT 283
#define KW 284
#define KWORD 285
#define KWOR2 286
#define OS 287
#define OSTXT 288
#define OC 289
#define OCNOD 290
#define OCNO2 291
#define OG 292
#define RN 293
#define RC 294
#define RP 295
#define RX 296
#define RXDB 297
#define RXID 298
#define RG 299
#define RA 300
#define RAAUT 301
#define RT 302
#define RL 303
#define DR 304
#define AH 305
#define AS 306
#define FH 307
#define FT 308
#define CC 309
#define CO 310
#define SQ 311
#define SEQ 312
#define SEQBAS 313
#define END 314




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 26 "embly.y"
 char *str; int num; 


/* Line 214 of yacc.c  */
#line 259 "sequence/embly.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 271 "sequence/embly.c"

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   178

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  103
/* YYNRULES -- Number of rules.  */
#define YYNRULES  168
/* YYNRULES -- Number of states.  */
#define YYNSTATES  268

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     9,    23,    25,    30,    33,    34,
      37,    38,    43,    47,    49,    51,    52,    58,    60,    61,
      68,    71,    72,    76,    79,    81,    84,    85,    89,    92,
      94,    97,    98,   101,   104,   105,   110,   115,   119,   123,
     125,   127,   128,   131,   132,   136,   138,   142,   144,   147,
     148,   151,   152,   157,   161,   166,   170,   172,   173,   175,
     177,   180,   181,   185,   188,   190,   193,   194,   203,   205,
     211,   214,   215,   219,   222,   224,   227,   228,   231,   232,
     237,   241,   245,   247,   251,   254,   255,   262,   265,   266,
     270,   273,   275,   278,   281,   282,   287,   292,   296,   298,
     299,   303,   305,   306,   309,   310,   317,   321,   326,   330,
     336,   341,   344,   346,   349,   351,   355,   358,   360,   363,
     364,   368,   371,   373,   376,   377,   380,   381,   385,   388,
     390,   393,   395,   399,   402,   404,   407,   411,   414,   415,
     418,   420,   424,   427,   429,   432,   433,   437,   440,   441,
     445,   447,   450,   453,   455,   459,   462,   464,   466,   470,
     473,   475,   478,   480,   485,   489,   491,   494,   495
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      61,     0,    -1,    62,   151,   162,    -1,     7,    -1,    63,
      66,    69,    71,    73,    76,    79,    85,    99,   132,   148,
     136,   135,    -1,    64,    -1,    17,    18,    65,     3,    -1,
      65,    14,    -1,    -1,    66,    67,    -1,    -1,    19,    68,
      12,     3,    -1,    68,    10,    20,    -1,    20,    -1,    70,
      -1,    -1,    21,    20,    10,    22,     3,    -1,    72,    -1,
      -1,    23,    24,    10,    25,    12,     3,    -1,    74,    74,
      -1,    -1,    26,    75,     3,    -1,    75,    14,    -1,    14,
      -1,    76,    77,    -1,    -1,    27,    78,     3,    -1,    78,
      28,    -1,    28,    -1,    80,    82,    -1,    -1,    80,    81,
      -1,    80,    83,    -1,    -1,    29,    84,    13,     3,    -1,
      29,    84,    12,     3,    -1,    29,    84,     3,    -1,    84,
      10,    30,    -1,    30,    -1,    31,    -1,    -1,    85,    86,
      -1,    -1,    87,    90,    96,    -1,    88,    -1,    32,    89,
       3,    -1,    33,    -1,    91,    93,    -1,    -1,    91,    92,
      -1,    -1,    34,    94,    13,     3,    -1,    34,    94,     3,
      -1,    34,    94,    12,     3,    -1,    94,    10,    95,    -1,
      95,    -1,    -1,    35,    -1,    36,    -1,    96,    97,    -1,
      -1,    37,    98,     3,    -1,    98,    14,    -1,    14,    -1,
      99,   100,    -1,    -1,   101,   103,   106,   112,   114,   117,
     122,   129,    -1,   102,    -1,    38,    16,     5,    15,     3,
      -1,   103,   104,    -1,    -1,    39,   105,     3,    -1,   105,
      14,    -1,    14,    -1,   107,   109,    -1,    -1,   107,   108,
      -1,    -1,    40,   110,    12,     3,    -1,    40,   110,     3,
      -1,   110,    10,   111,    -1,   111,    -1,     5,     6,     5,
      -1,   112,   113,    -1,    -1,    41,    42,    10,    43,    12,
       3,    -1,   114,   115,    -1,    -1,    44,   116,     3,    -1,
     116,    14,    -1,    14,    -1,   118,   120,    -1,   118,   119,
      -1,    -1,    45,   121,    13,     3,    -1,    45,   121,    12,
       3,    -1,   121,    10,    46,    -1,    46,    -1,    -1,   125,
     123,   127,    -1,   124,    -1,    -1,   123,   126,    -1,    -1,
      47,     9,   128,     9,    12,     3,    -1,    47,    12,     3,
      -1,    47,     9,   128,     3,    -1,    47,   128,     3,    -1,
      47,   128,     9,    12,     3,    -1,    47,     9,    12,     3,
      -1,   128,    14,    -1,    14,    -1,   129,   130,    -1,   130,
      -1,    48,   131,     3,    -1,   131,    14,    -1,    14,    -1,
     132,   133,    -1,    -1,    49,   134,     3,    -1,   134,    14,
      -1,    14,    -1,   142,   145,    -1,    -1,   137,   139,    -1,
      -1,    50,   138,     3,    -1,   138,    14,    -1,    14,    -1,
     139,   140,    -1,   140,    -1,    51,   141,     3,    -1,   141,
      14,    -1,    14,    -1,   143,   143,    -1,    52,   144,     3,
      -1,   144,    14,    -1,    -1,   145,   146,    -1,   146,    -1,
      53,   147,     3,    -1,   147,    14,    -1,    14,    -1,   148,
     149,    -1,    -1,    54,   150,     3,    -1,   150,    14,    -1,
      -1,   152,   155,   158,    -1,   152,    -1,   155,   158,    -1,
     152,   153,    -1,   153,    -1,    55,   154,     3,    -1,   154,
      14,    -1,    14,    -1,   156,    -1,    56,   157,     3,    -1,
     157,    14,    -1,    14,    -1,   158,   159,    -1,   159,    -1,
      57,   160,   161,     3,    -1,   160,    10,    58,    -1,    58,
      -1,    11,     5,    -1,    -1,    59,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    70,    70,    71,    74,    76,    77,    79,    79,    81,
      81,    82,    83,    84,    87,    87,    88,    91,    91,    92,
      94,    94,    95,    96,    96,    98,    98,    99,   100,   101,
     104,   104,   105,   105,   105,   106,   107,   108,   109,   110,
     111,   112,   115,   115,   116,   118,   119,   120,   122,   122,
     123,   123,   124,   124,   125,   126,   126,   126,   127,   127,
     129,   129,   130,   131,   131,   133,   133,   134,   136,   137,
     139,   139,   140,   141,   141,   143,   143,   144,   144,   145,
     146,   147,   147,   148,   150,   150,   151,   153,   153,   154,
     155,   155,   157,   158,   158,   159,   160,   161,   161,   161,
     163,   163,   163,   164,   164,   165,   165,   166,   167,   168,
     168,   169,   169,   171,   171,   172,   173,   173,   175,   175,
     176,   177,   177,   179,   179,   181,   181,   182,   183,   183,
     184,   184,   185,   186,   186,   188,   189,   190,   190,   192,
     192,   193,   194,   194,   196,   196,   197,   198,   198,   200,
     200,   200,   202,   202,   203,   204,   204,   206,   207,   208,
     208,   210,   210,   211,   212,   213,   215,   215,   217
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EOL", "ERR", "INT", "MIN", "NUL", "NUM",
  "QUO", "SEP", "SPC", "TER", "TER2", "TXT", "CBR", "OBR", "ID", "IDNAM",
  "AC", "ACNUM", "SV", "SVNUM", "PR", "PRVAL", "PRNUM", "DT", "DE",
  "DETXT", "KW", "KWORD", "KWOR2", "OS", "OSTXT", "OC", "OCNOD", "OCNO2",
  "OG", "RN", "RC", "RP", "RX", "RXDB", "RXID", "RG", "RA", "RAAUT", "RT",
  "RL", "DR", "AH", "AS", "FH", "FT", "CC", "CO", "SQ", "SEQ", "SEQBAS",
  "END", "$accept", "embl", "annots", "locus", "idline", "idtxt", "access",
  "acline", "aclist", "vers", "svline", "proj", "prline", "date", "dtline",
  "dttxt", "desc", "deline", "detxt", "kwords", "kwlines", "kwline1",
  "kwline2", "kwline3", "kwlist", "orgas", "orgent", "orgspe", "osline",
  "ostxt", "orgcla", "oclines", "ocline1", "ocline2", "oclist", "ocnode",
  "orggan", "ogline", "ogtxt", "refs", "refent", "refnum", "rnline",
  "refcom", "rcline", "rctxt", "refpos", "rplines", "rpline1", "rpline2",
  "rplist", "rpval", "refxdb", "rxline", "refgrp", "rgline", "rgtxt",
  "refaut", "ralines", "raline1", "raline2", "ralist", "reftit", "rtlines",
  "rtline", "rtline1", "rtline2", "rtline3", "rttxt", "refloc", "rlline",
  "rltxt", "dbref", "drline", "drtxt", "feats", "asmb", "ahline", "ahtxt",
  "aslines", "asline", "astxt", "feathead", "fhline", "fhtxt", "featdata",
  "ftline", "fttxt", "comm", "ccline", "cctxt", "sequence", "seqcont",
  "coline", "cotxt", "seqhead", "sqline", "sqtxt", "seqdata", "seqline",
  "seqlist", "seqnum", "end", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    62,    63,    64,    65,    65,    66,
      66,    67,    68,    68,    69,    69,    70,    71,    71,    72,
      73,    73,    74,    75,    75,    76,    76,    77,    78,    78,
      79,    79,    80,    80,    80,    81,    82,    83,    84,    84,
      84,    84,    85,    85,    86,    87,    88,    89,    90,    90,
      91,    91,    92,    92,    93,    94,    94,    94,    95,    95,
      96,    96,    97,    98,    98,    99,    99,   100,   101,   102,
     103,   103,   104,   105,   105,   106,   106,   107,   107,   108,
     109,   110,   110,   111,   112,   112,   113,   114,   114,   115,
     116,   116,   117,   118,   118,   119,   120,   121,   121,   121,
     122,   122,   122,   123,   123,   124,   124,   125,   126,   127,
     127,   128,   128,   129,   129,   130,   131,   131,   132,   132,
     133,   134,   134,   135,   135,   136,   136,   137,   138,   138,
     139,   139,   140,   141,   141,   142,   143,   144,   144,   145,
     145,   146,   147,   147,   148,   148,   149,   150,   150,   151,
     151,   151,   152,   152,   153,   154,   154,   155,   156,   157,
     157,   158,   158,   159,   160,   160,   161,   161,   162
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,    13,     1,     4,     2,     0,     2,
       0,     4,     3,     1,     1,     0,     5,     1,     0,     6,
       2,     0,     3,     2,     1,     2,     0,     3,     2,     1,
       2,     0,     2,     2,     0,     4,     4,     3,     3,     1,
       1,     0,     2,     0,     3,     1,     3,     1,     2,     0,
       2,     0,     4,     3,     4,     3,     1,     0,     1,     1,
       2,     0,     3,     2,     1,     2,     0,     8,     1,     5,
       2,     0,     3,     2,     1,     2,     0,     2,     0,     4,
       3,     3,     1,     3,     2,     0,     6,     2,     0,     3,
       2,     1,     2,     2,     0,     4,     4,     3,     1,     0,
       3,     1,     0,     2,     0,     6,     3,     4,     3,     5,
       4,     2,     1,     2,     1,     3,     2,     1,     2,     0,
       3,     2,     1,     2,     0,     2,     0,     3,     2,     1,
       2,     1,     3,     2,     1,     2,     3,     2,     0,     2,
       1,     3,     2,     1,     2,     0,     3,     2,     0,     3,
       1,     2,     2,     1,     3,     2,     1,     1,     3,     2,
       1,     2,     1,     4,     3,     1,     2,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     0,    10,     5,     8,     1,     0,
       0,     0,   150,   153,     0,   157,    15,     0,   156,     0,
     160,     0,     0,     2,   152,     0,     0,   151,   162,     0,
       0,     9,    18,    14,     6,     7,   154,   155,   158,   159,
     168,   149,   165,   167,   161,    13,     0,     0,     0,    21,
      17,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,   164,   166,   163,    12,    11,     0,     0,    24,     0,
      31,    20,    16,     0,    22,    23,     0,    25,    43,     0,
       0,    29,     0,    66,    41,    32,    30,    33,    19,    27,
      28,     0,    42,    49,    45,   119,    39,    40,     0,    47,
       0,    61,     0,     0,    65,    71,    68,   145,    37,     0,
       0,     0,    46,    44,    57,    50,    48,     0,    76,     0,
     118,   126,    38,    36,    35,     0,    60,    58,    59,     0,
      56,     0,     0,    70,    85,     0,   122,     0,     0,   148,
     124,     0,   144,    64,     0,    53,     0,     0,     0,     0,
      74,     0,    88,     0,    77,    75,   120,   121,   129,     0,
       0,   138,     4,     0,     0,     0,   125,   131,    62,    63,
      55,    54,    52,    69,    72,    73,     0,    84,    94,     0,
       0,    82,   127,   128,   146,   147,     0,     0,   123,   140,
     135,   134,     0,   130,     0,     0,    87,   102,     0,     0,
      80,     0,     0,   136,   137,   143,     0,   139,   132,   133,
       0,    91,     0,     0,     0,   101,   104,    99,    93,    92,
      83,    81,    79,   141,   142,     0,    89,    90,     0,     0,
       0,    67,   114,     0,    98,     0,     0,   112,     0,   106,
     117,     0,   113,     0,   103,   100,     0,     0,     0,    86,
     107,     0,   111,   115,   116,     0,     0,    97,    96,    95,
       0,     0,   108,     0,   105,   110,     0,   109
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    17,    16,    31,    46,    32,
      33,    49,    50,    59,    60,    69,    70,    77,    82,    78,
      79,    85,    86,    87,    98,    83,    92,    93,    94,   100,
     101,   102,   115,   116,   129,   130,   113,   126,   144,    95,
     104,   105,   106,   118,   133,   151,   134,   135,   154,   155,
     180,   181,   152,   177,   178,   196,   212,   197,   198,   218,
     219,   235,   214,   233,   215,   216,   244,   245,   238,   231,
     232,   241,   107,   120,   137,   162,   140,   141,   159,   166,
     167,   192,   163,   164,   186,   188,   189,   206,   121,   142,
     160,    11,    12,    13,    19,    14,    15,    21,    27,    28,
      43,    53,    23
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -84
static const yytype_int16 yypact[] =
{
      27,   -84,   -14,    36,    19,   -84,   -84,   -84,   -84,    32,
      39,    -2,    19,   -84,   -24,   -84,    48,     2,   -84,     3,
     -84,     4,    62,   -84,   -84,   -24,    14,   -24,   -84,    63,
      67,   -84,    59,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -24,   -84,    66,   -84,   -84,    58,    76,    64,    65,
     -84,    31,    85,    89,    73,    91,    74,    87,    81,   -84,
      65,   -84,   -84,   -84,   -84,   -84,    95,    75,   -84,     7,
      44,   -84,   -84,    90,   -84,   -84,    71,   -84,   -84,    72,
     100,   -84,    -3,    77,    50,   -84,   -84,   -84,   -84,   -84,
     -84,    78,   -84,    70,   -84,    68,   -84,   -84,    38,   -84,
     102,   -84,    79,    92,   -84,   -84,   -84,    61,   -84,    82,
     104,   111,   -84,    80,    43,   -84,   -84,   110,    45,   105,
     -84,    10,   -84,   -84,   -84,   106,   -84,   -84,   -84,    42,
     -84,   101,   107,   -84,   -84,    83,   -84,     8,   108,   -84,
      84,    86,   -84,   -84,     9,   -84,    43,   115,   121,   122,
     -84,    16,    88,   123,   -84,   -84,   -84,   -84,   -84,    17,
      21,   -84,   -84,    93,    84,   112,    86,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,    96,   -84,    97,   124,
      46,   -84,   -84,   -84,   -84,   -84,    23,   113,    93,   -84,
     -84,   -84,    24,   -84,   125,   117,   -84,    98,    94,   127,
     -84,   123,   130,   -84,   -84,   -84,    25,   -84,   -84,   -84,
      99,   -84,    26,    54,   103,   -84,   -84,   109,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   128,   -84,   -84,   120,   140,
     133,   103,   -84,   114,   -84,    49,   141,   -84,    -1,   -84,
     -84,    29,   -84,    33,   -84,   -84,   116,   145,   146,   -84,
     -84,   138,   -84,   -84,   -84,   142,     0,   -84,   -84,   -84,
     149,   150,   -84,   144,   -84,   -84,   154,   -84
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   118,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,    12,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -42,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -83,   -84,
     -68,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
       1,   -84,   -84,     5,   -84,   -84,   -23,   -84,   -84,   -84,
     -84,   -84,   -84,   152,   -84,   156,   -84,   -84,   147,   -26,
     -84,   -84,   -84
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -79
static const yytype_int16 yytable[] =
{
      89,    44,   250,   262,     7,    34,    36,    38,   251,   263,
      74,   156,   168,   252,   252,    44,    35,    37,    39,   174,
     182,    75,   157,   169,   184,    90,   203,   208,   223,   226,
     175,   183,   253,    26,     1,   185,     8,   204,   209,   224,
     227,   108,   255,   254,     2,   145,    18,   237,   109,   200,
     110,   111,   146,    20,   147,   148,   201,    22,   202,   246,
     138,   247,   248,   228,   139,    40,   229,    29,    54,    30,
      55,    76,    42,   -34,     9,    10,    51,    52,   127,   128,
      96,    97,    48,    45,   132,   -78,    56,    47,    57,    61,
      62,    58,    63,    64,    65,    68,    66,    67,    72,    81,
      73,    84,    80,    88,   -51,   112,   103,   123,   117,    91,
     119,    99,   122,   114,   124,   131,   149,   125,   171,   136,
     143,   150,   158,   153,   172,   173,   191,   205,   179,   176,
     199,   211,   220,   222,   237,   210,   161,   165,   194,   217,
     236,   195,   225,   239,   249,   213,   187,   240,   258,   259,
     260,   230,   264,   265,   261,   234,   266,   267,   170,   221,
     256,   243,   257,   242,    24,   207,     0,   193,    25,   190,
       0,     0,    41,     0,     0,     0,     0,     0,    71
};

static const yytype_int16 yycheck[] =
{
       3,    27,     3,     3,    18,     3,     3,     3,     9,     9,
       3,     3,     3,    14,    14,    41,    14,    14,    14,     3,
       3,    14,    14,    14,     3,    28,     3,     3,     3,     3,
      14,    14,     3,    57,     7,    14,     0,    14,    14,    14,
      14,     3,     9,    14,    17,     3,    14,    14,    10,     3,
      12,    13,    10,    14,    12,    13,    10,    59,    12,    10,
      50,    12,    13,     9,    54,     3,    12,    19,    10,    21,
      12,    27,    58,    29,    55,    56,    10,    11,    35,    36,
      30,    31,    23,    20,    39,    40,    10,    20,    24,    58,
       5,    26,     3,    20,     3,    14,    22,    10,     3,    28,
      25,    29,    12,     3,    34,     3,    38,     3,    16,    32,
      49,    33,    30,    34,     3,     5,    15,    37,     3,    14,
      14,    14,    14,    40,     3,     3,    14,    14,     5,    41,
       6,    14,     5,     3,    14,    10,    52,    51,    42,    45,
      12,    44,    43,     3,     3,    47,    53,    14,     3,     3,
      12,    48,     3,     3,    12,    46,    12,     3,   146,   201,
     243,    47,    46,   231,    12,   188,    -1,   166,    12,   164,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    60
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    17,    61,    62,    63,    64,    18,     0,    55,
      56,   151,   152,   153,   155,   156,    66,    65,    14,   154,
      14,   157,    59,   162,   153,   155,    57,   158,   159,    19,
      21,    67,    69,    70,     3,    14,     3,    14,     3,    14,
       3,   158,    58,   160,   159,    20,    68,    20,    23,    71,
      72,    10,    11,   161,    10,    12,    10,    24,    26,    73,
      74,    58,     5,     3,    20,     3,    22,    10,    14,    75,
      76,    74,     3,    25,     3,    14,    27,    77,    79,    80,
      12,    28,    78,    85,    29,    81,    82,    83,     3,     3,
      28,    32,    86,    87,    88,    99,    30,    31,    84,    33,
      89,    90,    91,    38,   100,   101,   102,   132,     3,    10,
      12,    13,     3,    96,    34,    92,    93,    16,   103,    49,
     133,   148,    30,     3,     3,    37,    97,    35,    36,    94,
      95,     5,    39,   104,   106,   107,    14,   134,    50,    54,
     136,   137,   149,    14,    98,     3,    10,    12,    13,    15,
      14,   105,   112,    40,   108,   109,     3,    14,    14,   138,
     150,    52,   135,   142,   143,    51,   139,   140,     3,    14,
      95,     3,     3,     3,     3,    14,    41,   113,   114,     5,
     110,   111,     3,    14,     3,    14,   144,    53,   145,   146,
     143,    14,   141,   140,    42,    44,   115,   117,   118,     6,
       3,    10,    12,     3,    14,    14,   147,   146,     3,    14,
      10,    14,   116,    47,   122,   124,   125,    45,   119,   120,
       5,   111,     3,     3,    14,    43,     3,    14,     9,    12,
      48,   129,   130,   123,    46,   121,    12,    14,   128,     3,
      14,   131,   130,    47,   126,   127,    10,    12,    13,     3,
       3,     9,    14,     3,    14,     9,   128,    46,     3,     3,
      12,    12,     3,     9,     3,     3,    12,     3
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
#line 70 "embly.y"
    { return 0;  /*NOTREACHED*/ }
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 71 "embly.y"
    { return -1; /*NOTREACHED*/ }
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 77 "embly.y"
    { parse_namadd(seq, (yyvsp[(2) - (4)].str)); }
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 83 "embly.y"
    { parse_accadd(seq, (yyvsp[(3) - (3)].str)); }
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 84 "embly.y"
    { parse_accadd(seq, (yyvsp[(1) - (1)].str)); }
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 88 "embly.y"
    { parse_veradd(seq, (yyvsp[(4) - (5)].num)); }
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 100 "embly.y"
    { parse_dscadd2(seq, (yyvsp[(2) - (2)].str)); }
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 101 "embly.y"
    { parse_dscadd1(seq, (yyvsp[(1) - (1)].str)); }
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 109 "embly.y"
    { parse_kwdadd(seq, (yyvsp[(3) - (3)].str)); }
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 110 "embly.y"
    { parse_kwdadd(seq, (yyvsp[(1) - (1)].str)); }
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 111 "embly.y"
    { parse_kwdupd(seq, (yyvsp[(1) - (1)].str)); }
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 212 "embly.y"
    { parse_stradd(seq, (yyvsp[(3) - (3)].str)); }
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 213 "embly.y"
    { parse_stradd(seq, (yyvsp[(1) - (1)].str)); }
    break;



/* Line 1464 of yacc.c  */
#line 1828 "sequence/embly.c"
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
#line 219 "embly.y"



/* Checks EMBL sequence */
int embly_check(FILE *f) {
  extern FILE *emblin;
  int i;

  emblin = f;
  i = yyparse(NULL);

  return i; }


/* Parse EMBL sequence */
sequence_t *embly_parse(FILE *f) {
  extern FILE *emblin;
  int i;
  sequence_t *seq;

  emblin = f;

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

