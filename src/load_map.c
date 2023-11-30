/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:21:15 by castorga          #+#    #+#             */
/*   Updated: 2023/11/27 15:21:17 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*Funcion que calcula columnas para luego reservar la matriz*/
void	create_map(int fd, t_game *game, char *av)
{
	char	*line;
	int		row_count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = get_next_line(fd);
	if (!line)
		write (2, "Invalid map!\n", 13);
	game->width = ft_strlen(line) - 1;
	row_count = 1;
	while (line)
	{
		row_count++;
		free(line);
		line = get_next_line(fd);
	}
	game->height = row_count;
	close(fd);
	open_map(av, game);
	game->matrix = malloc((game->height + 1) * sizeof(char *));
	while (game->height)
	{
		game->matrix[i] = malloc(game->width * sizeof(char));
	}
	//game->matrix[i] = get_next_line(game->map_fd);
	//while (game->matrix[i])
	while (i < game->height)
	{
		while (j < game->width)
		{
			game->matrix[i] = get_next_line(game->map_fd);
		}
		i++;
	}
	close(fd);
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

/*Funcion que abre el mapa en modo lectura y almacena su fd en map_fd*/
int	open_map(char *av, t_game *game)
{
	game->map_fd = open(av, O_RDONLY);
	if (game->map_fd == -1)
		ft_errors(2);
	return (0);
}
