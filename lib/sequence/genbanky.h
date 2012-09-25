/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1685 of yacc.c  */
#line 26 "genbanky.y"
 char *str; int num; 


/* Line 1685 of yacc.c  */
#line 161 "sequence/genbanky.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif




