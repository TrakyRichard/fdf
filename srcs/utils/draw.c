/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:07:42 by rkanmado          #+#    #+#             */
/*   Updated: 2022/11/22 16:43:05 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	set_coord(t_st *st, t_coords *c)
{
	c->x0 = st->i.x;
	c->x1 = st->next->i.x;
	c->y0 = st->i.y;
	c->y1 = st->next->i.y;
	c->z0 = st->i.elt.z_val;
	c->z1 = st->next->i.elt.z_val;
	c->slope = st->i.elt.z_val - st->next->i.elt.z_val;
	return ;
}

void	draw(t_fdf *fdf)
{
	t_st		*st;
	t_coords	c;

	st = fdf->points.head;
	display_menu(fdf);
	while (st && st->next)
	{
		set_coord(st, &c);
		bresenham(&c, fdf);
		st = st->next;
	}
	return ;
}

void	init_bresenham(t_b *b, t_coords *c)
{
	b->x = c->x0;
	b->y = c->y0;
	b->dx = c->x1 - c->x0;
	b->dy = c->y1 - c->y0;
	b->p = (2 * b->dy) - b->dx;
	return ;
}

void	put_pixel(t_fdf *f, t_b	*b, t_coords *c)
{
	mlx_pixel_put(f->wi.mlx_ptr, f->wi.win_ptr, b->x, \
	b->y, c->color);
	return ;
}

void	bresenham(t_coords *c, t_fdf *f)
{
	t_b	b;

	set_color(f, c);
	if (f->wi.is_iso == 1)
		hdle_iso_view(f, c);
	hdle_normal_view(f, c);
	init_bresenham(&b, c);
	if (b.x == ((f->c - 1) * f->wi.zoom) + f->wi.shift_x)
		draw_y_axis(c, f, &b);
	else if (b.y == ((f->r - 1) * f->wi.zoom) + f->wi.shift_y)
		draw_x_axis(c, f, &b);
	else
	{
		draw_x_axis(c, f, &b);
		draw_y_axis(c, f, &b);
	}
	return ;
}
