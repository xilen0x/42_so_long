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

/*Funcion que cuenta la cantidad de P en la mapa*/
int	is_initial_position(t_game *game)
{
	int	i;
	int	j;
	int	count_p;

	i = 0;
	j = 0;
	count_p = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->matrix[i][j] == 'P')
			{
				count_p++;
			}
			j++;
		}
		i++;
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

t_point	find_p(t_copy_game *copy_map)
{
	int		i;
	int		j;
	t_point	coord;

	i = 0;
	while (i < copy_map->h2)
	{
		j = 0;
		while (j < copy_map->w2)
		{
			if (copy_map->m2[i][j] == 'P')
			{
				coord.x = i;
				coord.y = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (coord);
}

/*Funcion que verifica si hay una ruta valida en el mapa - continuacion*/
void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return ;

	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

/*Funcion que verifica si hay una ruta valida en el mapa*/
int	has_a_valid_path(t_game *game)
{
	int			i;
	t_point		size;
	t_point		p_loc;
	t_copy_game	copy_map;

	copy_map.w2 = game->width;
	copy_map.h2 = game->height;
	copy_map.m2 = malloc((game->height + 1) * sizeof(char *));
	i = 0;
	while (game->matrix[i])
	{
		copy_map.m2[i] = ft_strdup(game->matrix[i]);
		i++;
	}
	p_loc = find_p(&copy_map);
	size.x = p_loc.x;
	size.y = p_loc.y;
	fill(copy_map.m2, size, p_loc, 0);
	return (0);
}
