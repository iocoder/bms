/*****************************************************************************/
/* File:    uart.h                                                           */
/* Date:    July 17th, 2021                                                  */
/* Author:  Ramses Nagib                                                     */
/* Desc:    SSEG module header                                               */
/*****************************************************************************/

#ifndef _UART_H_
#define _UART_H_

/* AVR includes */
#include "inttypes.h"
#include "avr/interrupt.h"
#include "avr/io.h"

/* UART baudrate */
#define UART_BAUDRATE     9600
#define UART_PRESCALE     (((F_CPU / (UART_BAUDRATE * 8UL))) - 1)

/* UART receive buffer */
#define UART_BUFSIZE      20

/* module prototypes */
void uart_readl (char *buf, uint8_t *result);
void uart_writel(char *buf, uint8_t *result);
void uart_task  (void);
void uart_init  (void);

#endif /* _UART_H_ */
