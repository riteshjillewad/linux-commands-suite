/***************************************************************************************
*   File name   :   mycp.c
*   Description :   Custom implementation of linux 'cp' command
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
        The cp command is used to copy source to destination.

    USAGE:
        ./mycp     sourceFile     destFile
        argv[0]     argv[1]        argv[2]
        
        argc = 3

        Step 1) We need to open the source file using open()
        Step 2) Read the contents from the source file using read()
        Step 3) Write the contents of source file to destination file using write()
*/

int main(int argc, char *argv[])
{
    int sourceFd = 0;
    int destFd = 0;
    int bytesRead = 0;
    int ret = 0;

    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, '\0', sizeof(buffer));

    // Filters
    if(argc != 3)
    {
        printf("ERROR: Invalid number of arguments!\n");
        printf("TRY: ./mycp  sourceFile  destFile\n");
        return -1;
    }

    // Step 1: Open the source file
    sourceFd = open(argv[1], O_RDONLY);
    if(sourceFd == -1)
    {
        printf("ERROR: Source file does not exists!\n");
        printf("Please ensure source file exists.\n");
        return -1;
    }

    // Step 2: Open the destination file (create if not present)
    destFd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0777);
    if(destFd == -1)
    {
        printf("ERROR: Unable to open destination file!\n");
        close(sourceFd);
        return -1;
    }

    // Step 3: Copy the soruce file contents into the destination file contents
    while((bytesRead = read(sourceFd, buffer, sizeof(buffer))) > 0)
    {
        // Write the source file contents into the destination file contents
        ret = write(destFd, buffer, bytesRead);
        if(ret == -1)
        {
            printf("ERROR: Error writing to destination!\n");
            close(sourceFd);
            close(destFd);
            return -1;
        }
    }

    if(bytesRead == -1)
    {
        printf("ERROR: Error reading the source!\n");
        return -1;
    }

    close(sourceFd);
    close(destFd);

    printf("File copied successfully.\n");
    return 0;
}

 