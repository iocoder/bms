/*****************************************************************************/
/* File:    adcx.h                                                           */
/* Date:    June 6th, 2021                                                   */
/* Author:  Ramses Nagib                                                     */
/* Desc:    ADCX module header                                               */
/*****************************************************************************/

#ifndef _ADCX_H_
#define _ADCX_H_

/* AVR includes */
#include "inttypes.h"

/* module prototypes */
void adcx_read (double *volt);
void adcx_task (void);
void adcx_init (void);

#endif /* _ADCX_H_ */
