#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../headers/library.h"

char *path(void)
{
    char *home_env;
    char *CONF;
    char *PROMPT;

    home_env = getenv("HOME");

    char home[512];

    strcpy(home, home_env);

    CONF = strcat(home, "/.config/ksh/config.sh");

    

    if (access(CONF, F_OK) != 0)
    {
        return NULL;
    }

    PROMPT = exec_sh(CONF);
    
    if (PROMPT == NULL)
    {
        return NULL;
    }

    return PROMPT;
}