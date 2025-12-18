#include "uart.h"
#include "log.h"
#include <string.h>

static char last_sent[100]; // buffer för simulerad sändning

void init_uart(void)
{
    log_info("UART: Init");
}

int uart_send(const char *data)
{
    if (data == NULL)
    {
        log_error("UART: data is NULL");
        return -1;
    }

    strncpy(last_sent, data, sizeof(last_sent) - 1);
    last_sent[sizeof(last_sent) - 1] = '\0';

    log_info("UART: Data sent");
    return 0;
}

int uart_receive(char *buffer, size_t size)
{
    if (buffer == NULL || size == 0)
    {
        log_error("UART: Invalid receive buffer");
        return -1;
    }

    strncpy(buffer, last_sent, size - 1);
    buffer[size - 1] = '\0';

    log_info("UART: Data received");
    return 0;
}
