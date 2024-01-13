/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:08:04 by pudry             #+#    #+#             */
/*   Updated: 2023/12/29 10:08:04 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

static t_data	*init_game(char **argv)
{
	t_data	*data;

	data = init_list(argv);
	if (!data)
		return (NULL);
	data->x = data->xpos;
	data->y = data->ypos;
	data->make_moov = '1';
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "CUBE3D");
	return (data);
}

static void	ft_moov_door(t_data *data)
{
	data->dvalue += data->dstep;
	data->cdvalue = 'D';
	ft_change_door(data);
	data->cdvalue = 'O';
	data->dchanged = 0;
	if (data->dvalue <= 0 || data->dvalue >= 100)
	{
		data->dchanged = 1;
		if (data->dstep < 0 && !data->drevers)
			data->cdvalue = 'O';
		else if (data->dstep < 0 && data->drevers)
			data->cdvalue = 'D';
		else if (data->dstep > 0 && !data->drevers)
			data->cdvalue = 'D';
		else
			data->cdvalue = 'O';
		data->dstep = 0;
		ft_change_door(data);
	}
	data->make_moov = '1';
}

static int	ft_loop(t_data *data)
{
	if (!data->no.img)
	{
		put_texture_in_data(data);
		free(data->no.path);
		free(data->so.path);
		free(data->ea.path);
		free(data->we.path);
		free(data->door.path);
	}
	if (data->dstep != 0)
		ft_moov_door(data);
	if (data->make_moov == '1')
	{
		data->lok = data->look;
		ft_make_moov(data, data->x, data->y);
		data->make_moov = '0';
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		*data;

	if (argc < 2)
		return (printf ("Error\nToo few arguments in input.\n"));
	if (argc > 2)
		return (printf ("Error\nToo much arguments in input.\n"));
	if (argc != 2)
		exit(1);
	if (check_extension(argv[1]) != 0)
		exit(1);
	data = init_game(argv);
	if (!data)
		return (0);
	mlx_hook(data->mlx_win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->mlx_win, 17, 0, ft_press_cross, NULL);
	if (MSE_LOCK)
		mlx_mouse_hide();
	mlx_hook(data->mlx_win, 6, 0, mouse_move, data);
	mlx_loop_hook(data->mlx, ft_loop, data);
	mlx_loop(data->mlx);
	free_and_exit_final(data);
}
