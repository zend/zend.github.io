#include <stdio.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <linux/if.h>
#include <linux/sockios.h>

#define MAX_IFINDEX 6

int
main()
{
	int i, sockfd, errno = 0;
	struct sockaddr_in *loc;
	struct ifreq req[1];

	char *ip = "65.49.24.250";
	
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0)
	{
		fprintf(stderr, "Unable to create socket.\n");
		return -1;
	}

	for (i = 0; i<= MAX_IFINDEX; ++i)
	{
		req->ifr_ifindex = i;
		if (ioctl(sockfd, SIOCGIFNAME, req) < 0)
		{
			fprintf(stderr, "ioctl error: %s\n", strerror(errno));
			continue;
		}
		if (ioctl(sockfd, SIOCGIFADDR, req) < 0)
		{
			fprintf(stderr, "ioctl error: %s\n", strerror(errno));
			continue;
		}
		loc = (struct sockaddr_in *) (&(req->ifr_ifru.ifru_addr));
		
		if (loc->sin_addr.s_addr == inet_addr(ip))
		{
			fprintf(stderr, "%s bind at %s.\n", ip, req->ifr_name);
			break;
		}
	}

	if (i == MAX_IFINDEX)
	{
		fprintf(stderr, "input IP error.\n");
		close(sockfd);
		return -2;
	}
	if (ioctl(sockfd, SIOCGIFHWADDR, req) < 0)
	{
		fprintf(stderr, "ioctl error: %s\n", strerror(errno));
		close(sockfd);
		return -3;
	}
	close(sockfd);

	printf("%02X%02X%02X%02X%02X%02X",
			req->ifr_hwaddr.sa_data[0] & 0xff,
			req->ifr_hwaddr.sa_data[1] & 0xff,
			req->ifr_hwaddr.sa_data[2] & 0xff,
			req->ifr_hwaddr.sa_data[3] & 0xff,
			req->ifr_hwaddr.sa_data[4] & 0xff,
			req->ifr_hwaddr.sa_data[5] & 0xff);
	return 0;
}

