
#include "../include/so_long.h"
#include "../include/window.h"

int	exit_game(t_game *g)
{
	write (1, "GAME OVER!\n", 11);
	mlx_destroy_window(g->mlx, g->mlx_win);
	free(g->mlx);
	exit(0);
}

int	press_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_w(game);
	/*else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_a(game);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_s(game);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_d(game);*/
	return (0);
}
