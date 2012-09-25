/* fasta.h - FASTA sequence functions */

#ifndef __SEQUENCE_FASTA_H_
#define __SEQUENCE_FASTA_H_

#include <stdio.h>
#include "sequence.h"


/* Functions prototypes */

sequence_t *fasta_parse(FILE *);
int fasta_check(FILE *);
void fasta_print(FILE *, sequence_t *);

#endif /* __SEQUENCE_FASTA_H_ */

