/***************************************************************************************
*   File name   :   mymount.c
*   Description :   Custom implementation of linux 'mount' command
*   Input       :   void
*   Output      :   void
*   Author      :   Ritesh Jillewad
*   Date        :   18|02|2026
***************************************************************************************/

#include <stdio.h>
#include <sys/mount.h>

/*
    ALGORITHM:
        The mount command is used to mount the filesystem. It attaches a filesystem found on a device to the big system directory tree.
        Step 1) Check if it is a root user, as mount() requires root privileges
        Step 2) If root, then mount the filesystem from source to destination

    USAGE:
        ./mymount   sourceDevice    targetDirectory   [type]
        argv[0]       argv[1]           argv[2]       argv[3]
        
        argc = 4
*/

int main(int argc, char *argv[]) 
{
    char *source = NULL;                    // source is the physical location of content you want to attach
    char *target = NULL;                    // target is the mount point (contents of source will appear here)
    char *type = NULL;                      // tpye is the filesystem type (ex: "ext4", "vfat", "ntfs")

    int ret = 0;

    // Filters
    if(argc < 3)
    {
        printf("ERROR: Invalid number of arguments!\n");
        printf("TRY: ./mymount sourceDevice /dev/sb1  /mnt/external ext4\n");
        return -1;
    }

    source = argv[1];
    target = argv[2];

    // Specifying our own filesystem type
    if(argc > 3)
    {
        type = argv[3];
    }
    else
    {
        type = "ext4";                      // default
    }

    // Step 1: Check if it is root user or not
    if(geteuid() != 0)
    {
        printf("ERROR: You must be root user to perform this action!\n");
        return -1;
    }

    // Step 2: Use the mount() system call
    ret = mount(source, target, type, NULL, 0);
    if(ret == 0)
    {
        printf("Successfully mounted %s on %s using %s\n", source, target, type);
    }
    else
    {
        printf("ERROR: Unable to mount!\n");
        return -1;
    }

    return 0;
}
 