/* pir.h - PIR sequence functions */

#ifndef __SEQUENCE_PIR_H_
#define __SEQUENCE_PIR_H_

#include <stdio.h>
#include "sequence.h"


/* Functions prototypes */

sequence_t *pir_parse(FILE *);
int pir_check(FILE *);
void pir_print(FILE *, sequence_t *);

#endif /* __SEQUENCE_PIR_H_ */

