/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:50:45 by castorga          #+#    #+#             */
/*   Updated: 2023/11/27 10:50:47 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <unistd.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_UP					126
# define KEY_DOWN				125
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define IMG_PX 				50

typedef struct s_player
{
	void	*player_up;
	void	*player_right;
	void	*player_down;
	void	*player_left;
}				t_player;

typedef struct s_img
{
	void		*wall;
	void		*floor;
	void		*cols;
	void		*exit;
	void		*open;
	t_player	player;
	int			w;
	int			h;
}	t_img;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
	int		height;
	int		width;
	t_img	imgs;
}	t_win;

t_win	set_game(t_game *game);
void	set_img(t_game *game, char dir);

#endif
