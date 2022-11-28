/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:07:42 by rkanmado          #+#    #+#             */
/*   Updated: 2022/11/28 13:42:56 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	set_coord_x(t_st *st, t_coords *c, t_fdf *f)
{
	init_coord(c);
	c->x0 = st->i.x;
	c->y0 = st->i.y;
	c->x1 = st->i.x;
	if (c->x0 == f->c - 1)
		return (0);
	else
		c->x1 = st->i.x + 1;
	c->z0 = f->elts[c->y0][c->x0].z_val;
	c->z1 = f->elts[c->y1][c->x1].z_val;
	c->slope = c->z0 - c->z1;
	return (1);
}

int set_coord_y(t_st *st, t_coords *c, t_fdf *f)
{
	init_coord(c);
	c->x0 = st->i.x;
	c->y0 = st->i.y;
	c->y1 = st->i.y;
	if (c->y0 == f->r - 1)
		return (0);
	else
		c->y1 = st->i.y + 1;
	c->z0 = f->elts[c->y0][c->x0].z_val;
	c->z1 = f->elts[c->y1][c->x1].z_val;
	c->slope = c->z0 - c->z1;
	return (1);
}

void	draw(t_fdf *fdf)
{
	t_st		*st;
	t_coords	c;

	st = fdf->points.head;
	display_menu(fdf);
	while (st && st->next)
	{
		if (set_coord_x(st, &c, fdf))
			bresenham(&c, fdf);
		if (set_coord_y(st, &c, fdf))
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
	draw_axis(c, f, &b);
	return ;
}
