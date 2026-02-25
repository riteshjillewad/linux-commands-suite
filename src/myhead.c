/***************************************************************************************
*   File name   :   myhead.c
*   Description :   Custom implementation of linux 'head' command
*   Input       :   void
*   Output      :   void
*   Author      :   Ritesh Jillewad
*   Date        :   25|02|2026
***************************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

/*
    ALGORITHM:
        The head command is used to print the first 10 lines of each file to the standard output.
        Step 1) Open the target file for reading
        Step 2) Read the file character by character
        Step 3) Print every character to the screen
        Step 4) Count every \n character found (used for line counting)
        Step 5) If count reaches 10 (default limit)
                    - Stop reading and close the file
        Step 6) Else, continue until the end of file (EOF)

    USAGE:
        ./myhead    fileName
        argv[0]     argv[1]
        
        argc = 2
*/

int main(int argc, char *argv[])
{
    int fd = 0;
    int newlineCount = 0;

    char ch = '\0';

    // Filters
    if(argc != 2)
    {
        printf("ERROR: Invalid number of arguments!\n");
        printf("TRY: ./myhead fileName\n");
        return -1;
    }

    // Step 1) Open the file for reading
    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("ERROR: Unable to open the file!\n");
        return -1;
    }

    // Step 2) Read the file character by character
    while(read(fd, &ch, 1) > 0)
    {
        // Step 3) Print every character to the screen
        printf("%c", ch);
        
        // Step 4) Count the number of newlines
        if(ch == '\n')
        {
            newlineCount++;
        }

        // Step 5) Default behaviour
        if(newlineCount == 10)
        {
            break;
        } 
    }

    close(fd);
    return 0;
}

 