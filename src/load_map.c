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

/**/
void	create_map(int fd, t_game *game)
{
	char	*line_result;

	(void)game;
	while ((line_result = get_next_line(fd)) != NULL)
	{
		ft_printf("%s\n", line_result);
		free(line_result);
	}
	close(fd);
}

/*Funcion que abre el mapa en modo lectura y almacena su fd en map_fd*/
int	open_map(char *av, t_game *game)
{
	game->map_fd = open(av, O_RDONLY);
	if (game->map_fd == -1)
		ft_errors(2);
	create_map(game->map_fd, game);
	return (0);
}
