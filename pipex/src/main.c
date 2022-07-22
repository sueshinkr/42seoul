/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:26:59 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/22 13:54:06 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(int num)
{
	if (num == 1)
	{
		ft_printf("ARG Error\n");
		exit(1);
	}
	if (num == 2)
	{
		ft_printf("File Error\n");
		exit(1);
	}
	if (num == 3)
	{
		ft_printf("Not valid cmdand Error\n");
		exit(1);
	}
}

char	**set_cmd(char *cmd, char *outfile)
{
	char	*temp;
	char	*temp_cmd;
	char	**return_cmd;

	temp = ft_strjoin_pipex(cmd, " ");
	temp_cmd = ft_strjoin_pipex(temp, outfile);
	return_cmd = ft_split(temp_cmd, ' ');
	free(temp);
	free(temp_cmd);
	return (return_cmd);
}

void	read_arg(char **argv, char **envp)
{
	char	**path;
	char	**cmd1;
	char	**cmd2;
	char	*path_cmd1;
	char	*path_cmd2;
	int		idx = 0;

	check_file(argv[1]);
	path = find_enpath(envp);
	cmd1 = set_cmd(argv[2], argv[4]);
	cmd2 = set_cmd(argv[3], argv[4]);
	//cmd1 = ft_split(argv[2], ' ');
	path_cmd1 = check_path(path, cmd1[0]);
	ft_printf("path_cmd1 : %s\n", path_cmd1);
	path_cmd2 = check_path(path, cmd2[0]);
	if (!check_path(path, cmd1[0]) || !check_path(path, cmd2[0]))
		print_error(3);
	ft_printf("11111\n");
	//execl("/bin/touch", "touch", argv[4], NULL);
	ft_printf("22222\n");
	//execl(path_cmd1, "grep", "c", NULL);
	execve(path_cmd1, cmd1, NULL);
	ft_printf("asdfaf\n");
}
/*
	arr = ft_split(argv[2], argv[4], ' ');
	while (arr[idx])
	{
		ft_printf(":%s\n", arr[idx++]);
	}
*/
	//ft_printf("first : %d\n", execle("/bin/touch", "touch", argv[4], NULL, NULL));
	//execle("/bin/ls", argv[1], "ls", "-l", argv[4], NULL, NULL);
	//ft_printf("::%d\n", execv("/bin/ls", arr));

/*
main에서 세번째 인자로 envp받기
envp에서 path찾아서 저장해두기
exec함수들에서 사용되는 명령어가 path에서 :로 구분된 디렉토리에 존재하는지 확인 > access함수 이용

cmd 뒤에 outfile붙이기
*/

int	main(int argc, char **argv, char **envp)
{
	int		fd[2]; 
	pid_t	pid;
	int		x;
	char	*str;

	if (argc != 5)
		print_error(1);
	read_arg(argv, envp);
	if (pipe(fd) == -1)  // fd[0] : read, fd[1] : write
		exit(1);
	pid = fork();

	if (pid == 0) // child
	{
		close(fd[0]);
		dup2(fd[1], 1);
		x = 1;
		write(1, "hello\n", 6);
		//ft_printf("child : %d, x : %d\n", getpid(), x);
	}
	else // parent
	{
		close(fd[1]);
		dup2(fd[0], 0);
		x = 2;
		str = get_next_line(0);
		ft_printf("str : %s", str);
		ft_printf("parent : %d, x : %d\n", getpid(), x);
	}
	//ft_printf("x : %d ::::\n", x);
}

/*
infile outfile
*/
