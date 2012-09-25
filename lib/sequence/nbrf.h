/* nbrf.h - NBRF sequence functions */

#ifndef __SEQUENCE_NBRF_H_
#define __SEQUENCE_NBRF_H_

#include <stdio.h>
#include "sequence.h"


/* Functions prototypes */

sequence_t *nbrf_parse(FILE *);
int nbrf_check(FILE *);
void nbrf_print(FILE *, sequence_t *);

#endif /* __SEQUENCE_NBRF_H_ */

