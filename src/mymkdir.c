/***************************************************************************************
*   File name   :   mymkdir.c
*   Description :   Custom implementation of linux 'mkdir' command
*   Input       :   void
*   Output      :   void
*   Author      :   Ritesh Jillewad
*   Date        :   18|02|2026
***************************************************************************************/

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

/*
    ALGORITHM:
        The mkdir command is used to make a directory
        Step 1) Check arguments
        Step 2) Use the mkdir() command to create the directory

    USAGE:
        Case 1)
        ./mymkdir   directoryName
        argv[0]        argv[1]       
        argc = 2

        Case 2)
        /mymkdir    -m        700    myfolder
        argv[0]   argv[1]   argv[2]   argv[3]        
        argc = 4
*/

int main(int argc, char *argv[]) 
{
    const char *directoryName = NULL;
    mode_t mode = 0;
    int ret = 0;

    // Step 1: Filters
    if((argc == 4) && (strcmp(argv[1], "-m")) == 0)
    {
        // Case 2: User provided the permissions for the directory
        mode = strtol(argv[2], NULL, 8);
        directoryName = argv[3];
    }
    // Case 1: Only directory name provided
    else if(argc == 2)
    {
        mode = 0775;                                                // default permission for directory
        directoryName = argv[1];
    }
    else
    {
        printf("ERROR: Invalid number of arguments!\n");
        printf("TRY: ./mymkdir directoryName or ./mymkdir -m mode directoryName\n");
        return -1;
    }

    // Step 2: Call the mkdir() system call
    ret = mkdir(directoryName, mode);
    if(ret == -1)
    {
        // Handling error codes
        if(errno == EACCES)
        {
            printf("ERROR: The parent directory does not allow write permission to the process!\n");
        }
        else if(errno == EDQUOT)
        {
            printf("ERROR: The user's quota of disk blocks or inodes on the filesystem has been exhausted!\n");
        }
        else if(errno == EEXIST)
        {
            printf("ERROR: Directory already exists!\n");
        }
        else if(errno == ENOMEM)
        {
            printf("ERROR: Insufficient kernel memory was available!\n");
        }
        else if(errno == ENOSPC)
        {
            printf("ERROR: The new directory cannot be created because the user's disk quota is exhausted!\n");
        }
        else if(errno == EPERM)
        {
            printf("ERROR: Filesystem does not support the creation of directories!\n");
        }
        else
        {
            perror("ERROR: mkdir failed");
        }

        return -1;
    }
    return 0;
}
 