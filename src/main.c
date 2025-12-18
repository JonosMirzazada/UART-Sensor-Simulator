#include "log.h"
#include "sensor.h"
#include "uart.h"
#include "parser.h"

int main(void)
{
    set_log_level(LOG_INFO); // TESTA: DEBUG / INFO / ERROR

    log_info("UART Sensor Simulator startar");

    init_sensors();
    init_uart();

    char data[100];
    read_sensor_data(data, sizeof(data));
    log_debug("Sensor data: %s", data);

    if (uart_send(data) != 0)
    {
        log_error("UART send failed");
        return -1;
    }

    char received[100];
    if (uart_receive(received, sizeof(received)) != 0)
    {
        log_error("UART receive failed");
        return -1;
    }

    if (parse_data(received) != 0)
    {
        log_error("Parsing failed");
    }

    log_info("Simulator klar");
    return 0;
}
