/***************************************************************************************
*   File name   :   mycat.c
*   Description :   Custom implementation of linux 'cat' command
*   Input       :   void
*   Output      :   void
*   Author      :   Ritesh Jillewad
*   Date        :   17|02|2026
***************************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

/*
    ALGORITHM:
        The cat command is used to read the file contents from command line

    USAGE:
        ./mycat     filename
        argv[0]      argv[1]
        
        argc = 2

        Step 1) We need to open the file using open()
        Step 2) Read the file contents using read()
        Step 3) Display the file contents
*/

int main(int argc, char *argv[])
{
    char buffer[MAX_BUFFER_SIZE];
    int bytesRead = 0;
    int fd = 0;

    memset(buffer, '\0', sizeof(buffer));

    // Filters
    if(argc < 2 || argc > 2)
    {
        printf("ERROR: Invalid number of arguments!\n");
        printf("TRY: ./mycat filename\n");
        return -1;
    }

    // Step 1: Opening the file
    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        perror("open failed");
        return -1;
    }

    // Step 2: Read the contents of file
    while((bytesRead = read(fd, buffer, sizeof(buffer))) > 0)
    {
        // Step 3: Print the contents of file
        write(1, buffer, bytesRead);
    }

    close(fd);
    return 0;
}

 