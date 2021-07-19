/*****************************************************************************/
/* File:    adcx.c                                                           */
/* Date:    June 6th, 2021                                                   */
/* Author:  Ramses Nagib                                                     */
/* Desc:    Analogue-Digital Converter                                       */
/*****************************************************************************/

#include "gpio.h"
#include "spix.h"
#include "wait.h"
#include "amux.h"

/*****************************************************************************/
/*                              amux_read()                                  */
/*****************************************************************************/

void adcx_read (double *volt)
{
  /* values to transfer over SPI */
  uint16_t addr = 0xFFFF;
  uint16_t data = 0x0000;

  /* start sampling */
  gpio_set(PORT_A, PIN_5, DIG_LOW);

  /* transfer 16 bits to allow ADC to sample 16 bits */
  spix_xfer(((uint8_t*)&addr)+1, ((uint8_t*)&data)+1);
  spix_xfer(((uint8_t*)&addr)+0, ((uint8_t*)&data)+0);

  /* start conversion */
  gpio_set(PORT_A, PIN_5, DIG_HIGH);

  /* busy wait until conversion is complete */
  wait_us(100);

  /* start reading data */
  gpio_set(PORT_A, PIN_5, DIG_LOW);

  /* transfer 16 bits to read conversion result */
  spix_xfer(((uint8_t*)&addr)+1, ((uint8_t*)&data)+1);
  spix_xfer(((uint8_t*)&addr)+0, ((uint8_t*)&data)+0);

  /* done */
  gpio_set(PORT_A, PIN_5, DIG_HIGH);

  /* convert to voltage */
  *volt  = data;
  *volt *= 5000.0;
  *volt /= 65536.0;
}

/*****************************************************************************/
/*                              adcx_task()                                  */
/*****************************************************************************/

void adcx_task (void)
{
  /* nothing to do here */
}

/*****************************************************************************/
/*                              adcx_init()                                  */
/*****************************************************************************/

void adcx_init (void)
{
  /* initialize CONV pin which controls ADC */
  gpio_mode(PORT_A, PIN_5, MODE_OUT, DIG_HIGH);
}