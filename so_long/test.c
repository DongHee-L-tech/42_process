#include <stdio.h>
#include <stdlib.h>
#include "mlx/mlx.h"

typedef struct s_param
{
	void	*mlx;
	void	*win;
	void	*c;
	void	*g;
	void	*w;
	size_t	fd;
	int		x;
	int		y;
	int		width;
	int		height;
	int		win_width;
	int		win_height;
}	t_param;

#define KEY_ESC				53
#define	KEY_W				13
#define	KEY_S				1
#define	KEY_A				0
#define	KEY_D				2
// #define	PRESS_RED_BUTTON	17

int	key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W && param->y != 0)
		param->y -= param->height;
	if (keycode == KEY_S && param->y != 960)
		param->y += param->height;
	if (keycode == KEY_A && param->x != 0)
		param->x -= param->width;
	if (keycode == KEY_D && param->x != 896)
		param->x += param->width;
	if (keycode == KEY_ESC)
		exit(0);
	printf("y: %d x: %d\n", param->y, param->x);
	return (0);
}

int draw(t_param *location)
{
	mlx_clear_window(location->mlx, location->win);
	mlx_put_image_to_window(location->mlx, location->win, location->c, location->x, location->y);
	return (0);
}

int main(void)
{
	t_param	param;

	param.mlx = mlx_init();
	param.c = mlx_xpm_file_to_image(param.mlx, "coin.xpm", &param.width, &param.height);
	param.win = mlx_new_window(param.mlx, 1000, 1000, "Draw_Map");
	param.x = 0;
	param.y = 0;
	mlx_key_hook(param.win, &key_press, &param);
	mlx_loop_hook(param.mlx, &draw, &param);
	mlx_loop(param.mlx);
	return (0);
}
