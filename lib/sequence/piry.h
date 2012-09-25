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

/* Line 1685 of yacc.c  */
#line 26 "piry.y"
 char *str; 


/* Line 1685 of yacc.c  */
#line 127 "sequence/piry.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif




