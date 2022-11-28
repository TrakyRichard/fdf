/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:34:24 by rkanmado          #+#    #+#             */
/*   Updated: 2022/11/28 13:42:19 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	set_color(t_fdf *f, t_coords *c)
{
	int	color;

	color = f->elts[c->y0][c->x0].hex;
	if (color != -1)
		c->color = color;
	// else if ((c->z0 || c->z1) && (c->z0 != c->z1))
	// 	c->is_slope = 0;
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

	x = b->x;
	y = b->y;
	while ((b->x < c->x1) || (b->y < c->y1))
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
	// b->x = x;
	// b->y = y;
	// while (b->y < c->y1 && (axis == 'y' || axis == 'a'))
	// {
	// 	put_pixel(f, b, c);
	// 	b->y++;
	// 	// if (b->p < 0)
	// 	// 	b->p = b->p + (2 * b->dx);
	// 	// else
	// 	// {
	// 	// 	b->p = b->p + (2 * b->dx) - (2 * b->dy);
	// 	// 	b->x++;
	// 	// }
	// }
}
