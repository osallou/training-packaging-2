/* megal.l - MEGA alignment lexer */

%{
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif

#include "align/megay.h"

#undef  YY_DECL
#define YY_DECL int yylex(YYSTYPE *yylval)
%}

%option caseless
%option never-interactive
%option nounput noyywrap

%x HDRTAG DEFTAG NAMTAG CMTTAG SEQTAG
%x DEFTA2 DEFTA3

alp        [[:alpha:]]
blk        [[:blank:]]
cbr        "]"
col        ":"
exc        "!"
die        "#"
dot        "."
eol        "\n"
min        "-"
obr        "["
que        "?"
quo        "\""
sem        ";"
spc        " "
sta        "*"

txt        .{1,80}

tag        mega
key        [^!; \n]{1,20}
key2       Title
nam        [^ \n]{1,50}
cmt        [^"\n]{1,50}
gap        ({min}|{que})
bas        ({alp}|{gap}|{sta}|{dot}){1,10}

%%

^{eol}         ; /* Empty lines ignored */
<*>{obr}.*{cbr}   ; /* Comments ignored */

^{die}/{tag} { BEGIN HDRTAG; return DIE; }
<HDRTAG>{tag}  { return TAG; }
<HDRTAG>{blk}+/{eol} ; /* Trailing spaces ignored */
<HDRTAG>{eol}  { BEGIN INITIAL; return EOL; }
<HDRTAG>.      { return ERR; }

^{exc}         { BEGIN DEFTAG; return EXC; }
^{key2}        { BEGIN DEFTAG; return KEY; }
<DEFTAG>{key}  { return KEY; }
<DEFTAG>{col}{spc} { BEGIN DEFTA3; }
<DEFTAG>{spc}  { BEGIN DEFTA2; }
<DEFTAG>{sem}  { BEGIN DEFTA2; return SEM; }
<DEFTAG>{eol}/{spc} { BEGIN DEFTA2; } /* Line continuation ignored */
<DEFTAG>{eol}  { return ERR; }
<DEFTAG>.      { return ERR; }

<DEFTA2>{txt}/{sem}{eol} { return TXT; }
<DEFTA2>{txt}/{eol}{spc} { return TXT; }
<DEFTA2>{sem}  { return SEM; }
<DEFTA2>{eol}/{spc} /* Line continuation ignored */
<DEFTA2>{eol}  { BEGIN INITIAL; return EOL; }
<DEFTA2>.      { return ERR; }

<DEFTA3>{txt}  { return TXT; }
<DEFTA3>{eol}  { BEGIN INITIAL; return EOL; }

^{die}/{nam}   { BEGIN NAMTAG; return DIE; }
<NAMTAG>{nam}  { yylval->str = strdup(yytext); return NAM; }
<NAMTAG>{spc}+{quo} { BEGIN CMTTAG; }
<NAMTAG>{spc}+ { BEGIN SEQTAG; return EOL; }
<NAMTAG>{eol}  { BEGIN SEQTAG; return EOL; }

<CMTTAG>{quo}  { BEGIN NAMTAG; }
<CMTTAG>{cmt}  ; /* Comment ignored */
<CMTTAG>{eol}  { return ERR; }

<SEQTAG>{bas}  { yylval->str = strdup(yytext); return BAS; }
<SEQTAG>{spc}  ; /* Spaces ignored */
<SEQTAG>{eol}  ; /* Newlines ignored */
<SEQTAG>{eol}/{die} { BEGIN INITIAL; return EOL; }
<SEQTAG><<EOF>> { BEGIN INITIAL; return EOL; }
<SEQTAG>.      { return ERR; }

<<EOF>>        { return END; }
{eol}          { return ERR; }
.              { return ERR; }

%%
