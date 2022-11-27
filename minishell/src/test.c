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

int check_empty(char *str)
{
    while (*str)
    {
        if (*str++ != ' ')
            return (0);
    }
    return (1);
}

void	make_list(t_list *env, char **envp)
{
	int	idx;
	int	idx2;

	idx = -1;
	while (envp[++idx])
	{
		idx2 = -1;
		while (envp[idx][++idx2] != '=')
			;
		env->key = str_cut_front(envp[idx], idx2 + 1);
		env->value = str_cut_back(envp[idx], idx2);
		env->next = malloc(sizeof(t_list));
		env = env->next;
	}
	env = NULL;
}

int main(int argc, char **argv, char **envp)
{
    struct termios term;
    char *line;
    (void)argc;
    (void)argv;
    // 환경변수 받아와야됨

    t_data	*data = malloc(sizeof(t_data));
	t_list	*env = malloc(sizeof(t_list));

	data->infile_fd = -1;
	data->outfile_fd = -1;
    data->pipe_num = 0;
	make_list(env, envp);
    data->env = env;

    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ECHOCTL);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    set_signal();

    while (1)
    {
        line = readline("MINISHELL$ ");
        if (line)
        {
            if (check_empty(line))
                continue;
            add_history(line);
            init_tree(line, data);
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

//gcc -I/Users/sueshin/goinfre/.brew/Cellar/readline/8.2.1/include -L/Users/sueshin/goinfre/.brew/Cellar/readline/8.2.1/lib -lreadline test.c tree.c text.c util.c util2.c tree_case.c rdir.c cmd.c get_next_line_bonus.c get_next_line_utils_bonus.c builtin.c -fsanitize=address

// <a < b cat >c | echo "abc"
// ls -a -l >> a < b > c | grep "" | cat << x > y
// cat cmd.c | abc  <a >> b | grep 'es" > c