/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_colours_to_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:05:47 by pudry             #+#    #+#             */
/*   Updated: 2023/12/17 11:05:47 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

// Check if the nbr is to big.
// If it is too big : return 1
// If R.A.S : return (0);
static int	is_size_nbr_valid(char *str)
{
	long long	nbr;
	int			i;

	nbr = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (1);
		i++;
	}
	while (str[i])
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	if (nbr < 0)
		return (1);
	else if (nbr > 255)
		return (1);
	return (0);
}

// Return 1 if an  error was discovered.
// Return 0 if everything was fine.
static int	convert_colours_to_int(char *str, int *colour)
{
	if (other_than_digit(str) == 1)
	{
		printf ("Error\nonly numbers are allowed for colours value\n");
		return (1);
	}
	else if (is_size_nbr_valid(str) == 1)
	{
		printf ("Error\nnumber between 0-255 are allowed for colours value\n");
		return (1);
	}
	*colour = ft_atoi(str);
	return (0);
}

// Return (0) : if everything went well.
// Return (1) : Error has been detected,
// Error message has been printed.
// Ex input: 220,100,0
static int	separe_colours_in_str_f(char *str, t_input *input, int counter)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_split(str, ',');
	if (!tab)
		return (printf("Error\nallocation failed\n"));
	while (tab[i])
	{
		if (i == 0)
			counter += convert_colours_to_int(tab[i], &input->f_r);
		else if (i == 1)
			counter += convert_colours_to_int(tab[i], &input->f_g);
		else if (i == 2)
			counter += convert_colours_to_int(tab[i], &input->f_b) == 1;
		i++;
	}
	free_tab(tab);
	return (counter);
}

static int	separe_colours_in_str_c(char *str, t_input *input, int counter)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_split(str, ',');
	if (!tab)
		return (printf ("Error\nallocation failed\n"));
	while (tab[i])
	{
		if (i == 0)
			counter += (convert_colours_to_int(tab[i], &input->c_r) == 1);
		else if (i == 1)
			counter += (convert_colours_to_int(tab[i], &input->c_g) == 1);
		else if (i == 2)
			counter += (convert_colours_to_int(tab[i], &input->c_b) == 1);
		i++;
	}
	free_tab(tab);
	return (counter);
}

int	init_separe_colours(t_input *input)
{
	if (not_enough_commas(input->c) == 1)
		return (1);
	if (not_enough_commas(input->f) == 1)
		return (1);
	if (separe_colours_in_str_c(input->c, input, 0) != 0)
		return (1);
	if (separe_colours_in_str_f(input->f, input, 0) != 0)
		return (1);
	return (0);
}
