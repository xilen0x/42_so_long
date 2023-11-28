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
	//char	*line;
	char	*row;
	int		i;
	int		j;

	i = 0;
	j = 0;
	row = get_next_line(fd);
	game->width = ft_strlen(get_next_line(fd));//n de cols
	while (row[i])
	{
		row = get_next_line(fd);
		ft_printf("test ");//entra 2 veces aqui?
		while (row[i] <= game->width)
		{
			if (row[i] == '\n')
				i++;
		}
	}
	game->height = i;//n de rows
	game->map = (char *)malloc(sizeof(char) * (game->width * game->height));
	while (i < game->height)
	{
		while (j < game->width)
		{
			game->map = get_next_line(fd);
			ft_printf("%s", game->map);
			j++;
		}
		i++;
	}
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
