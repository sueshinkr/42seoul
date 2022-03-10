/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:14:26 by sounchoi          #+#    #+#             */
/*   Updated: 2022/01/16 16:06:37 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# define NUM 5

int		recur_board(char *condition, char array[][NUM], int x, int y);
char	loop_x1(char array[][NUM], int i);
char	loop_x2(char array[][NUM], int i);
char	loop_y1(char array[][NUM], int i);
char	loop_y2(char array[][NUM], int i);

#endif
