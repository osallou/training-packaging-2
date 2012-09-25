/* rawl.l - RAW sequence lexer */

%{
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif

#include "sequence/rawy.h"

#undef  YY_DECL
#define YY_DECL int yylex(YYSTYPE *yylval)
%}

%option never-interactive
%option nounput noyywrap

alp            [[:alpha:]]
blk            [[:blank:]]
eol            "\n"
min            "-"
spc            " "
sta            "*"
tab            "\t"

gap            {min}
bas            ({alp}|{gap}|{sta}){1,80}

%%

{eol}          ; /* Newlines ignored */
{blk}          ; /* Spaces/Tabs ignored */

{bas}          { yylval->str = strdup(yytext); return BAS; }

<<EOF>>        { return NUL; }
.              { return ERR; }

%%
