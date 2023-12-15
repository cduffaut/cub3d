/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:06:29 by csil              #+#    #+#             */
/*   Updated: 2023/12/15 11:25:01 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "utils/utils.h"
# include "gnl/get_next_line.h"

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}				t_list;

typedef struct s_input
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	t_list	*map;
	char	**tab_map;
}				t_input;

// Init

void	print_list(t_list *list);
void	print_tab(char **tab);
void	add_end(t_list **list, char *line, t_input *input);
t_list	*ptr_last_node(t_list *list);
int		len_tab(t_list *list);
char	*ft_strdup_free(const char *str);
int		only_path(t_input *input);
int		only_nbr(t_input *input);
int		init_print_error(char *str);
void	init_free_all_and_exit(t_input *input);
void	free_str_and_null(char *str);

// a supp
size_t	ft_strlen(const char *s);

#endif
