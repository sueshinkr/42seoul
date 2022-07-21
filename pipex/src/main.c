/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:26:59 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/22 00:44:01 by sueshin          ###   ########.fr       */
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
}

void	check_file(char *argv)
{
	int	mode;

	mode = F_OK | X_OK;
	if (access(argv, mode) == -1)
		print_error(2);
}

void	read_arg(char **argv)
{
	char	**arr;
	int		idx = 0;
	ft_printf("argv[1] : %s\n", argv[1]);
	check_file(argv[1]);
	//check_file(argv[4]);
	arr = ft_split(argv[2], argv[4], ' ');
	while (arr[idx])
	{
		ft_printf(":%s\n", arr[idx++]);
	}
	ft_printf("first : %d\n", execle("/bin/touch", "touch", argv[4], NULL, NULL));
	execle("/bin/ls", argv[1], "ls", "-l", argv[4], NULL, NULL);
	//ft_printf("::%d\n", execv("/bin/ls", arr));
	ft_printf("adfasdf\n");
}

/*
main에서 세번째 인자로 envp받기
envp에서 path찾아서 저장해두기
exec함수들에서 사용되는 명령어가 path에서 :로 구분된 디렉토리에 존재하는지 확인 > access함수 이용

*/

int	main(int argc, char **argv)
{
	int		fd[2]; 
	pid_t	pid;
	int		x;
	char	*str;

	if (argc != 5)
		print_error(1);
	read_arg(argv);
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
