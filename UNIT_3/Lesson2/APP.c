#include "UART.h"
unsigned char string_buffer[100]="Learn-in-depth:<Alaa>";
void main(void)
{
	Uart_Send_String(string_buffer);
}

