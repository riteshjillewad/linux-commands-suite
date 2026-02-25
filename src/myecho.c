/***************************************************************************************
*   File name   :   echo.c
*   Description :   Custom implementation of linux 'echo' command
*   Input       :   void
*   Output      :   void
*   Author      :   Ritesh Jillewad
*   Date        :   17|02|2026
***************************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*
    ALGORITHM:
        echo command is used to display the line of text or string to standard output
        Step 1) Take the string from the command line argument 
        Step 2) Print it

    USAGE:
        ./myecho    string
        argv[0]     argv[1]
        
        argc = 2
*/

int main(int argc, char *argv[])
{
    // If we don't provide anything it prints newline
    if(argc == 1)
    {
        write(1, "\n", 1);
        return 0;
    }

    // Count the number of arguments and print them
    for(int i = 1; i < argc; i++)
    {
        write(1, argv[i], strlen(argv[i]));

        // To add space between words
        if(i < argc - 1)
        {
            write(1, " ", 1);
        }
    }
    
    // Always end with newline
    write(1, "\n", 1);

    return 0;
}
