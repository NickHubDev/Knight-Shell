#include <stdio.h>
#include <unistd.h>
#include "k_loop.h"
#include "util/items/raw_mode.h"
#include "util/actions/translation.h"

void knight_prompt(void)
{
    printf("[] & dirrectory (nizolax) {git.branch}\n");
    printf(" 󱞩 ");
    fflush(stdout);
}

int knight_loop(void)
{
    enableRawm();
    knight_prompt();
    
    char buffer[1024];
    int position = 0;

    while(1)
    {
        char c = '\0';
        if (read(STDIN_FILENO, &c, 1) == -1)
        {
            perror("knight: Read Error.");
            return 1;
        }

        if (c != '\0')
        {
            if (c == 0x0C) 
            {
                printf("\x1b[2J\x1b[H");
                knight_prompt();
                continue;
            }

            if (c == 0x03)
            {
                printf("\n");
                return 1;
            }

            if (c == 0x08 || c == 0x7F)
            {
                position--;
                printf("\b \b");
                fflush(stdout);
                continue;
            }

            if (c == 0x1B)
            {
                char res[2];
                if (read(STDIN_FILENO, &res[0], 1) > 0 && read(STDIN_FILENO, &res[1], 1) > 0)
                {
                    if (res[0] == 0x5B)
                    {
                        if (res[1] == 0x44)
                        {
                            printf("\b");
                            fflush(stdout);
                            continue;
                        }
                        else if (res[1] == 0x43)
                        {
                            printf("\x1b[C");
                            fflush(stdout);
                            continue;
                        }
                    }
                }
            }

            if (c == 0x0D)
            {
                printf("\r\n");
                buffer[position] = '\0';

                if (position > 0)
                {
                    knight_trans(buffer);
                }

                position = 0;
                knight_prompt();
                continue;
            }

            if (c >= 32 && c <= 126 && position < 1023)
            {
                buffer[position++] = c;
                printf("%c", c);
                fflush(stdout);
            }
        }
    }
    disableRawm();
    return 0;
}