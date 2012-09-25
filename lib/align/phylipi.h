/* phylipi.h - PHYLIPI alignment functions */

#ifndef __ALIGN_PHYLIPI_H_
#define __ALIGN_PHYLIPI_H_

#include <stdio.h>

#include "align.h"


/* Functions prototypes */

int phylipi_check(FILE *);
align_t *phylipi_parse(FILE *);
void phylipi_print(FILE *, align_t *);

#endif /* __ALIGN_PHYLIPI_H_ */
