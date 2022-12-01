/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:07:42 by rkanmado          #+#    #+#             */
/*   Updated: 2022/11/30 23:04:40 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

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
