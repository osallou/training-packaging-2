/* stockl.l - STOCKHOLM alignment lexer */

%{
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif

#include "align/stocky.h"

#undef  YY_DECL
#define YY_DECL int yylex(YYSTYPE *yylval)
%}

%option never-interactive
%option nounput noyywrap

%x HDRTAG SEQTAG ENDTAG

alp            [[:alpha:]]
blk            [[:blank:]]
dig            [[:digit:]]
dot            "."
eol            "\n"
min            "-"
sla            "/"
spc            " "
sta            "*"

tag            #{spc}STOCKHOLM
nam            [^# \t\n][^ \t\n]{0,49}
gap            ({min}|{dot})
bas            ({alp}|{gap}|{sta}){1,10}
end            {sla}{2}

%%

<*>^#=GC.*{eol} /* Column annot. markup ignored */
<*>^#=GF.*{eol} /* File annot. markup ignored */
<*>^#=GR.*{eol} /* Residue annot. markup ignored */
<*>^#=GS.*{eol} /* Sequence annot. markup ignored */
<*>^{eol}       /* Empty lines ignored */

^{tag}         { BEGIN HDRTAG; return TAG; }
<HDRTAG>{spc}  { return SPC; }
<HDRTAG>{dig}+ { return INT; }
<HDRTAG>{dot}  { return DOT; }
<HDRTAG>{eol}  { BEGIN INITIAL; return EOL; }
<HDRTAG>.      { return ERR; }

^{eol}/{nam}   { return EOL; }
^{nam}/{blk}+{bas} { BEGIN SEQTAG; yylval->str = strdup(yytext); return NAM; }
<SEQTAG>{blk}+ { return SPC; }
<SEQTAG>{bas}  { yylval->str = strdup(yytext); return BAS; }
<SEQTAG>{eol}  { BEGIN INITIAL; return EOL; }
<SEQTAG>.      { return ERR; }

<*>^{end}      { BEGIN ENDTAG; return END; }
<ENDTAG>{eol}  { BEGIN INITIAL; return EOL; }
<ENDTAG><<EOF>> { BEGIN INITIAL; return EOL; }
<ENDTAG>.      { return ERR; }

{eol}          { return ERR; }
.              { return ERR; }

%%
