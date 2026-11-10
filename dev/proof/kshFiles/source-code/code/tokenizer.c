#include <stdio.h>
#include <string.h>
#include "../info/define.h"

void tokenizer()
{
    FILE *file_url;
    int ch;
    char *config_file;
    config_file = "/home/nizolax/.nizolax/K-Shell/dev/proof/kshFiles/files/utils.ksh";

    file_url = fopen(config_file, "r");

    while ((ch = fgetc(file_url)) != -1)
    {
        
    }
    
    
}