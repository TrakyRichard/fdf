/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:10:30 by rkanmado          #+#    #+#             */
/*   Updated: 2022/11/03 15:21:01 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	display_menu(t_fdf *d)
{
	int		color;
	void	*win_ptr;
	void	*mlx_ptr;

	win_ptr = d->wi.win_ptr;
	mlx_ptr = d->wi.mlx_ptr;
	color = 0xFFFFF;
	mlx_string_put(mlx_ptr, win_ptr, 10, 10, color, "move -> arrow");
	mlx_string_put(mlx_ptr, win_ptr, 10, 40, color, "2D/3D -> i");
	mlx_string_put(mlx_ptr, win_ptr, 10, 70, color, "Exit -> esc");
	mlx_string_put(mlx_ptr, win_ptr, 10, 100, color, "full screen -> f");
	return ;
}
