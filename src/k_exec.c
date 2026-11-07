#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "raw_mode.h"

int knight_exec(char **args)
{
	disableRawm();
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Pid Error");
		enableRawm();
		return 1;
	}
	else if (pid == 0)
	{	
		execvp(args[0], args);
		perror("knight");
		exit(1);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
	}
	enableRawm();
	return 0;
}
