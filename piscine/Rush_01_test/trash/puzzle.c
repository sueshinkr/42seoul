/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:20:42 by sueshin           #+#    #+#             */
/*   Updated: 2022/01/15 15:40:10 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	chk_possible_right(int board[][6], int row, int column, int i);
int	chk_possible_left(int board[][6], int row, int column, int i);
int	chk_possible(int board[][6], int row, int column, int i);
void	input_number(int board[][6], int column, int row, int i);
void	test_print(int board[][6]);

int	main(void)
{
	int i = 1;
	int j = 1;

	int board[6][6] = {0, 4, 3, 2, 1, 0,
					   4, 0, 0, 0, 0, 1,
					   3, 0, 0, 0, 0, 2,
					   2, 0, 0, 0, 0, 2,
					   1, 0, 0, 0, 0, 2,
					   0, 1, 2, 2, 2, 0};
	i = 0;
	while(i < 6)
	{	
		j = 0;
		while(j < 6)
		{
			printf("%d",board[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	

	input_number(board, 1, 1, 1);

	test_print(board);

	return (0);
}

void	test_print(int board[][6])
{
	int i = 1;
	int j;

	while(i < 5)
	{	
		j = 1;
		while(j < 5)
		{
			printf("%d",board[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}



void	input_number(int board[][6], int column, int row, int i)
{
	int count;

	if (column == 5)
	{	
		column = 1;
		row++;
	}

	while (row < 5)
	{
		while (column < 5)
		{
			//if (!chk_space(column, row))
			//	return ;
			count = 0;
			while (count++ < 4)
			{
				if (chk_possible(board, row, column, i))
				{						
					board[row][column] = i % 4;
					i++;
					input_number(board, column + 1, row, i);
				}
			}	
			test_print(board);
			return ;	
		}
		row++;
	}
}

int	chk_possible(int board[][6], int row, int column, int i)
{
	if(!chk_possible_left(board, row, column, i))
		return (0);
	if(!chk_possible_right(board, row, column, i))
		return (0);
	return (1);
}

int	chk_possible_left(int board[][6], int row, int column, int i)
{
	int temp = 0;
	int count = 0;
	int l_max = board[row][temp + 1];
	while (++temp < column)
	{
		if (i == board[row][temp])
			return (0); //이전에 나왔던 수와 같을경우
		if (l_max < board[row][temp])
		{
			l_max = board[row][temp];
			count++;
		}	
		if (l_max < i)
			count++;
	}
	if (board[row][0] < count + 1)
	   return (0); //왼쪽 조건 불만족
	return (1);
}

int	chk_possible_right(int board[][6], int row, int column, int i)
{
	int temp = column;
	int count = 0;
	int r_max = i;
	while (--temp > 0)
	{
		if (r_max < board[row][temp])
		{
			r_max = board[row][temp];
			count++;
		}	
	}
	if (board[row][5] < count + 1)
	   return (0); //오른쪽 조건 불만족
	return (1);
}







