/* clustall.l - CLUSTAL alignment lexer */

%{
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif

#include "align/clustaly.h"

#undef  YY_DECL
#define YY_DECL int yylex(YYSTYPE *yylval)
%}

%option never-interactive
%option nounput noyywrap

%x HDRTAG SEQTAG CONTAG

alp        [[:alpha:]]
blk        [[:blank:]]
dig        [[:digit:]]
dot        "."
eol        "\n"
min        "-"
que        "?"
spc        " "
sta        "*"
tab        "\t"
til        "~"

txt        .{1,80}

tag        (CLUSTAL|[Cc]lustal)
nam        [^ \t\n]{1,50}
msk        !(SS|GM)_{nam}
gap        ({dot}|{min}|{que}|{til})
bas        ({alp}|{gap}|{sta}){1,10}
con        ({blk}|{dot}|{sta}|":"){1,10}
%%

^{blk}*{eol}   ; /* Empty lines ignored */
^{blk}*{eol}+/{tag} ; /* Empty lines ignored */
^{blk}+        ; /* Empty lines at EOF ignored */

^{tag}         { BEGIN HDRTAG; return TAG; }
<HDRTAG>{txt}  { return TXT; }
<HDRTAG>{eol}  { BEGIN INITIAL; return EOL; }
<HDRTAG>{eol}/{nam} { BEGIN SEQTAG; return EOL; }

^{spc}*{eol}+/{nam} { BEGIN SEQTAG; return EOL; }
<SEQTAG>^{msk}.*{eol} /* Ignore masks lines */
<SEQTAG>^{nam} { yylval->str = strdup(yytext); return NAM; }
<SEQTAG>{bas}  { yylval->str = strdup(yytext); return BAS; }
<SEQTAG>{dig}+ { return INT; }
<SEQTAG>{blk}+ { return SPC; }
<SEQTAG>{blk}+/{eol} ; /* Trailing spaces ignored */
<SEQTAG>{eol}/{nam}  { return EOL; }
<SEQTAG>{eol}/{con} { BEGIN CONTAG; return EOL; }
<SEQTAG>{eol}  { BEGIN INITIAL; return EOL; }
<SEQTAG><<EOF>> { BEGIN INITIAL; return EOL; }
<SEQTAG>.      { return ERR; }

<CONTAG>{con} { return CON; }
<CONTAG>{eol} { BEGIN INITIAL; return EOL; }
<CONTAG><<EOF>> { BEGIN INITIAL; return EOL; }
<CONTAG>.      { return ERR; }

<<EOF>>        { return END; }
{eol}          { return ERR; }
.              { return ERR; }

%%
