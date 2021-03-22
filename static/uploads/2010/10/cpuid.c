#include <stdio.h>

int
main()
{
	unsigned int eax = 0, edx = 0, ecx = 0;
	asm volatile ("cpuid"
			: "=a"(eax), "=d"(edx)
			: "a"(0x01)
			);

	if (edx & (1 << 17))
	{
		asm volatile ("cpuid"
				: "=c"(ecx), "=d"(edx)
				: "a"(0x03)
				);

		printf("Serial Number: %04x-%04x-%04x-%04x-%04x-%04x\n",
				eax >> 16, eax << 16,
				edx >> 16, edx << 16,
				ecx >> 16, ecx << 16);

		return 0;
	}
	else
	{
		fprintf(stderr, "can not get cpu serial number.\n");
		return 1;
	}
}

