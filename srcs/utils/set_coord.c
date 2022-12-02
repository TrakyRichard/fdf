/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:56:30 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/01 09:32:41 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	init_coord(t_coords *c)
{
	c->x0 = 0;
	c->x1 = 0;
	c->y0 = 0;
	c->y1 = 0;
	return ;
}

int	set_coord_x(t_st *st, t_coords *c, t_fdf *f)
{
	init_coord(c);
	c->x0 = st->i.x;
	c->y0 = st->i.y;
	c->x1 = st->i.x;
	c->y1 = st->i.y;
	if (c->x0 == f->c - 1)
		return (0);
	else
		c->x1 = st->i.x + 1;
	c->z0 = f->elts[st->i.y][st->i.x].z_val;
	c->z1 = f->elts[st->i.y][st->i.x + 1].z_val;
	c->slope = c->z0 - c->z1;
	return (1);
}

int	set_coord_y(t_st *st, t_coords *c, t_fdf *f)
{
	init_coord(c);
	c->x0 = st->i.x;
	c->x1 = st->i.x;
	c->y0 = st->i.y;
	c->y1 = st->i.y;
	if (c->y0 == f->r - 1)
		return (0);
	else
		c->y1 = st->i.y + 1;
	c->z0 = f->elts[st->i.y][st->i.x].z_val;
	c->z1 = f->elts[st->i.y + 1][st->i.x].z_val;
	c->slope = c->z0 - c->z1;
	return (1);
}

void	drawing_by_x(t_coords *c, t_fdf *f, t_b *b)
{
	while (b->x <= c->x1)
	{
		put_pixel(f, b, c);
		b->x++;
		if (b->p < 0)
			b->p = b->p + (2 * b->dy);
		else
		{
			b->p = b->p + (2 * b->dy) - (2 * b->dx);
			b->y++;
		}
	}
	return ;
}

void	drawing_by_y(t_coords *c, t_fdf *f, t_b *b)
{
	while (b->y <= c->y1)
	{
		put_pixel(f, b, c);
		b->y++;
		if (b->p < 0)
			b->p = b->p + (2 * b->dx);
		else
		{
			b->p = b->p + (2 * b->dx) - (2 * b->dy);
			b->x++;
		}
	}
	return ;
}
