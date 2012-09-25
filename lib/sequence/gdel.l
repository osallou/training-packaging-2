/* gdel.l - GDE sequence lexer */

%{
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif

#include "sequence/gdey.h"

#undef  YY_DECL
#define YY_DECL int yylex(YYSTYPE *yylval)
%}

%option never-interactive
%option nounput noyywrap

%x HEAD SEQS

alp      [[:alpha:]]
blk      [[:blank:]]
die      "#"
eol      "\n"
min      "-"
per      "%"

txt      .{1,80}

tag      ({die}|{per})
nam      [^ \n]{1,80}
gap      {min}
bas      ({alp}|{min}){1,80}

%%

^{eol}         ; /* Empty lines ignored */

^{tag}         { BEGIN HEAD; return TAG; }
<HEAD>{nam}    { yylval->str = strdup(yytext); return NAM; }
<HEAD>{blk}/{eol} ; /* Ignore trailing spaces */
<HEAD>{eol}    { BEGIN SEQS; return EOL; }
<HEAD>.        { return ERR; }

<SEQS>{bas}    { yylval->str = strdup(yytext); return BAS; }
<SEQS>{eol}/{tag} { BEGIN INITIAL; return END; }
<SEQS>{eol}    ; /* Newlines ignored */
<SEQS>{blk}    ; /* Spaces ignored */
<SEQS><<EOF>>  { BEGIN INITIAL; return END; }
<SEQS>.        { return ERR; }

<<EOF>>        { return NUL; }
{eol}          { return ERR; }
.              { return ERR; }

%%
