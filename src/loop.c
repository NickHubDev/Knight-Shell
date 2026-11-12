#include "../headers/library.h"

int Kloop(void)
{
    enableRawm();
    Kprompt();
    
    char buffer[1024];
    int position = 0;
    int cont = 0;

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
                Kprompt();
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
                if (cont < 0)
                {
                    continue;
                }
                else if (cont > 0)
                {
                    cont--;
                    printf("\b \b");
                    fflush(stdout);
                    continue;
                }
                
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
                            if (cont <= 0 )
                            {
                                continue;
                            }
                            else
                            {
                                cont--;
                                printf("\b");
                                fflush(stdout);
                                continue;
                            }
                        }
                        else if (res[1] == 0x43)
                        {
                            if (cont < 0)
                            {
                                continue;
                            }
                            else
                            {
                                cont++;
                                printf("\x1b[C");
                                fflush(stdout);
                                continue;
                            }
                            
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
                    if (!build_in(buffer))
                    {
                        Ktranslate(buffer);
                    }
                    
                }

                position = 0;
                int n_cont = cont;
                cont = cont - n_cont;
                Kprompt();
                continue;
            }



            if (c >= 32 && c <= 126 && position < 1023)
            {
                buffer[position++] = c;
                cont++;
                printf("%c", c);
                fflush(stdout);
            }
        }
    }
    disableRawm();
    return 0;
}
