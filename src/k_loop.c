#include <stdio.h>
#include "k_loop.h"
#include "k_checker.h"

void knight_loop(void)
{
    int status = 0;
    do {
    printf("Knight >> $ ");
    char *buffer = NULL;
    size_t space = 0;
    ssize_t prompt = getline(&buffer, &space, stdin);
    status = knight_check(buffer, status);
    } while (status == 0);
}