#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "k_exec.h"
#include "raw_mode.h"

int knight_check(char *buffer, int status)
{
    enableRawm();
    char *token;
    char *prompt_data[10];
    int i = 0;
    size_t prompt_lenght = strlen(buffer);
    token = strtok(buffer, " ");

    while (token != NULL && i < 9)
    {
        prompt_data[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    prompt_data[i] = NULL;

    knight_exec(prompt_data);
}