/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 06:17:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/11/03 14:46:40 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_si	set_info(int x, int y, int value, int hex)
{
	t_si	i;

	i.elt.z_val = value;
	i.elt.hex = hex;
	i.x = x;
	i.y = y;
	return (i);
}

void	init_fdf(t_fdf *fdf)
{
	init_sb(&fdf->points);
	init_win_info(&fdf->wi);
	return ;
}

void	init_win_info(t_winfo *wi)
{
	wi->sx = 1900;
	wi->sy = 1080;
	wi->mlx_ptr = mlx_init();
	wi->win_ptr = mlx_new_window(wi->mlx_ptr, wi->sx, wi->sy, "FDF");
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

void	fill_st_in_elts(t_fdf *fdf)
{
	t_st	*tmp;
	t_elt	*ptr;
	t_elt	new;
	int		len;
	int		counter;

	tmp = fdf->points.head;
	ptr = NULL;
	counter = 0;
	len = sizeof(t_elt *) * fdf->r + sizeof(t_elt) * fdf->c * fdf->r;
	fdf->elts = (t_elt **) malloc(len);
	ptr = (t_elt *)(fdf->elts + fdf->r);
	while (counter <= fdf->r)
	{
		fdf->elts[counter] = (ptr + fdf->c * counter);
		counter++;
	}
	while (tmp != NULL)
	{
		new.hex = tmp->i.elt.hex;
		new.z_val = tmp->i.elt.z_val;
		fdf->elts[tmp->i.x][tmp->i.y] = new;
		tmp = tmp->next;
	}
	return ;
}
