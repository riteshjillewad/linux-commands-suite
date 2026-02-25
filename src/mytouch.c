/***************************************************************************************
*   File name   :   mytouch.c
*   Description :   Custom implementation of linux 'touch' command
*   Input       :   void
*   Output      :   void
*   Author      :   Ritesh Jillewad
*   Date        :   18|02|2026
***************************************************************************************/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

/*
    ALGORITHM:
        The touch command is used to create a file
        Step 1) Use the open() system call to create the required file

    USAGE:
        ./mytouch       fileName
        argv[0]          argv[1]       
    
        argc = 2
*/

int main(int argc, char *argv[]) 
{
    int fd = 0;
    char *fileName = NULL;

    // Filters
    if(argc != 2)
    {
        printf("ERROR: Invalid number of arguments!\n");
        printf("TRY: ./mytouch  demo.txt\n");
        return -1;
    }

    fileName = argv[1];
    if(fileName == NULL)
    {
        printf("Filename missing!\n");
        return -1;
    }

    fd = open(fileName, O_CREAT | O_WRONLY | O_EXCL, 0664);
    if(fd == -1)
    {
        // Handling error codes
        if(errno == EACCES)
        {
            printf("ERROR: Permission denied!\n");
        }
        else if(errno == EEXIST)
        {
            printf("ERROR: File already exists!\n");
        }
        else if(errno == ENFILE)
        {
            printf("ERROR: The system-wide limit on the total number of open files has been reached!\n");
        }
        else
        {
            perror("open failed");
        }
        
        return -1;
    }

    close(fd);
    return 0;
}
 