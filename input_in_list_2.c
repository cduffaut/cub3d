/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_in_list_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:02:41 by csil              #+#    #+#             */
/*   Updated: 2023/12/17 12:34:08 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "cub3d.h"

t_list	*ptr_last_node(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
	{
		list = list->next;
	}
	return (list);
}

int	len_tab(t_list *list)
{
	int		len;

	len = 0;
	while (list->next != NULL)
	{
		list = list->next;
		len++;
	}
	return (len);
}

char	*ft_strdup_free(const char *str)
{
	int		isize;
	int		i;
	char	*dup;

	isize = ft_strlen(str);
	dup = (char *) malloc(isize + 1);
	if (! dup)
		return (NULL);
	dup[isize --] = '\0';
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i ++;
	}
	return (dup);
}

int	only_path(t_input *input)
{
	if (input->no[0] == 'N' && input->no[1] == 'O' && input->no[2] == ' ')
		input->no = ft_strdup_free(input->no + 3);
	else
		return (init_print_error("Error : NO is not valid.\n"));
	if (input->so[0] == 'S' && input->so[1] == 'O' && input->so[2] == ' ')
		input->so = ft_strdup_free(input->so + 3);
	else
		return (init_print_error("Error : SO is not valid.\n"));
	if (input->we[0] == 'W' && input->we[1] == 'E' && input->we[2] == ' ')
		input->we = ft_strdup_free(input->we + 3);
	else
		return (init_print_error("Error : WE is not valid.\n"));
	if (input->ea[0] == 'E' && input->ea[1] == 'A' && input->ea[2] == ' ')
		input->ea = ft_strdup_free(input->ea + 3);
	else
		return (init_print_error("Error : EA is not valid.\n"));
	return (0);
}

int	only_nbr(t_input *input)
{
	if (input->f[0] == 'F' && input->f[1] == ' ')
		input->f = ft_strdup_free(input->f + 2);
	else
		return (init_print_error("Error : F is not valid.\n"));
	if (input->c[0] == 'C' && input->c[1] == ' ')
		input->c = ft_strdup_free(input->c + 2);
	else
		return (init_print_error("Error : C is not valid.\n"));
	return (0);
}