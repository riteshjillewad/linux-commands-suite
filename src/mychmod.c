/***************************************************************************************
*   File name   :   mychmod.c
*   Description :   Custom implementation of linux 'chmod' command
*   Input       :   void
*   Output      :   void
*   Author      :   Ritesh Jillewad
*   Date        :   25|02|2026
***************************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdlib.h>

/*
    ALGORITHM:
        The chmod command is used to change the permissions of a file
        Step 1) Recieve the filename and the new permissions from the user
        Step 2) Convert the permission from string to octal integer
        Step 3) Use the chmod() system call for changing permissions
        Step 4) Only the superuser can execute the chmod command
        Step 5) Read from that current position forward to end of the file

    USAGE:
        ./mychmod   filename    permission
        argv[0]     argv[1]     argv[2]

        argc = 3
*/

int main(int argc, char *argv[])
{
    mode_t mode = 0;
    int ret = 0;

    // Filter
    if(argc != 3)
    {
        printf("ERROR: Invalid number of arguments!\n");
        printf("TRY: %s <permission> <fileName>\n", argv[0]);
        return -1;
    }

    // Here we convert the string accepted permission into octal integer
    mode = (mode_t)strtol(argv[1], NULL, 8);

    // Calling the chmod() system call
    ret = chmod(argv[2], mode);

    if(ret == -1) 
    {
        if(errno == EACCES) 
        {
            printf("ERROR: Search permission denied for path component!\n");
        } 
        else if(errno == ENOENT) 
        {
            printf("ERROR: File '%s' not found!\n", argv[2]);
        } 
        else if(errno == EPERM) 
        {
            printf("ERROR: You are not the owner of '%s'!\n", argv[2]);
        } 
        else 
        {
            perror("ERROR: chmod failed");
        }
        return -1;
    }

    printf("Permissions of '%s' changed successfully.\n", argv[2]);
    return 0;
}

 