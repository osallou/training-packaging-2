/* format.h - Sequence/Alignment format functions */

#ifndef __FORMAT_H_
#define __FORMAT_H_

#include <stdio.h>

#include "align.h"
#include "sequence.h"


/* Types definitions */
typedef struct {
  alifmt_t ali;
  seqfmt_t seq;
  int num;
  FILE *f; } allfmt_t;


/* Functions prototypes */

void format_detect(allfmt_t *, FILE *, allfmt_t *, int);
void format_verify(allfmt_t *, FILE *, allfmt_t *, int);

void format_convert(allfmt_t *, allfmt_t *);

const char *format_name(allfmt_t *);
void format_fmt(allfmt_t *, char *);

void format_list(allfmt_t *);


#endif /* __FORMAT_H_ */

