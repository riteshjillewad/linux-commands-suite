# 🐧 Linux Command Suite
The Linux Command Suite is a **collection of custom implementations of fundamental Linux utilities written in C**. Instead of relying on existing GNU utilities, we developed our own versions of important commands to understand their internal working at the OS level. Each command is uniquely identified with the postfix letter _"my"_(ex `myls`, `mypwd`, `mycp`). **This project demonstrates deep understanding of Linux internals, system calls, file systems, and process management.**

## 📌 Project Objective
The goal of this project is to:
* Re-implement commonly used Linux commands
* Use system calls wherever required
* Understand file descriptors, processes, directories, and permissions
* Strengthen low-level C programming skills
* Learn how real UNIX utilities are built

## 🛠️ Implemented Commands
The following commands have been implemented using native C system calls.

| Command | Description | Core System Calls Used | Category |
|----------|------------|------------------------|-----------|
| `mycat` | Displays file contents to standard output. | `open()`, `read()`, `write()` | File I/O |
| `mychmod` | Changes file permissions (supports octal mode). | `chmod()`, `strtol()` | File Permissions |
| `mycp` | Copies content from a source file to a destination file. | `open()`, `read()`, `write()` | File I/O |
| `mydate` | Displays current system date and time. | `time()`, `localtime()`, `strftime()` | System Information |
| `mydf` | Reports filesystem disk space usage. | `statvfs()` | Filesystem |
| `myecho` | Displays a line of text to standard output. | `write()` | File I/O |
| `myhead` | Outputs the first 10 lines of a file. | `open()`, `read()` | File I/O |
| `mytail` | Outputs the last 10 lines of a file. | `lseek()`, `read()`, `write()` | File I/O |
| `myls` | Lists contents of the current directory. | `opendir()`, `readdir()`, `closedir()` | Directory Handling |
| `mymkdir` | Creates new directories (supports `-m` option). | `mkdir()` | Directory Management |
| `mymount` | Attaches a filesystem to the directory tree (requires root privileges). | `mount()`, `geteuid()` | Filesystem Management |
| `myunmount` | Detaches a mounted filesystem (requires root privileges). | `umount()`, `geteuid()` | Filesystem Management |
| `mymv` | Moves or renames files. | `rename()` | File Management |
| `mypwd` | Prints the absolute path of the current working directory. | `getcwd()` | Directory Handling |
| `myrm` | Removes (unlinks) files. | `unlink()` | File Management |
| `myrmdir` | Removes empty directories. | `rmdir()` | Directory Management |
| `mysleep` | Suspends execution for a specified interval. | `sleep()`, `atoi()` | Process Control |
| `mystat` | Displays detailed metadata about a file. | `stat()`, `access()` | File Metadata |
| `mytouch` | Creates a new empty file or updates timestamp. | `open()` | File Management |
| `myuname` | Prints system and kernel information. | `uname()` | System Information |
| `mywhoami` | Displays the username of the current effective user. | `geteuid()`, `getpwuid()` | User Management |

