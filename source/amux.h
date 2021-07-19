/*****************************************************************************/
/* File:    amux.h                                                           */
/* Date:    June 6th, 2021                                                   */
/* Author:  Ramses Nagib                                                     */
/* Desc:    AMUX module header                                               */
/*****************************************************************************/

#ifndef _AMUX_H_
#define _AMUX_H_

/* AVR includes */
#include "inttypes.h"

/* module prototypes */
void amux_sel  (uint8_t addr);
void amux_task (void);
void amux_init (void);

#endif /* _AMUX_H_ */
