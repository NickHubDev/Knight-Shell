#include <stdio.h>
#include <string.h>
#include "k_exec.h"

int knight_check(char *buffer, int status)
{
    char *token;
    char *prompt_data[10];
    int i = 0;
    size_t prompt_lenght = strlen(buffer);
    int ext_comp = strncmp("exit", buffer, 4);
    int en_comp = strncmp("\n", buffer, 1);

    token = strtok(buffer, " ");

    while (token != NULL && i < 9)
    {
        prompt_data[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    prompt_data[i] = NULL;

    knight_exec(prompt_data);

    if (prompt_lenght != 5 && prompt_lenght != 1)
    {
        return status = 0;
    }
    else
    {    
        if (en_comp == 0)
        {
            return status = 1;
        }
        else if (ext_comp == 0)
        {
            return status = 1;
        }
        else
        {
            return status = 0;
        }
    }
}