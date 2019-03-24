#include <avr/io.h>

#define       FCLK_SYSTEM     8000000UL

void          usart_init(unsigned  int baudrate);
void          usart_putc(unsigned char data);
unsigned char usart_getc(void);
void          usart_puts(char *str);
void 		  usart_gets( char* str );
