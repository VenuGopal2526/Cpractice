#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct my_date_t
{
    uint8_t date;   // date 
    uint8_t month;  // month 
    uint16_t year;  // year 
} my_date_t;

typedef enum status_t
{
    SUCCESS,    // Function has successfully converted the string to structure 
    NULL_PTR,   // Function is given NULL pointers to work with 
    INCORRECT   // Incorrect values for date or month or year 
} status_t;

status_t string_to_date_converter(char* input_string, my_date_t* result_date)
{
    if (input_string == NULL || result_date == NULL) {
        return NULL_PTR;
    }

    char* endptr;
    result_date->date = strtol(input_string, &endptr, 10);
    if (*endptr != '/') {
        return INCORRECT;
    }

    result_date->month = strtol(endptr + 1, &endptr, 10);
    if (*endptr != '/') {
        return INCORRECT;
    }

    result_date->year = strtol(endptr + 1, &endptr, 10);
    if (*endptr != '\0') {
        return INCORRECT;
    }

    return SUCCESS;
}

int main()
{
    char input_string[10];
    scanf("%s", input_string);
    my_date_t result_date;
    status_t status = string_to_date_converter(input_string, &result_date);

    if (status == SUCCESS) {
        printf("Conversion successful:\n");
        printf("Date: %02u\n", result_date.date);
        printf("Month: %02u\n", result_date.month);
        printf("Year: %04u\n", result_date.year);
    } else if (status == NULL_PTR) {
        printf("Error: NULL pointers provided\n");
    } else if (status == INCORRECT) {
        printf("Error: Incorrect date format\n");
    }

    return 0;
}
