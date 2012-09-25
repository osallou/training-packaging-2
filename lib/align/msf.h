/* msf.h - MSF alignment functions */

#ifndef __ALIGN_MSF_H_
#define __ALIGN_MSF_H_

#include <stdio.h>

#include "align.h"


/* Functions prototypes */
int msf_check(FILE *);
align_t *msf_parse(FILE *);
void msf_print(FILE *, align_t *);

#endif /* __ALIGN_MSF_H_ */
