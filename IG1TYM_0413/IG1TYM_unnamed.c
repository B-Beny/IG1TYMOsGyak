#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSIZE 128

int main()
{
	char inBuffer[MSIZE];
	int p[2], nbytes, pid;

	if (pipe(p) < 0)
	{
		perror("Hiba tortent!\n");
		exit(1);
	}

	pid = fork();

	if (pid < 0)
		exit(2);

	if (pid == 0)
	{
		printf("Child most irja a pipeba!\n");
		write(p[1], "BB IG1TYM", MSIZE);
		printf("Child irt a pipe-ba, lehet olvasni\n");
	}

	else if (pid > 0 )
	{
		wait(NULL);
		printf("Parent most fog kiolvasni a pipebol!\n");
		read(p[0], inBuffer, MSIZE);
		printf("Parent ezt olvasta ki: %s\n", inBuffer);
	}

	return 0;
}
