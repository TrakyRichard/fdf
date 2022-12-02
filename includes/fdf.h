/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 04:43:22 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/02 17:15:22 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include "../includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

typedef struct s_elements
{
	int	hex;
	int	z_val;
}	t_elt;

typedef struct s_coords
{
	double	x0;
	double	x1;
	double	y0;
	double	y1;
	double	z0;
	double	z1;
	int		slope;
	int		is_slope;
	int		color;
}	t_coords;

typedef struct s_inc_axis
{
	double	xinc;
	double	yinc;
	double	max;
}	t_ax;

typedef struct s_stack_info
{
	t_elt	elt;
	int		x;
	int		y;
}	t_si;

typedef struct s_stack
{
	t_si			i;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_st;

typedef struct s_stack_bundle
{
	t_st	*head;
	t_st	*tail;
	int		size;
}	t_sb;

typedef struct s_window_info
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		shift_x;
	int		shift_y;
	int		scale;
	int		win_x;
	int		win_y;
	float	z_multi;
	float	rot_x;
	float	rot_y;
	float	rot_z;
	int		zoom;
	int		is_iso;
	int		is_blur;
}	t_winfo;

typedef struct s_fdf
{
	t_sb	points;
	t_elt	**elts;
	int		r;
	int		c;
	t_winfo	wi;
}	t_fdf;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_bresenham
{
	int		x;
	int		y;
	t_ax	ax;
	int		z;
	int		dx;
	int		dy;
	int		p;
}	t_b;

typedef struct s_increment
{
	int	xs;
	int	ys;
	int	zs;
}	t_i;

int		main(int argc, char **argv);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_error(char *str);

/* ops */
void	ft_unshift(t_sb *stack, t_si info);
void	ft_push(t_sb *stack, t_si info);
t_si	ft_pop(t_sb *stack);
t_si	ft_shift(t_sb *stack);

/* init */
t_si	set_info(int x, int y, int value, int hex);
void	init_sb(t_sb *sb);
void	init_fdf(t_fdf *fdf);
void	init_win_info(t_winfo *wi);
void	fill_st_in_elts(t_fdf *fdf);

/* parser */
void	parser_process(t_fdf *fdf, char *line, int line_nbr);
void	parser(char *file, t_fdf *fdf);
void	retrieve_line(t_fdf *fdf, char *line, int fd);

/* io */
void	ft_display_stack(t_st *head);

/* free */
void	free_st(t_st **h, t_st **t, int *size);
void	free_fdf(t_fdf *fdf);
void	ft_free_dbl_point(char **str);

/* utils */
int		hex_to_int(char *hex);
int		index_of(char *s, char c);
int		max(int a, int b);

/* draw */
void	draw(t_fdf *fdf);
void	set_coord(t_st *st, t_coords *c, t_fdf *f);
int		set_coord_x(t_st *st, t_coords *c, t_fdf *f);
int		set_coord_y(t_st *st, t_coords *c, t_fdf *f);
void	put_pixel(t_fdf *f, t_b *b, t_coords *c);
void	bresenham(t_coords *c, t_fdf *f);

/* display */
void	display_menu(t_fdf *d);

/* key */
int		is_valid_key(int key);
void	manage_trans(int key, t_winfo *wi);
void	manage_rot(int key, t_winfo *wi);
void	manage_mut(int key, t_winfo *wi);
int		key_handler(int key, t_fdf *fdf);

/* close */
int		win_close(t_fdf *fdf);

/* isometric */
void	init_coord(t_coords *c);

/* draw utils */
void	set_color(t_fdf *f, t_coords *c);
void	hdle_normal_view(t_fdf *f, t_coords *c);
void	hdle_iso_view(t_fdf *f, t_coords *c);
void	draw_axis(t_coords *c, t_fdf *f, t_b *b);
void	init_bresenham(t_b *b, t_coords *c);

/* mutation utils */
void	zoom(t_coords *c, t_fdf *f);
void	translation(t_coords *c, t_fdf *f);
void	rotate(t_coords *c, t_fdf *f);
void	zoom(t_coords *c, t_fdf *f);
void	translation(t_coords *c, t_fdf *f);
int		round_no(float n);

/* Rotation function */
void	rot_x(t_coords *c, t_fdf *f);
void	rot_y(t_coords *c, t_fdf *f);
void	rot_z(t_coords *c, t_fdf *f);
void	isometric(t_coords *c);

#endif
