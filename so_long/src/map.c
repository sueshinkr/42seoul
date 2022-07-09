#include "so_long.h"

void	open_map(char	*map_file, t_data *data)
{
	int		fd;
	char	*line;
	fd = open(map_file, O_RDONLY);

	line = get_next_line(fd);
	if (!line)
		exit_game_with_map(0, data);
	else
	{
		data->column = ft_strlen(line);
		data->map = ft_strdup(line);
		while(line)
		{
			line = get_next_line(fd);
			if (line)
			{
				data->map = ft_strjoin(data->map, line);
				data->row++;
			}
		}
	}
	close(fd);
}

void	check_map(t_data *data)
{
	int	idx;
	idx = -1;

	while (data->map[++idx])
	{
		if (!ft_strchr("01CPOE", data->map[idx]))
			exit_game_with_map(1, data);
		if (idx < data->column || (idx >= data->column * (data->row - 1)) ||
			idx % data->column == 0 || idx % data->column == data->column - 1)
		{
			if (data->map[idx] != '1')
				exit_game_with_map(2, data);
		}
		if (data->map[idx] == 'C')
			data->C_flag++;
		if (data->map[idx] == 'E')
			data->E_flag++;
		if (data->map[idx] == 'P')
			data->P_flag++;
	}
	if (idx != data->column * data->row)
		exit_game_with_map(3, data);
	if (data->C_flag < 1 || data->E_flag < 1 || data->P_flag != 1)
		exit_game_with_map(4, data);
	data->base->win = mlx_new_window(data->base->mlx, 24 * data->column, 24 * (data->row + 1), "So_Long");
}
	//맵이 직사각형모양인가 ok
	//벽이 둘러싸고있는가 ok
	//exit와 collectible이 하나 이상 존재하는가 ok
	//플레이어가 하나 존재하는가 ok
	//이상한게 꺄있지는 않은가 ok

void	render_map(t_data *data)
{
	int	idx;

	idx = -1;
	while(data->map[++idx])
	{
		mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->grass_img, (idx % data->column) * 24, (idx / data->column) * 24);
		if (data->map[idx] == '1')
			mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->wall_img, (idx % data->column) * 24, (idx / data->column) * 24);
		else if (data->map[idx] == 'C')
			mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->collectible_img, (idx % data->column) * 24, (idx / data->column) * 24);
		else if (data->map[idx] == 'P')
		{
			data->P_location = idx;
			mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->pi->front_img, (idx % data->column) * 24, (idx / data->column) * 24);
		}
		else if (data->map[idx] == 'O')
			mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->ei->enemy_img, (idx % data->column) * 24, (idx / data->column) * 24);
		else if (data->map[idx] == 'E')
			mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->exit_img, (idx % data->column) * 24, (idx / data->column) * 24);
	}
	print_count(data);
}

void	render_map_after_move(t_data *data, int cur, int new, int dir)
{
	mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->grass_img, (cur % data->column) * 24, (cur / data->column) * 24);
	mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->grass_img, (new % data->column) * 24, (new / data->column) * 24);
	if (dir == 1)
		mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->pi->back_img, (new % data->column) * 24, (new / data->column) * 24);
	else if (dir == 2)
		mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->pi->left_img, (new % data->column) * 24, (new / data->column) * 24);
	else if (dir == 3)
		mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->pi->front_img, (new % data->column) * 24, (new / data->column) * 24);
	else if (dir == 4)
		mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->pi->right_img, (new % data->column) * 24, (new / data->column) * 24);
	data->move_count++;
	data->P_location = new;
}

void	render_map_fail_exit(t_data *data, int cur, int new)
{
	if (data->map[new] == 'E')
	{
		mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->grass_img, (cur % data->column) * 24, (cur / data->column) * 24);
		mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->pi->front_img, (new % data->column) * 24, (new / data->column) * 24);
	}
	else if (data->map[cur] == 'E')
	{
		mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->grass_img, (cur % data->column) * 24, (cur / data->column) * 24);
		mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->exit_img, (cur % data->column) * 24, (cur / data->column) * 24);
		reset_animation_flag(data, 1);
	}
	data->P_location = new;
}

void	render_player_stop_motion1(t_data *data, int dir)
{
	mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->grass_img, (data->P_location % data->column) * 24, (data->P_location / data->column) * 24);
	if (dir == 1) //front
	{
		if (data->base->pi->front_flag == 1)
			mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->pi->back2_img, (data->P_location % data->column) * 24, (data->P_location / data->column) * 24);
		else
			mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->pi->back_img, (data->P_location % data->column) * 24, (data->P_location / data->column) * 24);
	}
	if (dir == 2) //left
	{
		if (data->base->pi->left_flag == 1)
			mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->pi->left2_img, (data->P_location % data->column) * 24, (data->P_location / data->column) * 24);
		else
			mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->pi->left_img, (data->P_location % data->column) * 24, (data->P_location / data->column) * 24);
	}
	if (dir == 0) //exit
	{
		mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->grass_img, (data->P_location % data->column) * 24, (data->P_location / data->column) * 24);
		mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->exit_img, (data->P_location % data->column) * 24, (data->P_location / data->column) * 24);
		if (data->base->pi->front_flag == 1)
			mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->pi->back2_img, (data->P_location % data->column) * 24, (data->P_location / data->column) * 24);
		else
			mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->pi->back_img, (data->P_location % data->column) * 24, (data->P_location / data->column) * 24);
			
	}
}

void	render_player_stop_motion2(t_data *data, int dir)
{
	mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->grass_img, (data->P_location % data->column) * 24, (data->P_location / data->column) * 24);
	if (dir == 3) //back
	{
		if (data->base->pi->back_flag == 1)
			mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->pi->front2_img, (data->P_location % data->column) * 24, (data->P_location / data->column) * 24);
		else
			mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->pi->front_img, (data->P_location % data->column) * 24, (data->P_location / data->column) * 24);
	}
	if (dir == 4) //right
	{
		if (data->base->pi->right_flag == 1)
			mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->pi->right2_img, (data->P_location % data->column) * 24, (data->P_location / data->column) * 24);
		else
			mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->pi->right_img, (data->P_location % data->column) * 24, (data->P_location / data->column) * 24);
	}
}

void	render_enemy_stop_motion(t_data *data)
{
	if (data->base->pi->right_flag == 1)
			mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->pi->right2_img, (data->P_location % data->column) * 24, (data->P_location / data->column) * 24);
		else
			mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->pi->right_img, (data->P_location % data->column) * 24, (data->P_location / data->column) * 24);
}

