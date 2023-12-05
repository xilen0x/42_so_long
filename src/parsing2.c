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
void	fill(char **tab, t_point cur, int *exit_found)
{
	if (tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == '*' \
	|| *exit_found == 1)
		return ;
	if (tab[cur.y][cur.x] == 'E')
		*exit_found = 1;
	tab[cur.y][cur.x] = '*';
	if (*exit_found == 0)
	{
		fill(tab, (t_point){cur.x - 1, cur.y}, exit_found);
		fill(tab, (t_point){cur.x + 1, cur.y}, exit_found);
		fill(tab, (t_point){cur.x, cur.y - 1}, exit_found);
		fill(tab, (t_point){cur.x, cur.y + 1}, exit_found);
	}
}

/*Funcion que verifica si hay una ruta valida en el mapa*/
int	valid_path_to_exit(t_game *game)
{
	int			i;
	int			exit_found;
	t_point		p_loc;
	t_copy_game	copy_map;

	exit_found = 0;
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
	fill(copy_map.m2, p_loc, &exit_found);
	//print_matrix2(&copy_map);
	return (exit_found);
}
