/***************************************************************************************
*   File name   :   stat.c
*   Description :   Custom implementation of linux 'stat' command
*   Input       :   void
*   Output      :   void
*   Author      :   Ritesh Jillewad
*   Date        :   17|02|2026
***************************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
    ALGORITHM:
        stat is command used to display the metadata about files and filesystems
        Step 1) Accept the filename from command line
        Step 2) Call access to check if file exists or not
        Step 3) Call stat() system call and get the file's metadata
        Step 4) Display the metadata

    USAGE:
        ./mystat    filename
        argv[0]     argv[1]
        
        argc = 2
*/

void displayPermissions(mode_t m)
{
    char arr[11] = "-----------";               // We will add letters in this string

    // File types
    if(S_ISDIR(m))
    {
        arr[0] = 'd';
    }
    if(S_ISLNK(m))
    {
        arr[0] = 'l';
    }

    // User permissions
    if(m & S_IRUSR)
    {
        arr[1] = 'r';
    }
    if(m & S_IWUSR)
    {
        arr[2] = 'w';
    }
    if(m & S_IXUSR)
    {
        arr[3] = 'x';
    }

    // Group permissions
    if(m & S_IRGRP)
    {
        arr[4] = 'r';
    }
    if(m & S_IWGRP)
    {
        arr[5] = 'w';
    }
    if(m & S_IXGRP)
    {
        arr[6] = 'x';
    }

    // Other permissions
    if(m & S_IROTH)
    {
        arr[7] = 'r';
    }
    if(m & S_IWOTH)
    {
        arr[8] = 'w';
    }
    if(m & S_IXOTH)
    {
        arr[9] = 'x';
    }

    printf("File permission: %s\n", arr);
}

int main(int argc, char *argv[])
{
    int ret = 0;
    struct stat sobj;

    // Filters
    if(argc > 2)
    {
        printf("ERROR: Invalid number of arguments!\n");
        printf("TRY: ./mystat filename\n");
        return -1;
    }

    if(access(argv[1], F_OK) == 0)
    {
        ret = stat(argv[1], &sobj);
        if(ret == -1)
        {
            printf("ERROR: Unable to fetch the statistical information!\n");
            return -1;
        }

        printf("Filename: %s\n", argv[1]);
        printf("Filesize: %ld bytes\n", (long)sobj.st_size);
        displayPermissions(sobj.st_mode);
        printf("Inode number: %ld\n", (long)sobj.st_ino);
        printf("Number of hardlinks: %ld\n", (long)sobj.st_nlink);
        printf("UserID of owner: %ld\n", (long)sobj.st_uid);
        printf("GroupID of owner: %ld\n", (long)sobj.st_gid);

    }
    else
    {
        printf("stat: cannot stat '%s': No such file or directory (os error 2)\n", argv[1]);
        return -1;
    }

    return 0;
}
