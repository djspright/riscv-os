#include "common.h"
#include "user.h"

void	main(void)
{
  while (1)
  {
  prompt:
    ft_printf("> ");
    char cmdline[128];
    for(int i = 0;; i++)
    {
      char ch = getchar();
      putchar(ch);
      if(i == sizeof(cmdline) - 1)
      {
        ft_printf("command line too long\n");
        goto prompt;
      } else if (ch == '\r')
      {
        ft_printf("\n");
        cmdline[i] = '\0';
        break;
      } else
          cmdline[i] = ch;
    }
    if(ft_strcmp(cmdline, "hello") == 0)
      ft_printf("Hello 42Tokyo!\n");
    else if(ft_strcmp(cmdline, "exit") == 0)
      exit();
    else if(ft_strcmp(cmdline, "readfile") == 0)
    {
      char buf[128];
      int len = readfile("hello.txt", buf, sizeof(buf));
      buf[len] = '\0';
      ft_printf("%s\n", buf);
    }
    else if(ft_strcmp(cmdline, "writefile") == 0)
      writefile("hello.txt", "Hello from shell!\n", 19);
    else
      ft_printf("unknown command: %s\n", cmdline);
  }
}
