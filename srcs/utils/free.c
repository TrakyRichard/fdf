/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 06:18:23 by rkanmado          #+#    #+#             */
/*   Updated: 2022/11/02 09:11:42 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/* Function to free stack */
void	free_st(t_st **h, t_st **t, int *size)
{
	t_st	*tmp;

	if (*h == NULL)
		return ;
	tmp = *h;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		free(tmp->prev);
	}
	free(tmp);
	*h = NULL;
	*size = 0;
	*t = NULL;
	return ;
}


void	free_fdf(t_fdf *fdf)
{
	free(fdf->elts);
	free_st(&fdf->points.head, &fdf->points.tail, &fdf->points.size);
	return ;
}

void	ft_free_dbl_point(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return ;
}
