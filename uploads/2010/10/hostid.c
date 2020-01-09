#include <stdio.h>
#include <unistd.h>

int 
main()
{
	printf("%ld\n", gethostid());
	return 0;
}

