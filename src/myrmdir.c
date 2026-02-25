/***************************************************************************************
*   File name   :   myrmdir.c
*   Description :   Custom implementation of linux 'rmdir' command
*   Input       :   void
*   Output      :   void
*   Author      :   Ritesh Jillewad
*   Date        :   18|02|2026
***************************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

/*
    ALGORITHM:
        The rmdir is used to remove the directory
        Step 1) Check arguments
        Step 2) Use the rmdir() command to remove the directory

    USAGE:
        Case 1)
        ./myrmdir   directoryName
        argv[0]        argv[1]       
        argc = 2
*/

int main(int argc, char *argv[]) 
{
    int ret = 0;
    const char *directoryName = NULL;

    // Step 1) Filters
    if(argc != 2)
    {
        printf("ERROR: Invalid number of arguments!\n");
        printf("TRY: ./myrmdir directoryName\n");
        return -1;
    }

    directoryName = argv[1];

    // Step 2) Use the rmdir() system call
    ret = rmdir(directoryName);
    if(ret == -1)
    {
        // Handling error codes
        if(errno == EACCES)
        {
            printf("ERROR: Write access to the directory containing '%s' is not allowed.\n", directoryName);
        }
        else if(errno == ENOTEMPTY)
        {
            printf("ERROR: Directory '%s' is not empty!\n", directoryName);
        }
        else if(errno == ENOENT)
        {
            printf("ERROR: Directory '%s' does not exist.\n", directoryName);
        }
        else if(errno == ENOTDIR)
        {
            printf("ERROR: '%s' is not a directory.\n", directoryName);
        }
        else if(errno == EBUSY)
        {
            printf("ERROR: Directory '%s' is being used by the system or another process.\n", directoryName);
        }
        else
        {
            perror("ERROR: rmdir failed");
        }
        return -1;
    }

    return 0;
}
 