#include "sensor.h"
#include "log.h"

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void init_sensors(void)
{
    log_info("SENSOR: Init");

    /* Seed random generator (körs EN gång) */
    srand(time(NULL));
}

void read_sensor_data(char *buffer, size_t size)
{
    if (buffer == NULL || size == 0)
    {
        log_error("SENSOR: Invalid buffer");
        return;
    }

    int temp = 15 + rand() % 16;      // 15–30
    int humidity = 30 + rand() % 51;  // 30–80

    snprintf(buffer, size, "Temp=%d;Humidity=%d", temp, humidity);

    log_debug("SENSOR: Sensor data generated: %s", buffer);
}
