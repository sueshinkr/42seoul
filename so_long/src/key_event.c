#include "so_long.h"

void	move_up(t_data *data)
{
	int	new_location;

	new_location = data->P_location - data->column;
	if (new_location >= 0)
	{
		if (data->map[new_location] == '1')
			return ;
		if (data->map[new_location] == 'E' || data->map[data->P_location] == 'E')
		{
			if (data->C_flag == 0)
				exit_game_with_map(6, data);
			else
			{
				render_map_fail_exit(data, data->P_location, new_location);
				return ;
			}
		}
		else if (data->map[new_location] == 'C')
			data->C_flag--;
		data->map[data->P_location] = '0';
		data->map[new_location] = 'P';
		render_map_after_move(data, data->P_location, new_location);
	}
}

void	move_down(t_data *data)
{
	int	new_location;

	new_location = data->P_location + data->column;
	if (new_location < data->column * data->row)
	{
		if (data->map[new_location] == '1')
			return ;
		if (data->map[new_location] == 'E' || data->map[data->P_location] == 'E')
		{
			if (data->C_flag == 0)
				exit_game_with_map(6, data);
			else
			{
				render_map_fail_exit(data, data->P_location, new_location);
				return ;
			}
		}
		else if (data->map[new_location] == 'C')
			data->C_flag--;
		data->map[data->P_location] = '0';
		data->map[new_location] = 'P';
		render_map_after_move(data, data->P_location, new_location);
	}
}

void	move_left(t_data *data)
{
	int	new_location;

	new_location = data->P_location - 1;
	if (data->P_location % data->column != 0)
	{
		if (data->map[new_location] == '1')
			return ;
		if (data->map[new_location] == 'E' || data->map[data->P_location] == 'E')
		{
			if (data->C_flag == 0)
				exit_game_with_map(6, data);
			else
			{
				render_map_fail_exit(data, data->P_location, new_location);
				return ;
			}
		}
		else if (data->map[new_location] == 'C')
			data->C_flag--;
		data->map[data->P_location] = '0';
		data->map[new_location] = 'P';
		render_map_after_move(data, data->P_location, new_location);
	}
}

void	move_right(t_data *data)
{
	int	new_location;

	new_location = data->P_location + 1;
	if (data->P_location % data->column != data->column - 1)
	{
		if (data->map[new_location] == '1')
			return ;
		if (data->map[new_location] == 'E' || data->map[data->P_location] == 'E')
		{
			if (data->C_flag == 0)
				exit_game_with_map(6, data);
			else
			{
				render_map_fail_exit(data, data->P_location, new_location);
				return ;
			}
		}
		else if (data->map[new_location] == 'C')
			data->C_flag--;
		data->map[data->P_location] = '0';
		data->map[new_location] = 'P';
		render_map_after_move(data, data->P_location, new_location);
	}
}

int	keypress(int keycode, t_data *data)
{
	data->key_count++;
	if (keycode == 53)
		exit_game_with_map(5, data);
	else if (keycode == 13)
		move_up(data);
	else if (keycode == 1)
		move_down(data);
	else if (keycode == 0)
		move_left(data);
	else if (keycode == 2)
		move_right(data);

	print_count(data);
	printf("keycode : %d, count : %d\n", keycode, data->key_count);
	
	return (0);
}

void	print_count(t_data *data)
{
	char	*str;
	int		idx;

	printf("column : %d\n", data->column);
	idx = -1;
	while (++idx < data->column)
	{
		printf("idx : %d\n", idx);
		mlx_put_image_to_window(data->base->mlx, data->base->win, data->base->grass_img, idx * 24, 24 * data->row);
	}
	str = ft_itoa(data->key_count);
	mlx_string_put(data->base->mlx, data->base->win, 6, 24 * data->row + 12, 0xffffff, "count : ");
	mlx_string_put(data->base->mlx, data->base->win, 60, 24 * data->row + 12, 0xffffff, str);
	free(str);
}
// w 13 d 2 a 0 s 1 esc 53