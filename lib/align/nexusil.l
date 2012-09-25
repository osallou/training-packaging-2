/* nexusil.l - NEXUSI alignment lexer */

%{
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif
#include <ctype.h>

#include "align/nexusiy.h"

#undef  YY_DECL
#define YY_DECL int yylex(YYSTYPE *yylval)

static void clean_quo(char *str);
%}

%option caseless
%option never-interactive
%option nounput noyywrap

%x BBLO COMM MATX EBLO IGNO

alp        [[:alpha:]]
blk        [[:blank:]]
cbr        "]"
dot        "."
eol        "\n"
equ        "="
min        "-"
obr        "["
que        "?"
quo        ("\""|"\'")
sem        ";"
spa        [[:space:]]
spc        " "
sta        "*"
til        "~"

tag        #NEXUS
beg        begin
key        (characters?|data)
end        end(block)?
blo        [^; \n]{1,80}

com        (dimensions|format|options|title|char(state)?labels)
tok        {alp}{1,80}
val        ([^ \t=;\n]{1,80}|{quo}[^;\n]{1,80}{quo})

mat        matrix
nam        ([^\[\] \t\n]{1,80}|{quo}[^\n]{1,80}{quo})
gap        ({dot}|{min}|{que}|{til})
bas        ({alp}|{gap}|{sta}){1,10}

%%

<*>{blk}*{obr}[^\]]*{cbr} ; /* Comments ignored */
<*>^{blk}*{obr}[^\]]*{cbr}{blk}*{eol} ; /* Comments ignored */

{eol}          ; /* Newlines ignored */
{spc}+/{eol}   ; /* Trailing spaces ignored */

^{tag}         { return TAG; }

^{blk}*{beg}/{spc}{key} { BEGIN BBLO; return BEG; }
<BBLO>{key}    { return KEY; }
<BBLO>{sem}    { return SEM; }
<BBLO>{spc}    { return SPC; }
<BBLO>{eol}    { BEGIN COMM; } /* Newlines ignored */
<BBLO>.        { return ERR; }

<COMM>{com}/{blk} { return COM; }
<COMM>{com}/{eol} { return COM; }
<COMM>{tok}/{blk}?{equ}{blk}? { return TOK; }
<COMM>{val}/{blk} { return VAL; }
<COMM>{val}/{sem} { return VAL; }
<COMM>{val}/{eol} { return VAL; }
<COMM>{blk}?{equ}{blk}? { return EQU; }
<COMM>{sem}{blk}* { return SEM; }
<COMM>^{blk}+  ; /* Leading spaces ignored */
<COMM>{blk}+/{sem} ; /* Ingore extra spaces before `;' */
<COMM>{blk}+   { return SPC; }
<COMM>{eol}/{blk}*{mat} { BEGIN MATX; }
<COMM>{eol}    ; /* Newlines ignored */
<COMM>.        { return ERR; }

<MATX>^{blk}*{mat}{blk}*{eol} { return MAT; }
<MATX>^{blk}*{nam}/{blk} { yylval->str = strdup(yytext); clean_quo(yylval->str);
                           if (*yylval->str == '\0') return ERR; return NAM; }
<MATX>{bas}    { yylval->str = strdup(yytext); return BAS; }
<MATX>{sem}/{blk}*{eol} { BEGIN EBLO; return SEM; }
<MATX>^{blk}+  ; /* Leading spaces ignored */
<MATX>{blk}+/{eol} ; /* Trailing spaces ignored */
<MATX>{blk}+   { return SPC; }
<MATX>^{eol}+/{sem} ; /* Ignore extra lines */
<MATX>^{eol}+  { return SEP; }
<MATX>{eol}    { return EOL; }
<MATX>.        { return ERR; }

<EBLO>{end}    { return END; }
<EBLO>{sem}    { BEGIN INITIAL; return SEM; }
<EBLO>{blk}+   ; /* Spaces ignored */
<EBLO>{eol}    ; /* Newlines ignored */
<EBLO>.        { return ERR; }

^{blk}*{beg}/{spc} { BEGIN IGNO; }
<IGNO>^{blk}*{end}{sem} { BEGIN INITIAL; }
<IGNO>{eol}    ; /* Newlines ignored */
<IGNO>.        ; /* All chars ignored */
<IGNO><<EOF>>  { return ERR; }

.              { return ERR; }

%%

/* Remove quotes ... */
static void clean_quo(char *str) {
  char *p;

  p = str;
  if (*p != '\'' && *p != '"')
    return;
  while (*p && *(p+1)) {
    *p = *(p+1);
    p++; }
  *(p-1) = '\0';

  return; }
