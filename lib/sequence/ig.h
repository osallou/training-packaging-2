/* ig.h - IG sequence functions */

#ifndef __SEQUENCE_IG_H_
#define __SEQUENCE_IG_H_

#include <stdio.h>
#include "sequence.h"


/* Functions prototypes */

sequence_t *ig_parse(FILE *);
int ig_check(FILE *);
void ig_print(FILE *, sequence_t *);

#endif /* __SEQUENCE_IG_H_ */

