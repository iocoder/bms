/*****************************************************************************/
/* File:    gpio.h                                                           */
/* Date:    June 6th, 2021                                                   */
/* Author:  Ramses Nagib                                                     */
/* Desc:    GPIO module header                                               */
/*****************************************************************************/

#ifndef _GPIO_H_
#define _GPIO_H_

/* AVR includes */
#include "inttypes.h"
#include "avr/io.h"

/* port definitions */
#define PORT_A    0
#define PORT_B    1
#define PORT_C    2
#define PORT_D    3

/* pin definitions */
#define PIN_0     0
#define PIN_1     1
#define PIN_2     2
#define PIN_3     3
#define PIN_4     4
#define PIN_5     5
#define PIN_6     6
#define PIN_7     7

/* modes for GPIO pins */
#define MODE_IN   0
#define MODE_OUT  1

/* digital output */
#define DIG_LOW   0
#define DIG_HIGH  1

/* module prototypes */
void gpio_mode (uint8_t port, uint8_t pin, uint8_t mode, uint8_t init);
void gpio_set  (uint8_t port, uint8_t pin, uint8_t val);
void gpio_get  (uint8_t port, uint8_t pin, uint8_t *val);
void gpio_task (void);
void gpio_init (void);

#endif /* _GPIO_H_ */
