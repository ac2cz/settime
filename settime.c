/*
 * settime.c
 *
 *  Created on: Jan 19, 2024
 *      Author: g0kla
 */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>

int main(int argc, char *argv[])  {

	if (argc != 2) {
		printf("Usage: settime <unixtime>\n");
		exit(1);
	}

	struct timeval tval;
	time_t secs = strtol(argv[1], (char **)NULL, 10);

	tval.tv_usec = 0;
	tval.tv_sec = secs;
	if (settimeofday(&tval, 0) != 0) {
		printf ("error %d setting time to %ld - %s\n", errno, tval.tv_sec, strerror(errno));
		exit(errno);
	} else {
		printf("Setting time to %ld secs\n",secs);
	}
}
