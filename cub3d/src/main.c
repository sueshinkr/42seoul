#include "cub3d.h"

void	map_texture(char *line, int i, t_info *d)
{
	char	*texture;
	int		start;

	start = i;
	i++;
	while (line[++i] == ' ')
		;
	texture = ft_strjoin(ft_strdup(""), &line[++i]);
	if (line[start] == 'N')
		d->cub->north_texture = texture;
	else if (line[start] == 'S')
		d->cub->south_texture = texture;
	else if (line[start] == 'W')
		d->cub->west_texture = texture;
	else if (line[start] == 'E')
		d->cub->east_texture = texture;
	d->cub->count++;
}

void	map_color(char *line, int i, t_info *d)
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
			{
				object[rgb] *= 10;
				object[rgb] += line[i++] - '0';
			}
			if (object[rgb] < 0 || object[rgb] > 255)
				exit_game_with_map(4);
			rgb++;
		}
	}
	d->cub->count++;
}

void	complete_map(t_map *map)
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

void	check_map_wall(t_map *map, char **field, int r, int c)
{
	int len;

	while (++r < map->row)
	{
		c = -1;
		len = ft_strlen(field[r]);
		while (++c < len)
		{
			if (field[r][c] == '0')
			{
				if (r == 0 || r == map->row - 1 || c == 0 || c == len - 1)
					exit_game_with_map(1);
				else if (r != 0 && (c >= ft_strlen(field[r - 1]) || 
				 		(c < ft_strlen(field[r - 1]) && field[r - 1][c] == ' ')))
					exit_game_with_map(1);
				else if (r != map->row - 1 && (c >= ft_strlen(field[r + 1]) ||
						(c < ft_strlen(field[r + 1]) && field[r + 1][c] == ' ')))
					exit_game_with_map(1);
				else if ((c != 0 && field[r][c - 1] == ' ') ||
						(c != len - 1 && field[r][c + 1] == ' '))
					exit_game_with_map(1);
			}
		}
	}
}

void	check_map_chr(t_map *map, char **field, int r, int c)
{
	int	len;
	int	count;

	count = 0;
	while (++r < map->row)
	{
		c = -1;
		len = ft_strlen(field[r]);
		while (++c < len)
		{
			if (!(field[r][c] == '0' || field[r][c] == '1' ||
				field[r][c] == ' ' || field[r][c] == 'N' ||
				field[r][c] == 'S' || field[r][c] == 'W' || field[r][c] == 'E'))
				exit_game_with_map(2);
			if (field[r][c] == 'N' || field[r][c] == 'S' || 
				field[r][c] == 'W' || field[r][c] == 'E')
				count++;
			if (count > 1)
				exit_game_with_map(3);
		}
	}
}

void	open_map(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line))
		{
			if (ft_strlen(line) > map->col)
				map->col = ft_strlen(line);
			map->row++;
			line = ft_strjoin(line, ft_strdup("\n"));
			map->temp_field = ft_strjoin(map->temp_field, line);
		}
		line = get_next_line(fd);
	}
	complete_map(map);
	check_map_wall(map, map->field, -1, -1);
	check_map_chr(map, map->field, -1, -1);
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
			{
				map_texture(line, i, d);
				break;
			}
			else if (line[i] == 'F' || line[i] == 'C')
			{
				map_color(line, i, d);
				break;
			}
		}
		if (d->cub->count == 6)
			break;
		i = -1;
		line = get_next_line(d->cub->fd);
	}
	if (d->cub->count != 6)
		exit_game_with_map(0);
	free(line);
	open_map(d->cub->fd, d->cub->map);
}

static void	init_map(t_map *map)
{
	map->temp_field = ft_strdup("");
	map->col = INT_MIN;
	map->row = 0;
}

static void	init_cub(t_cub *cub)
{
	int	i;

	i = -1;
	cub->count = 0;
	while (++i < 3)
	{
		cub->floor_color[i] = 0;
		cub->ceiling_color[i] = 0;
	}
	cub->map = malloc(sizeof(t_map));
	init_map(cub->map);
}

static void	init_data(t_info *d)
{
	d->mlx = mlx_init();
	d->win = NULL;
	d->cub = malloc(sizeof(t_cub));
	init_cub(d->cub);
}

int	main(int argc, char **argv)
{
	t_info	*d;

	if (argc != 2)
	{
		printf("Wrong input file : Error\n");
		return (0);
	}
	d = malloc(sizeof(t_info));
	init_data(d);
	open_cub(argv[1], d);

	// CHECK
	printf("NO : %s\n", d->cub->north_texture);
	printf("SO : %s\n", d->cub->south_texture);
	printf("WE : %s\n", d->cub->west_texture);
	printf("EA : %s\n", d->cub->east_texture);

	printf("floor : %d %d %d\n", d->cub->floor_color[0], d->cub->floor_color[1], d->cub->floor_color[2]);
	printf("ceiling : %d %d %d\n", d->cub->ceiling_color[0], d->cub->ceiling_color[1], d->cub->ceiling_color[2]);

	printf("Map : \n");

	for (int i = 0; i < d->cub->map->row; i++)
	{
		printf("%s\n", d->cub->map->field[i]);
	}
	return 0;
}
/*
	mlx_hook(d->cub->win, 2, 0, &keypress, data);
	mlx_hook(d->cub->win, 17, 0, &exit_game_with_red, data);
	mlx_loop_hook(d->cub->mlx, &sel_animation, data);
	mlx_loop(d->cub->mlx);
*/
