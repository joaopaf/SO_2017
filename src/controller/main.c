#include <stdio.h>
#include <sys/wait.h>

#include "controller.h"

int main() {

	node(1, "build/const", "10");
	node(2, "build/const", "11");
	// node(3, "build/const", "12");
	node(4, "tee", "output/out.txt");


	connect(1, 2);
	connect(2, 4);
	// connect(3, 4);
	// connect(2, 4);

	inject(1, "ping", "google.pt");
	
	wait(NULL);

	return 0;
}