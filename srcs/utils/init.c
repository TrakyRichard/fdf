/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 06:17:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/31 16:40:52 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_si	set_info(int x, int y, int value)
{
	t_si	i;

	i.value = value;
	i.x = x;
	i.y = y;
	return (i);
}

void	init_fdf(t_fdf *fdf)
{
	init_sb(&fdf->points);
	init_win_info(&fdf->w_i);
	return ;
}

void	init_win_info(t_winfo *w_i)
{
	w_i->sx = 1900;
	w_i->sy = 1080;
	w_i->mlx_ptr = mlx_init();
	w_i->win_ptr = mlx_new_window(w_i->mlx_ptr, w_i->sx, w_i->sy, "FDF");
	return ;
}

/* initialize stack bundle */
void	init_sb(t_sb *sb)
{
	sb->head = NULL;
	sb->tail = NULL;
	sb->size = 0;
	return ;
}
