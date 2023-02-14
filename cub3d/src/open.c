#include "cub3d.h"

static int	map_texture(char *line, int i, t_info *d)
{
	char	*texture;
	int		start;

	start = i;
	i++;
	while (line[++i] == ' ')
		;
	texture = ft_strjoin(ft_strdup(""), &line[++i]);
	if (line[start] == 'N' && line[start + 1] == 'O')
		d->cub->north_texture = texture;
	else if (line[start] == 'S' && line[start + 1] == 'O')
		d->cub->south_texture = texture;
	else if (line[start] == 'W' && line[start + 1] == 'E')
		d->cub->west_texture = texture;
	else if (line[start] == 'E' && line[start + 1] == 'A')
		d->cub->east_texture = texture;
	else
		d->cub->count--;
	d->cub->count++;
	while (line[i++])
		;
	return i;
}

static int	map_color(char *line, int i, t_info *d)
{
	int	*object;
	int	rgb;

	rgb = 0;
	if (line[i] == 'F')
		object = d->cub->floor_color;
	else
		object = d->cub->ceiling_color;
	while (line[++i])
	{
		if (isdigit(line[i]))
		{
			while (isdigit(line[i]))
				object[rgb] = object[rgb] * 10 + line[i++] - '0';
			if (object[rgb] < 0 || object[rgb] > 255)
				exit_game_with_map(4);
			rgb++;
		}
	}
	d->cub->count++;
	return i;
}

static void	complete_map(t_map *map)
{
	int		i;
	int		len;

	i = -1;
	len = -1;
	map->field = malloc(sizeof(char*) * map->row);
	while (++i < map->row)
	{
		map->field[i] = ft_strdup("");
		
		while (map->temp_field[++len])
		{
			if (map->temp_field[len] == '\n')
				break;
			map->field[i] = ft_strjoin_len(map->field[i], &map->temp_field[len], 1);
		}
	}
}

static void	open_map(int fd, t_cub *cub)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line))
		{
			if (ft_strlen(line) > cub->map->col)
				cub->map->col = ft_strlen(line);
			cub->map->row++;
			line = ft_strjoin(line, ft_strdup("\n"));
			cub->map->temp_field = ft_strjoin(cub->map->temp_field, line);
		}
		line = get_next_line(fd);
	}
	complete_map(cub->map);
	check_map_wall(cub->map, cub->map->field, -1, -1);
	check_map_chr(cub, cub->map->field, -1, -1);
}

void	open_cub(char *cub_file, t_info *d)
{
	int		i;
	char	*line;

	i = -1;
	d->cub->fd = open(cub_file, O_RDONLY);
	line = get_next_line(d->cub->fd);
	while (line)
	{
		while (line[++i])
		{
			if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
				i = map_texture(line, i, d);
			else if (line[i] == 'F' || line[i] == 'C')
				i = map_color(line, i, d);
		}
		if (d->cub->count == 6)
			break;
		i = -1;
		line = get_next_line(d->cub->fd);
	}
	if (d->cub->count != 6)
		exit_game_with_map(0);
	free(line);
	open_map(d->cub->fd, d->cub);
}