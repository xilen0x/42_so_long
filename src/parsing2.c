/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:26:15 by castorga          #+#    #+#             */
/*   Updated: 2023/12/04 16:26:17 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*Funcion que cuenta la cantidad de P en el mapa*/
int	is_initial_position(t_game *game)
{
	int		x;
	int		y;
	int		count_p;

	x = 0;
	y = 0;
	count_p = 0;
	while (x < game->h)
	{
		y = 0;
		while (y < game->w)
		{
			if (game->matrix[y][x] == 'P')
			{
				count_p++;
			}
			y++;
		}
		x++;
	}
	return (count_p);
}

/*Funcion que verifica si el mapa es rectangular*/
int	is_rectangular(t_game *game)
{
	int		i;
	int		curr_row_len;
	int		first_row_len;

	i = 0;
	if (game->w <= 4 || game->w > 34)
		ft_errors(3);
	first_row_len = ft_strlen(game->matrix[i]);
	while (i < game->h)
	{
		curr_row_len = ft_strlen(game->matrix[i]);
		if (first_row_len != (int)ft_strlen(game->matrix[i]))
			ft_errors(3);
		i++;
	}
	return (0);
}

t_point	find_p(t_game *copy_map)
{
	int		x;
	int		y;
	t_point	coord;

	x = 0;
	while (x < copy_map->h)
	{
		y = 0;
		while (y < copy_map->w)
		{
			if (copy_map->matrix[y][x] == 'P')
			{
				coord.x = x;
				coord.y = y;
				break ;
			}
			y++;
		}
		x++;
	}
	return (coord);
}

/*Funcion que verifica si hay una ruta valida en el mapa - continuacion*/
void	fill(char **map, t_point cur, int *exit_found)
{
	if (map[cur.y][cur.x] == '1' || map[cur.y][cur.x] == '*' \
	|| *exit_found == 1)
		return ;
	if (map[cur.y][cur.x] == 'E')
		*exit_found = 1;
	map[cur.y][cur.x] = '*';
	if (*exit_found == 0)
	{
		fill(map, (t_point){cur.x - 1, cur.y}, exit_found);
		fill(map, (t_point){cur.x + 1, cur.y}, exit_found);
		fill(map, (t_point){cur.x, cur.y - 1}, exit_found);
		fill(map, (t_point){cur.x, cur.y + 1}, exit_found);
	}
}

/*Funcion que verifica si hay una ruta valida en el mapa*/
int	valid_path_to_exit(t_game *game)
{
	int			i;
	int			exit_found;
	t_point		p_loc;
	t_game		copy_map;

	exit_found = 0;
	copy_map.w = game->w;
	copy_map.h = game->h;
	copy_map.matrix = malloc(sizeof(char *) * (game->h + 1));
	i = 0;
	while (i < game->h)
	{
		copy_map.matrix[i] = ft_strdup(game->matrix[i]);
		i++;
	}
	p_loc = find_p(&copy_map);
	fill(copy_map.matrix, p_loc, &exit_found);
	print_matrix(&copy_map);
	return (exit_found);
}
