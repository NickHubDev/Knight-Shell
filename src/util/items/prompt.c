#include "../../../headers/library.h"

void Kprompt(void)
{
  char *PROMPT = path();
  
  if (PROMPT == NULL)
  {
    printf("ERROR\n");
    return;
  }

  printf("%s\n", PROMPT);
  printf(" 󱞪 ");
  fflush(stdout);
}
