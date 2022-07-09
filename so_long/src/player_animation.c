#include "so_long.h"

void player_exit_animation(t_data *data)
{
	if (data->base->pi->front_flag == 1 || data->base->pi->front_flag == 5000)
		render_player_stop_motion1(data, 0);
	data->base->pi->front_flag = data->base->pi->front_flag % 10000 + 1;
}

void player_front_animation(t_data *data)
{
	if (data->base->pi->front_flag == 1 || data->base->pi->front_flag == 5000)
		render_player_stop_motion1(data, 1);
	data->base->pi->front_flag = data->base->pi->front_flag % 10000 + 1;
}

void player_left_animation(t_data *data)
{
	if (data->base->pi->left_flag == 1 || data->base->pi->left_flag == 5000)
		render_player_stop_motion1(data, 2);
	data->base->pi->left_flag = data->base->pi->left_flag % 10000 + 1;
}

void player_back_animation(t_data *data)
{
	if (data->base->pi->back_flag == 1 || data->base->pi->back_flag == 5000)
		render_player_stop_motion2(data, 3);
	data->base->pi->back_flag = data->base->pi->back_flag % 10000 + 1;
}

void player_right_animation(t_data *data)
{
	if (data->base->pi->right_flag == 1 || data->base->pi->right_flag == 5000)
		render_player_stop_motion2(data, 4);
	data->base->pi->right_flag = data->base->pi->right_flag % 10000 + 1;
}