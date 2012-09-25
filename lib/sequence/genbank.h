/* genbank.h - GENBANK sequence functions */

#ifndef __SEQUENCE_GENBANK_H_
#define __SEQUENCE_GENBANK_H_

#include <stdio.h>
#include "sequence.h"


/* Functions prototypes */

sequence_t *genbank_parse(FILE *);
int genbank_check(FILE *);
void genbank_print(FILE *, sequence_t *);

#endif /* __SEQUENCE_GENBANK_H_ */

