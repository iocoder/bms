/*****************************************************************************/
/* File:    sseg.h                                                           */
/* Date:    June 6th, 2021                                                   */
/* Author:  Ramses Nagib                                                     */
/* Desc:    SSEG module header                                               */
/*****************************************************************************/

#ifndef _SSEG_H_
#define _SSEG_H_

/* AVR includes */
#include "inttypes.h"

/* module prototypes */
void sseg_putd (uint16_t num);
void sseg_task (void);
void sseg_init (void);

#endif /* _SSEG_H_ */

