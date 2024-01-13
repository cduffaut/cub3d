/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_in_list_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <cduffaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:02:41 by csil              #+#    #+#             */
/*   Updated: 2024/01/05 13:31:16 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

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

char	*ft_strdup_free(char *str)
{
	int		isize;
	int		i;
	char	*dup;

	isize = ft_strlen(str);
	dup = (char *) malloc(isize + 1);
	if (!dup)
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
		input->no = relay_only(input->no, 2);
	else
		return (init_print_error("Error\nNO is not valid.\n"));
	if (input->so[0] == 'S' && input->so[1] == 'O' && input->so[2] == ' ')
		input->so = relay_only(input->so, 2);
	else
		return (init_print_error("Error\nSO is not valid.\n"));
	if (input->we[0] == 'W' && input->we[1] == 'E' && input->we[2] == ' ')
		input->we = relay_only(input->we, 2);
	else
		return (init_print_error("Error\nWE is not valid.\n"));
	if (input->ea[0] == 'E' && input->ea[1] == 'A' && input->ea[2] == ' ')
		input->ea = relay_only(input->ea, 2);
	else
		return (init_print_error("Error\nEA is not valid.\n"));
	if (!input->ea || !input->we || !input->so || !input->no)
		return (printf ("Error\nElement in file input are not valid.\n"));
	return (0);
}

int	only_nbr(t_input *input)
{
	if (!input || !input->f || !input->c)
		return (init_print_error("Error\nInvalid input pointers.\n"));
	if (input->f[0] == 'F' && input->f[1] == ' ')
		input->f = relay_only(input->f, 1);
	else
		return (init_print_error("Error\nF is not valid.\n"));
	if (input->c[0] == 'C' && input->c[1] == ' ')
		input->c = relay_only(input->c, 1);
	else
		return (init_print_error("Error\nC is not valid.\n"));
	if (!input->c || !input->f)
		return (init_print_error("Error\nElement map are not valid.\n"));
	return (0);
}
