/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_in_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:02:41 by csil              #+#    #+#             */
/*   Updated: 2023/12/15 13:00:20 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "utils/utils.h"
#include "cub3d.h"

int		len_tab(t_list *list)
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

void	put_map_int_tab(t_input *input)
{
	int		i;
	int		len;
	t_list	*tmp;

	tmp = input->map;
	len = len_tab(tmp);
	input->tab_map = malloc(sizeof(char *) * (len + 1));
	if (!input->tab_map)
	{
		// exit error func
		return ;
	}
	i = 0;
	while (tmp->next != NULL)
	{
		input->tab_map[i] = tmp->str;
		tmp = tmp->next;
		i++;
	}
	input->tab_map[i] = tmp->str;
	input->tab_map[i + 1] = NULL;
}

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

void	add_end(t_list **list, char *line)
{
	t_list	*tmp;
	t_list	*new_node;
	int		i;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		printf ("Error list allocation\n");
		return ;
	}
	new_node->str = line;
	new_node->next = NULL;
	if (!*list)
	{
		*list = new_node;
		return ;
	}
	tmp = ptr_last_node(*list);
	tmp->next = new_node;
}

void	create_linked_list(t_input *input, int fd, char	*line)
{
	while (1)
	{
		if (line == NULL)
		{
			free(line);
			break;
		}
		add_end(&input->map, line);
		line = get_next_line(fd);
	}
}

void	input_in_list(t_input *input, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line[0] == '\n' && line[1] == '\0')
		{
			free (line);
			line = NULL;
		}
		else if (!input->no)
			input->no = line;
		else if (!input->so)
			input->so = line;
		else if (!input->we)
			input->we = line;
		else if (!input->ea)
			input->ea = line;
		else if (!input->f)
			input->f = line;
		else if (!input->c)
			input->c = line;
		else
		{
			create_linked_list(input, fd, line);
			break ;
		}
	}
	if (line)
	{
		free (line);
		line = NULL;
	}
}

void	init_list(char **argv)
{
	t_input	input;
	int		fd;

	input = (t_input){};
	fd = open(argv[1], O_RDWR);
	// put an exit error func
	if (fd < 0)
	{
		printf ("error map opening\n");
		return ;
	}
	input_in_list(&input, fd);
	put_map_int_tab(&input);
	print_list(input.map);
	print_tab(input.tab_map);
	close(fd);
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	init_list(argv);
	return (0);
}
