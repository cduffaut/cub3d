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

static void	put_map_int_tab(t_input *input)
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

static int	create_linked_list(t_input *input, int fd, char	*line)
{
	if (only_path(input))
		return (1);
	if (only_nbr(input))
		return (1);
	while (1)
	{
		if (line == NULL)
		{
			free(line);
			break;
		}
		add_end(&input->map, line, input);
		line = get_next_line(fd);
	}
	return (0);
}

void	free_str_and_null(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	} 
}

static void	input_in_list(t_input *input, int fd, char *line)
{
	while (1)
	{
		line = get_next_line(fd);
		if (line[0] == '\n' && line[1] == '\0')
			free_str_and_null(line);
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
			if (create_linked_list(input, fd, line) == 1)
				init_free_all_and_exit(input);
			break ;
		}
	}
	free_str_and_null(line);
}

// NULL case: return free and exit list that return NULL
t_input	*init_list(char **argv)
{
	t_input	*input;
	char	*line;
	int		fd;

	input = malloc(sizeof(t_input));
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
	{
		init_print_error("Error map opening\n");
		return (NULL);
	}
	input_in_list(input, fd, line);
	put_map_int_tab(input);
	print_list(input->map);
	print_tab(input->tab_map);
	printf ("NO: %s\n", input->no);
	printf ("SO: %s\n", input->so);
	printf ("WE: %s\n", input->we);
	printf ("EA: %s\n", input->ea);
	printf ("F: %s\n", input->f);
	printf ("C: %s\n", input->c);
	close(fd);
	return (input);
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	init_list(argv);
	return (0);
}
