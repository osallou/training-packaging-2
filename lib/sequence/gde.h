/* gde.h - GDE sequence functions */

#ifndef __SEQUENCE_GDE_H_
#define __SEQUENCE_GDE_H_

#include <stdio.h>
#include "sequence.h"


/* Functions prototypes */

sequence_t *gde_parse(FILE *);
int gde_check(FILE *);
void gde_print(FILE *, sequence_t *);

#endif /* __SEQUENCE_GDE_H_ */

