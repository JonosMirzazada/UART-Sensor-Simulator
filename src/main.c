#include <stdio.h>
#include "sensor.h"
#include "uart.h"
#include "parser.h"
#include "log.h"

int main() {
    // Starta simulatorn
    log_info("MAIN: UART Sensor Simulator startar...");

    // Initiera sensorer och UART
    init_sensors();
    init_uart();

    // Skapa buffer för sensordata
    char data[100];
    read_sensor_data(data, sizeof(data));

    // Skicka data via UART med felkontroll
    if (uart_send(data) != 0) {
        log_error("MAIN: UART send failed");
        return -1;
    }

    // Ta emot data via UART
    char received[100];
    if (uart_receive(received, sizeof(received)) != 0) {
        log_error("MAIN: UART receive failed");
        return -1;
    }

    // Tolk data
    if (parse_data(received) != 0) {
        log_error("MAIN: Parsing failed");
    }

    // Simulatorn är klar
    log_info("MAIN: Simulator klar!");
    return 0;
}
