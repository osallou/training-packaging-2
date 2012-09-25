/* protein.c - Protein sequence functions */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <ctype.h>

#include "extern/file.h"
#include "sequence/protein.h"

/* Global variables */     /* FIXME: To be loaded from external file ... */
/* ??? X = 118.8860 */

#ifdef notyet
/* Average isotopic masses of amino acids, from
   <URL:http://www.expasy.org/tools/findmod/findmod_masses.html#AA> */

static float aaw[26] = {
  071.0788, ???.????, 103.1388, 115.0886, 129.1155, 147.1766, 057.0519,
  137.1411, 113.1594, ???.????, 128.1741, 113.1594, 131.1926, 114.1038,
  ???.????, 097.1167, 128.1307, 156.1875, 087.0782, 101.1051, ???.????,
  099.1326, 186.2132, ???.????, 163.1760, ???.???? };
#endif

static float aaw[26] = {
  071.0788, 114.5962, 103.1388, 115.0886, 129.1155, 147.1766, 057.0519, /*A-G*/
  137.1411, 113.1594, 113.1594, 128.1741, 113.1594, 131.1926, 114.1038, /*H-N*/
  000.0000, 097.1167, 128.1307, 156.1875, 087.0782, 101.1051, 000.0000, /*O-U*/
  099.1326, 186.2132, 110.0000, 163.1760, 128.6231 };                   /*V-Z*/


/* Get molecular weigth */
float protein_weight(char *seq) {
  char *p;
  float w;
  int i;

  /* Water average mass (H + OH) ... */
  w = 18.01524;

  p = seq;
  while (*p) {
    if (! isalpha((unsigned char)*p)) {
      p++; continue; }
    i = toupper((unsigned char)*p) - 'A';
    w += aaw[i];
    p++; }

  return w; }
