/***************************************************************************************
*   File name   :   whoami.c
*   Description :   Custom implementation of linux 'whoami' command
*   Input       :   void
*   Output      :   void
*   Author      :   Ritesh Jillewad
*   Date        :   17|02|2026
***************************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

/*
    ALGORITHM:
        The username is stored in the /etc/passwd.
        Step 1) Call geteuid() to get the effective userid of the user currently running the process.
        Step 2) Pass the euid to getpwuid() that searches systems database(/etc/passwd) for mathching record.
        Step 3) It will return a pointer to the passwd structure

        struct passwd{
            char *pw_name;
            ....
        };

    USAGE:
        ./mywhoami
        argv[0]
        
        argc = 1
*/

int main(int argc, char *argv[])
{
    uid_t uid = 0;
    struct passwd *pw = NULL;

    // Filters
    if(argc > 1)
    {
        printf("ERROR: Invalid number of arguments!\n");
        printf("TRY: ./mywhoami\n");
        return -1;
    }

    // Step 1) We need to get the effective userid of current runnign process
    uid = geteuid();

    // Step 2) Now we need to look for the password entry for that effective userid
    pw = getpwuid(uid);

    // Error checking
    if(pw == NULL)
    {
        printf("ERROR: whoami cannot find name for userID.\n");
        return -1;
    }

    // Step 3) Print the username
    printf("%s\n", pw -> pw_name);

    return 0;
}

