/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:20:33 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/31 21:58:44 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	init_fdf(&fdf);
	if (argc != 2)
		ft_error("Usage: ./fdf [./test_maps/file]");
	parser(argv[1], &fdf);
	ft_display_stack(fdf.points.head);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
