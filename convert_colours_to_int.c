/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_colours_to_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:28:38 by csil              #+#    #+#             */
/*   Updated: 2023/12/16 13:49:52 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	(void) colour;
	if (other_than_digit(str) == 1)
	{
		printf ("Error: only numbers are allowed for colours value\n");
		free_str_and_null(str);
		return (1);
	}
	else if (is_size_nbr_valid(str) == 1)
	{
		printf ("Error: number between 0-255 are allowed for colours value\n");
		free_str_and_null(str);
		return (1);
	}
	*colour = ft_atoi(str);
	free(str);
	str = NULL;
	return (0);
}

// Return (0) : if everything went well.
// Return (1) : Error has been detected,
// Error message has been printed.
// Ex input: 220,100,0
static int	separe_colours_in_str_f(char *str, t_input *input)
{
	int		i;
	int		step;

	step = 0;
	i = 0;
	while (str[i])
	{
		i = 0;
		while (str[i] && str[i] != ',')
			i++;
		if (step == 0
			&& (convert_colours_to_int(ft_strndup(str, i), &input->f_r) == 1))
			return (1);
		else if (step == 1
			&& (convert_colours_to_int(ft_strndup(str, i), &input->f_g) == 1))
			return (1);
		else if (step == 2
			&& (convert_colours_to_int(ft_strndup(str, i), &input->f_b) == 1))
			return (1);
		step++;
		str += i;
		if (*str && *str == ',')
			str++;
	}
	return (0);
}

static int	separe_colours_in_str_c(char *str, t_input *input)
{
	int		i;
	int		step;

	step = 0;
	i = 0;
	while (str[i])
	{
		i = 0;
		while (str[i] && str[i] != ',')
			i++;
		if (step == 0
			&& (convert_colours_to_int(ft_strndup(str, i), &input->c_r) == 1))
			return (1);
		else if (step == 1
			&& (convert_colours_to_int(ft_strndup(str, i), &input->c_g) == 1))
			return (1);
		else if (step == 2
			&& (convert_colours_to_int(ft_strndup(str, i), &input->c_b) == 1))
			return (1);
		step++;
		str += i;
		if (*str && *str == ',')
			str++;
	}
	return (0);
}

int	init_separe_colours(t_input *input)
{
	if (not_enough_commas(input->c) == 1)
		return (1);
	if (not_enough_commas(input->f) == 1)
		return (1);
	if (separe_colours_in_str_c(input->c, input) == 1)
		return (1);
	if (separe_colours_in_str_f(input->f, input) == 1)
		return (1);
	return (0);
}

/*int main(int argc, char **argv)
{
    t_input input;
    (void) argc;
    (void) argv;

    input = (t_input){};
    input.f = "23,346373,+353";
    input.c = "1111111,22222,3333333";

    printf("return value : %d\n", init_separe_colours(&input));

    printf("input 1: %d\n", input.c_r);
    printf("input 2: %d\n", input.c_g);
    printf("input 3: %d\n", input.c_b);

    printf("input 1: %d\n", input.f_r);
    printf("input 2: %d\n", input.f_g);
    printf("input 3: %d\n", input.f_b);

    return (0);
}*/
