/* nbrfl.l - NBRF sequence lexer */

%{
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif

#include "sequence/nbrfy.h"

#undef  YY_DECL
#define YY_DECL int yylex(YYSTYPE *yylval)
%}

%option never-interactive
%option nounput noyywrap

%x HTAG HNAM DESC SEQS

alp            [[:alpha:]]
com            ","
cpa            ")"
dot            "."
eol            "\n"
equ            "="
min            "-"
opa            "("
que            "?"
sem            ";"
sla            "/"
spc            " "
sta            "*"
sup            ">"
til            "~"

nam            [^ \n]+
tag            ([PpFfDd]1|[DdRr][LlCl]|[Nn][13])
gap            ({min}|{que}|{til})
bas            ({alp}|{sta}|{gap}){1,80}
pun            ({com}|{cpa}|{dot}|{equ}|{opa}|{sla})

txt            .{1,80}

%%

^{eol}         ; /* Empty lines ignored */

^{sup}/{tag}   { BEGIN HTAG; return SUP; }
<HTAG>{tag}/{sem} { return TAG; }
<HTAG>{sem}    { BEGIN HNAM; return SEM; }
<HTAG>{eol}    { return ERR; }
<HTAG>.        { return ERR; }

<HNAM>{spc}/{nam} ; /* Leading spaces ignored */
<HNAM>{nam}    { yylval->str = strdup(yytext); return NAM; }
<HNAM>{spc}+/{eol} ; /* Trailing spaces ignored */
<HNAM>{eol}    { BEGIN DESC; return EOL; }
<HNAM>.        { return ERR; }

<DESC>{txt}    { yylval->str = strdup(yytext); return TXT; }
<DESC>{eol}    { BEGIN SEQS; return EOL; }

<SEQS>{bas}    { yylval->str = strdup(yytext); return BAS; }
<SEQS>{pun}    ; /* Punctuation ignored */
<SEQS>{spc}    ; /* Spaces ignored */
<SEQS>{eol}    ; /* Newlines ignored */
<SEQS>{eol}/{sup} { BEGIN INITIAL; return END; }
<SEQS><<EOF>>  { BEGIN INITIAL; return END; }
<SEQS>.        { return ERR; }

<<EOF>>        { return NUL; }
{eol}          { return ERR; }
.              { return ERR; }

%%
