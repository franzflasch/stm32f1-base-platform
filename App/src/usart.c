#include <stm32f10x.h>
#include <stm32_configuration.h>
#include <usart.h>

#include <main.h>

void UART_put(uint8_t ch)
{
      USART_SendData(STM32_CONFIG_PRINTF_USART, (uint8_t) ch);
      //Loop until the end of transmission
      while(USART_GetFlagStatus(STM32_CONFIG_PRINTF_USART, USART_FLAG_TC) == RESET)
      {
      }
}


void UART_init(uartInfo_t *uartInfo, char *buffer, uint16_t maxBufLen)
{
	uartInfo->maxBufLen = maxBufLen;
	uartInfo->rxBuffer = buffer;
	uartInfo->bufReady = 1;
}


void UART_receiveHandler(uartInfo_t *uartInfo)
{
	printf("Got Message! %s\n\r", uartInfo->rxBuffer);
	applicationData.uartInfo.bufReady = 1;
}

