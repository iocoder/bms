/*****************************************************************************/
/* File:    amux.c                                                           */
/* Date:    June 6th, 2021                                                   */
/* Author:  Ramses Nagib                                                     */
/* Desc:    Analogue multiplexor controller                                  */
/*****************************************************************************/

#include "gpio.h"
#include "wait.h"
#include "amux.h"

/*****************************************************************************/
/*                              amux_sel()                                   */
/*****************************************************************************/

void amux_sel (uint8_t addr)
{
  /* convert range (1->32) to (0>31) */
  addr--;

  /* select analog signal by address */    
  gpio_set(PORT_A, PIN_0, (addr>>0)&1);
  gpio_set(PORT_A, PIN_1, (addr>>1)&1);
  gpio_set(PORT_A, PIN_2, (addr>>2)&1);
  gpio_set(PORT_A, PIN_3, (addr>>3)&1);
  gpio_set(PORT_A, PIN_4, (addr>>4)&1);

  /* wait until signal propagates through muxes */
  wait_us(100);
}

/*****************************************************************************/
/*                              amux_task()                                  */
/*****************************************************************************/

void amux_task (void)
{
  /* nothing to do. */
}

/*****************************************************************************/
/*                              amux_init()                                  */
/*****************************************************************************/

void amux_init (void)
{
  /* initialize address pins */
  gpio_mode(PORT_A, PIN_0, MODE_OUT, DIG_LOW);
  gpio_mode(PORT_A, PIN_1, MODE_OUT, DIG_LOW);
  gpio_mode(PORT_A, PIN_2, MODE_OUT, DIG_LOW);
  gpio_mode(PORT_A, PIN_3, MODE_OUT, DIG_LOW);
  gpio_mode(PORT_A, PIN_4, MODE_OUT, DIG_LOW);
}
