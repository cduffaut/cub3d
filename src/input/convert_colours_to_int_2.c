/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_colours_to_int_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:05:38 by pudry             #+#    #+#             */
/*   Updated: 2023/12/17 11:05:43 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

// return 1: if the number of commas is incorrect
// return 0: if there is the right number of commas
int	not_enough_commas(char *str)
{
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			counter++;
		i++;
	}
	if (counter == 2)
		return (0);
	printf ("Error\nshould be 3 numbers separate by commas (RGB)\n");
	return (1);
}

char	*ft_strndup(const char *str, int isize)
{
	int		i;
	char	*dup;

	dup = NULL;
	if (str)
	{
		dup = (char *) malloc(isize + 1);
		if (!dup)
			return (NULL);
		i = 0;
		while (i < isize)
		{
			dup[i] = str[i];
			i++;
		}
		dup[i] = '\0';
	}
	return (dup);
}

// Check if there is other sh*ts than digits.
// return 1 if yes, 0 if no.
int	other_than_digit(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (1);
		}
		i++;
	}
	return (0);
}
