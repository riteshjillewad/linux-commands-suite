/***************************************************************************************
*   File name   :   mytail.c
*   Description :   Custom implementation of linux 'tail' command
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
        The tail command is used to print the last 10 lines of each FILE to standard output.
        Step 1) Open the target file for reading
        Step 2) Go to the end of file
        Step 3) Read backwards
        Step 4) Stop when we have counted 10 newlines
        Step 5) Read from that current position forward to end of the file

    USAGE:
        ./mytail    fileName
        argv[0]     argv[1]
        
        argc = 2
*/

int main(int argc, char *argv[])
{
    int fd = 0;
    int newlineCount = 0;
    size_t fileSize = 0;
    off_t pos = 0;

    char ch = '\0';

    // Filters
    if(argc != 2)
    {
        printf("ERROR: Invalid number of arguments!\n");
        printf("TRY: ./mytail fileName\n");
        return -1;
    }

    // Step 1) Open the file for reading
    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("ERROR: Unable to open the file!\n");
        return -1;
    }

    // Step 2) Move to end of file
    fileSize = lseek(fd, 0, SEEK_END);

    // Step 3) Read backwards from end to find 10 newlines.
    // We will start from filesize - 2, to skip the last newline it it exists
    pos = fileSize - 1;
    while(pos > 0)
    {
        // Now the cursor is at second last position
        lseek(fd, pos, SEEK_SET);

        // Now start reading from that position until 10 newlines are encounterd
        read(fd, &ch, 1);

        // Checking for newline
        if(ch == '\n')
        {
            newlineCount++;
        }

        if(newlineCount == 10)
        {
            // Here we found the 10th newline, so we move the position of the cursor, as we don't want to print the current newline
            pos++;
            break;
        }
        pos--;
    }

    // Step 3: If filesize is small, we start from beginning
    if(pos <= 0)
    {
        lseek(fd, 0, SEEK_SET);
    }
    else
    {
        lseek(fd, pos, SEEK_SET);
    }

    // Step 4: Print everything from current position to end
    while(read(fd, &ch, 1) > 0)
    {
        write(STDOUT_FILENO, &ch, 1);
    }

    close(fd);
    return 0;
}

 