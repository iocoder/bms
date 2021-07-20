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

/* delay macros */
#define wait_us(usecs)  _delay_us(usecs)
#define wait_ms(msecs)  _delay_ms(msecs)

/* module prototypes */
void wait_task (void);
void wait_init (void);

#endif /* _WAIT_H_ */

