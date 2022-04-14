/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:55:33 by sueshin           #+#    #+#             */
/*   Updated: 2022/04/14 17:56:36 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{	
	int		fd;
	char	*temp;

	fd = open("./test1.txt", O_RDWR);
	temp = get_next_line(fd);
	while (temp)
	{	
		printf(":::::%s\n", temp);
		free(temp);
		temp = get_next_line(fd);
	}


	/*
	//invalid fd
	printf("invalid fd\n");
	printf("NULL / NULL / NULL\n");
	fd = open("./files/empty", O_RDWR);
	temp = get_next_line(1000);
	printf("1:::::%s\n", temp);
	free(temp);
	temp = get_next_line(-1);
	printf("2:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("3:::::%s\n", temp);
	free(temp);
	printf("******************************************\n");
	
	//files/empty
	printf("files/empty\n");
	printf("NULL / NULL\n");
	fd = open("./files/empty", O_RDWR);
	temp = get_next_line(fd);
	printf("1:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("2:::::%s\n", temp);
	free(temp);
	printf("******************************************\n");

	//files/nl
	printf("files/nl\n");
	printf("nl / NULL\n");
	fd = open("./files/nl", O_RDWR);
	temp = get_next_line(fd);
	printf("1:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("2:::::%s\n", temp);
	free(temp);
	printf("******************************************\n");

	//files/41_no_nl
	printf("files/41_no_nl\n");
	printf("01234567890123456789012345678901234567890 / NULL\n");
	fd = open("./files/41_no_nl", O_RDWR);
	temp = get_next_line(fd);
	printf("1:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("2:::::%s\n", temp);
	free(temp);
	printf("******************************************\n");
	
	//files/41_with_nl
	printf("files/41_with_nl\n");
	printf("0123456789012345678901234567890123456789nl / 0 / NULL\n");
	fd = open("./files/41_with_nl", O_RDWR);
	temp = get_next_line(fd);
	printf("1:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("2:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("3:::::%s\n", temp);
	free(temp);
	printf("******************************************\n");

	//files/42_no_nl
	printf("files/42_no_nl\n");
	printf("012345678901234567890123456789012345678901 / NULL\n");
	fd = open("./files/42_no_nl", O_RDWR);
	temp = get_next_line(fd);
	printf("1:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("2:::::%s\n", temp);
	free(temp);
	printf("******************************************\n");

	//files/42_with_nl
	printf("files/42_with_nl\n");
	printf("01234567890123456789012345678901234567890nl / 1 / NULL\n");
	fd = open("./files/42_with_nl", O_RDWR);
	temp = get_next_line(fd);
	printf("1:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("2:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("3:::::%s\n", temp);
	free(temp);
	printf("******************************************\n");

	//files/43_no_nl
	printf("files/43_no_nl\n");
	printf("0123456789012345678901234567890123456789012 / NULL\n");
	fd = open("./files/43_no_nl", O_RDWR);
	temp = get_next_line(fd);
	printf("1:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("2:::::%s\n", temp);
	free(temp);
	printf("******************************************\n");

	//files/43_with_nl
	printf("files/43_with_nl\n");
	printf("012345678901234567890123456789012345678901nl / 2 / NULL\n");
	fd = open("./files/43_with_nl", O_RDWR);
	temp = get_next_line(fd);
	printf("1:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("2:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("3:::::%s\n", temp);
	free(temp);
	printf("******************************************\n");

	//files/multiple_nlx5
	printf("files/multiple_nlx5\n");
	printf("nl / nl / nl / nl / nl / NULL\n");
	fd = open("./files/multiple_nlx5", O_RDWR);
	temp = get_next_line(fd);
	printf("1:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("2:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("3:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("4:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("5:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("6:::::%s\n", temp);
	free(temp);
	printf("******************************************\n");

	//files/multiple_line_no_nl
	printf("files/multiple_line_no_nl\n");
	fd = open("./files/multiple_line_no_nl", O_RDWR);
	temp = get_next_line(fd);
	printf("1:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("2:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("3:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("4:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("5:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("6:::::%s\n", temp);
	free(temp);
	printf("******************************************\n");

	//files/multiple_line_with_nl
	printf("files/multiple_line_with_nl\n");
	fd = open("./files/multiple_line_with_nl", O_RDWR);
	temp = get_next_line(fd);
	printf("1:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("2:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("3:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("4:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("5:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("6:::::%s\n", temp);
	free(temp);
	printf("******************************************\n");

	//files/alternate_line_nl_no_nl
	printf("files/alternate_line_nl_no_nl\n");
	fd = open("./files/alternate_line_nl_no_nl", O_RDWR);
	temp = get_next_line(fd);
	printf("1:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("2:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("3:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("4:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("5:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("6:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("7:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("8:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("9:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("10:::::%s\n", temp);
	free(temp);
	printf("******************************************\n");

	//files/alternate_line_nl_with_nl
	printf("files/alternate_line_nl_with_nl\n");
	fd = open("./files/alternate_line_nl_with_nl", O_RDWR);
	temp = get_next_line(fd);
	printf("1:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("2:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("3:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("4:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("5:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("6:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("7:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("8:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("9:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("10:::::%s\n", temp);
	free(temp);
	printf("******************************************\n");

	//files/big_line_no_nl
	printf("files/big_line_no_nl\n");
	fd = open("./files/big_line_no_nl", O_RDWR);
	temp = get_next_line(fd);
	printf("1:::::%s\n", temp);
	free(temp);
	printf("******************************************\n");

	//files/big_line_with_nl
	printf("files/big_line_with_nl\n");
	fd = open("./files/big_line_with_nl", O_RDWR);
	temp = get_next_line(fd);
	printf("1:::::%s\n", temp);
	free(temp);
	temp = get_next_line(fd);
	printf("2:::::%s\n", temp);
	free(temp);
	printf("******************************************\n");
	*/







	/*
	//stdin
	printf("stdin\n");
	fd = open("./files/alternate_line_nl_with_nl", O_RDWR);
	temp = get_next_line(0);
	printf("1:::::%s\n", temp);
	free(temp);
	temp = get_next_line(0);
	printf("2:::::%s\n", temp);
	free(temp);
	temp = get_next_line(0);
	printf("3:::::%s\n", temp);
	free(temp);
	temp = get_next_line(0);
	printf("4:::::%s\n", temp);
	free(temp);
	temp = get_next_line(0);
	printf("5:::::%s\n", temp);
	free(temp);
	temp = get_next_line(0);
	printf("6:::::%s\n", temp);
	free(temp);
	temp = get_next_line(0);
	printf("7:::::%s\n", temp);
	free(temp);
	temp = get_next_line(0);
	printf("8:::::%s\n", temp);
	free(temp);
	temp = get_next_line(0);
	printf("9:::::%s\n", temp);
	free(temp);
	temp = get_next_line(0);
	printf("10:::::%s\n", temp);
	free(temp);
	printf("******************************************\n");
	*/
	close(fd);
	system("leaks a.out");
	return (0);
}