/*****************************************************************************/
/* File:    wait.h                                                           */
/* Date:    June 6th, 2021                                                   */
/* Author:  Ramses Nagib                                                     */
/* Desc:    WAIT module header                                               */
/*****************************************************************************/

#ifndef _WAIT_H_
#define _WAIT_H_

/* AVR includes */
#include "inttypes.h"
#include "util/delay.h" 

/* module prototypes */
void wait_us   (uint16_t usecs);
void wait_ms   (uint16_t msecs);
void wait_task (void);
void wait_init (void);

#endif /* _WAIT_H_ */

