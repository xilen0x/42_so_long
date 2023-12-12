/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:48:40 by castorga          #+#    #+#             */
/*   Updated: 2023/12/05 12:48:44 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*Funcion que verifica si hay una ruta valida para todos los coleccionables-2*/
int	fill2(char **map, t_point cur, int *collectible)
{
	if (map[cur.y][cur.x] == '1' || map[cur.y][cur.x] == '*' \
	|| map[cur.y][cur.x] == 'E')
		return (1);
	if (map[cur.y][cur.x] == 'C')
		(*collectible)--;
	map[cur.y][cur.x] = '*';
	if (*collectible > 0)
	{
		fill2(map, (t_point){cur.x - 1, cur.y}, collectible);
		fill2(map, (t_point){cur.x + 1, cur.y}, collectible);
		fill2(map, (t_point){cur.x, cur.y - 1}, collectible);
		fill2(map, (t_point){cur.x, cur.y + 1}, collectible);
	}
	//printf("col: %d\n", *collectible);
	return (*collectible);
}

/*Funcion que verifica si hay una ruta valida para todos los coleccionables-1*/
int	valid_path_to_collectables(t_game *game)
{
	int			i;
	t_point		p_loc;
	t_game		copy_map;
	int			collectible;

	i = 0;
	copy_map.matrix = malloc(sizeof(char *) * (game->h + 1));
	while (game->matrix[i])
	{
		copy_map.matrix[i] = ft_strdup(game->matrix[i]);
		i++;
	}
	p_loc = find_p(&copy_map, game);
	collectible = fill2(copy_map.matrix, p_loc, &game->q_collec);
	//print_matrix(&copy_map);
	return (collectible);
}

