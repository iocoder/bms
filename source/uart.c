/*****************************************************************************/
/* File:    uart.c                                                           */
/* Date:    July 17th, 2021                                                  */
/* Author:  Ramses Nagib                                                     */
/* Desc:    UART interface implementation                                    */
/*****************************************************************************/

#include "string.h"

#include "uart.h"

/*****************************************************************************/
/*                          UART GLOBAL VARIABLES                            */
/*****************************************************************************/

/* RX buffer */
uint8_t uart_ready = 0;
uint8_t uart_count = 0;
char uart_buf[UART_BUFSIZE+1];

/*****************************************************************************/
/*                              uart_readl()                                 */
/*****************************************************************************/

void uart_readl(char *buf, uint8_t *result) {
  /* check if line is ready to be read */
  if (uart_ready == 1) {
    /* copy string */
    strcpy(buf, uart_buf);

    /* reset buffer */
    uart_count = 0;
    uart_ready = 0;

    /* success */
    *result = 1;
  } else {
    /* no data to read */
    *result = 0;
  }
}

/*****************************************************************************/
/*                             uart_writel()                                 */
/*****************************************************************************/

void uart_writel(char *buf, uint8_t *result) {
  /* loop over buffer */
  while (*buf != 0) {
    /* new line sends CR and LF */
    if (*buf == '\n') {
      /* Wait for empty transmit buffer (for the echo) */
      while ( !( UCSRA & (1<<UDRE)) );

      /* send carriage return */
      UDR = '\r';

      /* Wait for empty transmit buffer (for the echo) */
      while ( !( UCSRA & (1<<UDRE)) );

      /* send line feed */
      UDR = '\n';
    } else {
      /* Wait for empty transmit buffer (for the echo) */
      while ( !( UCSRA & (1<<UDRE)) );

      /* send character */
      UDR = *buf;
    }

    /* next character */
    buf++;
  }

  /* done */
  *result = 1;
}

/*****************************************************************************/
/*                              uart_task()                                  */
/*****************************************************************************/

void uart_task (void)
{
  /* do nothing */
}

/*****************************************************************************/
/*                              uart_init()                                  */
/*****************************************************************************/

void uart_init (void)
{
  /* Set UART baud rate */
  UBRRH = (unsigned char)((UART_PRESCALE>>8)&0xFF);
  UBRRL = (unsigned char)((UART_PRESCALE>>0)&0xFF);

  /* Double the baudrate for prescale calculation */
  UCSRA = (1<<U2X);

  /* Enable receiver and transmitter */
  UCSRB = (1<<RXCIE)|(1<<RXEN)|(1<<TXEN);

  /* Set frame format: 8data, 1stop bit */
  UCSRC = (1<<URSEL)|(3<<UCSZ0);
  sei();
}

/*****************************************************************************/
/*                             UART IRQ HANDLER                              */
/*****************************************************************************/

ISR(USART_RXC_vect)
{
  char byte;

  /* read data from UDR register */
  byte = UDR;

  /* we didn't hit line feed yet */
  if (uart_ready == 0) {

    /* check what the byte contains */
    if (byte == '\n') {

      /* ignore line feed */

    } else if (byte == '\r') {

      /* set ready flag */
      uart_ready = 1;

      /* append null terminator to the data in buffer */
      uart_buf[uart_count] = 0;

      /* Wait for empty transmit buffer (for the echo) */
      while ( !( UCSRA & (1<<UDRE)) );

      /* echo carriage return */
      UDR = '\r';

      /* Wait for empty transmit buffer (for the echo) */
      while ( !( UCSRA & (1<<UDRE)) );

      /* echo line feed */
      UDR = '\n';

    } else if (byte == '\b') {

      if (uart_count > 0) {
        /* one step back */
        uart_buf[--uart_count] = 0;

        /* Wait for empty transmit buffer (for the echo) */
        while ( !( UCSRA & (1<<UDRE)) );

        /* echo back the backspace character */
        UDR = byte;
      }

    } else {

     if (uart_count < UART_BUFSIZE) {

        /* store in buffer */
        uart_buf[uart_count++] = byte;

        /* Wait for empty transmit buffer (for the echo) */
        while ( !( UCSRA & (1<<UDRE)) );

        /* echo data */
        UDR = byte;

      }

    }
  }
}
