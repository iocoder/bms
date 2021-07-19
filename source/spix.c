/*****************************************************************************/
/* File:    spix.c                                                           */
/* Date:    June 6th, 2021                                                   */
/* Author:  Ramses Nagib                                                     */
/* Desc:    SPI bus controller                                               */
/*****************************************************************************/

#include "gpio.h"
#include "spix.h"

/*****************************************************************************/
/*                              spix_xfer()                                  */
/*****************************************************************************/

void spix_xfer (uint8_t *out, uint8_t *in)
{
  /* start transfer */
  SPDR = *out;

  /* wait for transfer cycle to complete */
  while (!(SPSR & (1<<SPIF)));

  /* retrieve input */
  *in = SPDR;
}

/*****************************************************************************/
/*                              spix_task()                                  */
/*****************************************************************************/

void spix_task (void)
{
  /* nothing to do here */
}

/*****************************************************************************/
/*                              spix_init()                                  */
/*****************************************************************************/

void spix_init (void)
{
  /* initialize SCK pin mode */
  gpio_mode(PORT_B, PIN_7, MODE_OUT, DIG_HIGH);

  /* initialize MOSI pin mode */
  gpio_mode(PORT_B, PIN_5, MODE_OUT, DIG_LOW);

  /* initialize MISO pin mode */
  gpio_mode(PORT_B, PIN_6, MODE_IN, DIG_LOW);

  /* Enable SPI, MSB, Master, set clock rate fck/16 */
  SPCR = (1<<SPE)|(1<<MSTR)|(1<<CPOL)|(1<<CPHA)|(1<<SPR0);
}
