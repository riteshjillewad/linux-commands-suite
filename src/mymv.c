/***************************************************************************************
*   File name   :   mymv.c
*   Description :   Custom implementation of linux 'mv' command
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
        The mv command is used to move/rename files
        Step 1) Use the rename() command to move/rename files

    USAGE:
        ./mymv     sourceFile     destFile
        argv[0]     argv[1]        argv[2]
        
        argc = 3
*/

int main(int argc, char *argv[]) 
{
    // Filters
    if(argc != 3) 
    {
        printf("ERROR: Invalid number of arguments!\n");
        printf("TRY: ./mymv source dest\n");
        return -1;
    }

    // Use rename() to move/rename files
    if(rename(argv[1], argv[2]) == 0) 
    {
        printf("Renamed/Moved '%s' to '%s' successfully.\n", argv[1], argv[2]);
    } 
    else 
    {
        perror("mymv failed");
        return -1;
    }

    return 0;
}
 