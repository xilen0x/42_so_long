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
		//write (2, "bash: outfile: Permission denied\n", 33);
		exit(1);
	}
	else if (n == 4)
	{
		//write (2, "Command not found!\n", 19);
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

/*int	parsing_map(t_game *game)
{
	//es rectangular?

	//esta rodeado de muros?

	//tiene una posicion inicial?

	//tiene al menos un coleccionable?

	//tiene 1 salida(solamente)?

	//tiene un camino valido?

	if (all_collectables_collected && exit_count == 1)
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
	return map_invalid;
}
*/