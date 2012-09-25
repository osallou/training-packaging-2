/* nexusi.h - NEXUSI alignment functions */

#ifndef __ALIGN_NEXUSI_H_
#define __ALIGN_NEXUSI_H_

#include <stdio.h>

#include "align.h"


/* Functions prototypes */
int nexusi_check(FILE *);
align_t *nexusi_parse(FILE *);
void nexusi_print(FILE *, align_t *);

#endif /* __ALIGN_NEXUSI_H_ */
