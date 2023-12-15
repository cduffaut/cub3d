/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:06:29 by csil              #+#    #+#             */
/*   Updated: 2023/12/15 10:53:14 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "gnl/get_next_line.h"
# include "utils/utils.h"

typedef struct s_list
{
	char	*str;
	s_list	*next;
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
	char	*tab_map;
}				t_input;

#endif
