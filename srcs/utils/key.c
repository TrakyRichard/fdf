/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:36:04 by rkanmado          #+#    #+#             */
/*   Updated: 2022/11/10 05:46:47 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	is_valid_key(int key)
{
	return (key == 49 || key == 50 || key == 51 || key == 52 \
			|| key == 53 || key == 54 || key == 55 || key == 56 \
			|| key == 57 || key == 48 \
			|| key == 37 || key == 38 || key == 39 || key == 40 \
			|| key == 91 || key == 92);
}

void	manage_trans(int key, t_winfo *wi)
{
	if (key == 49)
		wi->shift_x -= 50;
	if (key == 50)
		wi->shift_x += 50;
	if (key == 51)
		wi->shift_y -= 50;
	if (key == 52)
		wi->shift_y += 50;
	return ;
}

void	manage_rot(int key, t_winfo *wi)
{
	if (key == 37)
		wi->rot_x -= 0.1;
	else if (key == 39)
		wi->rot_x += 0.1;
	else if (key == 38)
		wi->rot_y += 0.1;
	else if (key == 40)
		wi->rot_y -= 0.1;
	else if (key == 91)
		wi->rot_z -= 0.1;
	else if (key == 92)
		wi->rot_z += 0.1;
	return ;
}

void	manage_mut(int key, t_winfo *wi)
{
	if (key == 53)
		wi->z_multi += 0.2;
	if (key == 54)
		wi->z_multi -= 0.2;
	if (key == 55)
		wi->zoom += 5;
	if (key == 56)
	{
		if (wi->zoom > 0)
			wi->zoom -= 5;
	}
	if (key == 57)
		wi->is_blur = !wi->is_blur;
	if (key == 48)
		wi->is_iso = !wi->is_iso;
	return ;
}

int	key_handler(int key, t_fdf *fdf)
{
	if (is_valid_key(key))
	{
		if (key >= 49 && key <= 52)
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
