/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:46:30 by castorga          #+#    #+#             */
/*   Updated: 2023/11/26 15:46:32 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"
//#include "../include/window.h"
/*
cc main.c -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit
*/

/*int	main(void)
{
	t_win	my_program;

	my_program = new_program(300, 300, "so_long");
	if (!my_program.mlx || !my_program.mlx_win)
		return (1);
	mlx_loop(my_program.mlx);
	return (0);
}*/

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac == 2)
	{
		file_is_ber(av[1]);
		open_map(av[1], &game);
	}
	else
		ft_errors(1);
	return (0);
}
