/***************************************************************************************
*   File name   :   ls.c
*   Description :   Custom implementation of linux 'ls' command
*   Input       :   void
*   Output      :   void
*   Author      :   Ritesh Jillewad
*   Date        :   17|02|2026
***************************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

/*
    ALGORITHM:
        ls command is used to list the contents of a directory
        Step 1) 

    USAGE:
        ./myls    
        argv[0]     
        
        argc = 1
*/

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    int ret = 0;

    // Filters
    if(argc > 2)
    {
        printf("ERROR: Invalid number of arguments!\n");
        printf("TRY: ./myls\n");
        return -1;
    }

    // Step 1: Open the directory
    dp = opendir(".");
    if(dp == NULL)
    {
        perror("opendir failed");
        return -1;
    }

    // Step 2: Now read the contents of directory
    while((ptr = readdir(dp)) != NULL)
    {
        if((strcmp(ptr -> d_name, ".")) && (strcmp(ptr -> d_name, "..")) != 0)
        {
            printf("%s\n", ptr -> d_name);
        }
    }

    // Step 3: Close the directory
    closedir(dp);

    return 0;
}
