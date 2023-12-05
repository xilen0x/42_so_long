/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:26:04 by castorga          #+#    #+#             */
/*   Updated: 2023/12/04 16:26:06 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*Funcion que verifica si el mapa esta rodeado de paredes - continuacion*/
int	is_surrounded_by_walls2(t_game *game, int q_cols, int q_rows)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if (game->matrix[i][q_cols - 1] != '1')
			ft_errors(3);
		i++;
	}
	i = 0;
	while (game->matrix[0][i] && game->matrix[0][i] != '\n')
	{
		if (game->matrix[q_rows - 1][i] != '1')
			ft_errors(3);
		i++;
	}
	return (0);
}

/*Funcion que verifica si el mapa esta rodeado de paredes*/
int	is_surrounded_by_walls(t_game *game)
{
	int	i;
	int	q_rows;
	int	q_cols;

	i = 0;
	q_rows = game->height;
	q_cols = game->width;
	while (game->matrix[0][i] && game->matrix[0][i] != '\n')
	{
		if (game->matrix[0][i] != '1')
			ft_errors(3);
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->matrix[i][0] != '1')
			ft_errors(3);
		i++;
	}
	is_surrounded_by_walls2(game, q_cols, q_rows);
	return (0);
}

int	q_collectible(t_game *game)
{
	int	i;
	int	j;
	int	count_c;

	i = 0;
	j = 0;
	count_c = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->matrix[i][j] == 'C')
			{
				count_c++;
			}
			j++;
		}
		i++;
	}
	game->collectible = count_c;
	return (count_c);
}

int	has_only_one_exit(t_game *game)
{
	int	i;
	int	j;
	int	count_e;

	i = 0;
	j = 0;
	count_e = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->matrix[i][j] == 'E')
			{
				count_e++;
			}
			j++;
		}
		i++;
	}
	return (count_e);
}

int	parsing_map(t_game *game)
{
	if (is_rectangular(game) != 0)
		ft_errors(3);
	if (is_surrounded_by_walls(game) != 0)
		ft_errors(3);
	if (is_initial_position(game) != 1)
		ft_errors(3);
	if (q_collectible(game) < 1)
		ft_errors(3);
	if (has_only_one_exit(game) != 1)
		ft_errors(3);
	if (valid_path_to_exit(game) == 0)
		ft_errors(3);
	if (valid_path_to_collectables(game) != 0)
		ft_errors(4);
	return (0);
}

