#include "so_long2.h"

typedef struct d
{
	void	*mlx;
	void	*win;
}	data;

int main()
{
	data	*d;

	d = malloc(sizeof(data));
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, 72, 72, "SoLong");

	mlx_loop(d->mlx);
}