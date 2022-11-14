/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:36:04 by rkanmado          #+#    #+#             */
/*   Updated: 2022/11/14 21:55:15 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	is_valid_key(int key)
{
	return (key == 123 || key == 124 || key == 125 || key == 126 \
			|| key == 18 || key == 19 || key == 20 || key == 21 \
			|| key == 22 || key == 23 \
			|| key == 26 || key == 28 || key == 25 || key == 29 \
			|| key == 27 || key == 24);
}

void	manage_trans(int key, t_winfo *wi)
{
	if (key == 123)
		wi->shift_x -= 50;
	if (key == 124)
		wi->shift_x += 50;
	if (key == 126)
		wi->shift_y -= 50;
	if (key == 125)
		wi->shift_y += 50;
	return ;
}

void	manage_rot(int key, t_winfo *wi)
{
	if (key == 18)
		wi->rot_x -= 0.1;
	else if (key == 19)
		wi->rot_x += 0.1;
	else if (key == 20)
		wi->rot_y += 0.1;
	else if (key == 21)
		wi->rot_y -= 0.1;
	else if (key == 23)
		wi->rot_z -= 0.1;
	else if (key == 22)
		wi->rot_z += 0.1;
	return ;
}

void	manage_mut(int key, t_winfo *wi)
{
	if (key == 26)
		wi->z_multi += 0.2;
	if (key == 28)
		wi->z_multi -= 0.2;
	if (key == 25)
		wi->zoom += 5;
	if (key == 29)
	{
		if (wi->zoom > 0)
			wi->zoom -= 5;
	}
	if (key == 27)
		wi->is_blur = !wi->is_blur;
	if (key == 24)
		wi->is_iso = !wi->is_iso;
	return ;
}

int	key_handler(int key, t_fdf *fdf)
{
	printf("the fdf is %d", key);
	if (is_valid_key(key))
	{
		if (key >= 123 && key <= 126)
			manage_trans(key, &fdf->wi);
		if ((key >= 53 && key <= 57) || key == 48)
			manage_mut(key, &fdf->wi);
		if ((key >= 37 && key <= 40) || (key >= 91 && key <= 92))
			manage_rot(key, &fdf->wi);
		if (key == 53)
		{
			mlx_destroy_window(fdf->wi.mlx_ptr, fdf->wi.win_ptr);
			free_fdf(fdf);
			exit(EXIT_SUCCESS);
		}
		mlx_clear_window(fdf->wi.mlx_ptr, fdf->wi.win_ptr);
		draw(fdf);
	}
	return (0);
}
