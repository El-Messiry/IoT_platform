
#include <avr/io.h>
#include <avr/interrupt.h>
#include "usart_driver.h"


void usart_init(unsigned  int baudrate)
{
	//Set baud rate
	unsigned short int UBRRVAL=(FCLK_SYSTEM/(baudrate*16UL))-1;
	UBRRL=UBRRVAL; 			//low byte
	UBRRH=(UBRRVAL>>8); 	//high byte

	//Set data frame format: asynchronous mode,no parity, 1 stop bit, 8 bit size
	UCSRC=(1<<URSEL)|(0<<UMSEL)|(0<<UPM1)|(0<<UPM0)|(0<<USBS)|(0<<UCSZ2)|(1<<UCSZ1)|(1<<UCSZ0); 

	//Enable Transmitter and Receiver
	UCSRB=(1<<RXEN)|(1<<TXEN);
}


#if (UART_SYS == POLLING) //cad rc
unsigned char usart_getc( void )
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) );
	/* Get and return received data from buffer */
	return UDR;
}
void usart_putc( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)));
	/* Put data into buffer, sends the data */
	UDR = data;
}

void usart_puts( char* str )
{
	short int i=0;
	while(str[i])
	{
		usart_putc(str[i]);
		i++;
	}
}

void usart_gets( char* str )
{
	short int i=0;

	while(str[i-1]!="\n")
	{
		str[i]=usart_getc();
		i++;
	}

}
#else if UART_SYS == INTERRUPT





// RX Interrupt Handler
ISR(USART_RXC_vect){
	u8 byte = UDR;	// receive byte
	xQueueSendToBackFromISR(Q_Uart_RX,&byte,0);	// send received byte to T_SysComm
}


// TX Interrupt Handler
ISR(USART_TXC_vect){
	u8 byte ;	// byte holder to receive byte coming from queue
	// implement how to handle the queue data ....
		UDR=byte; // load byte to UDR and transmit
	}
}


#endif
