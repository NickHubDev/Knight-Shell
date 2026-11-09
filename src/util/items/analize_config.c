#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "analize_config.h"

char *path(void)
{
    FILE *HOME_PATH = popen("echo $HOME", "r");

    char buffer[1024];
    char *home;

    if (HOME_PATH == NULL)
    {
        printf("ERROR!");
    }

    while (fgets(buffer, sizeof(buffer), HOME_PATH) != NULL)
    {
        strcpy(home, buffer);

        char *CONFIG_PATH;
        FILE *FILE;

        CONFIG_PATH = strcat(home, "/.config/ksh/config.sh");
        FILE = fopen(CONFIG_PATH, "r");
        
        if (FILE != NULL)
        {
            char *positive;
            strcpy(positive, CONFIG_PATH);
            return positive;
        }
        else if (FILE == NULL)
        {
            char *negative = "no";
            return negative;
        }
        fclose(FILE);
    }

    pclose(HOME_PATH);
}