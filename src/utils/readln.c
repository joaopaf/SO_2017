#include "readln.h"

ssize_t readln(int fildes, void *buf, size_t nbyte) {

	ssize_t n = 0, rc;
	char c, *buffer;

	buffer = (char*) buf;

	memset(buf, '\0', nbyte);

	while ((rc = read (fildes, &c, 1)) && n < (nbyte - 1)) {

		if (c == '\n' || c == '\0') {
			if (c == '\0' && n == 0)
				continue;
			else
				break;
		}
		buffer[n++] = c;

	}

	return n;
}