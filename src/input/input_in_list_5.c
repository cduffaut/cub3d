/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_in_list_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:02:41 by csil              #+#    #+#             */
/*   Updated: 2024/01/05 17:29:36 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

// skip the spaces before dup the str
char	*relay_only(char *str, int i)
{
	char	*dup;

	dup = NULL;
	if (!str)
		return (NULL);
	while (str[i] && str[i] == 32)
		i++;
	if (str[i])
	{
		dup = ft_strdup(str + i);
		free_str_and_null(&str);
		return (dup);
	}
	free_str_and_null(&str);
	return (str);
}

void	init_to_null(t_input *input, char *str)
{
	input->map = NULL;
	input->tab_map = NULL;
	input->t_we.addr = NULL;
	input->t_ea.addr = NULL;
	input->t_no.addr = NULL;
	input->t_so.addr = NULL;
	input->door.addr = NULL;
	input->t_so.img = NULL;
	input->t_we.img = NULL;
	input->t_ea.img = NULL;
	input->t_no.img = NULL;
	input->door.path = NULL;
	input->no = NULL;
	input->so = NULL;
	input->we = NULL;
	input->ea = NULL;
	input->f = NULL;
	input->c = NULL;
	input->map = NULL;
	input->tab_map = NULL;
	if (check_multiple_input(str) != 0)
	{
		init_free_all_and_exit(input, 1);
		exit (1);
	}
}
