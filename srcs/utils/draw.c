/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:07:42 by rkanmado          #+#    #+#             */
/*   Updated: 2022/11/04 22:12:36 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	draw(t_fdf *fdf)
{
	display_menu(fdf);
	return ;
}

void	bresenham(t_coords *c, t_fdf *f)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	p;

	dx = c->x1 - c->x0;
	dy = c->y1 - c->y0;
	p = 2 * dx - dy;
	while (x <= c->x1)
	{
		if (f->elts[c->x1][c->y1].z_val == 0)
			mlx_pixel_put(f->wi.mlx_ptr, f->wi.win_ptr, x, y, 0);
		else
			mlx_pixel_put(f->wi.mlx_ptr, f->wi.win_ptr, x, y, 0xFFFFF);
		x++;
		if (p < 0)
			p = p + 2 * dy;
		else
			p = p + 2 * dy - 2 * dx;
		y++;
	}
}
