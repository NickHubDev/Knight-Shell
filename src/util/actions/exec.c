#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../headers/mf/exec.h"

char *exec_sh(const char* cmd)
{
    FILE *COMMAND;
    char buffer[1024];
    char *output = NULL;
    size_t total_len = 0;

    COMMAND = popen(cmd, "r");

    if (!COMMAND) return NULL;

    while (fgets(buffer, sizeof(buffer), COMMAND) != NULL)
    {
        size_t chunk_len = strlen(buffer);

        char *temp = realloc(output, total_len + chunk_len + 1);
        if (!temp)
        {
            free(output);
            pclose(COMMAND);
            return NULL;
        }        
        
        output = temp;

        strcpy(output + total_len, buffer);
        total_len += chunk_len;
    }
    pclose(COMMAND);
    return output;
}