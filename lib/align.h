/* align.h - Generic alignment functions */

#ifndef __ALIGN_H_
#define __ALIGN_H_

#include <stdio.h>

#include "sequence.h"


/* Types definitions */

typedef struct {
  sequence_t **cur;
  sequence_t **seq;
  char *_tmp;
} align_t;

typedef enum {
  ALIFMT_UNKWN, ALIFMT_CLUSTAL, ALIFMT_PHYLIPI, ALIFMT_PHYLIPS,
  ALIFMT_FASTA, ALIFMT_MEGA, ALIFMT_MSF, ALIFMT_NEXUSI, ALIFMT_STOCK,
  ALIFMT_NONE } alifmt_t;


/* Functions prototypes */

align_t *align_new(void);
void align_free(align_t *);

int align_check(FILE *, alifmt_t);
align_t *align_parse(FILE *, alifmt_t);

int align_strict(align_t *);
void align_print(FILE *, align_t *, alifmt_t);

alifmt_t align_format(FILE *);

#endif /* __ALIGN_H_ */

