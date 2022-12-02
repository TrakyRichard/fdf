/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:34:24 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/02 18:16:50 by rkanmado         ###   ########.fr       */
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
	b->dx = c->x1 - c->x0;
	b->dy = c->y1 - c->y0;
	b->ax.max = f_max(f_abs(b->dy), f_abs(b->dx));
	b->ax.xinc = b->dx / b->ax.max;
	b->ax.yinc = b->dy / b->ax.max;
	while ((int)(b->x - c->x1) || (int)(b->y - c->y1))
	{
		put_pixel(f, b, c);
		b->x += b->ax.xinc;
		b->y += b->ax.yinc;
		if (b->x > f->wi.win_x || b->y > f->wi.win_y)
			break ;
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
