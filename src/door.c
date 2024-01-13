/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 09:41:25 by pudry             #+#    #+#             */
/*   Updated: 2023/12/29 10:07:49 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

static void	ft_door(t_data *data, int y, int x)
{
	if (data->map[y][x] == 'D' && data->cdvalue == 'O')
		data->map[y][x] = 'O';
	else if (data->map[y][x] == 'O' && data->cdvalue == 'D')
		data->map[y][x] = 'D';
	data->dchanged ++;
}

void	ft_change_door(t_data *data)
{
	int	l;
	int	r;

	r = (int)ft_calcul_ang(data->lok, LOOK_ANGLE / 2);
	l = (int)ft_calcul_ang(data->lok, -(LOOK_ANGLE / 2));
	if ((l > 315 || l < 45) || (r > 315 || r < 45))
		ft_door(data, (int)data->ypos, (int)data->xpos + 1);
	if ((l > 45 && l < 135) || (r > 45 && r < 135))
		ft_door(data, (int)data->ypos + 1, (int)data->xpos);
	if ((l > 135 && l < 225) || (r > 135 && r < 225))
		ft_door(data, (int)data->ypos, (int)data->xpos - 1);
	if ((l > 225 && l < 315) || (r > 135 && r < 225))
		ft_door(data, (int)data->ypos - 1, (int)data->xpos);
}

void	ft_check_door2(t_data *data, int y, int x, int ineg)
{
	if ((data->map[y][x] == 'D' && !ineg)
		|| (data->map[y][x] == 'O' && ineg))
	{
		data->dstep = -2;
		data->dvalue = 100;
		data->drevers = ineg;
	}
	else if ((data->map[y][x] == 'O' && !ineg)
		|| (data->map[y][x] == 'D' && ineg))
	{
		data->dstep = 2;
		data->dvalue = 0;
		data->drevers = ineg;
	}
}

static void	ft_check_door_angl(t_data *data, int angl)
{
	if (angl > 315 || angl < 45)
		ft_check_door2(data, (int)data->ypos, (int)data->xpos + 1, 0);
	if (angl > 45 && angl < 135)
		ft_check_door2(data, (int)data->ypos + 1, (int)data->xpos, 1);
	if (angl > 135 && angl < 225)
		ft_check_door2(data, (int)data->ypos, (int)data->xpos - 1, 1);
	if (angl > 225 && angl < 315)
		ft_check_door2(data, (int)data->ypos - 1, (int)data->xpos, 0);
}

void	ft_check_door(t_data *data)
{
	int	l;
	int	r;

	r = (int)ft_calcul_ang(data->look, LOOK_ANGLE / 2);
	l = (int)ft_calcul_ang(data->look, -(LOOK_ANGLE / 2));
	ft_check_door_angl(data, r);
	ft_check_door_angl(data, l);
	ft_check_door_angl(data, (int)data->look);
}
