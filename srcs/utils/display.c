/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:10:30 by rkanmado          #+#    #+#             */
/*   Updated: 2022/11/23 23:11:21 by rkanmado         ###   ########.fr       */
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
	mlx_string_put(mlx_ptr, win_ptr, 10, 130, color, "zoom -> +/-");
	mlx_string_put(mlx_ptr, win_ptr, 10, 160, color, "rotate x -> 1,2");
	mlx_string_put(mlx_ptr, win_ptr, 10, 190, color, "rotate y -> 3,4");
	mlx_string_put(mlx_ptr, win_ptr, 10, 220, color, "rotate z -> 5,6");
	mlx_string_put(mlx_ptr, win_ptr, 10, 250, color, "z multi -> z,x");
	mlx_string_put(mlx_ptr, win_ptr, 10, 280, color, "is iso -> i");
	mlx_string_put(mlx_ptr, win_ptr, 10, 310, color, "is blur -> b");
	return ;
}
