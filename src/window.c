/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:13:32 by castorga          #+#    #+#             */
/*   Updated: 2023/11/27 12:13:34 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/window.h"

/*Funcion que inicializa minilibx y crea una ventana*/
t_win	new_program(int w, int h, char *str)

{
	void	*mlx;

	mlx = mlx_init();
	return ((t_win){mlx, mlx_new_window(mlx, w, h, str), w, h});
}
