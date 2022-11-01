/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 04:43:22 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/31 21:06:01 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include "../includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_stack_info
{
	int	value;
	int	x;
	int	y;
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
	int		sx;
	int		sy;
}	t_winfo;

typedef struct s_fdf
{
	t_sb	points;
	int		x_nbr;
	int		y_nbr;
	t_winfo	w_i;
}	t_fdf;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

int		main(int argc, char **argv);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_error(char *str);

/* ops */
void	ft_unshift(t_sb *stack, t_si info);
void	ft_push(t_sb *stack, t_si info);
t_si	ft_pop(t_sb *stack);
t_si	ft_shift(t_sb *stack);

/* init */
t_si	set_info(int x, int y, int value);
void	init_sb(t_sb *sb);
void	init_fdf(t_fdf *fdf);
void	init_win_info(t_winfo *w_i);

/* parser */
void	parser_process(t_fdf *fdf, char *line, int line_nbr);
void	parser(char *file, t_fdf *fdf);
void	retrieve_line(t_fdf *fdf, char *line, int fd);

/* io */
void	ft_display_stack(t_st *head);
#endif
