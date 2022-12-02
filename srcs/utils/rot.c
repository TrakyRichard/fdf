/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:58:40 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/01 07:29:43 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	rot_x(t_coords *c, t_fdf *f)
{
	t_coords	temp;

	temp = *c;
	c->y0 = (cos(f->wi.rot_x) * temp.y0) - (sin(f->wi.rot_x) * temp.z0);
	c->y1 = (cos(f->wi.rot_x) * temp.y1) - (sin(f->wi.rot_x) * temp.z1);
	c->z0 = (sin(f->wi.rot_x) * temp.y0) + (cos(f->wi.rot_x) * temp.z0);
	c->z1 = (sin(f->wi.rot_x) * temp.y1) + (cos(f->wi.rot_x) * temp.z1);
	return ;
}

void	rot_y(t_coords *c, t_fdf *f)
{
	t_coords	temp;

	temp = *c;
	c->x0 = (cos(f->wi.rot_y) * temp.x0) + (sin(f->wi.rot_y) * temp.z0);
	c->x1 = (cos(f->wi.rot_y) * temp.x1) + (sin(f->wi.rot_y) * temp.z1);
	c->z0 = -(sin(f->wi.rot_y) * temp.x0) + (cos(f->wi.rot_y) * temp.z0);
	c->z1 = -(sin(f->wi.rot_y) * temp.x1) + (cos(f->wi.rot_y) * temp.z1);
	return ;
}

void	rot_z(t_coords *c, t_fdf *f)
{
	t_coords	temp;

	temp = *c;
	c->x0 = (cos(f->wi.rot_z) * temp.x0) - (sin(f->wi.rot_z) * temp.y0);
	c->x1 = (cos(f->wi.rot_z) * temp.x1) - (sin(f->wi.rot_z) * temp.y1);
	c->y0 = (sin(f->wi.rot_z) * temp.x0) + (cos(f->wi.rot_z) * temp.y0);
	c->y1 = (sin(f->wi.rot_z) * temp.x1) + (cos(f->wi.rot_z) * temp.y1);
	return ;
}
