/***************************************************************************************
*   File name   :   mydf.c
*   Description :   Custom implementation of linux 'df' command
*   Input       :   void
*   Output      :   void
*   Author      :   Ritesh Jillewad
*   Date        :   18|02|2026
***************************************************************************************/

#include <stdio.h>
#include <sys/statvfs.h>

#define MAX_BUFFER_SIZE 1024

/*
    ALGORITHM:
        The df command is used to get the information about the mounted filesystem.
        Step 1) Check if file is present using access()
        Step 2) If present use the unlink() command to remove the file

    USAGE:
        ./df         path
        argv[0]     argv[1]
        
        argc = 2
*/

int main(int argc, char *argv[]) 
{
    struct statvfs sobj;

    unsigned long total_blks = 0;                                   // Total blocks
    unsigned long free_blks = 0;                                    // Free blocks
    unsigned long used_blks = 0;                                    // Used blocks

    int percentage = 0;

    // Filters
    if(argc > 2) 
    {
        printf("ERROR: Invalid number of arguments!\n");
        printf("TRY: ./df or ./df path\n");
        return -1;
    }

    total_blks = sobj.f_blocks;                               
    free_blks = sobj.f_bavail;                                   
    used_blks = sobj.f_blocks - sobj.f_bfree;

    if(total_blks > 0)
    {
        percentage = (used_blks * 100) / (used_blks + free_blks);
    }

    printf("Filesystem      Blocks        Used     Available  Use%%\n");
    printf("%-15s %-12lu %-10lu %-10lu %3d%%\n", argv[1], total_blks, used_blks, free_blks, percentage);

    return 0;
}
 