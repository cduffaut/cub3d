/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erreur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:34:24 by pudry             #+#    #+#             */
/*   Updated: 2023/12/18 11:34:35 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static void	ft_free_array(char **map)
{
	int	j;

	if (!map)
		return ;
	j = 0;
	while (map[j])
		free(map[j ++]);
	free(map);
}

static void	ft_send_msg(int i)
{
	if (i == 12)
		printf("Error\nmalloc\n");
	else if (i == 100)
		printf("Error\nLa map doit être entourée de murs.\n");
	else if (i == 101)
		printf("Error\nMap : player invalide.\n");
	else if (i == 102)
		printf("Error\nmap invalide.\n");
}

void	ft_error_quit(t_data *data, int icode)
{
	ft_free_array(data->map);
	if (data->mlx && data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	free(data);
	ft_send_msg(icode);
	if (icode == 12)
		exit(12);
	else if (icode == 0)
		exit(0);
	exit(1);
}
