/**
 *author: bangerlee
 *description: A simple program for testing init program and daemon.
 *             First run 'gcc -c init.c' to generate init.o,
 *             exec 'gcc test.c init.o -o test_init' to generate test_init,
 *             exec 'gcc test.c init.o -D DAEMON -o test_daemon' to generate test_daemon.
 *             Both test_init and test_daemon write a message to /tmp/test.log every 10 seconds.
 *date:  2012/03/30
 */

#include <stdio.h>
#include <time.h>
#include <unistd.h>

void init_daemon(void);

int main(int argc, char** argv)
{

        FILE* fp;
        time_t t;

#ifdef DAEMON
        init_daemon();
#endif

        while(1)
        {
                sleep(10);
                if((fp = fopen("/tmp/test.log", "a")) >= 0)
                {
                        t = time(0);

#ifdef DAEMON
                        fprintf(fp,"DAEMON: ");
#endif

                        fprintf(fp, "I am still alive! at %s", asctime(localtime(&t)));
                        fclose(fp);
                }
        }


        return 0;
}