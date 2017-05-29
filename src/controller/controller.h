#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#include <errno.h>
#include <string.h>

#include "../utils/readln.h"

/* Simplificado! Penso que os args têm que ser um array de strings, certo? */
void node(int id, char *cmd, char* args);
void connect(int idB, int idF);
void disconnect(int idB, int idF);
void inject(int id, char* cmd, char* args);