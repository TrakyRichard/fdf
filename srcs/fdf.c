/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:20:33 by rkanmado          #+#    #+#             */
/*   Updated: 2022/11/03 14:52:47 by rkanmado         ###   ########.fr       */
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
	return (0);
}
