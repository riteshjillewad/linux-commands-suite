/***************************************************************************************
*   File name   :   myrm.c
*   Description :   Custom implementation of linux 'rm' command
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
        The rm command is used to remove files
        Step 1) Check if file is present using access()
        Step 2) If present use the unlink() command to remove the file

    USAGE:
        ./myrm     fileName
        argv[0]     argv[1]
        
        argc = 2
*/

int main(int argc, char *argv[]) 
{
    // Filters
    if(argc != 2) 
    {
        printf("ERROR: Invalid number of arguments!\n");
        printf("TRY: ./rm filename\n");
        return -1;
    }

    // Use unlink() to remove the file
    if(unlink(argv[1]) == 0)
    {
        printf("File removed successfully.\n");
    }
    else
    {
        printf("rm: cannot remove 'z.txt': No such file or directory");
    }
    
    return 0;
}
 
