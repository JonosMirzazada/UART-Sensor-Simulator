#include "uart.h"
#include "log.h"
#include <string.h>

static char last_sent[100]; // Simulerad sändnings-buffer

// Initiera UART (simulerat)
void init_uart(void)
{
    log_info("UART: Init");
}

// Skicka data via UART
int uart_send(const char *data)
{
    if (data == NULL) {
        log_error("UART: data is NULL");
        return -1;
    }

    // Kopiera till intern buffer
    strncpy(last_sent, data, sizeof(last_sent) - 1);
    last_sent[sizeof(last_sent) - 1] = '\0';

    log_info("UART: Data sent");
    return 0;
}

// Ta emot data via UART
int uart_receive(char *buffer, size_t size)
{
    if (buffer == NULL || size == 0) {
        log_error("UART: Invalid receive buffer");
        return -1;
    }

    // Kopiera från intern buffer
    strncpy(buffer, last_sent, size - 1);
    buffer[size - 1] = '\0';

    log_info("UART: Data received");
    return 0;
}
