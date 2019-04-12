#include <avr/io.h>
#include "../Service_Layer/TypeDefs.h"
#include "FreeRTOS.h"

#include "queue.h"
#include "semphr.h"


#define       FCLK_SYSTEM     8000000UL

// Choose how you would like the UART to be driven
// INTERRUPT or POLLING
#define INTERRUPT 	0
#define POLLING 	1
#define UART_SYS 	INTERRUPT	// UART System




void          usart_init(unsigned  int baudrate);
void          usart_putc(unsigned char data);
unsigned char usart_getc(void);
void          usart_puts(char *str);
void 		  usart_gets( char* str );
