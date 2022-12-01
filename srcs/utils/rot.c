/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:58:40 by rkanmado          #+#    #+#             */
/*   Updated: 2022/11/30 10:50:16 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	rot_x(t_coords *c, t_fdf *f)
{
	c->y0 = (cos(f->wi.rot_x) * c->y0) - (sin(f->wi.rot_x) * c->z0);
	c->y1 = (cos(f->wi.rot_x) * c->y1) - (sin(f->wi.rot_x) * c->z1);
	c->z0 = (sin(f->wi.rot_x) * c->y1) + (cos(f->wi.rot_x) * c->z0);
	c->z1 = (sin(f->wi.rot_x) * c->y1) + (cos(f->wi.rot_x) * c->z1);
	return ;
}

void	rot_y(t_coords *c, t_fdf *f)
{
	c->x0 = (cos(f->wi.rot_y) * c->x0) + (sin(f->wi.rot_y) * c->z0);
	c->x1 = (cos(f->wi.rot_y) * c->x1) + (sin(f->wi.rot_y) * c->z1);
	c->z0 = -(sin(f->wi.rot_y) * c->x0) + (cos(f->wi.rot_y) * c->z0);
	c->z1 = -(sin(f->wi.rot_y) * c->x1) + (cos(f->wi.rot_y) * c->z1);
	return ;
}

void	rot_z(t_coords *c, t_fdf *f)
{
	c->x0 = (cos(f->wi.rot_z) * c->x0) - (sin(f->wi.rot_z) * c->y0);
	c->x1 = (cos(f->wi.rot_z) * c->x1) - (sin(f->wi.rot_z) * c->y1);
	c->y0 = (sin(f->wi.rot_z) * c->x0) + (cos(f->wi.rot_z) * c->y0);
	c->y1 = (sin(f->wi.rot_z) * c->x1) + (cos(f->wi.rot_z) * c->y1);
	return ;
}
