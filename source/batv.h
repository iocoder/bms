/*****************************************************************************/
/* File:    batv.h                                                           */
/* Date:    June 6th, 2021                                                   */
/* Author:  Ramses Nagib                                                     */
/* Desc:    BATV module header                                               */
/*****************************************************************************/

#ifndef _BATV_H
#define _BATV_H

/* AVR includes */
#include "inttypes.h"

/* module prototypes */
void batv_read (uint8_t index, uint16_t *volt);
void batv_task (void);
void batv_init (void);

#endif /* _BATV_H */
