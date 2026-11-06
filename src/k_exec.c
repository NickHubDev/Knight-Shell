#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int knight_exec(char **args)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Pid Error");
		return 1;
	}
	else if (pid == 0)
	{
		execvp(args[0], args);
		perror("Exec Error");
		exit(1);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
	}
	return 0;
}
