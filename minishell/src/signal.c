#include "minishell.h"

static void	handle_sigint(pid_t pid)
{
	if (pid == -1)
	{
		printf("MINISHELL$ \n");
		if (rl_on_new_line() == -1)
			exit(1);
		rl_replace_line("", 1);
		rl_redisplay();
	}
	else
	{
		printf("^C\n");
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

static void	handle_sigquit(pid_t pid)
{
	if (pid == -1)
	{
		rl_redisplay();
	}
	else
	{
		printf("^\\Quit: 3\n");
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

static void	sig_handler(int signum)
{
	pid_t	pid;
	int		status;

	pid = waitpid(-1, &status, WNOHANG);
	if (signum == SIGINT)
		handle_sigint(pid);
	else if (signum == SIGQUIT)
		handle_sigquit(pid);
}

void	set_signal(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
}
