#include "so_long.h"

int	sel_animation(t_data *data)
{
	sel_player_animation(data);
	//enemy_animation(data);
	return (0);
}

void	sel_player_animation(t_data *data)
{
	if (data->map[data->P_location] == 'E')
		player_exit_animation(data);
	else if (data->base->pi->front_flag != 0)
		player_front_animation(data);
	else if (data->base->pi->left_flag != 0)
		player_left_animation(data);
	else if (data->base->pi->back_flag != 0)
		player_back_animation(data);
	else if (data->base->pi->right_flag != 0)
		player_right_animation(data);
}

void	enemy_animation(t_data *data)
{
	if (data->base->ei->enemy_flag == 1 || data->base->ei->enemy_flag == 5000)
		render_enemy_stop_motion(data);
	data->base->ei->enemy_flag = data->base->ei->enemy_flag % 10000 + 1;
}

void	reset_animation_flag(t_data *data, int cur)
{
	data->base->pi->front_flag = 0;
	data->base->pi->back_flag = 0;
	data->base->pi->left_flag = 0;
	data->base->pi->right_flag = 0;
	if (cur == 1)
		data->base->pi->front_flag = 1;
	else if (cur == 2)
		data->base->pi->left_flag = 1;
	else if (cur == 3)
		data->base->pi->back_flag = 1;
	else if (cur == 4)
		data->base->pi->right_flag = 1;
}