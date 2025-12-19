#include "sensor.h"
#include "log.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// Initiera sensorer (simulerat)
void init_sensors(void)
{
    log_info("SENSOR: Init");

    srand(time(NULL));
}

// Läser sensordata (skapar fake data)
void read_sensor_data(char *buffer, size_t size)
{
    if (buffer == NULL || size == 0) {
        log_error("SENSOR: Invalid buffer");
        return;
    }

    // Skapa slumpmässig temperatur och fuktighet
    int temp = 15 + rand() % 16;      // 15–30
    int humidity = 30 + rand() % 51;  // 30–80

    // Skriv till buffer
    snprintf(buffer, size, "Temp=%d;Humidity=%d", temp, humidity);

    // Logga att data skapades
    log_debug("SENSOR: Sensor data generated: %s", buffer);
}
