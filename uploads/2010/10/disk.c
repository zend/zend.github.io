#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/hdreg.h>

int
main()
{
	int fd;
	struct hd_driveid hid;

	fd = open("/dev/sda", O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "open hard disk device failed.\n");
		return 1;
	}

	if (ioctl(fd, HDIO_GET_IDENTITY, &hid) < 0)
	{
		fprintf(stderr, "ioctl error\n");
		return 2;
	}
	close(fd);
	printf("%s\n", hid.serial_no);

	return 0;
}

