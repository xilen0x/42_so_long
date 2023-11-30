/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:47:14 by castorga          #+#    #+#             */
/*   Updated: 2023/11/27 13:47:17 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**matrix;
	int		map_fd;
	int		width;
	int		height;
}	t_game;

int		file_is_ber(char *str);
int		open_map(char *av, t_game *game);
int		ft_errors(int n);
void	create_map(int fd, t_game *game, char *av);
void	print_matrix(t_game *game);
int		parsing_map(t_game *game);

#endif
