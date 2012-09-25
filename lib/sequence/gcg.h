/* gcg.h - GCG sequence functions */

#ifndef __SEQUENCE_GCG_H_
#define __SEQUENCE_GCG_H_

#include <stdio.h>
#include "sequence.h"


/* Functions prototypes */

sequence_t *gcg_parse(FILE *);
int gcg_check(FILE *);
void gcg_print(FILE *, sequence_t *);

#endif /* __SEQUENCE_GCG_H_ */

