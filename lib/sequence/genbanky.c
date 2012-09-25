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
#define yyparse         genbankparse
#define yylex           genbanklex
#define yyerror         genbankerror
#define yylval          genbanklval
#define yychar          genbankchar
#define yydebug         genbankdebug
#define yynerrs         genbanknerrs


/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 3 "genbanky.y"

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
#endif

#include "sequence.h"
#include "sequence/parse.h"
#include "sequence/genbanky.h"

int yylex(YYSTYPE *);
static void yyerror(sequence_t *, const char *);

int genbanky_check(FILE *);
sequence_t *genbanky_parse(FILE *);


/* Line 189 of yacc.c  */
#line 101 "sequence/genbanky.c"

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
     NUL = 261,
     NUM = 262,
     NXT = 263,
     SEP = 264,
     SPC = 265,
     TER = 266,
     TER2 = 267,
     TXT = 268,
     LO = 269,
     LONAM = 270,
     DE = 271,
     DETXT = 272,
     DA = 273,
     AC = 274,
     ACNUM = 275,
     VE = 276,
     GI = 277,
     VENUM = 278,
     GINUM = 279,
     PJ = 280,
     LN = 281,
     DB = 282,
     KE = 283,
     KEWRD = 284,
     KEWR2 = 285,
     SE = 286,
     SO = 287,
     OG = 288,
     RE = 289,
     RA = 290,
     RC = 291,
     RT = 292,
     RJ = 293,
     RM = 294,
     RP = 295,
     RR = 296,
     CO = 297,
     PR = 298,
     FE = 299,
     BC = 300,
     WE = 301,
     PI = 302,
     LE = 303,
     OR = 304,
     CON = 305,
     SEQ = 306,
     SEQBAS = 307,
     END = 308
   };
#endif
/* Tokens.  */
#define EOL 258
#define ERR 259
#define INT 260
#define NUL 261
#define NUM 262
#define NXT 263
#define SEP 264
#define SPC 265
#define TER 266
#define TER2 267
#define TXT 268
#define LO 269
#define LONAM 270
#define DE 271
#define DETXT 272
#define DA 273
#define AC 274
#define ACNUM 275
#define VE 276
#define GI 277
#define VENUM 278
#define GINUM 279
#define PJ 280
#define LN 281
#define DB 282
#define KE 283
#define KEWRD 284
#define KEWR2 285
#define SE 286
#define SO 287
#define OG 288
#define RE 289
#define RA 290
#define RC 291
#define RT 292
#define RJ 293
#define RM 294
#define RP 295
#define RR 296
#define CO 297
#define PR 298
#define FE 299
#define BC 300
#define WE 301
#define PI 302
#define LE 303
#define OR 304
#define CON 305
#define SEQ 306
#define SEQBAS 307
#define END 308




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 26 "genbanky.y"
 char *str; int num; 


/* Line 214 of yacc.c  */
#line 247 "sequence/genbanky.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 259 "sequence/genbanky.c"

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   287

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  137
/* YYNRULES -- Number of rules.  */
#define YYNRULES  221
/* YYNRULES -- Number of states.  */
#define YYNSTATES  348

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     9,    11,    13,    15,    28,    40,
      53,    55,    60,    63,    65,    66,    70,    72,    74,    75,
      78,    79,    84,    88,    92,    96,   101,   104,   106,   108,
     112,   115,   117,   120,   121,   124,   125,   129,   133,   137,
     139,   141,   142,   147,   151,   153,   157,   158,   161,   163,
     166,   168,   170,   172,   176,   179,   181,   183,   187,   190,
     192,   195,   198,   199,   203,   207,   210,   212,   216,   218,
     219,   222,   223,   228,   232,   237,   241,   246,   250,   255,
     259,   263,   265,   267,   269,   270,   274,   277,   279,   282,
     284,   286,   287,   290,   293,   294,   298,   302,   305,   307,
     310,   313,   314,   318,   322,   325,   327,   330,   331,   340,
     343,   346,   347,   351,   355,   358,   360,   363,   364,   367,
     368,   372,   376,   379,   381,   384,   385,   388,   389,   393,
     397,   400,   402,   405,   406,   409,   410,   414,   418,   421,
     423,   426,   427,   430,   431,   435,   439,   442,   444,   446,
     447,   451,   454,   456,   458,   459,   463,   466,   468,   471,
     472,   475,   476,   480,   484,   487,   489,   492,   493,   496,
     497,   501,   505,   508,   509,   512,   513,   516,   517,   521,
     525,   528,   530,   533,   534,   537,   538,   542,   546,   549,
     551,   553,   554,   558,   561,   563,   565,   569,   571,   572,
     576,   578,   582,   584,   587,   590,   593,   594,   598,   602,
     605,   607,   609,   611,   615,   618,   619,   622,   624,   630,
     634,   636
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      55,     0,    -1,    56,   177,   190,    -1,     6,    -1,    57,
      -1,    58,    -1,    59,    -1,    60,    63,    73,    78,    94,
     101,   104,   115,   153,   158,   163,   168,    -1,    60,    63,
      70,    73,    78,    94,   104,   153,   171,   173,   175,    -1,
      60,    63,    73,    78,    82,    94,   101,   104,   115,   153,
     158,   163,    -1,    61,    -1,    14,    15,    62,     3,    -1,
      62,    13,    -1,    10,    -1,    -1,    66,    64,    68,    -1,
      66,    -1,    65,    -1,    -1,    64,    67,    -1,    -1,    16,
      69,    11,     3,    -1,    16,    11,     3,    -1,    16,    69,
       3,    -1,     8,    69,     3,    -1,     8,    69,    11,     3,
      -1,    69,    17,    -1,    17,    -1,    71,    -1,    18,    72,
       3,    -1,    72,    13,    -1,    13,    -1,    75,    74,    -1,
      -1,    74,    76,    -1,    -1,    19,    77,     3,    -1,     8,
      77,     3,    -1,    77,     9,    20,    -1,    20,    -1,    79,
      -1,    -1,    21,    80,    81,     3,    -1,    20,     9,    23,
      -1,    20,    -1,    10,    22,    24,    -1,    -1,    83,    86,
      -1,    83,    -1,    86,    89,    -1,    86,    -1,    89,    -1,
      84,    -1,    25,    85,     3,    -1,    85,    13,    -1,    13,
      -1,    87,    -1,    26,    88,     3,    -1,    88,    13,    -1,
      13,    -1,    91,    90,    -1,    90,    92,    -1,    -1,    27,
      93,     3,    -1,     8,    93,     3,    -1,    93,    13,    -1,
      13,    -1,    97,    95,    99,    -1,    96,    -1,    -1,    95,
      98,    -1,    -1,    28,   100,    11,     3,    -1,    28,    11,
       3,    -1,    28,   100,    12,     3,    -1,    28,   100,     3,
      -1,     8,   100,    12,     3,    -1,     8,   100,     3,    -1,
       8,   100,    11,     3,    -1,   100,     9,    29,    -1,   100,
       9,    30,    -1,    29,    -1,    30,    -1,   102,    -1,    -1,
      31,   103,     3,    -1,   103,    13,    -1,    13,    -1,   105,
     110,    -1,   105,    -1,   110,    -1,    -1,   107,   106,    -1,
     106,   108,    -1,    -1,    32,   109,     3,    -1,     8,   109,
       3,    -1,   109,    13,    -1,    13,    -1,   112,   111,    -1,
     111,   113,    -1,    -1,    33,   114,     3,    -1,     8,   114,
       3,    -1,   114,    13,    -1,    13,    -1,   115,   116,    -1,
      -1,   117,   122,   127,   132,   137,   142,   145,   148,    -1,
     119,   118,    -1,   118,   120,    -1,    -1,    34,   121,     3,
      -1,     8,   121,     3,    -1,   121,    13,    -1,    13,    -1,
     124,   123,    -1,    -1,   123,   125,    -1,    -1,    35,   126,
       3,    -1,     8,   126,     3,    -1,   126,    13,    -1,    13,
      -1,   129,   128,    -1,    -1,   128,   130,    -1,    -1,    36,
     131,     3,    -1,     8,   131,     3,    -1,   131,    13,    -1,
      13,    -1,   134,   133,    -1,    -1,   133,   135,    -1,    -1,
      37,   136,     3,    -1,     8,   136,     3,    -1,   136,    13,
      -1,    13,    -1,   139,   138,    -1,    -1,   138,   140,    -1,
      -1,    38,   141,     3,    -1,     8,   141,     3,    -1,   141,
      13,    -1,    13,    -1,   143,    -1,    -1,    39,   144,     3,
      -1,   144,    13,    -1,    13,    -1,   146,    -1,    -1,    40,
     147,     3,    -1,   147,    13,    -1,    13,    -1,   150,   149,
      -1,    -1,   149,   151,    -1,    -1,    41,   152,     3,    -1,
       8,   152,     3,    -1,   152,    13,    -1,    13,    -1,   155,
     154,    -1,    -1,   154,   156,    -1,    -1,    42,   157,     3,
      -1,     8,   157,     3,    -1,   157,    13,    -1,    -1,   160,
     159,    -1,    -1,   159,   161,    -1,    -1,    43,   162,     3,
      -1,     8,   162,     3,    -1,   162,    13,    -1,    13,    -1,
     165,   164,    -1,    -1,   164,   166,    -1,    -1,    44,   167,
       3,    -1,     8,   167,     3,    -1,   167,    13,    -1,    13,
      -1,   169,    -1,    -1,    45,   170,     3,    -1,   170,    13,
      -1,    13,    -1,   172,    -1,    46,     7,     3,    -1,   174,
      -1,    -1,    47,     7,     3,    -1,   176,    -1,    48,     5,
       3,    -1,   178,    -1,   183,   187,    -1,   180,   179,    -1,
     179,   181,    -1,    -1,    50,   182,     3,    -1,     8,   182,
       3,    -1,   182,    13,    -1,    13,    -1,   184,    -1,   185,
      -1,    49,   186,     3,    -1,   186,    13,    -1,    -1,   187,
     188,    -1,   188,    -1,    51,     5,    10,   189,     3,    -1,
     189,    10,    52,    -1,    52,    -1,    53,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    68,    68,    69,    72,    72,    72,    73,    74,    75,
      77,    78,    80,    80,    80,    82,    82,    82,    82,    83,
      83,    84,    84,    85,    86,    87,    88,    89,    92,    93,
      94,    94,    96,    96,    97,    97,    98,    99,   100,   101,
     104,   104,   105,   106,   107,   109,   110,   113,   113,   113,
     113,   113,   115,   116,   117,   117,   119,   120,   121,   121,
     123,   124,   124,   125,   126,   127,   127,   129,   129,   129,
     130,   130,   131,   131,   132,   132,   133,   133,   134,   135,
     136,   137,   138,   141,   141,   142,   143,   143,   145,   145,
     145,   145,   147,   148,   148,   149,   150,   151,   151,   153,
     154,   154,   155,   156,   157,   157,   159,   159,   160,   162,
     163,   163,   164,   165,   166,   166,   168,   168,   169,   169,
     170,   171,   172,   172,   174,   174,   175,   175,   176,   177,
     178,   178,   180,   180,   181,   181,   182,   183,   184,   184,
     186,   186,   187,   187,   188,   189,   190,   190,   192,   192,
     193,   194,   194,   196,   196,   197,   198,   198,   200,   200,
     201,   201,   202,   203,   204,   204,   206,   206,   207,   207,
     208,   209,   210,   210,   212,   212,   213,   213,   214,   215,
     216,   216,   218,   218,   219,   219,   220,   221,   222,   222,
     224,   224,   225,   226,   226,   228,   229,   231,   231,   232,
     234,   235,   237,   237,   239,   240,   240,   241,   242,   243,
     243,   245,   247,   248,   249,   249,   251,   251,   252,   253,
     254,   257
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EOL", "ERR", "INT", "NUL", "NUM", "NXT",
  "SEP", "SPC", "TER", "TER2", "TXT", "LO", "LONAM", "DE", "DETXT", "DA",
  "AC", "ACNUM", "VE", "GI", "VENUM", "GINUM", "PJ", "LN", "DB", "KE",
  "KEWRD", "KEWR2", "SE", "SO", "OG", "RE", "RA", "RC", "RT", "RJ", "RM",
  "RP", "RR", "CO", "PR", "FE", "BC", "WE", "PI", "LE", "OR", "CON", "SEQ",
  "SEQBAS", "END", "$accept", "genbank", "annots", "gbannots", "gpannots",
  "rfannots", "locus", "loline", "lotxt", "defs", "delines", "deline",
  "deline1", "deline2", "deline3", "detxt", "date", "daline", "datxt",
  "access", "aclines", "acline1", "acline2", "aclist", "vers", "veline",
  "vetxt", "gitxt", "rfsrc", "proj", "pjline", "pjtxt", "dblnk", "lnline",
  "lntxt", "dbsrc", "dblines", "dbline1", "dbline2", "dbtxt", "kwrds",
  "kelines", "keline", "keline1", "keline2", "keline3", "kelist", "segmt",
  "seline", "setxt", "orga", "orgsou", "solines", "soline1", "soline2",
  "sotxt", "orggan", "oglines", "ogline1", "ogline2", "ogtxt", "refs",
  "refent", "refnum", "relines", "reline1", "reline2", "retxt", "refaut",
  "ralines", "raline1", "raline2", "ratxt", "refcon", "rclines", "rcline1",
  "rcline2", "rctxt", "reftit", "rtlines", "rtline1", "rtline2", "rttxt",
  "refjou", "rjlines", "rjline1", "rjline2", "rjtxt", "refmed", "rmline",
  "rmtxt", "refpub", "rpline", "rptxt", "refrem", "rrlines", "rrline1",
  "rrline2", "rrtxt", "comm", "colines", "coline1", "coline2", "cotxt",
  "prim", "prlines", "prline1", "prline2", "prtxt", "feats", "felines",
  "feline1", "feline2", "fetxt", "bcount", "bcline", "bctxt", "weight",
  "weline", "piso", "piline", "length", "leline", "sequence", "seqcont",
  "conlines", "conline1", "conline2", "contxt", "seqhead", "origin",
  "orline", "ortxt", "seqdata", "seqline", "seqlist", "end", 0
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
     305,   306,   307,   308
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    56,    57,    58,    59,
      60,    61,    62,    62,    62,    63,    63,    63,    63,    64,
      64,    65,    65,    66,    67,    68,    69,    69,    70,    71,
      72,    72,    73,    73,    74,    74,    75,    76,    77,    77,
      78,    78,    79,    80,    80,    81,    81,    82,    82,    82,
      82,    82,    83,    84,    85,    85,    86,    87,    88,    88,
      89,    90,    90,    91,    92,    93,    93,    94,    94,    94,
      95,    95,    96,    96,    97,    97,    98,    98,    99,   100,
     100,   100,   100,   101,   101,   102,   103,   103,   104,   104,
     104,   104,   105,   106,   106,   107,   108,   109,   109,   110,
     111,   111,   112,   113,   114,   114,   115,   115,   116,   117,
     118,   118,   119,   120,   121,   121,   122,   122,   123,   123,
     124,   125,   126,   126,   127,   127,   128,   128,   129,   130,
     131,   131,   132,   132,   133,   133,   134,   135,   136,   136,
     137,   137,   138,   138,   139,   140,   141,   141,   142,   142,
     143,   144,   144,   145,   145,   146,   147,   147,   148,   148,
     149,   149,   150,   151,   152,   152,   153,   153,   154,   154,
     155,   156,   157,   157,   158,   158,   159,   159,   160,   161,
     162,   162,   163,   163,   164,   164,   165,   166,   167,   167,
     168,   168,   169,   170,   170,   171,   172,   173,   173,   174,
     175,   176,   177,   177,   178,   179,   179,   180,   181,   182,
     182,   183,   184,   185,   186,   186,   187,   187,   188,   189,
     189,   190
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     1,     1,     1,    12,    11,    12,
       1,     4,     2,     1,     0,     3,     1,     1,     0,     2,
       0,     4,     3,     3,     3,     4,     2,     1,     1,     3,
       2,     1,     2,     0,     2,     0,     3,     3,     3,     1,
       1,     0,     4,     3,     1,     3,     0,     2,     1,     2,
       1,     1,     1,     3,     2,     1,     1,     3,     2,     1,
       2,     2,     0,     3,     3,     2,     1,     3,     1,     0,
       2,     0,     4,     3,     4,     3,     4,     3,     4,     3,
       3,     1,     1,     1,     0,     3,     2,     1,     2,     1,
       1,     0,     2,     2,     0,     3,     3,     2,     1,     2,
       2,     0,     3,     3,     2,     1,     2,     0,     8,     2,
       2,     0,     3,     3,     2,     1,     2,     0,     2,     0,
       3,     3,     2,     1,     2,     0,     2,     0,     3,     3,
       2,     1,     2,     0,     2,     0,     3,     3,     2,     1,
       2,     0,     2,     0,     3,     3,     2,     1,     1,     0,
       3,     2,     1,     1,     0,     3,     2,     1,     2,     0,
       2,     0,     3,     3,     2,     1,     2,     0,     2,     0,
       3,     3,     2,     0,     2,     0,     2,     0,     3,     3,
       2,     1,     2,     0,     2,     0,     3,     3,     2,     1,
       1,     0,     3,     2,     1,     1,     3,     1,     0,     3,
       1,     3,     1,     2,     2,     2,     0,     3,     3,     2,
       1,     1,     1,     3,     2,     0,     2,     1,     5,     3,
       1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     0,     4,     5,     6,    18,    10,
      14,     1,   215,     0,     0,   202,   206,     0,   211,   212,
       0,    33,    17,    16,    13,     0,     0,   210,     0,     0,
       2,   204,     0,   203,   217,     0,    27,     0,     0,     0,
      33,    28,    41,    35,     0,    11,    12,   213,   214,   207,
     209,   221,     0,   205,     0,   216,    22,    23,     0,    26,
      31,     0,    39,     0,    41,     0,    69,    40,    32,     0,
      19,    15,     0,     0,    21,    29,    30,    36,     0,    69,
      44,    46,     0,     0,     0,     0,    69,    48,    52,    50,
      56,    51,    62,    84,    68,    71,     0,    34,     0,   208,
     220,     0,    38,    91,     0,     0,     0,    55,     0,    59,
       0,    66,     0,     0,    81,    82,     0,    84,    47,    49,
      60,     0,    91,    83,     0,     0,    24,     0,   218,     0,
       0,     0,   167,    89,    94,    90,   101,    43,     0,    42,
      53,    54,    57,    58,    63,    65,    73,    75,     0,     0,
       0,    91,     0,    61,    87,     0,   107,     0,    70,    67,
      37,    25,   219,    98,     0,   105,     0,   173,     0,   169,
      88,    92,    99,    45,    79,    80,    72,    74,   107,     0,
      85,    86,   167,     0,    95,    97,   102,   104,     0,     0,
     198,   195,   166,     0,    93,     0,   100,   167,    64,     0,
     106,   117,   111,   175,    77,     0,     0,   170,   172,     0,
       0,     0,   197,   173,   168,     0,     0,   175,   115,     0,
       0,   125,   119,   109,     0,   183,   177,    78,    76,   196,
       0,     0,     8,   200,     0,    96,   103,   183,   112,   114,
     123,     0,     0,   133,   127,   116,     0,   110,   181,     0,
       0,   191,   185,   174,   199,     0,   171,     9,   120,   122,
     131,     0,     0,   141,   135,   124,     0,   118,     0,   178,
     180,   189,     0,     0,     7,   190,   182,     0,   176,   201,
     128,   130,   139,     0,     0,   149,   143,   132,     0,   126,
       0,   113,   186,   188,   194,     0,     0,   184,     0,   136,
     138,   147,     0,     0,   154,   148,   140,     0,   134,     0,
     121,   192,   193,     0,   179,   144,   146,   152,     0,     0,
     159,   153,     0,   142,     0,   129,   187,   150,   151,   157,
       0,     0,   108,   161,     0,   137,   155,   156,   165,     0,
     158,   145,   162,   164,     0,   160,     0,   163
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,     9,    25,    21,
      44,    22,    23,    70,    71,    37,    40,    41,    61,    42,
      68,    43,    97,    63,    66,    67,    81,   106,    86,    87,
      88,   108,    89,    90,   110,    91,   120,    92,   153,   112,
      93,   124,    94,    95,   158,   159,   116,   122,   123,   155,
     132,   133,   171,   134,   194,   164,   135,   172,   136,   196,
     166,   182,   200,   201,   223,   202,   247,   219,   221,   245,
     222,   267,   241,   243,   265,   244,   289,   261,   263,   287,
     264,   308,   283,   285,   306,   286,   323,   302,   304,   305,
     318,   320,   321,   330,   332,   340,   333,   345,   339,   168,
     192,   169,   214,   188,   225,   253,   226,   278,   249,   251,
     276,   252,   297,   272,   274,   275,   295,   190,   191,   211,
     212,   232,   233,    14,    15,    31,    16,    53,    28,    17,
      18,    19,    26,    33,    34,   101,    30
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -181
static const yytype_int16 yypact[] =
{
      84,  -181,    -5,    87,   -41,  -181,  -181,  -181,    90,  -181,
     110,  -181,  -181,   108,    72,  -181,  -181,    73,  -181,  -181,
      -6,    95,  -181,   118,  -181,     0,     3,  -181,    11,   124,
    -181,   120,   125,    73,  -181,   126,  -181,     1,   119,   111,
     114,  -181,   113,  -181,   127,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,   108,  -181,   128,  -181,  -181,  -181,   133,  -181,
    -181,    19,  -181,    99,   113,   117,    91,  -181,   131,   123,
    -181,  -181,    20,    89,  -181,  -181,  -181,  -181,   122,   115,
     135,   136,   132,   134,   137,   -10,   115,   129,  -181,   121,
    -181,  -181,  -181,   130,  -181,  -181,   111,  -181,     4,  -181,
    -181,    97,  -181,    53,   139,   138,   146,  -181,    22,  -181,
      23,  -181,    24,   148,  -181,  -181,    85,   130,  -181,  -181,
     144,   140,    53,  -181,   149,   106,  -181,   151,  -181,   104,
     145,   150,   141,   142,  -181,  -181,  -181,  -181,   143,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,    81,   156,
     161,    53,   137,  -181,  -181,    25,  -181,    93,  -181,  -181,
    -181,  -181,  -181,  -181,    27,  -181,    28,  -181,   147,  -181,
    -181,   157,   158,  -181,  -181,  -181,  -181,  -181,  -181,    31,
    -181,  -181,    57,    92,  -181,  -181,  -181,  -181,    36,   162,
     152,  -181,   160,   145,  -181,   150,  -181,    57,  -181,   159,
    -181,   153,  -181,   154,  -181,   167,   168,  -181,  -181,   170,
     169,   155,  -181,  -181,  -181,    39,    40,   154,  -181,    42,
     164,   165,  -181,   166,   171,   163,  -181,  -181,  -181,  -181,
     175,   174,  -181,  -181,    43,  -181,  -181,   163,  -181,  -181,
    -181,    44,   172,   173,  -181,   178,   159,  -181,  -181,    45,
     176,   177,  -181,   179,  -181,   187,  -181,  -181,  -181,  -181,
    -181,    47,   181,   180,  -181,   183,   164,  -181,    48,  -181,
    -181,  -181,    51,   182,  -181,  -181,   184,   171,  -181,  -181,
    -181,  -181,  -181,    56,   185,   186,  -181,   188,   172,  -181,
      59,  -181,  -181,  -181,  -181,    60,   176,  -181,    62,  -181,
    -181,  -181,    63,   189,   190,  -181,   192,   181,  -181,    64,
    -181,  -181,  -181,    65,  -181,  -181,  -181,  -181,    67,   191,
     193,  -181,   185,  -181,    68,  -181,  -181,  -181,  -181,  -181,
      71,   195,  -181,  -181,    76,  -181,  -181,  -181,  -181,    79,
     197,  -181,  -181,  -181,   195,  -181,    80,  -181
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,   112,  -181,  -181,  -181,   196,
    -181,  -181,  -181,    86,   116,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,   194,  -181,  -181,   198,  -181,  -181,  -181,    54,
      26,  -181,  -181,  -181,  -181,  -181,    52,    94,  -181,  -181,
    -122,  -181,  -181,  -181,  -181,    21,    82,  -181,  -181,  -181,
      17,    35,  -181,  -181,  -181,  -181,  -181,   -30,  -181,  -181,
    -181,  -181,   -49,  -181,  -181,  -181,  -181,   -69,  -181,  -181,
    -181,  -181,   -87,  -181,  -181,  -181,  -181,  -101,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -121,  -180,
    -181,  -181,  -181,    13,     7,  -181,  -181,  -181,   -50,    -9,
    -181,  -181,  -181,   -67,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,   199,  -181,
    -181,  -181,  -181,  -181,   200,  -181,  -181
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -21
static const yytype_int16 yytable[] =
{
     156,   113,   203,    45,    57,    35,    47,   126,    12,    13,
      10,    36,    58,    46,    49,   127,    48,   217,    59,   114,
     115,    59,    75,    99,    50,   140,   142,   144,   180,   178,
     184,   186,    76,    50,   198,   141,   143,   145,   181,   207,
     185,   187,   235,   236,   145,   238,   256,   258,   269,   208,
     280,   291,   185,   187,   292,   239,   208,   259,   270,   299,
     281,   239,   310,   311,   293,   314,   315,   325,   326,   300,
     327,   335,   259,   312,   336,   270,   316,   281,   293,   341,
     328,   300,   342,   347,   337,   130,   131,    11,   147,   316,
       1,   199,   343,   343,   148,   204,   149,   150,     2,   167,
     128,   148,    77,   205,   206,   103,    20,   129,    78,   160,
     174,   175,   117,    38,    39,    78,    82,    83,    84,    85,
      24,    27,   114,   115,    32,    29,   -20,    51,    52,    56,
      54,    62,    60,    39,    65,    69,    74,    80,    73,    96,
      36,   100,   102,    85,   104,   107,   105,   109,    84,   139,
     111,   146,   152,   154,   161,    83,   162,   157,   163,   176,
     138,   121,   137,   165,   177,   193,   195,   173,   213,   209,
     227,   228,   218,   229,   246,   131,   230,   240,   254,   255,
      79,    98,   125,   167,   248,   260,   266,   277,   220,   271,
     279,   288,   296,   189,   282,   294,   307,   224,   301,   210,
     322,   242,   317,   231,   329,   344,   179,   250,   338,   183,
     262,   151,   216,   197,   215,   170,   268,   290,   284,   309,
     324,   334,   273,   346,   237,   303,   234,   298,   257,   313,
     319,     0,     0,    55,   331,     0,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    72,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   118,     0,     0,     0,     0,     0,   119
};

static const yytype_int16 yycheck[] =
{
     122,    11,   182,     3,     3,    11,     3,     3,    49,    50,
      15,    17,    11,    13,     3,    11,    13,   197,    17,    29,
      30,    17,     3,     3,    13,     3,     3,     3,     3,   151,
       3,     3,    13,    13,     3,    13,    13,    13,    13,     3,
      13,    13,     3,     3,    13,     3,     3,     3,     3,    13,
       3,     3,    13,    13,     3,    13,    13,    13,    13,     3,
      13,    13,     3,     3,    13,     3,     3,     3,     3,    13,
       3,     3,    13,    13,     3,    13,    13,    13,    13,     3,
      13,    13,     3,     3,    13,    32,    33,     0,     3,    13,
       6,    34,    13,    13,     9,     3,    11,    12,    14,    42,
       3,     9,     3,    11,    12,    79,    16,    10,     9,     3,
      29,    30,    86,    18,    19,     9,    25,    26,    27,    28,
      10,    13,    29,    30,    51,    53,     8,     3,     8,     3,
       5,    20,    13,    19,    21,     8,     3,    20,    10,     8,
      17,    52,    20,    28,     9,    13,    10,    13,    27,     3,
      13,     3,     8,    13,     3,    26,    52,     8,    13,     3,
      22,    31,    23,    13,     3,     8,     8,    24,     8,     7,
       3,     3,    13,     3,     8,    33,     7,    13,     3,     5,
      64,    69,    96,    42,    13,    13,     8,     8,    35,    13,
       3,     8,     8,    46,    13,    13,     8,    43,    13,    47,
       8,    36,    13,    48,    13,     8,   152,    44,    13,   157,
      37,   117,   195,   178,   193,   133,   246,   266,    38,   288,
     307,   322,    45,   344,   217,    39,   213,   277,   237,   296,
      40,    -1,    -1,    33,    41,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    89
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    14,    55,    56,    57,    58,    59,    60,    61,
      15,     0,    49,    50,   177,   178,   180,   183,   184,   185,
      16,    63,    65,    66,    10,    62,   186,    13,   182,    53,
     190,   179,    51,   187,   188,    11,    17,    69,    18,    19,
      70,    71,    73,    75,    64,     3,    13,     3,    13,     3,
      13,     3,     8,   181,     5,   188,     3,     3,    11,    17,
      13,    72,    20,    77,    73,    21,    78,    79,    74,     8,
      67,    68,   182,    10,     3,     3,    13,     3,     9,    78,
      20,    80,    25,    26,    27,    28,    82,    83,    84,    86,
      87,    89,    91,    94,    96,    97,     8,    76,    69,     3,
      52,   189,    20,    94,     9,    10,    81,    13,    85,    13,
      88,    13,    93,    11,    29,    30,   100,    94,    86,    89,
      90,    31,   101,   102,    95,    77,     3,    11,     3,    10,
      32,    33,   104,   105,   107,   110,   112,    23,    22,     3,
       3,    13,     3,    13,     3,    13,     3,     3,     9,    11,
      12,   101,     8,    92,    13,   103,   104,     8,    98,    99,
       3,     3,    52,    13,   109,    13,   114,    42,   153,   155,
     110,   106,   111,    24,    29,    30,     3,     3,   104,    93,
       3,    13,   115,   100,     3,    13,     3,    13,   157,    46,
     171,   172,   154,     8,   108,     8,   113,   115,     3,    34,
     116,   117,   119,   153,     3,    11,    12,     3,    13,     7,
      47,   173,   174,     8,   156,   109,   114,   153,    13,   121,
      35,   122,   124,   118,    43,   158,   160,     3,     3,     3,
       7,    48,   175,   176,   157,     3,     3,   158,     3,    13,
      13,   126,    36,   127,   129,   123,     8,   120,    13,   162,
      44,   163,   165,   159,     3,     5,     3,   163,     3,    13,
      13,   131,    37,   132,   134,   128,     8,   125,   121,     3,
      13,    13,   167,    45,   168,   169,   164,     8,   161,     3,
       3,    13,    13,   136,    38,   137,   139,   133,     8,   130,
     126,     3,     3,    13,    13,   170,     8,   166,   162,     3,
      13,    13,   141,    39,   142,   143,   138,     8,   135,   131,
       3,     3,    13,   167,     3,     3,    13,    13,   144,    40,
     145,   146,     8,   140,   136,     3,     3,     3,    13,    13,
     147,    41,   148,   150,   141,     3,     3,    13,    13,   152,
     149,     3,     3,    13,     8,   151,   152,     3
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
#line 68 "genbanky.y"
    { return 0;  /*NOTREACHED*/ }
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 69 "genbanky.y"
    { return -1; /*NOTREACHED*/ }
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 78 "genbanky.y"
    { parse_namadd(seq, (yyvsp[(2) - (4)].str)); }
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 88 "genbanky.y"
    { parse_dscadd2(seq, (yyvsp[(2) - (2)].str)); }
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 89 "genbanky.y"
    { parse_dscadd1(seq, (yyvsp[(1) - (1)].str)); }
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 100 "genbanky.y"
    { parse_accadd(seq, (yyvsp[(3) - (3)].str)); }
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 101 "genbanky.y"
    { parse_accadd(seq, (yyvsp[(1) - (1)].str)); }
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 106 "genbanky.y"
    { parse_veradd(seq, (yyvsp[(3) - (3)].num)); }
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 109 "genbanky.y"
    { parse_giadd(seq, (yyvsp[(3) - (3)].num)); }
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 135 "genbanky.y"
    { parse_kwdadd(seq, (yyvsp[(3) - (3)].str)); }
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 136 "genbanky.y"
    { parse_kwdupd(seq, (yyvsp[(3) - (3)].str)); }
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 137 "genbanky.y"
    { parse_kwdadd(seq, (yyvsp[(1) - (1)].str)); }
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 138 "genbanky.y"
    { parse_kwdupd(seq, (yyvsp[(1) - (1)].str)); }
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 253 "genbanky.y"
    { parse_stradd(seq, (yyvsp[(3) - (3)].str)); }
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 254 "genbanky.y"
    { parse_stradd(seq, (yyvsp[(1) - (1)].str)); }
    break;



/* Line 1464 of yacc.c  */
#line 1923 "sequence/genbanky.c"
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
#line 259 "genbanky.y"



/* Check GENBANK sequence */
int genbanky_check(FILE *f) {
  extern FILE *genbankin;
  int i;

  genbankin = f;

  i = yyparse(NULL);

  return i; }


/* Parse GENBANK sequence */
sequence_t *genbanky_parse(FILE *f) {
  extern FILE *genbankin;
  int i;
  sequence_t *seq;

  genbankin = f;

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

