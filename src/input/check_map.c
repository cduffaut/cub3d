/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:35:29 by pudry             #+#    #+#             */
/*   Updated: 2023/12/18 11:35:29 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static int	ft_check_char(char **map)
{
	int		i;
	int		j;
	int		iplayer;
	char	c;

	i = 0;
	iplayer = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
			if (c != '0' && c != ' ' && c != 'N' && c != 'S' && c != 'E' \
				&& c != 'W' && c != '1' && c != 'D')
				return (102);
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				iplayer ++;
			j ++;
		}
		i ++;
	}
	if (iplayer != 1)
		return (101);
	return (1);
}

static int	ft_check_wall(char c)
{
	return (c == '1' || c == ' ');
}

static int	ft_check_extern_line(char **map, int il1, int il2)
{
	int	i;

	i = 0;
	while (map[il1][i])
	{
		if (map[il1][i] != ' ' && map[il1][i] != '1')
			return (0);
		else if (map[il1][i] == ' ' && map[il2][i] != '1' \
			&& map[il2][i] != ' ' )
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_middle_line(char **map, int j)
{
	int	i;

	i = 1;
	if (map[j][0] != ' ' && map[j][0] != '1')
		return (0);
	while (map[j][i + 1])
	{
		if (map[j][i] == ' ')
		{
			if (!ft_check_wall(map[j][i - 1]) || !ft_check_wall(map[j][i + 1]))
				return (0);
			else if (!ft_check_wall(map[j - 1][i]) \
				|| !ft_check_wall(map[j + 1][i]))
				return (0);
		}
		i ++;
	}
	if (!ft_check_wall(map[j][i]))
		return (0);
	return (1);
}

int	ft_check_map(char **map)
{
	int	i;

	i = ft_check_char(map);
	if (i != 1)
		return (i);
	if (!ft_check_extern_line(map, 0, 1))
		return (100);
	while (map[i + 1])
	{
		if (!ft_check_middle_line(map, i))
			return (100);
		i ++;
	}
	if (!ft_check_extern_line(map, i, i - 1))
		return (100);
	return (0);
}
