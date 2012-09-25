/* phylipil.l - PHYLIPI alignment lexer */

%{
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif
#include <ctype.h>

#include "align/phylipiy.h"

#undef  YY_DECL
#define YY_DECL int yylex(YYSTYPE *yylval)

static void clean_spc(char *str);
%}

%option never-interactive
%option nounput noyywrap

%x HEAD NAMS SEQS

alp        [[:alpha:]]
blk        [[:blank:]]
dig        [[:digit:]]
dot        "."
eol        "\n"
min        "-"
que        "?"
spc        " "
sta        "*"
til        "~"

mis        ({blk}+{alp}*)+
nam        [^\(\):;,\[\]\n]{10}
gap        ({dot}|{min}|{til})
bas        ({alp}|{que}|{sta}|{gap}){1,10}

%%

^{blk}*{eol}   ; /* Empty lines ignored */

^{blk}*/{dig}+{blk}+{dig}+ { BEGIN HEAD; }
<HEAD>{dig}+   { return INT; }
<HEAD>{blk}+   { return SPC; }
<HEAD>{blk}+/{eol} ; /* Trailing spaces ignored */
<HEAD>{mis}/{eol} ; /* Extra stuff ignored */
<HEAD>{eol}    { BEGIN NAMS; return EOL; }
<HEAD>.        { return ERR; }

<NAMS>^{nam}   { yylval->str = strdup(yytext); clean_spc(yylval->str);
                 if (*yylval->str == '\0') return ERR; return NAM; }
<NAMS>{bas}    { yylval->str = strdup(yytext); return BAS; }
<NAMS>{blk}+   ; /* Sequence spaces ignored */
<NAMS>{eol}    { return EOL; }
<NAMS><<EOF>>  { BEGIN INITIAL; return EOL; }
<NAMS>.        { return ERR; }
<NAMS>^{eol}/{blk}*{bas} { BEGIN SEQS; return EOL; }

<SEQS>{bas}    { yylval->str = strdup(yytext); return BAS; }
<SEQS>{blk}+   ; /* Sequence spaces/tabs ignored */
<SEQS>{eol}    { return EOL; }
<SEQS><<EOF>>  { BEGIN INITIAL; return EOL; }
<SEQS>.        { return ERR; }

<<EOF>>        { return END; }
{eol}          { return ERR; }
.              { return ERR; }

%%


/* Clean trailing spaces ... */
static void clean_spc(char *str) {
  char *p;

  p = str;
  while (*p) { p++; }
  p--;
  while (p >= str && isspace((unsigned char)*p)) {
    *p = '\0'; p--; }

  return; }
