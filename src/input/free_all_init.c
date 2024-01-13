/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:05:28 by cduffaut          #+#    #+#             */
/*   Updated: 2024/01/05 17:12:16 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

void	destroy_img_texture(t_input *input)
{
	if (input->t_no.img)
		mlx_destroy_image(input->mlx, input->t_no.img);
	if (input->t_so.img)
		mlx_destroy_image(input->mlx, input->t_so.img);
	if (input->t_we.img)
		mlx_destroy_image(input->mlx, input->t_we.img);
	if (input->t_ea.img)
		mlx_destroy_image(input->mlx, input->t_ea.img);
	if (input->door.img)
		mlx_destroy_image(input->mlx, input->door.img);
}
