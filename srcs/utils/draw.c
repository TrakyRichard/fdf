/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:07:42 by rkanmado          #+#    #+#             */
/*   Updated: 2022/11/10 05:43:20 by rkanmado         ###   ########.fr       */
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

void	bresenham(t_coords *c, t_fdf *f)
{
	t_b	b;

	b.dx = c->x1 - c->x0;
	b.dy = c->y1 - c->y0;
	b.p = 2 * b.dx - b.dy;
	while (b.x <= c->x1)
	{
		if (f->elts[c->x1][c->y1].z_val == 0)
			mlx_pixel_put(f->wi.mlx_ptr, f->wi.win_ptr, b.x, b.y, 0);
		else
			mlx_pixel_put(f->wi.mlx_ptr, f->wi.win_ptr, b.x, b.y, 0xFFFFF);
		b.x++;
		if (b.p < 0)
			b.p = b.p + 2 * b.dy;
		else
			b.p = b.p + 2 * b.dy - 2 * b.dx;
		b.y++;
	}
	return ;
}
