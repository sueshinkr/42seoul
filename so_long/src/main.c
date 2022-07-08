#include "so_long.h"

void	init_data(t_data *data)
{
	int	img_width;
	int	img_height;

	data->key_count = 0;
	data->column = 0;
	data->row = 1;
	data->C_flag = 0;
	data->E_flag = 0;
	data->P_flag = 0;
	data->base = malloc(sizeof(t_mlx));
	data->base->mlx = mlx_init();
	data->base->win = NULL;
	data->base->grass_img = mlx_xpm_file_to_image (data->base->mlx, "./imageset/grass.xpm", &img_width, &img_height);
	data->base->wall_img = mlx_xpm_file_to_image (data->base->mlx, "./imageset/wall.xpm", &img_width, &img_height);
	data->base->player_img = mlx_xpm_file_to_image (data->base->mlx, "./imageset/front.xpm", &img_width, &img_height);
	data->base->collectible_img = mlx_xpm_file_to_image (data->base->mlx, "./imageset/collectible.xpm", &img_width, &img_height);
	data->base->exit_img = mlx_xpm_file_to_image (data->base->mlx, "./imageset/exit.xpm", &img_width, &img_height);
}
int	main(int argc, char **argv)
{
	t_data	*data;

	if(argc != 2)
		write(1, "error\n", 6);

	data = malloc(sizeof(t_data));
	init_data(data);


	open_map(argv[1], data);
	check_map(data);
	data->base->win = mlx_new_window(data->base->mlx, 24 * data->column, 24 * (data->row + 1), "Hello world!");
	render_map(data);
	print_count(data);

	mlx_hook(data->base->win, 2, 0, &keypress, data);
	mlx_hook(data->base->win, 17, 0, &exit_game_with_red, data);
	mlx_loop(data->base->mlx);
}



/*
int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	char	*test_image = "./imageset/front.xpm";
	int		*test_image_width;
	int		*test_image_height;
	int		width = 12;
	int		height = 4;
	t_data	img;

	if (argc != 2)
		printf("error\n");
	else
		open_map(argv[1]);

	test_image_width = &width;
	test_image_height = &height;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1200, 600, "Hello world!");
	img.img = mlx_xpm_file_to_image (mlx, test_image, test_image_width, test_image_height);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
*/

//gcc -L./ -lmlx -framework OpenGL -framework Appkit main.c

/* mlx_new_window
void *mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char* title );
int	mlx_clear_window ( void *mlx_ptr, void *win_ptr );
int	mlx_destroy_window ( void *mlx_ptr, void *win_ptr );
*/

/* mlx_pixel_put
int	mlx_pixel_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color );
int	mlx_string_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string );
*/

/* mlx_new_image
void	*mlx_new_image ( void *mlx_ptr, int width, int height );
char	*mlx_get_data_addr ( void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );
int		mlx_put_image_to_window ( void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y );
unsigned int	mlx_get_color_value ( void *mlx_ptr, int color );
void	*mlx_xpm_to_image ( void *mlx_ptr, char **xpm_data, int *width, int *height );
void	*mlx_xpm_file_to_image ( void *mlx_ptr, char *filename, int *width, int *height );
void	*mlx_png_file_to_image ( void *mlx_ptr, char *filename, int *width, int *height );
int		mlx_destroy_image ( void *mlx_ptr, void *img_ptr );
*/

/* mlx_loop
int	mlx_loop ( void *mlx_ptr );
int	mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
int	mlx_mouse_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
int	mlx_expose_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
int	mlx_loop_hook ( void *mlx_ptr, int (*funct_ptr)(), void *param );
int mlx_hook(void win_ptr, int x_event, int x_mask, int (funct)(), void *param);
*/