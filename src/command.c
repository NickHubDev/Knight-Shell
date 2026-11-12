#include <sys/wait.h>
#include "../headers/library.h"

int Kcommand(char **args)
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
