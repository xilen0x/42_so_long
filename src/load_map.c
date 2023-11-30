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

void	create_matrix(t_game *game, char *av)
{
	int	i;

	i = 0;
	open_map(av, game);
	game->matrix = malloc((game->height + 1) * sizeof(char *));
	game->matrix[game->height] = NULL;
	while (i < game->height)
	{
		game->matrix[i] = get_next_line(game->map_fd);
		i++;
	}
	close(game->map_fd);
}

/*Funcion que calcula las columnas & filas*/
void	create_map(int fd, t_game *game, char *av)
{
	int		i;
	int		j;
	char	*line;
	int		row_count;

	i = 0;
	j = 0;
	line = get_next_line(fd);
	if (!line)
		write (2, "Invalid map!\n", 13);
	game->width = ft_strlen(line) - 1;
	row_count = 0;
	while (line)
	{
		row_count++;
		free(line);
		line = get_next_line(fd);
	}
	game->height = row_count;
	close(fd);
	create_matrix(game, av);
}

/*Funcion que abre el mapa en modo lectura y almacena su fd en map_fd*/
int	open_map(char *av, t_game *game)
{
	game->map_fd = open(av, O_RDONLY);
	if (game->map_fd == -1)
		ft_errors(2);
	return (0);
}
