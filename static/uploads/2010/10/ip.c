#include <stdio.h>
#include <unistd.h>

int
main()
{
	long hostid;
	unsigned char a, b, c, d;

	hostid = gethostid();
	a = (hostid << 8) >> 24;
	b = hostid >> 24;
	c = (hostid << 24) >> 24;
	d = (hostid << 16) >> 24;

	printf("%d.%d.%d.%d\n", a, b, c, d);

	return 0;
}


