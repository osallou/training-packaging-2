/* fastal.l - FASTA sequence lexer */

%{
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif

#include "sequence/fastay.h"

#undef  YY_DECL
#define YY_DECL int yylex(YYSTYPE *yylval)
%}

%option never-interactive
%option nounput noyywrap

%x HEAD DESC SEQS

alp            [[:alpha:]]
blk            [[:blank:]]
dot            "."
eol            "\n"
min            "-"
pip            "|"
sem            ";"
spc            " "
sta            "*"
sup            ">"
tab            "\t"
til            "~"

nam            [^ \n]{1,80}
gap            ({min}|{til})
bas            ({alp}|{sta}|{gap}){1,80}
txt            .{1,80}

nbr            ([PF]1|[DR][LC]|N[13]){sem}[^ \n]+

%%

^{blk}*{eol}   ; /* Empty lines ignored */

^{sup}         { BEGIN HEAD; return SUP; }
<HEAD>{nbr}/{eol} { return ERR; } /* FIXME: Reject NBRF header */
<HEAD>{nam}    { yylval->str = strdup(yytext); return NAM; }
<HEAD>{spc}+   { BEGIN DESC; return SPC; }
<HEAD>{eol}    { BEGIN SEQS; return EOL; }

<DESC>{txt}    { yylval->str = strdup(yytext); return TXT; }
<DESC>{eol}    { BEGIN SEQS; return EOL; }

<SEQS>{bas}    { yylval->str = strdup(yytext); return BAS; }
<SEQS>{blk}    ; /* Spaces/Tabs ignored */
<SEQS>{eol}    ; /* Newlines ignored */
<SEQS>{eol}/{sup} { BEGIN INITIAL; return END; }
<SEQS><<EOF>>  { BEGIN INITIAL; return END; }
<SEQS>.        { return ERR; }

<<EOF>>        { return NUL; }
{eol}          { return ERR; }
.              { return ERR; }

%%
