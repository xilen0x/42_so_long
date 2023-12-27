/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 20:51:14 by castorga          #+#    #+#             */
/*   Updated: 2023/12/23 20:51:16 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/window.h"

void	set_open_exit(t_game *game)
{
	int	y;
	int	x;

	y = game->exit.y;
	x = game->exit.x;
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	game->imgs.open, x * 32, y * 32);
}

void	move_right(t_game *g)
{
	int	y;
	int	x;

	y = g->position.y;
	x = g->position.x;
	if (g->matrix[y - 1][x] >= 0 && g->matrix[y][x + 1] != '1')
	{
		if (g->matrix[y][x + 1] == 'C')
			g->collected++;
		if (g->matrix[y][x + 1] == '@' || \
		(g->matrix[y][x + 1] == 'E' && g->collected == g->q_collec))
			exit_game(g);
		else if (g->matrix[y][x + 1] != '1' && g->matrix[y][x + 1] != 'E')
		{
			g->matrix[y][x] = '0';
			g->position.x++;
			x = g->position.x;
			g->matrix[y][x] = 'P';
			g->walk_cnt++;
			set_images_to_win(g, 'd');
			ft_printf("Steps N: %d\n", g->walk_cnt);
			if (g->collected == g->q_collec)
				set_open_exit(g);
		}
	}
}

void	move_up(t_game *g)
{
	int	y;
	int	x;

	y = g->position.y;
	x = g->position.x;
	if (g->matrix[y - 1][x] >= 0 && g->matrix[y - 1][x] != '1')
	{
		if (g->matrix[y - 1][x] == 'C')
			g->collected++;
		if (g->matrix[y - 1][x] == '@' || \
		(g->matrix[y - 1][x] == 'E' && g->collected == g->q_collec))
			exit_game(g);
		else if (g->matrix[y - 1][x] != '1' && g->matrix[y - 1][x] != 'E')
		{
			g->matrix[y][x] = '0';
			g->position.y--;
			y = g->position.y;
			g->matrix[y][x] = 'P';
			g->walk_cnt++;
			set_images_to_win(g, 'w');
			ft_printf("Steps N: %d\n", g->walk_cnt);
			if (g->collected == g->q_collec)
				set_open_exit(g);
		}
	}
}

void	move_left(t_game *g)
{
	int	y;
	int	x;

	y = g->position.y;
	x = g->position.x;
	if (g->matrix[y - 1][x] >= 0 && g->matrix[y][x - 1] != '1')
	{
		if (g->matrix[y][x - 1] == 'C')
			g->collected++;
		if (g->matrix[y][x - 1] == '@' || \
		(g->matrix[y][x - 1] == 'E' && g->collected == g->q_collec))
			exit_game(g);
		else if (g->matrix[y][x - 1] != '1' && g->matrix[y][x - 1] != 'E')
		{
			g->matrix[y][x] = '0';
			g->position.x--;
			x = g->position.x;
			g->matrix[y][x] = 'P';
			g->walk_cnt++;
			set_images_to_win(g, 'a');
			ft_printf("Steps N: %d\n", g->walk_cnt);
			if (g->collected == g->q_collec)
				set_open_exit(g);
		}
	}
}

void	move_down(t_game *g)
{
	int	y;
	int	x;

	y = g->position.y;
	x = g->position.x;
	if (g->matrix[y + 1][x] >= 0 && g->matrix[y + 1][x] != '1')
	{
		if (g->matrix[y + 1][x] == 'C')
			g->collected++;
		if (g->matrix[y + 1][x] == '@' || \
		(g->matrix[y + 1][x] == 'E' && g->collected == g->q_collec))
			exit_game(g);
		else if (g->matrix[y + 1][x] != '1' && g->matrix[y + 1][x] != 'E')
		{
			g->matrix[y][x] = '0';
			g->position.y++;
			y = g->position.y;
			g->matrix[y][x] = 'P';
			g->walk_cnt++;
			set_images_to_win(g, 's');
			ft_printf("Steps N: %d\n", g->walk_cnt);
			if (g->collected == g->q_collec)
				set_open_exit(g);
		}
	}
}
