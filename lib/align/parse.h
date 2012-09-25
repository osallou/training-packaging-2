/* parse.h - Alignment parsing helper functions */

#ifndef __ALIGN_PARSE_H_
#define __ALIGN_PARSE_H_

#include "align.h"

#define CHKERR(v) if ((v) != 0) { return -1; }

/* Functions prototypes */
int parse_tmpupd(align_t *, char *);
int parse_sequpd(align_t *, char *);

int parse_seqnew(align_t *);
int parse_seqrst(align_t *);
int parse_seqnxt(align_t *);

#endif /* __ALIGN_PARSE_H_ */
