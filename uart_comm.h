/*
 * uart_comm.h
 *
 * Created: 22/5/2020 9:29:58 PM
 *  Author: Jordan Madden
 *
 * This library is intended for use with the AtMega16/32 micro-controller
 */ 


#ifndef UART_COMM_H_
#define UART_COMM_H_

#define F_CPU 8000000UL

#define CR 0x00
#define LF 0x0A

void		  send_string(char *);						  //Sends a string of characters
void		  uart_init(unsigned int);					//Sets the registers necessary for the protocol to work - baud = 51
void		  uart_send(unsigned char);			  	//Sends a single character
unsigned char uart_receive(void);						//Receives a single character
 

#endif /* USART_COMM_H_ */
