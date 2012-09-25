/* igl.l - IG sequence lexer */

%{
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif

#include "sequence/igy.h"

#undef  YY_DECL
#define YY_DECL int yylex(YYSTYPE *yylval)
%}

%option never-interactive
%option nounput noyywrap

%x HCOM HNAM SEQS

alp            [[:alpha:]]
blk            [[:blank:]]
dot            "."
eol            "\n"
min            "-"
sem            ";"
spc            " "
sta            "*"
til            "~"

txt            .{1,80}

nam            [^ \t\n]{1,80}
gap            ({min}|{dot}|{til})
bas            ({alp}|{gap}|{sta}){1,80}
typ            [12]

%%

^{eol}         ; /* Empty lines ignored */

^{sem}/{txt}   { BEGIN HCOM; return SEM; }
^{sem}/{eol}   { BEGIN HCOM; return SEM; }
<HCOM>{txt}    { yylval->str = strdup(yytext); return TXT; }
<HCOM>{eol}    { BEGIN HNAM; return EOL; }
<HCOM>{eol}/{sem} { BEGIN INITIAL; return EOL; }

<HNAM>{nam}    { yylval->str = strdup(yytext); return NAM; }
<HNAM>^{blk}+  ; /* Leading spaces ignored */
<HNAM>{blk}+/{eol} ; /* Trailing spaces ignored */
<HNAM>{eol}    { BEGIN SEQS; return EOL; }
<HNAM>.        { return ERR; }

<SEQS>{bas}    { yylval->str = strdup(yytext); return BAS; }
<SEQS>{blk}    ; /* Spaces ignored */
<SEQS>{typ}    { return TYP; }
<SEQS>{eol}    ; /* Newlines ignored */
<SEQS>{eol}/{sem} { BEGIN INITIAL; return END; }
<SEQS><<EOF>>  { BEGIN INITIAL; return END; }
<SEQS>.        { return ERR; }

<<EOF>>        { BEGIN INITIAL; return NUL; }
{eol}          { return ERR; }
.              { return ERR; }

%%
