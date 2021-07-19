/*****************************************************************************/
/* File:    gpio.c                                                           */
/* Date:    June 6th, 2021                                                   */
/* Author:  Ramses Nagib                                                     */
/* Desc:    General Purpose I/O (GPIO) controller                            */
/*****************************************************************************/

#include "gpio.h"

/*****************************************************************************/
/*                              gpio_mode()                                  */
/*****************************************************************************/

void gpio_mode (uint8_t port, uint8_t pin, uint8_t mode, uint8_t init) 
{
  switch (port) {
    case PORT_A:
      PORTA = (PORTA & (~(1<<pin))) | ((init&1)<<pin);
      DDRA  = (DDRA  & (~(1<<pin))) | ((mode&1)<<pin);
      break;
    case PORT_B:
      PORTB = (PORTB & (~(1<<pin))) | ((init&1)<<pin);
      DDRB  = (DDRB  & (~(1<<pin))) | ((mode&1)<<pin);
      break;
    case PORT_C:
      PORTC = (PORTC & (~(1<<pin))) | ((init&1)<<pin);
      DDRC  = (DDRC  & (~(1<<pin))) | ((mode&1)<<pin);
      break;
    case PORT_D:
      PORTD = (PORTD & (~(1<<pin))) | ((init&1)<<pin);
      DDRD  = (DDRD  & (~(1<<pin))) | ((mode&1)<<pin);
      break;
    default:
      break;
  }
}

/*****************************************************************************/
/*                              gpio_set()                                   */
/*****************************************************************************/

void gpio_set (uint8_t port, uint8_t pin, uint8_t val) 
{
  switch (port) {
    case PORT_A:
      PORTA = (PORTA & (~(1<<pin))) | ((val&1)<<pin);
      break;
    case PORT_B:
      PORTB = (PORTB & (~(1<<pin))) | ((val&1)<<pin);
      break;
    case PORT_C:
      PORTC = (PORTC & (~(1<<pin))) | ((val&1)<<pin);
      break;
    case PORT_D:
      PORTD = (PORTD & (~(1<<pin))) | ((val&1)<<pin);
      break;
    default:
      break;
  }
}

/*****************************************************************************/
/*                              gpio_get()                                   */
/*****************************************************************************/

void gpio_get (uint8_t port, uint8_t pin, uint8_t *val) 
{
  switch (port) {
    case PORT_A:
      *val = (PINA>>pin) & 1;
      break;
    case PORT_B:
      *val = (PINB>>pin) & 1;
      break;
    case PORT_C:
      *val = (PINC>>pin) & 1;
      break;
    case PORT_D:
      *val = (PIND>>pin) & 1;
      break;
    default:
      *val = 0;
      break;
  }
}

/*****************************************************************************/
/*                              gpio_task()                                  */
/*****************************************************************************/

void gpio_task (void)
{
  /* no specific task to perform periodically. */
}

/*****************************************************************************/
/*                              gpio_init()                                  */
/*****************************************************************************/

void gpio_init (void)
{
  /* all AVR GPIOs are initialized as inputs by default. */
}
