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

/* Line 1685 of yacc.c  */
#line 26 "embly.y"
 char *str; int num; 


/* Line 1685 of yacc.c  */
#line 173 "sequence/embly.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif




