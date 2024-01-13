/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 09:38:55 by pudry             #+#    #+#             */
/*   Updated: 2023/12/29 09:38:55 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <math.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1880
# define HEIGHT 1300
# define MAP_SIZE 10
# define PLAYER_SIZE 3
# define DEPLACEMENT 0.2
# define RENDER_DIST 50.0
# define LOOK_ANGLE 66
# define WALL_SIZE 1200
# define RESOLUTION 1
# define ANGLE 30
# define PI 3.141592653589793
# define MOUSE_SENSIBILITY 0.3
# define DOOR "./img/door5.xpm"
# define MSE_LOCK 0

//# define DEBUG printf("%s, %d\n", __FILE__, __LINE__);

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}				t_list;

typedef struct s_pixput
{
	void	*img;
	char	*addr;
	int		bit_pp;
	int		line_len;
	int		endian;
	int		width;
	int		heigth;
	char	*path;
}	t_pixput;

typedef struct s_wall
{
	t_pixput	*text;
	int			img_xstrt;
	int			iystrt;
	int			ixstrt;
	double		iyend;
	int			ixend;
	double		iscale;
	double		texpos;
	double		iy;
}	t_wall;

typedef struct s_input
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	void		*mlx;
	t_pixput	t_no;
	t_pixput	t_so;
	t_pixput	t_ea;
	t_pixput	t_we;
	t_pixput	door;
	char		*f;
	char		*c;
	t_list		*map;
	char		**tab_map;
	int			f_r;
	int			f_g;
	int			f_b;
	int			c_r;
	int			c_g;
	int			c_b;
	int			color_ceiling;
	int			color_floor;
}			t_input;

typedef struct s_ray
{
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	wallx;
	int		texx;
	int		texy;
	double	prpwalldist;
	double	deltadistx;
	double	deltadisty;
	double	angle;
	int		stepx;
	int		stepy;
	int		side;
	int		wall_height;
}	t_ray;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	double		xpos;
	double		ypos;
	double		look;
	double		lok;
	double		x;
	double		y;
	int			mousex;
	char		**map;
	int			ix;
	int			iy;
	t_pixput	no;
	t_pixput	so;
	t_pixput	we;
	t_pixput	ea;
	t_pixput	door;
	int			f;
	int			c;
	t_pixput	img;
	t_ray		raystruct;
	char		make_moov;
	int			dstep;
	int			dvalue;
	char		cdvalue;
	int			dchanged;
	int			drevers;
}	t_data;

enum	e_img
{
	NO,
	SO,
	WE,
	EA
};

unsigned int	get_color_pixel(t_pixput *img, int x, int y);

// utils mlx
void			ft_put_square(t_data *data, int x, int y, int icolor);
void			ft_make_moov(t_data *data, double x, double y);
void			ft_new_img(t_data *data);
void			put_pixel_img(t_data *data, int x, int y, int icolor);

// utils calcul
double			ft_calc_depl_x(double iangl);
double			ft_calc_depl_y(double iangl);
double			ft_calcul_ang(double iangl, double iofset);
int				ft_check_colision(t_data *data, double x, double y, int iangl);
double			deg_to_rad(double deg);

// key_hook
int				key_hook(int keycode, t_data *data);
int				ft_press_cross(void);
int				mouse_move(int x, int y, t_data *data);

// Init part
int				input_not_full(t_input *input);
int				check_extension(char *str);
void			print_list(t_list *list);
void			print_tab(char **tab);
void			add_end(t_list **list, char *line, t_input *input);
t_list			*ptr_last_node(t_list *list);
int				len_tab(t_list *list);
char			*ft_strdup_free(char *str);
int				only_path(t_input *input);
int				only_nbr(t_input *input);
int				init_print_error(char *str);
int				init_free_all_and_exit(t_input *input, int exit);
int				free_str_and_null(char **str);
char			*ft_strndup(const char *str, int isize);
int				not_enough_commas(char *str);
int				other_than_digit(char *str);
int				init_separe_colours(t_input *input);
t_data			*t_input_to_t_data(t_input *input);
void			free_tab(char **tab);
char			*relay_only(char *str, int i);
void			clean_list(t_list *list);
void			destroy_img_texture(t_input *input);
void			init_to_null(t_input *input, char *str);
int				all_texture_in_data(t_input *input);
t_data			*init_list(char **argv);
int				ft_check_map(char **map);

// RGB part
int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);
void			get_trgb(t_input *input);
int				create_trgb(int t, int r, int g, int b);

// Err
void			ft_error_quit(t_data *data, int icode);

// Utils
char			*ft_strdup_endl(char *str);
void			ft_put_array(char **a);

// raycasting
void			ft_raycasting(t_data *data);
void			put_wall(t_data *data, t_ray *ray, int iframe);
void			ft_background(t_data *data);

// Free and exit
void			clean_list(t_list *list);
void			free_and_exit_final(t_data *data);

// Refresh texture
int				put_texture_in_data(t_data *data);

// door
void			ft_change_door(t_data *data);
void			ft_check_door(t_data *data);

// Put player
int				ft_check_player(char c);

// New
int				check_multiple_input_2(int fd, int counter);
int				check_multiple_input(char *str);

#endif
