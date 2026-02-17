/***************************************************************************************
*   File name   :   myuname.c
*   Description :   Custom implementation of linux 'uname' command
*   Input       :   void
*   Output      :   void
*   Author      :   Ritesh Jillewad
*   Date        :   17|02|2026
***************************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <string.h>

/*
    ALGORITHM:
        The uname command is used to get name and information about current kernel.
        Step 1) Call the system call uname
        Step 2) Print the information from the utsname structure

    USAGE:
        ./myuname   -options
        argv[0]      argv[1]
        
        argc = 2

        struct utsname {
            char sysname[];     Operating system name (e.g., "Linux") 
            char nodename[];    Name within communications network to which the node is attached, if any
            char release[];     Operating system release (e.g., "2.6.28") 
            char version[];     Operating system version 
            char machine[];     Hardware type identifier 
        };
*/

int main(int argc, char *argv[])
{
    struct utsname buf;
    int ret = 0;

    if(argc > 2)
    {
        printf("ERROR: Invalid number of arguments!\n");
        printf("TRY: ./myuname or ./myuname -options\n");
        return -1;
    }

    // ./myuname --help
    if(argc == 2 && strcmp(argv[1], "--help") == 0)
    {
        printf("Usage: %s [OPTION]...\n", argv[0]);
        printf("Print certain system information.  With no OPTION, same as -s.\n\n");
        printf("  -a, --all                print all information\n");
        printf("  -s, --kernel-name        print the kernel name\n");
        printf("  -n, --nodename           print the network node hostname\n");
        printf("  -r, --kernel-release     print the kernel release\n");
        printf("  -v, --kernel-version     print the kernel version\n");
        printf("  -m, --machine            print the machine hardware name\n");
        printf("      --help               display this help and exit\n");

        return 0;
    }

    ret = uname(&buf);
    if(ret == -1)
    {
        perror("uname failed");
        return -1;
    }

    // CASE 1: No arguments provided (./myuname)
    // Default behavior is to print the kernel name (same as -s)
    if(argc == 1)
    {
        printf("%s\n", buf.sysname);
        return 0;
    }

    // CASE 2: Arguments provided (argc == 2)

    // ./myuname -a
    if(strcmp(argv[1], "-a") == 0) 
    {
        printf("%s %s %s %s %s\n", buf.sysname, buf.nodename, buf.release, buf.version, buf.machine);
    }
    
    // ./myuname -s
    else if(strcmp(argv[1], "-s") == 0)
    {
        printf("%s\n", buf.sysname);
    }

    // ./myuname -n
    else if(strcmp(argv[1], "-n") == 0)
    {
        printf("%s\n", buf.nodename);
    }

    // ./myuname -r
    else if(strcmp(argv[1], "-r") == 0)
    {
        printf("%s\n", buf.release);
    }

    // ./myuname -v
    else if(strcmp(argv[1], "-v") == 0)
    {
        printf("%s\n", buf.version);
    }

    // ./myuname -m
    else if(strcmp(argv[1], "-m") == 0)
    {
        printf("%s\n", buf.machine);
    }

    // Handle invalid flags (e.g., ./myuname -z)
    else
    {
        printf("uname: invalid option '%s'\n", argv[1]);
        printf("Try './myuname --help' for more information.\n");
        return -1;
    }

    return 0;
}

