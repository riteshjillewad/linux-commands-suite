/***************************************************************************************
*   File name   :   mypwd.c
*   Description :   Custom implementation of linux 'pwd' command
*   Input       :   void
*   Output      :   void
*   Author      :   Ritesh Jillewad
*   Date        :   17|02|2026
***************************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

/*
    ALGORITHM:
        Step 1) Call the system call getcwd(). getcwd() interacts with kernel and gives us the current working directory
        Step 2) Print the buffer value to the console

    USAGE:
        ./mypwd
        argv[0]
        
        argc = 1
*/

int main(int argc, char *argv[])
{
    char buffer[PATH_MAX];

    // Filters
    if(argc > 1)
    {
        printf("ERROR: Invalid number of arguments!\n");
        printf("TRY: ./mypwd\n");
        return -1;
    }

    // Cleaning the buffer
    memset(buffer, '\0', sizeof(buffer));

    // Step 1: Use the getcwd() command to get the path
    if(getcwd(buffer, sizeof(buffer)) == NULL) 
    {
        perror("getcwd failed");
        return -1;
    }

    // Setp 2: Now we need to print the value
    printf("%s\n", buffer);

    return 0;
}


