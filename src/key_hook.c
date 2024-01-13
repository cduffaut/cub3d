/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 09:47:37 by pudry             #+#    #+#             */
/*   Updated: 2023/12/29 09:47:37 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

static int	ft_check_angle(t_data *data, int keycode)
{
	if (keycode == 123)
		data->look = ft_calcul_ang(data->look, ANGLE * -1);
	else if (keycode == 124)
		data->look = ft_calcul_ang(data->look, ANGLE);
	else if (keycode == 49)
		ft_check_door(data);
	else
		return (0);
	ft_make_moov(data, data->xpos, data->ypos);
	return (0);
}

// a ajouter :
// pour decaler a droite iangl += 90;
// pour deplacer a gauche iangle -= 90;
// pour deplacer en arriere, iangle += 180;
// 123 / 124 change angle
int	key_hook(int keycode, t_data *data)
{
	double	iangl;

	if (keycode == 53)
		exit(0);
	else if (data->dstep)
		return (0);
	else if (keycode == 13 || keycode == 126)
		iangl = data->look;
	else if (keycode == 1 || keycode == 125)
		iangl = ft_calcul_ang(data->look, 180);
	else if (keycode == 0)
		iangl = ft_calcul_ang(data->look, -90);
	else if (keycode == 2)
		iangl = ft_calcul_ang(data->look, 90);
	else
		return (ft_check_angle(data, keycode));
	data->x = ft_calc_depl_x(iangl) + data->xpos;
	data->y = (ft_calc_depl_y(iangl) + data->ypos);
	if (ft_check_colision(data, data->x, data->y, (int)(iangl)))
		return (0);
	data->xpos = data->x;
	data->ypos = data->y;
	data->make_moov = '1';
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	int			dx;
	float		angle;
	static int	ignore_event = 0;

	if (ignore_event || data->make_moov == '1' || data->dstep)
	{
		ignore_event = 0;
		return (0);
	}
	dx = x - data->mousex;
	angle = dx * MOUSE_SENSIBILITY;
	data->mousex = x;
	data->look = ft_calcul_ang(data->look, angle);
	data->make_moov = '1';
	if ((x < 10 || x >= WIDTH - 10 || y < 0 || y >= HEIGHT) && MSE_LOCK)
	{
		ignore_event = 1;
		mlx_mouse_move(data->mlx_win, WIDTH / 2, HEIGHT / 2);
		data->mousex = WIDTH / 2;
	}
	return (0);
}

int	ft_press_cross(void)
{
	printf("Exit\n");
	exit(0);
	return (0);
}
