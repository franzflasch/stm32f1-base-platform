#ifndef USART_H
#define USART_H

typedef struct uartInfo_s
{
	uint16_t maxBufLen;
	char *rxBuffer;
	uint8_t bufReady;

}uartInfo_t;

void UART_put(uint8_t ch);
void UART_init(uartInfo_t *uartInfo, char *buffer, uint16_t maxBufLen);
void UART_receiveHandler(uartInfo_t *uartInfo);

#endif /*USART_H */
