/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 04:35:42 by rkanmado          #+#    #+#             */
/*   Updated: 2022/11/02 09:39:04 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			counter;
	unsigned char	character;

	p = (unsigned char *)s;
	character = (unsigned char)c;
	counter = 0;
	if (*p == character && n != 0)
		return (p);
	while (counter < n)
	{
		if (*p == character)
			return (p);
		p++;
		counter++;
	}
	return (NULL);
}
