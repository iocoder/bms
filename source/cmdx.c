/*****************************************************************************/
/* File:    cmdx.c                                                           */
/* Date:    July 17th, 2021                                                  */
/* Author:  Ramses Nagib                                                     */
/* Desc:    Command line interpreter                                         */
/*****************************************************************************/

#include "stdio.h"
#include "string.h"

#include "uart.h"
#include "cmdx.h"
#include "batv.h"

/*****************************************************************************/
/*                          CMDX GLOBAL VARIABLES                            */
/*****************************************************************************/

/* command buffer */
char cmdx_buf[UART_BUFSIZE+1];

/*****************************************************************************/
/*                              cmdx_task()                                  */
/*****************************************************************************/

void cmdx_task (void)
{
  uint8_t result = 0;
  uint16_t value = 0;
  char output[20] = {0};
  char *tok = NULL;

  /* read line from UART */
  uart_readl(cmdx_buf, &result);

  /* read something? */
  if (result == 1) {
    /* retrieve first token */
    tok = strtok (cmdx_buf, " \t\r\n");

    /* check which command to process */
    if (tok != NULL) {
      if (!strcmp(tok, "GET")) {
        /********* GET COMMAND ***********/
        /* get next token */
        tok = strtok (NULL, " \t\r\n");
        /* check if tok is OK */
        if (tok == NULL) {
          uart_writel("EXPECTED VAR NAME\n", &result);
        } else {
          /* parse variable name */
          if (!strcmp(tok, "B1")) {
            /* get B1 */
            batv_read(1, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B2")) {
            /* get B2 */
            batv_read(2, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B3")) {
            /* get B3 */
            batv_read(3, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B4")) {
            /* get B4 */
            batv_read(4, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B5")) {
            /* get B5 */
            batv_read(5, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B6")) {
            /* get B6 */
            batv_read(6, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B7")) {
            /* get B7 */
            batv_read(7, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B8")) {
            /* get B8 */
            batv_read(8, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B9")) {
            /* get B9 */
            batv_read(9, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B10")) {
            /* get B10 */
            batv_read(10, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B11")) {
            /* get B11 */
            batv_read(11, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B12")) {
            /* get B12 */
            batv_read(12, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B13")) {
            /* get B13 */
            batv_read(13, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B14")) {
            /* get B14 */
            batv_read(14, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B15")) {
            /* get B15 */
            batv_read(15, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B16")) {
            /* get B16 */
            batv_read(16, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B17")) {
            /* get B17 */
            batv_read(17, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B18")) {
            /* get B18 */
            batv_read(18, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B19")) {
            /* get B19 */
            batv_read(19, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B20")) {
            /* get B20 */
            batv_read(20, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B21")) {
            /* get B21 */
            batv_read(21, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B22")) {
            /* get B22 */
            batv_read(22, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B23")) {
            /* get B23 */
            batv_read(23, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B24")) {
            /* get B24 */
            batv_read(24, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B25")) {
            /* get B25 */
            batv_read(25, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B26")) {
            /* get B26 */
            batv_read(26, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B27")) {
            /* get B27 */
            batv_read(27, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B28")) {
            /* get B28 */
            batv_read(28, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B29")) {
            /* get B29 */
            batv_read(29, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B30")) {
            /* get B30 */
            batv_read(30, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B31")) {
            /* get B31 */
            batv_read(31, &value);
            sprintf(output, "%d\n", value);
          } else if (!strcmp(tok, "B32")) {
            /* get B32 */
            batv_read(32, &value);
            sprintf(output, "%d\n", value);
          } else {
            sprintf(output, "UNKNOWN VAR\n");
          }

          /* print output */
          uart_writel(output, &result);
        }
      } else {
        /******* UNKNOWN COMMAND *********/
        uart_writel("UNKNOWN COMMAND\n", &result);
      }
    }

    /* print prompt */
    uart_writel(">> ", &result);
  }
}

/*****************************************************************************/
/*                              cmdx_init()                                  */
/*****************************************************************************/

void cmdx_init (void)
{
  uint8_t result = 0;

  uart_writel("*****************************************\n", &result);
  uart_writel("            Welcome to BMS               \n", &result);
  uart_writel("                                         \n", &result);
  uart_writel(" This command line interface allows you  \n", &result);
  uart_writel(" to control the BMS board and read data. \n", &result);
  uart_writel("                                         \n", &result);
  uart_writel(" Copyright (C) Ozone and Ramses Nagib.   \n", &result);
  uart_writel("*****************************************\n", &result);
  uart_writel("\n", &result);
  uart_writel(">> ", &result);
}
