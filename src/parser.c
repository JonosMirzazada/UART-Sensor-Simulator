#include "parser.h"
#include "log.h"
#include <stdio.h>

// Tolk sensor-data
int parse_data(const char *data)
{
    if (data == NULL) {
        log_error("PARSER: data is NULL");
        return -1;
    }

    int temp = 0;
    int humidity = 0;

    // Läs data från format Temp=%d;Humidity=%d
    int result = sscanf(data, "Temp=%d;Humidity=%d", &temp, &humidity);

    if (result != 2) {
        log_error("PARSER: Invalid data format");
        return -1;
    }

    // Visa värden
    log_info("PARSER: Temp = %d C", temp);
    log_info("PARSER: Humidity = %d %%", humidity);

    return 0;
}
