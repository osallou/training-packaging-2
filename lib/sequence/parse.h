/* parse.h - Sequence parsing helper functions */

#ifndef __SEQUENCE_PARSE_H_
#define __SEQUENCE_PARSE_H_

#include "sequence.h"

/* Functions prototypes */
void parse_nuladd(sequence_t *, char *);
void parse_namadd(sequence_t *, char *);
void parse_accadd(sequence_t *, char *);
void parse_veradd(sequence_t *, int);
void parse_giadd(sequence_t *, int);
void parse_dscadd1(sequence_t *, char *);
void parse_dscadd2(sequence_t *, char *);
void parse_kwdadd(sequence_t *, char *);
void parse_kwdupd(sequence_t *, char *);
void parse_stradd(sequence_t *, char *);

#endif /* __SEQUENCE_PARSE_H_ */
