#ifndef UART_H
#define UART_H

#include <stddef.h>

void init_uart(void);
int uart_send(const char *data);
int uart_receive(char *buffer, size_t size);

#endif
