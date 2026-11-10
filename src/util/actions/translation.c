#include <stdio.h>
#include <string.h>
#include "../../../headers/library.h"

void Ktranslate(char *buffer)
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
    Kcommand(args);
}