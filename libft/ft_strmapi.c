/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:52:25 by rkanmado          #+#    #+#             */
/*   Updated: 2022/11/02 09:39:04 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		counter;
	int		len;
	char	*result;

	if (s == NULL || f == NULL)
		return (NULL);
	counter = 0;
	len = ft_strlen(s);
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (s[counter] != '\0')
	{
		result[counter] = f(counter, s[counter]);
		counter++;
	}
	result[len] = '\0';
	return (result);
}
