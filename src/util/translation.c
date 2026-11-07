#include <stdio.h>
#include <string.h>
#include "../k_exec.h"

void knight_trans(char *buffer)
{
    int i = 0;
    char *args[10];
    char *token = strtok(buffer, " ");

    while(token != NULL && i < 9)
    {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
    knight_exec(args);
}