#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>

#include <stdlib.h>
#include "minishell.h"

void sig_handler(int signum)
{
    if (signum != SIGINT)
        return ;
    printf("MINISHELL$ \n");
    if (rl_on_new_line() == -1)
        exit(1);
    rl_replace_line("", 1);
    rl_redisplay();
}

void set_signal()
{
    signal(SIGINT, sig_handler);
    //signal(SIGQUIT, SIG_IGN);
}

int main(int argc, char **argv, char **envp)
{
    struct termios term;
    char *line;

    // 환경변수 받아와야됨

    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ECHOCTL);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    set_signal();

    while (1)
    {
        line = readline("MINISHELL$ ");
        if (line)
        {
            add_history(line);
            // 여기서 파싱하고 저장하면 될듯

            init_tree(line);
            free(line);
            line = NULL;
        }
        else
        {
            ///printf("\033[1A");
            //printf("\033[11C");
            //printf("exit\n");
            exit(-1);
        }
    }
    return (0);
}

//gcc -I/Users/sueshin/.brew/Cellar/readline/8.2.1/include -L/Users/sueshin/.brew/Cellar/readline/8.2.1/lib -lreadline test.c

// <a < b cat >c | echo "abc"
// ls -a -l >> a < b > c | grep "" | cat << x > y