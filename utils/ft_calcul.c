/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:56:18 by pudry             #+#    #+#             */
/*   Updated: 2023/12/17 09:06:39 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

double	deg_to_rad(double deg)
{
	return (((double) deg * 2 * PI) / 360);
}

double	ft_calc_depl_x(double iangl)
{
	return (cos(deg_to_rad(iangl)) * DEPLACEMENT);
}

double	ft_calc_depl_y(double iangl)
{
	return (sin(deg_to_rad(iangl)) * DEPLACEMENT);
}

double	ft_calcul_ang(double iangl, double iofset)
{
	iangl += iofset;
	if (iangl < 0)
		return (360 + iangl);
	else if (iangl >= 360)
		return (iangl - 360);
	return (iangl);
}
