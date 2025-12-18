#ifndef SENSOR_H
#define SENSOR_H

#include <stddef.h>

void init_sensors(void);
void read_sensor_data(char *buffer, size_t size);

#endif
