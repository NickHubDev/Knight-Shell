#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

struct termios original;


void disableRawm(void)
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original);
}

void enableRawm(void)
{
    tcgetattr(STDIN_FILENO, &original);
    atexit(disableRawm);

    struct termios raw = original;

    raw.c_iflag &= ~(IXON | ICRNL);
    raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
    raw.c_cc[VMIN] = 1;
    raw.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}