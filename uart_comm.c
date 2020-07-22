/*
 * uart_comm.c
 *
 * Created: 22/5/2020 9:30:26 PM
 * Author: Jordan Madden
 *
 * This library is intended for use with the AtMega16/32 micro-controller
 */ 

#include "uart_comm.h"

void uart_init(unsigned int baud)
{
	//Set Baud Rate
	UBRRH = (unsigned char)(baud>>8);
	UBRRL = (unsigned char)baud;

	//Enable Transmitter and Receiver
	UCSRB = (1<<RXEN)|(1<<TXEN);
	
	//Set frame format: 8 data bits, 2 stop bits
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}

unsigned char uart_receive()
{
	//Wait for data to be received
	while (!(UCSRA & (1<<RXC)));

	//Acquire and return received data from the buffer
	return UDR;
}

void uart_send(unsigned char word)
{
	//Wait for empty transmit buffer
	while(!(UCSRA & (1<<UDRE)));

	//Put data into the buffer and send it
	UDR  = word;
}

void send_string(char *str)
{
	unsigned int i = 0;
	
	while(str[i] != 0)
	{
		usart_send(str[1]);
	}
}

void new_line(void)
{
	usart_send(CR);		//Send Carriage Return
	usart_send(LF);		//Send Line Feed
}

