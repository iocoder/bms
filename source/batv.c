/*****************************************************************************/
/* File:    batv.c                                                           */
/* Date:    June 6th, 2021                                                   */
/* Author:  Ramses Nagib                                                     */
/* Desc:    Battery voltage probing                                          */
/*****************************************************************************/

#include "amux.h"
#include "adcx.h"
#include "sseg.h"
#include "wait.h"
#include "batv.h"

/*****************************************************************************/
/*                                Globals                                    */
/*****************************************************************************/

uint8_t  batv_last = 0;
double   batv_volt[33] = {0};

/*****************************************************************************/
/*                              batv_read()                                  */
/*****************************************************************************/

void batv_read (uint8_t index, uint16_t *volt) {
  *volt = (batv_volt[index] - batv_volt[index-1]) + 0.5;
}

/*****************************************************************************/
/*                              batv_task()                                  */
/*****************************************************************************/

void batv_task (void)
{
  int indx;
  double volt;

  /* battery index to read */
  indx = batv_last + 1;

  /* select next battery */
  amux_sel(indx);

  /* read battery voltage */
  adcx_read(&volt);

  /* reverse voltage division */
  if (indx <= 8) {
    volt *= 10 + 59;
    volt /= 10;
  } else if (indx <= 16) {
    volt *= 10 + 130;
    volt /= 10;
  } else if (indx <= 24) {
    volt *= 10 + 200;
    volt /= 10;
  } else if (indx <= 32) {
    volt *= 10 + 274;
    volt /= 10;
  }

  /* store in array */
  batv_volt[indx] = volt;

  /* next battery */
  batv_last = (batv_last + 1) % 32;
}

/*****************************************************************************/
/*                              batv_init()                                  */
/*****************************************************************************/

void batv_init (void)
{
  /* nothing to do here. */
}