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

// Utils

void	print_list(t_list *list);
void	print_tab(char **tab);

#endif
