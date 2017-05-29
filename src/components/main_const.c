#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

#include "../utils/readln.h"


int main(int argc, char **argv) {
	char buf[PIPE_BUF];
	int readBytes;

	while(readBytes = readln(0, buf, PIPE_BUF)) {

		write(1, buf, readBytes);

		write(1, ":", 1);
		write(1, argv[1], strlen(argv[1]));
		write(1, "\n", 1);

	}

	return 0;
}