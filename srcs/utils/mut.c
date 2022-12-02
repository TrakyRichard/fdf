/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:46:11 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/02 17:53:42 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	zoom(t_coords *c, t_fdf *f)
{
	c->x0 *= f->wi.zoom;
	c->x1 *= f->wi.zoom;
	c->y0 *= f->wi.zoom;
	c->y1 *= f->wi.zoom;
	return ;
}

void	translation(t_coords *c, t_fdf *f)
{
	c->x0 += f->wi.shift_x;
	c->x1 += f->wi.shift_x;
	c->y0 += f->wi.shift_y;
	c->y1 += f->wi.shift_y;
	return ;
}

void	rotate(t_coords *c, t_fdf *f)
{
	rot_x(c, f);
	rot_y(c, f);
	rot_z(c, f);
	return ;
}

void	isometric(t_coords *c)
{
	c->x0 = (c->x0 - c->y0) * cos(0.8);
	c->y0 = (c->x0 + c->y0) * sin(0.8) - c->z0;
	c->x1 = (c->x1 - c->y1) * cos(0.8);
	c->y1 = (c->x1 + c->y1) * sin(0.8) - c->z1;
	return ;
}

/* 	c->x0 = round_no((c->x0 - c->y0) * cos(0.8));
	c->y0 = round_no((c->x0 + c->y0) * sin(0.8) - c->z0);
	c->x1 = round_no((c->x1 - c->y1) * cos(0.8));
	c->y1 = round_no((c->x1 + c->y1) * sin(0.8) - c->z1); */
