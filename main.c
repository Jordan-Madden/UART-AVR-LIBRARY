/*
 * uart_sample_lib.c
 *
 * Created: 22/5/2020 8:55:53 PM
 * Author : Jordan Madden
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart_comm.h"
		
int main(void)
{
	DDRC = 0xFF;
	DDRD = 0b00000010;
	
	uart_init(51);							//9600 baud at 8MHz
	
	while(1)
	{
		uart_send(uart_receive() + 1);	//Receives a character and send the next one
		PORTC ^= 0xFF;						//Set all of the pins on PORTC to high
		_delay_ms(1000);
	}
	return 0;
}
