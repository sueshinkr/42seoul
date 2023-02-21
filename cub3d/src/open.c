/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeok <taehyeok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:50:42 by sueshin           #+#    #+#             */
/*   Updated: 2023/02/19 21:30:09 by taehyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_texture(char *line, t_info *d)
{
	char	**words;

	words = ft_split(line, ' ');
	if (!words || words[2])
		exit_game(5);
	if (ft_strncmp(words[0], "NO", 3) == 0 && d->cub.count == 0
		&& d->cub.count++ + 1)
		d->cub.north_texture = ft_strdup(words[1]);
	else if (ft_strncmp(words[0], "SO", 3) == 0 && d->cub.count == 1
		&& d->cub.count++ + 1)
		d->cub.south_texture = ft_strdup(words[1]);
	else if (ft_strncmp(words[0], "WE", 3) == 0 && d->cub.count == 2
		&& d->cub.count++ + 1)
		d->cub.west_texture = ft_strdup(words[1]);
	else if (ft_strncmp(words[0], "EA", 3) == 0 && d->cub.count == 3
		&& d->cub.count++ + 1)
		d->cub.east_texture = ft_strdup(words[1]);
	else
		exit_game(5);
	free_arr(words);
}

static void	calc_rgb(int *object, char *line, int rgb, int *flag)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((rgb == 0 || rgb == 3) && is_space(line[i]))
			i++;
		else if (rgb > 0 && rgb < 3 && line[i] == ',' && (*flag)++ + 1)
		{
			i++;
			while (is_space(line[i]))
				i++;
		}
		else if (isdigit(line[i]) && (*flag)++ + 1)
		{
			while (isdigit(line[i]))
				object[rgb] = object[rgb] * 10 + line[i++] - '0';
			if (object[rgb] < 0 || object[rgb] > 255)
				exit_game(4);
			rgb++;
		}
		else
			exit_game(5);
	}
}

static void	map_color(char *line, int i, t_info *d)
{
	int	*object;
	int	flag;

	object = NULL;
	flag = 0;
	if (line[i] == 'F' && d->cub.count == 4
		&& d->cub.count++ + 1)
		object = d->cub.floor_color;
	else if (line[i] == 'C' && d->cub.count == 5
		&& d->cub.count++ + 1)
		object = d->cub.ceiling_color;
	else
		exit_game(5);
	calc_rgb(object, &line[i + 1], 0, &flag);
	if (flag != 5)
		exit_game(5);
}

static void	complete_map(t_map *map)
{
	int		i;
	int		len;

	i = -1;
	len = -1;
	map->field = malloc(sizeof(char *) * map->row);
	while (++i < map->row)
	{
		map->field[i] = ft_strdup("");
		while (map->temp_field[++len])
		{
			if (map->temp_field[len] == '\n')
				break ;
			map->field[i] = ft_strjoin_len(map->field[i],
					&map->temp_field[len], 1);
		}
	}
}

static void	open_map(char *line, int fd, t_info *d)
{
	while (line && is_emptyline(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		exit_game(5);
	while (line)
	{
		if (is_emptyline(line))
			exit_game(5);
		else
		{
			if (ft_strlen(line) > d->map.col)
				d->map.col = ft_strlen(line);
			d->map.row++;
			line = ft_strjoin(line, "\n");
			d->map.temp_field = ft_strjoin(d->map.temp_field, line);
		}
		free(line);
		line = get_next_line(fd);
	}
	complete_map(&d->map);
	check_map_wall(&d->map, d->map.field, -1, -1);
	check_map_chr(d, d->map.field, -1, -1);
}

void	open_cub(char *cub_file, t_info *d)
{
	char	*line;

	d->cub.fd = open(cub_file, O_RDONLY);
	line = get_next_line(d->cub.fd);
	while (line)
	{
		if (is_emptyline(line))
			;
		else if (d->cub.count < 4)
			map_texture(line, d);
		else if (d->cub.count < 6)
			map_color(line, 0, d);
		if (d->cub.count == 6)
			break ;
		free(line);
		line = get_next_line(d->cub.fd);
	}
	if (line)
		free(line);
	if (d->cub.count != 6)
		exit_game(0);
	open_map(get_next_line(d->cub.fd), d->cub.fd, d);
}
