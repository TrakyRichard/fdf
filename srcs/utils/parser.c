/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 03:13:22 by rkanmado          #+#    #+#             */
/*   Updated: 2022/11/01 07:46:56 by rkanmado         ###   ########.fr       */
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
	int			line_nbr;

	line_nbr = 1;
	if (ft_strlen(line) > 0)
		fdf->x_nbr = ft_word_count(line, ' ');
	while (line)
	{
		parser_process(fdf, line, line_nbr);
		free(line);
		line = get_next_line(fd);
		if (line != NULL)
			line_nbr++;
	}
	fdf->y_nbr = line_nbr;
	return ;
}

void	parser_process(t_fdf *fdf, char *line, int line_nbr)
{
	char	**split;
	int		counter;
	int		value;

	split = ft_split(line, ' ');
	counter = 0;
	value = 0;
	while (split[counter] != NULL)
	{
		value = ft_atoi(split[counter]);
		ft_unshift(&fdf->points, set_info(counter, line_nbr, value));
		counter++;
	}
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
	return ;
}
