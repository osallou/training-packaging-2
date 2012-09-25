/* sprot.h - SWISSPROT sequence functions */

#ifndef __SEQUENCE_SPROT_H_
#define __SEQUENCE_SPROT_H_

#include <stdio.h>
#include "sequence.h"


/* Functions prototypes */

sequence_t *sprot_parse(FILE *);
int sprot_check(FILE *);
void sprot_print(FILE *, sequence_t *);

#endif /* __SEQUENCE_SPROT_H_ */

