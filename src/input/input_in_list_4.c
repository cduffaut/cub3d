/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_in_list_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:16:27 by pudry             #+#    #+#             */
/*   Updated: 2023/12/28 18:16:27 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static char	*ft_change_size_line(char *line, int ilen)
{
	int		i;
	char	*new_line;

	new_line = (char *) malloc(sizeof(char) * (ilen + 1));
	if (!new_line)
		return (NULL);
	new_line[ilen] = '\0';
	i = 0;
	while (line && line[i] && line[i] != '\n' && i < ilen)
	{
		new_line[i] = line[i];
		i ++;
	}
	while (i < ilen)
		new_line[i ++] = ' ';
	line = NULL;
	return (new_line);
}

static t_data	*ft_map_equal_line(char **map, t_data *data)
{
	int		i;
	int		ilen;

	i = 0;
	ilen = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) > ilen)
			ilen = (ft_strlen(map[i]));
		i ++;
	}
	i = 0;
	while (map[i])
	{
		map[i] = ft_change_size_line(map[i], ilen);
		if (!map[i])
			ft_error_quit(data, 12);
		i ++;
	}
	data->map = map;
	data->ix = ilen;
	data->iy = i;
	return (data);
}

static t_data	*ft_put_player(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (data->map[i])
	{
		j = 1;
		while (data->map[i][j] && !ft_check_player(data->map[i][j]))
			j ++;
		if (ft_check_player(data->map[i][j]))
			break ;
		i ++;
	}
	if (data->map[i][j] == 'N')
		data->look = 270;
	else if (data->map[i][j] == 'S')
		data->look = 90;
	else if (data->map[i][j] == 'E')
		data->look = 0;
	else if (data->map[i][j] == 'W')
		data->look = 180;
	data->xpos = (double)j + 0.5;
	data->ypos = (double)i + +0.5;
	return (data);
}

// no et so are revers
static void	put_paths_in_data(t_data *data, t_input *input)
{
	data->no.path = ft_strdup(input->so);
	data->so.path = ft_strdup(input->no);
	data->ea.path = ft_strdup(input->ea);
	data->we.path = ft_strdup(input->we);
	data->door.path = ft_strdup(input->door.path);
	data->no.img = NULL;
	data->so.img = NULL;
	data->ea.img = NULL;
	data->we.img = NULL;
	data->door.img = NULL;
	data->mousex = 0;
}

t_data	*t_input_to_t_data(t_input *input)
{
	t_data	*data;

	all_texture_in_data(input);
	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		ft_error_quit(NULL, 12);
	data->mlx = input->mlx;
	data->mlx_win = NULL;
	data = ft_map_equal_line(input->tab_map, data);
	if (ft_check_map(data->map))
	{
		init_free_all_and_exit(input, 0);
		ft_error_quit(data, ft_check_map(data->map));
	}
	data = ft_put_player(data);
	put_paths_in_data(data, input);
	data->f = input->color_floor;
	data->c = input->color_ceiling;
	return (data);
}
