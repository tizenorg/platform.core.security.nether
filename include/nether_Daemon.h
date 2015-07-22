#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>

bool runAsDaemon()
{
    pid_t pid = fork();

    if (pid == -1)
        return (false);
    else if (pid != 0)
        exit (0);

    if (setsid() == -1)
        return (false);

    signal(SIGHUP,SIG_IGN);

    pid = fork();

    if (pid == -1)
        return (false);
    else if (pid != 0)
        _exit(0);

    if (chdir("/") == -1)
        return (false);

    umask(0);

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    if (open("/dev/null",O_RDONLY) == -1)
        return (false);

    if (open("/dev/null",O_WRONLY) == -1)
        return (false);

    if (open("/dev/null",O_RDWR) == -1)
        return (false);

    return (true);
}
