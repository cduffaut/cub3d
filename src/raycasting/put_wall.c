/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:57:09 by pudry             #+#    #+#             */
/*   Updated: 2023/12/28 16:57:14 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static t_pixput	*ft_get_texture(t_ray *ray, t_data *data)
{
	if (data->map[ray->mapy][ray->mapx] == 'D')
		return (&data->door);
	if (ray->side == 0)
	{
		if (ray->dirx >= 0 && ray->diry >= 0)
			return (&data->ea);
		else if (ray->dirx < 0 && ray->diry >= 0)
			return (&data->we);
		else if (ray->dirx < 0 && ray->diry < 0)
			return (&data->we);
		else
			return (&data->ea);
	}
	if (ray->dirx >= 0 && ray->diry >= 0)
		return (&data->no);
	else if (ray->dirx < 0 && ray->diry >= 0)
		return (&data->no);
	else if (ray->dirx < 0 && ray->diry < 0)
		return (&data->so);
	else
		return (&data->so);
}

static void	put_wall_2(t_data *data, t_wall wall, t_ray *ray, int iframe)
{
	int			iy;
	int			icolor;
	t_pixput	*img;

	img = wall.text;
	iy = wall.iystrt;
	while (iy <= HEIGHT - wall.iystrt && iy < HEIGHT)
	{
		icolor = get_color_pixel(img, ray->texx, (int)wall.iy);
		put_pixel_img(data, iframe * RESOLUTION, iy, icolor);
		wall.iy += wall.iscale;
		iy ++;
	}
	if (((data->dvalue <= (int)(ray->wallx * 100.0) && !data->drevers)
		|| (data->dvalue >= (int)(ray->wallx * 100.0) && data->drevers))
			&& data->map[ray->mapy][ray->mapx] != '1' && data->dchanged == 0)
		ft_change_door(data);
}

static void	ft_wall_biger(t_wall *wall, t_pixput *img, int wall_height)
{
	int	istart;

	istart = (wall_height - HEIGHT) / 2;
	wall->iy = (img->heigth * istart) / (double)wall_height;
	wall->iystrt = 0;
}

void	put_wall(t_data *data, t_ray *ray, int iframe)
{
	t_pixput		*img;
	t_wall			wall;

	ray->wall_height = (int)(WALL_SIZE / ray->prpwalldist);
	img = ft_get_texture(ray, data);
	if (ray->side == 0)
		ray->wallx = ray->posy + ray->prpwalldist * ray->diry;
	else
		ray->wallx = ray->posx + ray->prpwalldist * ray->dirx;
	ray->wallx -= floor(ray->wallx);
	ray->texx = ray->wallx * img->width;
	if ((ray->side == 0 && ray->dirx > 0) || (ray->side == 1 && ray->diry < 0))
		ray->texx = img->width - ray->texx - 1;
	wall.text = img;
	wall.iscale = 1.0 * img->heigth / ray->wall_height;
	wall.iystrt = HEIGHT / 2 - ray->wall_height / 2;
	wall.iy = 0.0;
	if (wall.iystrt < 0)
		ft_wall_biger(&wall, img, ray->wall_height);
	wall.iyend = (HEIGHT - wall.iystrt) * wall.iscale;
	put_wall_2(data, wall, ray, iframe);
}
