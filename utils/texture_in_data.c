/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_in_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:10:05 by pudry             #+#    #+#             */
/*   Updated: 2023/12/26 21:10:05 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

static int	put_texture_in_data_2(t_data *data, t_pixput *texture)
{
	texture->img = mlx_xpm_file_to_image(data->mlx, texture->path, \
		&texture->width, &texture->heigth);
	if (!texture->img)
		return (1);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bit_pp, \
		&texture->line_len, &texture->endian);
	if (!texture->addr)
		return (1);
	return (0);
}

// To launch the textures !
int	put_texture_in_data(t_data *data)
{
	if (put_texture_in_data_2(data, &data->no) == 1)
		return (1);
	if (put_texture_in_data_2(data, &data->so) == 1)
		return (1);
	if (put_texture_in_data_2(data, &data->we) == 1)
		return (1);
	if (put_texture_in_data_2(data, &data->ea) == 1)
		return (1);
	if (put_texture_in_data_2(data, &data->door) == 1)
		return (1);
	return (0);
}

static int	put_texture_in_node(t_pixput *texture, t_input *input, char *name)
{
	texture->img = mlx_xpm_file_to_image(input->mlx, name, &texture->width, \
		&texture->heigth);
	if (!texture->img)
		return (1);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bit_pp, \
		&texture->line_len, &texture->endian);
	if (!texture->addr)
		return (1);
	return (0);
}

int	all_texture_in_data(t_input *input)
{
	int	count;

	count = 0;
	count += put_texture_in_node(&input->t_no, input, input->no);
	count += put_texture_in_node(&input->t_so, input, input->so);
	count += put_texture_in_node(&input->t_we, input, input->we);
	count += put_texture_in_node(&input->t_ea, input, input->ea);
	count += put_texture_in_node(&input->door, input, input->door.path);
	if (count > 0)
	{
		printf ("Error\nFailed to open img.\n");
		free (input->tab_map);
		init_free_all_and_exit(input, 0);
		exit(1);
	}
	return (0);
}
