/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:45:51 by castorga          #+#    #+#             */
/*   Updated: 2023/11/27 15:45:54 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*Funcion que muestra mensajes de error*/
int	ft_errors(int n)
{
	if (n == 1)
	{
		write (2, "Error\n", 6);
		write (2, "Use: ./so_long <map.ber>\n", 25);
		exit(1);
	}
	else if (n == 2)
	{
		write (2, "Error\n", 6);
		write (2, "It was not possible to open the file\n", 37);
		exit(1);
	}
	else if (n == 3)
	{
		write (2, "Error\n", 6);
		write (2, "Invalid map file!\n", 18);
		exit(1);
	}
	else if (n == 4)
	{
		write (2, "Error\n", 6);
		write (2, "Invalid x!\n", 11);
		exit(1);
	}
	else
		//write (2, "error", 5);
	return (1);
}

/*funcion que imprime la matriz*/
void	print_matrix(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		ft_printf("%s", game->matrix[i]);
		i++;
	}
}

/*Funcion que verifica si el mapa es rectangular*/
int	is_rectangular(t_game *game)
{
	int		i;
	int		curr_row_len;
	int		first_row_len;

	i = 0;
	if (game->width <= 4 || game->width > 34)
		ft_errors(3);
	first_row_len = ft_strlen(game->matrix[i]);
	while (i < game->height)
	{
		curr_row_len = ft_strlen(game->matrix[i]);
		if (first_row_len != (int)ft_strlen(game->matrix[i]))
			ft_errors(3);
		i++;
	}
	return (0);
}

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

int	is_initial_position(t_game *game)//*******aki voy!!!!!
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->height)
	{
		//while (j < game->width)
		//{
			if (game->matrix[i][j] == 'P')
			{
				printf("%c\n", game->matrix[i][j]);
				return 0;
			}
			//j++;
		//}
		i++;
	}
	return (1);
}

int	parsing_map(t_game *game)
{
	if (is_rectangular(game) != 0)
		ft_errors(3);
	//esta rodeado de muros?
	if (is_surrounded_by_walls(game) != 0)
		ft_errors(3);
	//tiene una posicion inicial?
	if (is_initial_position(game) != 0)
		ft_errors(4);
	//tiene al menos un coleccionable?

	//tiene 1 salida(solamente)?

	//tiene un camino valido?

	/*if (all_collectables_collected && exit_count == 1)
		return map_valid;
	if (on_wall)
		return map_invalid;
	if (on_collectable)
		collectables++;
	if (on_exit)
		exits++;
	replace_current_position_with_wall;
	if (one_of_the_four_adjacent_directions_is_possible)
		return map_valid;
	return map_invalid; */
	return 0;
}
