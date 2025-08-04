#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convertTimeTo24HourFormat(const char* input) {
    int hour;
    char period[3];
    char* converted = malloc(9); 

    
    strncpy(period, input + 8, 2);
    period[2] = '\0';

   
    sscanf(input, "%2d", &hour);

    
    if (strcmp(period, "AM") == 0 && hour == 12) {
        hour = 0;
    } else if (strcmp(period, "PM") == 0 && hour != 12) {
        hour += 12;
    }
    snprintf(converted, 9, "%02d%s", hour, input + 2);

    return converted;
}

int main() {
    char input[11]; 
    
    printf("Enter time in 12-hour format (e.g. 07:05:45PM): ");
    scanf("%10s", input);

    char* result = convertTimeTo24HourFormat(input);
    printf("24-hour format: %s\n", result);

    free(result);
    return 0;
}
