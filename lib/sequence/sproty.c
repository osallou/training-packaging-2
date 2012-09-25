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
#define yyparse         sprotparse
#define yylex           sprotlex
#define yyerror         sproterror
#define yylval          sprotlval
#define yychar          sprotchar
#define yydebug         sprotdebug
#define yynerrs         sprotnerrs


/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 3 "sproty.y"

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
#endif

#include "sequence.h"
#include "sequence/parse.h"
#include "sequence/sproty.h"

int yylex(YYSTYPE *);
static void yyerror(sequence_t *seq, const char *);

int sproty_check(FILE *);
sequence_t *sproty_parse(FILE *);


/* Line 189 of yacc.c  */
#line 101 "sequence/sproty.c"

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
     EQU = 259,
     ERR = 260,
     INT = 261,
     NUL = 262,
     QUO = 263,
     SEP = 264,
     SPC = 265,
     TER = 266,
     TER2 = 267,
     TER3 = 268,
     TXT = 269,
     CBR = 270,
     OBR = 271,
     ID = 272,
     IDNAM = 273,
     AC = 274,
     ACNUM = 275,
     DT = 276,
     DE = 277,
     DETXT = 278,
     GN = 279,
     OS = 280,
     OSTXT = 281,
     OSTX2 = 282,
     OG = 283,
     OC = 284,
     OCNOD = 285,
     OX = 286,
     OH = 287,
     RN = 288,
     RP = 289,
     RC = 290,
     RX = 291,
     RXKEY = 292,
     RXVAL = 293,
     RG = 294,
     RA = 295,
     RAAUT = 296,
     RT = 297,
     RL = 298,
     CC = 299,
     DR = 300,
     DRVAL = 301,
     DRVAL2 = 302,
     PE = 303,
     KW = 304,
     KWORD = 305,
     FT = 306,
     SQ = 307,
     SEQ = 308,
     SEQBAS = 309,
     END = 310
   };
#endif
/* Tokens.  */
#define EOL 258
#define EQU 259
#define ERR 260
#define INT 261
#define NUL 262
#define QUO 263
#define SEP 264
#define SPC 265
#define TER 266
#define TER2 267
#define TER3 268
#define TXT 269
#define CBR 270
#define OBR 271
#define ID 272
#define IDNAM 273
#define AC 274
#define ACNUM 275
#define DT 276
#define DE 277
#define DETXT 278
#define GN 279
#define OS 280
#define OSTXT 281
#define OSTX2 282
#define OG 283
#define OC 284
#define OCNOD 285
#define OX 286
#define OH 287
#define RN 288
#define RP 289
#define RC 290
#define RX 291
#define RXKEY 292
#define RXVAL 293
#define RG 294
#define RA 295
#define RAAUT 296
#define RT 297
#define RL 298
#define CC 299
#define DR 300
#define DRVAL 301
#define DRVAL2 302
#define PE 303
#define KW 304
#define KWORD 305
#define FT 306
#define SQ 307
#define SEQ 308
#define SEQBAS 309
#define END 310




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 26 "sproty.y"
 char *str; 


/* Line 214 of yacc.c  */
#line 251 "sequence/sproty.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 263 "sequence/sproty.c"

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
#define YYLAST   216

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  115
/* YYNRULES -- Number of rules.  */
#define YYNRULES  181
/* YYNRULES -- Number of states.  */
#define YYNSTATES  295

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

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
      55
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     9,    22,    24,    29,    32,    34,
      37,    38,    43,    47,    49,    53,    54,    58,    61,    63,
      66,    69,    70,    73,    74,    78,    83,    87,    90,    92,
      95,    96,   100,   103,   105,   111,   114,   116,   117,   120,
     122,   125,   127,   130,   133,   136,   139,   140,   144,   149,
     154,   159,   161,   163,   166,   167,   171,   174,   176,   179,
     180,   183,   184,   189,   194,   198,   200,   203,   204,   208,
     211,   213,   216,   217,   221,   224,   226,   229,   230,   238,
     241,   243,   245,   247,   253,   256,   259,   260,   264,   269,
     272,   274,   277,   278,   282,   285,   287,   289,   291,   292,
     295,   297,   302,   307,   311,   313,   317,   321,   324,   327,
     328,   332,   337,   340,   342,   345,   348,   349,   354,   359,
     363,   365,   369,   371,   372,   375,   376,   383,   388,   392,
     398,   401,   403,   406,   407,   410,   411,   415,   420,   423,
     425,   428,   429,   433,   436,   438,   441,   442,   447,   454,
     459,   462,   463,   465,   466,   471,   474,   476,   479,   480,
     483,   484,   489,   494,   498,   500,   501,   504,   505,   509,
     512,   514,   517,   519,   523,   526,   528,   531,   533,   537,
     541,   543
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      57,     0,    -1,    58,   163,   170,    -1,     7,    -1,    59,
      62,    65,    68,    73,    76,   103,   145,   148,   152,   155,
     160,    -1,    60,    -1,    17,    18,    61,     3,    -1,    61,
      14,    -1,    10,    -1,    62,    63,    -1,    -1,    19,    64,
      11,     3,    -1,    64,     9,    20,    -1,    20,    -1,    66,
      66,    66,    -1,    -1,    21,    67,     3,    -1,    67,    14,
      -1,    14,    -1,    69,    71,    -1,    69,    70,    -1,    -1,
      69,    70,    -1,    -1,    22,    72,     3,    -1,    22,    72,
      11,     3,    -1,    22,    11,     3,    -1,    72,    23,    -1,
      23,    -1,    73,    74,    -1,    -1,    24,    75,     3,    -1,
      75,    14,    -1,    14,    -1,    77,    89,    92,    97,   100,
      -1,    78,    82,    -1,    82,    -1,    -1,    79,    81,    -1,
      81,    -1,    79,    80,    -1,    80,    -1,    83,    85,    -1,
      83,    86,    -1,    83,    87,    -1,    83,    84,    -1,    -1,
      25,    88,     3,    -1,    25,    88,    13,     3,    -1,    25,
      88,    12,     3,    -1,    25,    88,    11,     3,    -1,    26,
      -1,    27,    -1,    89,    90,    -1,    -1,    28,    91,     3,
      -1,    91,    14,    -1,    14,    -1,    93,    95,    -1,    -1,
      93,    94,    -1,    -1,    29,    96,    12,     3,    -1,    29,
      96,    11,     3,    -1,    96,     9,    30,    -1,    30,    -1,
      97,    98,    -1,    -1,    31,    99,     3,    -1,    99,    14,
      -1,    14,    -1,   100,   101,    -1,    -1,    32,   102,     3,
      -1,   102,    14,    -1,    14,    -1,   103,   104,    -1,    -1,
     106,   108,   113,   116,   105,   133,   140,    -1,   123,   128,
      -1,   123,    -1,   128,    -1,   107,    -1,    33,    16,     6,
      15,     3,    -1,   109,   111,    -1,   109,   110,    -1,    -1,
      34,   112,     3,    -1,    34,   112,    11,     3,    -1,   112,
      14,    -1,    14,    -1,   113,   114,    -1,    -1,    35,   115,
       3,    -1,   115,    14,    -1,    14,    -1,   117,    -1,   119,
      -1,    -1,   117,   118,    -1,   118,    -1,    36,   120,    11,
       3,    -1,    36,   122,    12,     3,    -1,   120,     9,   121,
      -1,   121,    -1,    37,     4,    38,    -1,    37,     9,    38,
      -1,   124,   126,    -1,   124,   125,    -1,    -1,    39,   127,
       3,    -1,    39,   127,    11,     3,    -1,   127,    14,    -1,
      14,    -1,   129,   131,    -1,   129,   130,    -1,    -1,    40,
     132,    12,     3,    -1,    40,   132,    11,     3,    -1,   132,
       9,    41,    -1,    41,    -1,   136,   134,   138,    -1,   135,
      -1,    -1,   134,   137,    -1,    -1,    42,     8,   139,     8,
      11,     3,    -1,    42,     8,   139,     3,    -1,    42,   139,
       3,    -1,    42,   139,     8,    11,     3,    -1,   139,    14,
      -1,    14,    -1,   141,   143,    -1,    -1,   141,   142,    -1,
      -1,    43,   144,     3,    -1,    43,   144,    11,     3,    -1,
     144,    14,    -1,    14,    -1,   145,   146,    -1,    -1,    44,
     147,     3,    -1,   147,    14,    -1,    14,    -1,   148,   149,
      -1,    -1,    45,   150,    11,     3,    -1,    46,     9,    46,
       9,    46,   151,    -1,     9,    46,     9,    46,    -1,     9,
      46,    -1,    -1,   153,    -1,    -1,    48,   154,    11,     3,
      -1,   154,    14,    -1,    14,    -1,   156,   158,    -1,    -1,
     156,   157,    -1,    -1,    49,   159,    12,     3,    -1,    49,
     159,    11,     3,    -1,   159,     9,    50,    -1,    50,    -1,
      -1,   160,   161,    -1,    -1,    51,   162,     3,    -1,   162,
      14,    -1,    14,    -1,   164,   167,    -1,   165,    -1,    52,
     166,     3,    -1,   166,    14,    -1,    14,    -1,   167,   168,
      -1,   168,    -1,    53,   169,     3,    -1,   169,    10,    54,
      -1,    54,    -1,    55,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    67,    67,    68,    71,    73,    74,    76,    76,    78,
      78,    79,    80,    81,    84,    84,    85,    86,    86,    88,
      88,    88,    89,    89,    90,    91,    91,    92,    93,    96,
      96,    97,    98,    98,   100,   102,   102,   102,   103,   103,
     104,   104,   105,   106,   107,   108,   108,   109,   110,   111,
     112,   113,   113,   115,   115,   116,   117,   117,   119,   119,
     120,   120,   121,   122,   123,   123,   125,   125,   126,   127,
     127,   129,   129,   130,   131,   131,   133,   133,   134,   135,
     135,   135,   137,   138,   140,   141,   141,   142,   143,   144,
     144,   146,   146,   147,   148,   148,   150,   150,   150,   151,
     151,   152,   153,   154,   154,   155,   156,   158,   159,   159,
     160,   161,   162,   162,   164,   165,   165,   166,   167,   168,
     168,   170,   170,   170,   171,   171,   172,   173,   174,   175,
     176,   176,   178,   178,   179,   179,   180,   181,   182,   182,
     184,   184,   185,   186,   186,   188,   188,   189,   190,   191,
     191,   191,   193,   193,   194,   195,   195,   197,   197,   198,
     198,   199,   200,   201,   202,   203,   206,   206,   207,   208,
     208,   210,   212,   213,   214,   214,   216,   216,   217,   218,
     219,   222
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EOL", "EQU", "ERR", "INT", "NUL", "QUO",
  "SEP", "SPC", "TER", "TER2", "TER3", "TXT", "CBR", "OBR", "ID", "IDNAM",
  "AC", "ACNUM", "DT", "DE", "DETXT", "GN", "OS", "OSTXT", "OSTX2", "OG",
  "OC", "OCNOD", "OX", "OH", "RN", "RP", "RC", "RX", "RXKEY", "RXVAL",
  "RG", "RA", "RAAUT", "RT", "RL", "CC", "DR", "DRVAL", "DRVAL2", "PE",
  "KW", "KWORD", "FT", "SQ", "SEQ", "SEQBAS", "END", "$accept", "sprot",
  "annots", "locus", "idline", "idtxt", "access", "acline", "aclist",
  "date", "dtline", "dttxt", "desc", "delines", "deline1", "deline2",
  "detxt", "gene", "gnline", "gntxt", "orga", "orgspe", "osents", "osentt",
  "osent1", "osent2", "osent3", "oslines", "osline", "osline1", "osline2",
  "osline3", "ostxt", "orggan", "ogline", "ogtxt", "orgcla", "oclines",
  "ocline1", "ocline2", "oclist", "orgtax", "oxline", "oxtxt", "orghos",
  "ohline", "ohtxt", "refs", "refent", "refper", "refnum", "rnline",
  "refpos", "rplines", "rpline1", "rpline2", "rptxt", "refcom", "rcline",
  "rctxt", "refxdb", "rxlines", "rxline", "rxline1", "rxlist", "rxent",
  "rxent1", "refgrp", "rglines", "rgline1", "rgline2", "rgtxt", "refaut",
  "ralines", "raline1", "raline2", "ralist", "reftit", "rtlines", "rtline",
  "rtline1", "rtline2", "rtline3", "rttxt", "refloc", "rllines", "rlline1",
  "rlline2", "rltxt", "comm", "ccline", "cctxt", "dbref", "drline",
  "drlist", "dropt", "exist", "peline", "petxt", "kwrds", "kwlines",
  "kwline1", "kwline2", "kwlist", "feats", "ftline", "fttxt", "sequence",
  "seqhead", "sqline", "sqtxt", "seqdata", "seqline", "seqlist", "end", 0
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
     305,   306,   307,   308,   309,   310
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    57,    58,    59,    60,    61,    61,    62,
      62,    63,    64,    64,    65,    65,    66,    67,    67,    68,
      68,    68,    69,    69,    70,    71,    71,    72,    72,    73,
      73,    74,    75,    75,    76,    77,    77,    77,    78,    78,
      79,    79,    80,    81,    82,    83,    83,    84,    85,    86,
      87,    88,    88,    89,    89,    90,    91,    91,    92,    92,
      93,    93,    94,    95,    96,    96,    97,    97,    98,    99,
      99,   100,   100,   101,   102,   102,   103,   103,   104,   105,
     105,   105,   106,   107,   108,   109,   109,   110,   111,   112,
     112,   113,   113,   114,   115,   115,   116,   116,   116,   117,
     117,   118,   119,   120,   120,   121,   122,   123,   124,   124,
     125,   126,   127,   127,   128,   129,   129,   130,   131,   132,
     132,   133,   133,   133,   134,   134,   135,   136,   137,   138,
     139,   139,   140,   140,   141,   141,   142,   143,   144,   144,
     145,   145,   146,   147,   147,   148,   148,   149,   150,   151,
     151,   151,   152,   152,   153,   154,   154,   155,   155,   156,
     156,   157,   158,   159,   159,   159,   160,   160,   161,   162,
     162,   163,   164,   165,   166,   166,   167,   167,   168,   169,
     169,   170
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,    12,     1,     4,     2,     1,     2,
       0,     4,     3,     1,     3,     0,     3,     2,     1,     2,
       2,     0,     2,     0,     3,     4,     3,     2,     1,     2,
       0,     3,     2,     1,     5,     2,     1,     0,     2,     1,
       2,     1,     2,     2,     2,     2,     0,     3,     4,     4,
       4,     1,     1,     2,     0,     3,     2,     1,     2,     0,
       2,     0,     4,     4,     3,     1,     2,     0,     3,     2,
       1,     2,     0,     3,     2,     1,     2,     0,     7,     2,
       1,     1,     1,     5,     2,     2,     0,     3,     4,     2,
       1,     2,     0,     3,     2,     1,     1,     1,     0,     2,
       1,     4,     4,     3,     1,     3,     3,     2,     2,     0,
       3,     4,     2,     1,     2,     2,     0,     4,     4,     3,
       1,     3,     1,     0,     2,     0,     6,     4,     3,     5,
       2,     1,     2,     0,     2,     0,     3,     4,     2,     1,
       2,     0,     3,     2,     1,     2,     0,     4,     6,     4,
       2,     0,     1,     0,     4,     2,     1,     2,     0,     2,
       0,     4,     4,     3,     1,     0,     2,     0,     3,     2,
       1,     2,     1,     3,     2,     1,     2,     1,     3,     3,
       1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     0,    10,     5,     0,     1,     0,
       0,     0,   172,    15,     8,     0,   175,     0,     0,     2,
       0,   171,   177,     0,     0,     9,    21,     0,     6,     7,
     173,   174,   181,   180,     0,   176,    13,     0,    18,     0,
      30,     0,     0,   178,     0,     0,     0,    16,    17,    37,
       0,    20,    19,    14,   179,    12,    11,     0,    29,    77,
      54,    46,    46,    41,    39,    36,     0,     0,    28,     0,
      33,     0,   141,    59,    35,     0,    40,    38,     0,     0,
      45,    42,    43,    44,    26,    24,     0,    27,    31,    32,
       0,    76,    86,    82,   146,     0,    53,    67,     0,     0,
       0,    51,    52,     0,    25,     0,    92,     0,     0,   140,
     153,    57,     0,    72,     0,    60,    58,     0,     0,    47,
       0,     0,     0,     0,    98,     0,    85,    84,   144,     0,
       0,     0,   145,   158,   152,    55,    56,     0,    66,    34,
      65,     0,    50,    49,    48,     0,     0,     0,    91,   109,
      96,   100,    97,    90,     0,   142,   143,     0,     0,   156,
       0,   167,     0,    70,     0,     0,    71,     0,     0,     0,
      83,    95,     0,     0,     0,   104,     0,   123,    80,     0,
      81,     0,     0,    99,    87,     0,    89,     0,     0,     0,
     155,     4,   165,   159,   157,    68,    69,    75,     0,    64,
      63,    62,    93,    94,     0,     0,     0,     0,     0,     0,
     133,   122,   125,    79,     0,   108,   107,     0,   115,   114,
       0,    88,     0,   147,   154,     0,   166,   164,     0,    73,
      74,   105,   106,   103,   101,   102,     0,    78,     0,     0,
     113,     0,   120,     0,     0,   170,     0,     0,     0,     0,
     131,     0,     0,   134,   132,     0,   124,   121,   110,     0,
     112,     0,     0,     0,   151,   168,   169,   163,   162,   161,
     127,     0,   130,   139,     0,     0,   111,   119,   118,   117,
       0,   148,     0,   136,     0,   138,   128,     0,   150,   126,
     137,     0,     0,   129,   149
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    15,    13,    25,    37,    26,
      27,    39,    40,    41,    51,    52,    69,    49,    58,    71,
      59,    60,    61,    62,    63,    64,    65,    66,    80,    81,
      82,    83,   103,    73,    96,   112,    97,    98,   115,   116,
     141,   113,   138,   164,   139,   166,   198,    72,    91,   177,
      92,    93,   106,   107,   126,   127,   154,   124,   148,   172,
     149,   150,   151,   152,   174,   175,   176,   178,   179,   215,
     216,   241,   180,   181,   218,   219,   243,   210,   239,   211,
     212,   256,   257,   251,   237,   238,   253,   254,   274,    94,
     109,   129,   110,   132,   158,   281,   133,   134,   160,   161,
     162,   193,   194,   228,   191,   226,   246,    10,    11,    12,
      17,    21,    22,    34,    19
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -66
static const yytype_int16 yypact[] =
{
      34,   -66,    42,    68,    12,   -66,   -66,    72,   -66,    73,
      17,    27,   -66,   -16,   -66,    10,   -66,    19,    93,   -66,
      43,    27,   -66,    56,    84,   -66,    77,    79,   -66,   -66,
     -66,   -66,   -66,   -66,    55,   -66,   -66,    -2,   -66,    22,
     -66,    80,    79,   -66,    47,    83,   101,   -66,   -66,    59,
      -9,    85,   -66,   -66,   -66,   -66,   -66,    91,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,    81,   105,   -66,    -3,
     -66,    23,    76,    60,   -66,    86,   -66,   -66,    87,    64,
     -66,   -66,   -66,   -66,   -66,   -66,   107,   -66,   -66,   -66,
      97,   -66,   -66,   -66,    71,   100,   -66,   -66,    88,    64,
      64,   -66,   -66,    41,   -66,   110,   -66,    89,   104,   -66,
       0,   -66,    26,    90,    92,   -66,   -66,    52,    44,   -66,
     116,   117,   121,   111,    50,   113,   -66,   -66,   -66,    28,
      82,   115,   -66,    94,   -66,   -66,   -66,   118,   -66,    98,
     -66,    58,   -66,   -66,   -66,   122,   119,    99,   -66,    95,
     102,   -66,   -66,   -66,     1,   -66,   -66,   125,   120,   -66,
      48,   -66,    96,   -66,    29,   123,   -66,   109,   137,   138,
     -66,   -66,    32,    57,    70,   -66,   130,   106,    95,   108,
     -66,   112,   114,   -66,   -66,   141,   -66,   103,   143,   147,
     -66,   124,   126,   -66,   -66,   -66,   -66,   -66,    35,   -66,
     -66,   -66,   -66,   -66,   127,   128,   114,   150,   151,   148,
     129,   -66,   -66,   -66,   144,   -66,   -66,   132,   -66,   -66,
     153,   -66,   146,   -66,   -66,   145,   -66,   -66,    62,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   149,   -66,   131,   135,
     -66,     7,   -66,    66,   133,   -66,    36,   134,   157,   158,
     -66,     3,   154,   -66,   -66,   149,   -66,   -66,   -66,   159,
     -66,   139,   161,   164,   160,   -66,   -66,   -66,   -66,   -66,
     -66,   167,   -66,   -66,    16,    20,   -66,   -66,   -66,   -66,
     136,   -66,   168,   -66,   178,   -66,   -66,   172,   176,   -66,
     -66,   183,   142,   -66,   -66
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -26,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   140,   152,   155,    31,   -66,   -66,
     -66,   -66,    -5,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,    37,   -66,   -66,   -36,   -66,   -66,   -66,   -66,
     -66,   -66,    11,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -65,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   170,   -66,   -66
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -161
static const yytype_int16 yytable[] =
{
      85,    42,    67,    23,   184,    24,   270,    45,    86,    46,
     258,   271,   185,    28,    68,   186,    53,   272,   259,   283,
      87,   260,    30,   286,    29,    47,    88,   284,   287,   135,
     285,   155,   195,    31,   272,   202,    48,    89,   229,   265,
     136,     1,   156,   196,   119,   130,   203,   119,   131,   230,
     266,     2,   120,   121,   122,   119,   121,   122,    43,   189,
       7,   204,   190,   120,     9,    44,   205,   167,     8,   168,
     169,   247,    18,   248,   249,   261,    36,   262,   263,   206,
      20,   207,    14,    57,   -46,   146,   147,    16,    95,   -61,
     101,   102,    75,    78,   117,   118,    32,    33,    38,   -23,
      24,    54,    50,    55,    56,    70,    79,   -22,    84,    90,
     104,    99,   100,   105,   111,   108,   123,   114,   128,   142,
     143,   137,   140,   125,   144,   170,   145,   153,   157,   159,
     165,   188,   163,   171,   187,  -116,   173,   197,   182,   199,
     200,   201,   208,  -160,   221,   192,   223,   214,   209,   222,
     224,   220,   217,   234,   235,   244,   236,   204,   240,   245,
     268,   269,   276,   250,   278,   231,   232,   279,   273,   280,
     233,   289,  -135,   242,   252,   225,   227,   255,   282,   264,
     277,   290,   288,   291,   267,   292,   293,   183,   294,   213,
     275,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,     0,    74
};

static const yytype_int16 yycheck[] =
{
       3,    27,    11,    19,     3,    21,     3,     9,    11,    11,
       3,     8,    11,     3,    23,    14,    42,    14,    11,     3,
      23,    14,     3,     3,    14,     3,     3,    11,     8,     3,
      14,     3,     3,    14,    14,     3,    14,    14,     3,     3,
      14,     7,    14,    14,     3,    45,    14,     3,    48,    14,
      14,    17,    11,    12,    13,     3,    12,    13,     3,    11,
      18,     4,    14,    11,    52,    10,     9,     9,     0,    11,
      12,     9,    55,    11,    12,     9,    20,    11,    12,     9,
      53,    11,    10,    24,    25,    35,    36,    14,    28,    29,
      26,    27,    61,    62,    99,   100,     3,    54,    14,    22,
      21,    54,    22,    20,     3,    14,    25,    22,     3,    33,
       3,    25,    25,    16,    14,    44,     6,    29,    14,     3,
       3,    31,    30,    34,     3,     3,    15,    14,    46,    14,
      32,    11,    14,    14,     9,    40,    37,    14,    36,    30,
       3,     3,    12,    49,     3,    49,     3,    39,    42,    46,
       3,    37,    40,     3,     3,     9,     8,     4,    14,    14,
       3,     3,     3,    14,     3,    38,    38,     3,    14,     9,
     206,     3,    43,    41,    43,    51,    50,    42,    11,    46,
      41,     3,    46,    11,    50,     9,     3,   150,    46,   178,
     255,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    61
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    17,    57,    58,    59,    60,    18,     0,    52,
     163,   164,   165,    62,    10,    61,    14,   166,    55,   170,
      53,   167,   168,    19,    21,    63,    65,    66,     3,    14,
       3,    14,     3,    54,   169,   168,    20,    64,    14,    67,
      68,    69,    66,     3,    10,     9,    11,     3,    14,    73,
      22,    70,    71,    66,    54,    20,     3,    24,    74,    76,
      77,    78,    79,    80,    81,    82,    83,    11,    23,    72,
      14,    75,   103,    89,    82,    83,    80,    81,    83,    25,
      84,    85,    86,    87,     3,     3,    11,    23,     3,    14,
      33,   104,   106,   107,   145,    28,    90,    92,    93,    25,
      25,    26,    27,    88,     3,    16,   108,   109,    44,   146,
     148,    14,    91,    97,    29,    94,    95,    88,    88,     3,
      11,    12,    13,     6,   113,    34,   110,   111,    14,   147,
      45,    48,   149,   152,   153,     3,    14,    31,    98,   100,
      30,    96,     3,     3,     3,    15,    35,    36,   114,   116,
     117,   118,   119,    14,   112,     3,    14,    46,   150,    14,
     154,   155,   156,    14,    99,    32,   101,     9,    11,    12,
       3,    14,   115,    37,   120,   121,   122,   105,   123,   124,
     128,   129,    36,   118,     3,    11,    14,     9,    11,    11,
      14,   160,    49,   157,   158,     3,    14,    14,   102,    30,
       3,     3,     3,    14,     4,     9,     9,    11,    12,    42,
     133,   135,   136,   128,    39,   125,   126,    40,   130,   131,
      37,     3,    46,     3,     3,    51,   161,    50,   159,     3,
      14,    38,    38,   121,     3,     3,     8,   140,   141,   134,
      14,   127,    41,   132,     9,    14,   162,     9,    11,    12,
      14,   139,    43,   142,   143,    42,   137,   138,     3,    11,
      14,     9,    11,    12,    46,     3,    14,    50,     3,     3,
       3,     8,    14,    14,   144,   139,     3,    41,     3,     3,
       9,   151,    11,     3,    11,    14,     3,     8,    46,     3,
       3,    11,     9,     3,    46
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
#line 67 "sproty.y"
    { return 0;  /*NOTREACHED*/ }
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 68 "sproty.y"
    { return -1; /*NOTREACHED*/ }
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 74 "sproty.y"
    { parse_namadd(seq, (yyvsp[(2) - (4)].str)); }
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 80 "sproty.y"
    { parse_accadd(seq, (yyvsp[(3) - (3)].str)); }
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 81 "sproty.y"
    { parse_accadd(seq, (yyvsp[(1) - (1)].str)); }
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 92 "sproty.y"
    { parse_dscadd2(seq, (yyvsp[(2) - (2)].str)); }
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 93 "sproty.y"
    { parse_dscadd1(seq, (yyvsp[(1) - (1)].str)); }
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 201 "sproty.y"
    { parse_kwdadd(seq, (yyvsp[(3) - (3)].str)); }
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 202 "sproty.y"
    { parse_kwdadd(seq, (yyvsp[(1) - (1)].str)); }
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 218 "sproty.y"
    { parse_stradd(seq, (yyvsp[(3) - (3)].str)); }
    break;

  case 180:

/* Line 1464 of yacc.c  */
#line 219 "sproty.y"
    { parse_stradd(seq, (yyvsp[(1) - (1)].str)); }
    break;



/* Line 1464 of yacc.c  */
#line 1839 "sequence/sproty.c"
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
#line 224 "sproty.y"



/* Check SPROT sequence */
int sproty_check(FILE *f) {
  extern FILE *sprotin;
  int i;

  sprotin = f;

  i = yyparse(NULL);

  return i; }


/* Parse SPROT sequence */
sequence_t *sproty_parse(FILE *f) {
  extern FILE *sprotin;
  int i;
  sequence_t *seq;

  sprotin = f;

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

