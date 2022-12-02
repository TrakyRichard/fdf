/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:34:24 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/01 11:18:25 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	set_color(t_fdf *f, t_coords *c)
{
	int	color;

	color = f->elts[(int)c->y0][(int)c->x0].hex;
	if (color != -1)
		c->color = color;
	else if (c->z0 > 0)
		c->color = 0xBF40BF;
	else
		c->color = 0xFFFFFF;
	return ;
}

void	hdle_normal_view(t_fdf *f, t_coords *c)
{
	zoom(c, f);
	translation(c, f);
	return ;
}

void	hdle_iso_view(t_fdf *f, t_coords *c)
{
	rotate(c, f);
	isometric(c);
	return ;
}

void	draw_axis(t_coords *c, t_fdf *f, t_b *b)
{
	int	x;
	int	y;
	int	slope;

	x = b->x;
	y = b->y;
	compute_slope(&slope, b);
	if (slope > 1)
		drawing_by_y(c, f, b);
	else if (slope < 1)
		drawing_by_x(c, f, b);
	else
	{
		while ((b->x <= c->x1) || (b->y <= c->y1))
		{
			put_pixel(f, b, c);
			b->y++;
			b->x++;
		}
	}
}

void	compute_slope(int *slope, t_b *b)
{
	if (b->dx == 0)
		*slope = 2;
	else if (b->dy == 0)
		*slope = 0;
	else
		*slope = b->dy / b->dx;
	return ;
}
