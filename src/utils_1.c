/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:45:51 by castorga          #+#    #+#             */
/*   Updated: 2023/11/27 15:45:54 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_errors2(int n)
{
	if (n == 4)
	{
		write (2, "Error\n", 6);
		write (2, "Invalid route in map!\n", 22);
		exit(1);
	}
	/*else if (n == 5)
	{
		write (2, "Error\n", 6);
		write (2, "It was not possible to open the file\n", 37);
		exit(1);
	}
	else if (n == 6)
	{
		write (2, "Error\n", 6);
		write (2, "Invalid map file!\n", 18);
		exit(1);
	}
	else
	{
		write (2, "Error\n", 6);
		write (2, "otro!\n", 6);
		exit(1);
	}*/
	return (1);
}

/*Funcion que muestra mensajes de error*/
int	ft_errors(int n)
{
	if (n == 1)
	{
		write (2, "Error\n", 6);
		write (2, "Use: ./so_long <map.ber>\n", 25);
		exit(1);
	}
	else if (n == 2)
	{
		write (2, "Error\n", 6);
		write (2, "It was not possible to open the file\n", 37);
		exit(1);
	}
	else if (n == 3)
	{
		write (2, "Error\n", 6);
		write (2, "Invalid map file!\n", 18);
		exit(1);
	}
	else
		ft_errors2(n);
	return (1);
}


/*funcion que imprime la matriz*/
void	print_matrix(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		ft_printf("%s", game->matrix[i]);
		i++;
	}
}

/*funcion que imprime la matriz copia*/
void	print_matrix2(t_copy_game *game)
{
	int	i;

	i = 0;
	while (i < game->h2)
	{
		ft_printf("%s", game->m2[i]);
		i++;
	}
}
