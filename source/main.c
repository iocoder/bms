/*****************************************************************************/
/* File:    main.c                                                           */
/* Date:    June 6th, 2021                                                   */
/* Author:  Ramses Nagib                                                     */
/* Desc:    Firmware entrypoint                                              */
/*****************************************************************************/

#include "wait.h"
#include "gpio.h"
#include "spix.h"
#include "amux.h"
#include "adcx.h"
#include "batv.h"
#include "uart.h"
#include "cmdx.h"

/*****************************************************************************/
/*                                 main()                                    */
/*****************************************************************************/

int main()
{
  /* setup modules */
  if (1) {
    wait_init();
    gpio_init();
    spix_init();
    amux_init();
    adcx_init();
    batv_init();
    uart_init();
    cmdx_init();
  }

  /* execute tasks */
  while (1) {
    wait_task();
    gpio_task();
    spix_task();
    amux_task();
    adcx_task();
    batv_task();
    uart_task();
    cmdx_task();
  }

  /* should never reach here */
  return 0;
}
