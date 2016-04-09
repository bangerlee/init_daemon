# init_daemon

init_daemon makes the pragrom to be a daemon, more about Linux daemon writing HOWTO, refer to the URL below:

http://www.netzmafia.de/skripten/unix/linux-daemon-howto.html

gcc -c init.c

gcc test.c init.o -o test_init

gcc test.c init.o -D DAEMON -o test_daemon

Both test_init and test_daemon write a message to /tmp/test.log every 10 seconds.

http://www.cnblogs.com/bangerlee/archive/2012/03/30/2412652.html