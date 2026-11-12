#include "../headers/library.h"

int build_in(char *cmd)
{
    cmd[strcspn(cmd, "\r\n")] = 0;
    
    if (strcmp(cmd, "cd") == 0 || strncmp(cmd, "cd ", 3) == 0)
    {
        char *path = NULL;

        if (strcmp(cmd, "cd") == 0)
        {
            path = getenv("HOME");
            if (path == NULL)
            {
                fprintf(stderr, "knight: cd: variable $HOME no definida\n");
                return 1; 
            }
        }
        else
        {
            path = cmd + 3;
            
            while (*path == ' ') {
                path++;
            }
        }
        
        if (chdir(path) != 0)
        {
            perror("knight: cd");
            return 1; 
        }

        return 1; 
    }

    return 0;
}
