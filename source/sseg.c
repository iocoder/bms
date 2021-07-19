/*****************************************************************************/
/* File:    sseg.c                                                           */
/* Date:    June 6th, 2021                                                   */
/* Author:  Ramses Nagib                                                     */
/* Desc:    7-Segment controller                                             */
/*****************************************************************************/

#include "gpio.h"
#include "sseg.h"

/*****************************************************************************/
/*                              sseg_putd()                                  */
/*****************************************************************************/

void sseg_putd (uint16_t num)
{
  /* this function puts decimal number on screen */
  uint8_t dig = 0;

  /* compute next digit to display */
  dig = num%10;
  num = num/10;

  /* display digit on 1st 7seg */
  gpio_set(PORT_C, PIN_0, (dig>>0)&1);
  gpio_set(PORT_C, PIN_1, (dig>>1)&1);
  gpio_set(PORT_C, PIN_2, (dig>>2)&1);
  gpio_set(PORT_C, PIN_3, (dig>>3)&1);

  /* compute next digit to display */
  dig = num%10;
  num = num/10;

  /* display digit on 2nd 7seg */
  gpio_set(PORT_C, PIN_4, (dig>>0)&1);
  gpio_set(PORT_C, PIN_5, (dig>>1)&1);
  gpio_set(PORT_C, PIN_6, (dig>>2)&1);
  gpio_set(PORT_C, PIN_7, (dig>>3)&1);

  /* compute next digit to display */
  dig = num%10;
  num = num/10;

  /* display digit on 3rd 7seg */
  gpio_set(PORT_D, PIN_0, (dig>>0)&1);
  gpio_set(PORT_D, PIN_1, (dig>>1)&1);
  gpio_set(PORT_D, PIN_2, (dig>>2)&1);
  gpio_set(PORT_D, PIN_3, (dig>>3)&1);

  /* compute next digit to display */
  dig = num%10;
  num = num/10;

  /* display digit on 4th 7seg */
  gpio_set(PORT_D, PIN_4, (dig>>0)&1);
  gpio_set(PORT_D, PIN_5, (dig>>1)&1);
  gpio_set(PORT_D, PIN_6, (dig>>2)&1);
  gpio_set(PORT_D, PIN_7, (dig>>3)&1);
}

/*****************************************************************************/
/*                              sseg_task()                                  */
/*****************************************************************************/

void sseg_task (void)
{
  /* nothing to do here */
}

/*****************************************************************************/
/*                              sseg_init()                                  */
/*****************************************************************************/

void sseg_init (void)
{
  /* initialize 1st 7seg */
  gpio_mode(PORT_C, PIN_0, MODE_OUT, DIG_LOW);
  gpio_mode(PORT_C, PIN_1, MODE_OUT, DIG_LOW);
  gpio_mode(PORT_C, PIN_2, MODE_OUT, DIG_LOW);
  gpio_mode(PORT_C, PIN_3, MODE_OUT, DIG_LOW);

  /* initialize 2nd 7seg */
  gpio_mode(PORT_C, PIN_4, MODE_OUT, DIG_LOW);
  gpio_mode(PORT_C, PIN_5, MODE_OUT, DIG_LOW);
  gpio_mode(PORT_C, PIN_6, MODE_OUT, DIG_LOW);
  gpio_mode(PORT_C, PIN_7, MODE_OUT, DIG_LOW);

  /* initialize 3rd 7seg */
  gpio_mode(PORT_D, PIN_0, MODE_OUT, DIG_LOW);
  gpio_mode(PORT_D, PIN_1, MODE_OUT, DIG_LOW);
  gpio_mode(PORT_D, PIN_2, MODE_OUT, DIG_LOW);
  gpio_mode(PORT_D, PIN_3, MODE_OUT, DIG_LOW);

  /* initialize 4th 7seg */
  gpio_mode(PORT_D, PIN_4, MODE_OUT, DIG_LOW);
  gpio_mode(PORT_D, PIN_5, MODE_OUT, DIG_LOW);
  gpio_mode(PORT_D, PIN_6, MODE_OUT, DIG_LOW);
  gpio_mode(PORT_D, PIN_7, MODE_OUT, DIG_LOW);
}
