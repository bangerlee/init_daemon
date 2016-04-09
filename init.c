/*
 *author: bangerlee
 *description: init_daemon makes the pragrom to be a daemon,
 *             more about Linux daemon writing HOWTO,refer to the URL below.
 *             http://www.netzmafia.de/skripten/unix/linux-daemon-howto.html
 *date: 2012/03/30
 */

#include <unistd.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>

void init_daemon(void)
{
        int pid;
        int i;

        if(pid = fork())
        {
                exit(0);
        }
        else if(pid < 0)
        {
                exit(1);
        }
        setsid();

        if(pid = fork())
        {
                exit(0);
        }
        else if(pid < 0)
        {
                exit(1);
        }

        for(i = 0; i < NOFILE; i++)
        {
                close(i);
        }

        chdir("/tmp");
        umask(0);

        return;
}
