/***************************************************************************************
*   File name   :   mysleep.c
*   Description :   Custom implementation of linux 'sleep' command
*   Input       :   void
*   Output      :   void
*   Author      :   Ritesh Jillewad
*   Date        :   18|02|2026
***************************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

/*
    ALGORITHM:
        The sleep command It suspends the calling thread until the number of real-time seconds specified has elapsed or a signal arrives that is not ignored.
        Step 1) Use atoi() to convert the ascii value to int value of seconds
        Step 2) Use the sleep() system call 

    USAGE:
        ./mysleep       n_seconds
        argv[0]          argv[1]       
    
        argc = 2
*/

int main(int argc, char *argv[]) 
{
    int ret = 0;
    unsigned int seconds = 0;

    // Filters
    if(argc != 2)
    {
        printf("ERROR: Invalid number of arguments!\n");
        printf("TRY: ./mysleep  5\n");
        return -1;
    }

    // Step 1: string to integet (ascii to int)
    seconds = atoi(argv[1]);                    
    if(seconds < 0)
    {
        printf("ERROR: Please provide a positive number of seconds.\n");
        return -1;
    }

    // Step 2: use the sleep() system call
    ret = sleep(seconds);
    if(ret > 0) 
    {
        printf("Sleep interrupted! %u seconds remaining.\n", ret);
    }

    return 0;
}
 