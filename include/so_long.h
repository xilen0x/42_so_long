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
	int		collectible;
}	t_game;

typedef struct s_game_copy
{
	char	**m2;
	int		w2;
	int		h2;
}	t_copy_game;

typedef struct s_point
{
	int			x;
	int			y;
}	t_point;

int		file_is_ber(char *str);
int		open_map(char *av, t_game *game);
int		ft_errors(int n);
void	create_map(int fd, t_game *game, char *av);
void	print_matrix(t_game *game);
void	print_matrix2(t_copy_game *game);
int		parsing_map(t_game *game);
int		is_rectangular(t_game *game);
int		is_initial_position(t_game *game);
int		is_surrounded_by_walls(t_game *game);
int		has_only_one_exit(t_game *game);
int		valid_path_to_exit(t_game *game);
int		valid_path_to_collectables(t_game *game);
int		q_collectible(t_game *game);
t_point	find_p(t_copy_game *copy_map);

#endif
