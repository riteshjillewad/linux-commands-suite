/***************************************************************************************
*   File name   :   date.c
*   Description :   Custom implementation of linux 'date' command
*   Input       :   void
*   Output      :   void
*   Author      :   Ritesh Jillewad
*   Date        :   17|02|2026
***************************************************************************************/

#include <stdio.h>
#include <time.h>   
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    time_t rawtime = 0;
    struct tm *timeinfo;
    char buffer[MAX_BUFFER_SIZE];

    memset(buffer, '\0', sizeof(buffer));

    if(argc > 1)
    {
        printf("ERROR: Invalid number of arguments!\n");
        printf("TRY: ./mydate");
        return -1;
    }

    // Step 1: Get raw time from kernel (Seconds since Epoch)
    time(&rawtime);

    // Step 2: Convert to local time structure
    timeinfo = localtime(&rawtime);

    // Step 3: Format the time into a readable string
    // Format: "Tue Feb 17 14:45:00 IST 2026"
    // %a: Abbreviated weekday (Tue)
    // %b: Abbreviated month (Feb)
    // %d: Day of month (17)
    // %H:%M:%S: Time
    // %Z: Timezone name (IST, UTC, etc.)
    // %Y: Year (2026)
    strftime(buffer, sizeof(buffer), "%a %b %d %H:%M:%S %Z %Y", timeinfo);

    // Step 4: Print the result
    printf("%s\n", buffer);
    return 0;
}