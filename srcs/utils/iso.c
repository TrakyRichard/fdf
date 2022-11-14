/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:56:30 by rkanmado          #+#    #+#             */
/*   Updated: 2022/11/14 22:39:42 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h";

void	init_coord(t_coords *c)
{
	c->x0 = 0;
	c->x1 = 0;
	c->y0 = 0;
	c->y1 = 0;
	return ;
}

t_coords	isometric(t_fdf *f, t_coords *c)
{
	t_coords	res;

	init_coord(c);
}
