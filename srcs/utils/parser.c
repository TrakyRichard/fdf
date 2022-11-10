/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 03:13:22 by rkanmado          #+#    #+#             */
/*   Updated: 2022/11/10 03:25:47 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../includes/get_next_line.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}

void	retrieve_line(t_fdf *fdf, char	*line, int fd)
{
	int			row;

	row = 0;
	if (ft_strlen(line) > 0)
		fdf->c = ft_word_count(line, ' ') + 1;
	while (line)
	{
		parser_process(fdf, line, row);
		free(line);
		line = get_next_line(fd);
		if (line != NULL)
			row++;
	}
	fdf->r = row + 1;
	return ;
}

void	parser_process(t_fdf *fdf, char *line, int row)
{
	char	**split;
	int		counter;
	int		value;
	int		hex;
	char	**val_and_hex;

	split = ft_split(line, ' ');
	counter = 0;
	value = 0;
	while (split[counter] != NULL)
	{
		val_and_hex = ft_split(split[counter], ',');
		value = ft_atoi(val_and_hex[0]);
		if (val_and_hex[1] != NULL)
			hex = hex_to_int(val_and_hex[1] + 2);
		else
			hex = -1;
		ft_unshift(&fdf->points, set_info(row, counter, value, hex));
		counter++;
		ft_free_dbl_point(val_and_hex);
	}
	ft_free_dbl_point(split);
	return ;
}

void	parser(char *file, t_fdf *fdf)
{
	int				fd;
	char			*line;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("error while opening the file");
	line = get_next_line(fd);
	retrieve_line(fdf, line, fd);
	fill_st_in_elts(fdf);
	// free_st(&fdf->points.head, &fdf->points.tail, &fdf->points.size);
	return ;
}
