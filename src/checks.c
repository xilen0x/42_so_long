/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:45:23 by castorga          #+#    #+#             */
/*   Updated: 2023/11/27 13:45:26 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*Funcion que verifica la extension .ber*/
int	file_is_ber(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (ft_strncmp(&str[len - 4], ".ber", 4) == 0)
		return (0);
	else
	{
		write (2, "Error\n", 6);
		write (2, "The file does not have a .ber extension.\n", 41);
		exit(1);
	}
}
