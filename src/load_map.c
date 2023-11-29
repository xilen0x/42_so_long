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

/*
	int		fd;
	char	*line_result;

	fd = open("only_nl.txt", O_RDONLY);
	while ((line_result = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line_result);
		free(line_result);
	}
	close(fd);
*/

/**/
/*void	create_map(int fd, t_game *game)
{
	char	*line;
	int		row_count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	row_count = 0;
	line = get_next_line(fd);
	if (!line)
		write (2, "Invalid map!\n", 13);
	close(fd);
	game->width = ft_strlen(line);//n de cols(anchura)
	while (line != NULL)
	{
		//ft_printf("%d", i);
		while (line[i] < game->width)
		{
			if (line[i] == '\n')
			{
				row_count++;
			}
			i++;
		}
	}
	game->height = row_count;//n de rows(altura)
	game->matrix = (char **)malloc(sizeof(char) * (game->width));
	i = 0;
	while (i < game->height)
	{
		while (j < game->width)
		{
			game->matrix[i][j] = get_next_line(fd);
			//ft_printf("%s", game->map);
			j++;
		}
		i++;
	}
}*/

void	create_map(int fd, t_game *game)//funcion q calc. el ancho de la linea, hasta el momento
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		write (2, "Invalid map!\n", 13);
	//game->matrix = (char **)malloc(sizeof(char *) * matrix_size);
	game->width = ft_strlen(line) - 1;
	/*while (line[i])
		i++;
	i--;
	ft_printf("%d", i);*/
	close(fd);
}
//falta crear otra q calc. el alto(filas) o integrarla con la de arriba
//game->height = i; //altura o cant. de filas

int	parsing_map(char *av, t_game *game)
{
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
	return map_invalid;*/
}

/*Funcion que abre el mapa en modo lectura y almacena su fd en map_fd*/
int	open_map(char *av, t_game *game)
{
	game->map_fd = open(av, O_RDONLY);
	if (game->map_fd == -1)
		ft_errors(2);
	return (0);
}
