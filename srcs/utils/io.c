/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 06:43:20 by rkanmado          #+#    #+#             */
/*   Updated: 2022/11/01 06:46:14 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
/* Display the informations into stack a */
void	ft_display_stack(t_st *head)
{
	t_st	*tmp;

	tmp = head;
	while (tmp != NULL && tmp->next != NULL)
	{
		ft_putchar_fd(tmp->i.value, 1);
		tmp = tmp->next;
	}
	if (tmp != NULL)
		ft_putchar_fd(tmp->i.value, 1);
	return ;
}
