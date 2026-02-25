/***************************************************************************************
*   File name   :   myumount.c
*   Description :   Custom implementation of linux 'umount' command
*   Input       :   void
*   Output      :   void
*   Author      :   Ritesh Jillewad
*   Date        :   18|02|2026
***************************************************************************************/

#include <stdio.h>
#include <sys/mount.h>
#include <errno.h>

/*
    ALGORITHM:
        The umount system call is used to remove the attachment of the(topmost) filesystem mounted on target
        Step 1) Check if it is a root user, as umount() requires root privileges
        Step 2) If root, then umount the filesystem mounted on target

    USAGE:
        ./mymount     target
        argv[0]       argv[1]       
    
        argc = 2
*/

int main(int argc, char *argv[]) 
{
    char *target = NULL;
    int ret = 0;

    // Filters
    if(argc < 2)
    {
        printf("ERROR: Invalid number of arguments!\n");
        printf("TRY: ./myunmount <target>\n");
        return -1;
    }

    target = argv[1];

    // Step 1: Check if it is root user or not
    if(geteuid() != 0)
    {
        printf("ERROR: You must be root user to perform this action!\n");
        return -1;
    }

    // Step 2: Use the unmount() system call
    ret = umount(target);
    if(ret == 0)
    {
        printf("Successfully unmounted %s\n", target);
    }
    else
    {        
        // Handling error codes
        if(errno == EBUSY)
        {
            printf("ERROR: target could not be unmounted because it is busy.\n")
        }
        else if(errno == EFAULT)
        {
            printf("ERROR: target points outside the user address space.\n")
        }
        else if(errno == EINVAL)
        {
            printf("ERROR: target is not mount point.\n");
        }
        else
        {
            perror("ERROR: unable to mount");
        }

        return -1;
    }
    return 0;
}
 