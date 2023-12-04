/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:13:32 by castorga          #+#    #+#             */
/*   Updated: 2023/11/27 12:13:34 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/window.h"

	/* Otras posibles funciones:
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
	
	//int			to_find;
//to_find = has_at_least_one_collectible(game) + 1;

void	map_flood_fill(t_copy_game *map, int i, int j, int *to_find)
{
	if (map->m2[map->i][map->j] == '1' || map->m2[map->i][map->j] \
	== '*' || *to_find == 0)
		return ;
	if (map->m2[map->i][map->j] == 'E' || map->m2[map->i][map->j] == 'C')
		*to_find = *to_find - 1;
	map->m2[map->i][map->j] = '*';
}
	
	*/

/*Funcion que inicializa minilibx y crea una ventana*/
t_win	new_program(int w, int h, char *str)

{
	void	*mlx;

	mlx = mlx_init();
	return ((t_win){mlx, mlx_new_window(mlx, w, h, str), w, h});
}
