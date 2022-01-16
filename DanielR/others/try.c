/// exec -> execvp (passing arguments with pointer)
/// exec program passed by arg[1]...argv[n] to this program argv[0]
/// simulation of own terminal program
///////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>

#define error(a) {perror(a); exit(1);};

void main(int argc, char *argv[]) {
	pid_t child;
	int modo, status;

	if (strcmp(argv[argc-1],"&")== 0) { // concurrent mode
		argv[argc-1] = NULL;
		argc = argc - 1;
		modo = 1;
	} else if (strcmp(argv[argc-1],";")== 0) {  // secuential mode
		argv[argc-1] = NULL;
		argc = argc - 1;
		modo = 0;
	} else {
		modo = 0;
    }

	child = fork();
	switch(child) {
		case -1:
			perror("fork");
			exit(1);
		case 0:
            argv++;
			if (execvp(argv[0], argv) == -1) {
				perror("execvp");
				exit(1);
			}
			break;
		default:
			if (modo == 0)
				wait(&status);
			break;
	}
}
