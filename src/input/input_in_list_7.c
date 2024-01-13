/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_in_list_7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:16:21 by csil              #+#    #+#             */
/*   Updated: 2024/01/06 10:29:13 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

// Counter should be at 0, nbr at 1.
int	check_multiple_input_2(int fd, int counter)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strlen(line) > 1 && !ft_strncmp(line, "SO", 2))
			counter += 1;
		else if (ft_strlen(line) > 1 && !ft_strncmp(line, "NO", 2))
			counter += 2;
		else if (ft_strlen(line) > 1 && !ft_strncmp(line, "WE", 2))
			counter += 3;
		else if (ft_strlen(line) > 1 && !ft_strncmp(line, "EA", 2))
			counter += 4;
		else if (line && !ft_strncmp(line, "F", 1))
			counter += 5;
		else if (line && !ft_strncmp(line, "C", 1))
			counter += 6;
		free (line);
		line = get_next_line(fd);
	}
	free_str_and_null(&line);
	if (counter != 21)
		return (printf ("Error\nWrong argument in file.\n"));
	return (0);
}
