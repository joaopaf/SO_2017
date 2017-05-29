#include "controller.h"

#define READ 0
#define WRITE 1

typedef struct node_info {
	int pipe_in;
	int pipe_out;
} *INFO, node_info;

node_info nodes[10]; // Assumindo que os ids são contíguos...

void node(int id, char *cmd, char *args) {
	int pipe_in[2], pipe_out[2];
//esta a enviar metade para cada nodo em vez de mandar tudo para todos
	pipe(pipe_in);
	pipe(pipe_out);

	nodes[id].pipe_in = pipe_in[WRITE];
	nodes[id].pipe_out = pipe_out[READ];

	// printf("EXEC -> %d - %s\n", , strerror(errno));

	if(fork() == 0) {
		dup2(pipe_in[READ], 0);
		close(pipe_in[WRITE]);
		dup2(pipe_out[WRITE], 1);
		close(pipe_out[READ]);

		execlp(cmd, cmd, args, NULL);
	}

	close(pipe_in[READ]);
	close(pipe_out[WRITE]);

}

void connect(int idB, int idF) {
	if(fork() == 0) {
		dup2(nodes[idB].pipe_out, 0);
		dup2(nodes[idF].pipe_in, 1);

		execlp("cat", "cat", NULL);
	}
}

void inject(int id, char *cmd, char *args) {

	if(fork() == 0) {
		
		dup2(nodes[id].pipe_in, 1);
		close(0);

		execlp(cmd, cmd, args, NULL);

	}

	close(nodes[id].pipe_in);

}

void disconnect(int idB, int idF) {

}