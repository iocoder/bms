/*****************************************************************************/
/* File:    spix.h                                                           */
/* Date:    June 6th, 2021                                                   */
/* Author:  Ramses Nagib                                                     */
/* Desc:    SPIX module header                                               */
/*****************************************************************************/

#ifndef _SPIX_H
#define _SPIX_H

/* AVR includes */
#include "inttypes.h"
#include "avr/io.h"

/* module prototypes */
void spix_xfer (uint8_t *out, uint8_t *in);
void spix_task (void);
void spix_init (void);

#endif /* _SPIX_H */
