/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 07:20:09 by rkanmado          #+#    #+#             */
/*   Updated: 2022/11/03 15:10:09 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	hex_to_int(char *hex)
{
	int		decimal;
	size_t	len;
	char	first;
	int		i;
	char	*hex_code;

	hex_code = "0123456789ABCDEF";
	len = ft_strlen(hex);
	decimal = 0;
	i = 0;
	while (hex[i] != '\0')
	{
		if (ft_isalpha(hex[i]))
			hex[i] = ft_toupper(hex[i]);
		i++;
	}
	if (len > 0)
	{
		first = *hex;
		hex++;
		decimal = index_of(hex_code, first) * pow(16, len - 1) \
			+ hex_to_int(hex);
	}
	return (decimal);
}

int	index_of(char *s, char c)
{
	int		counter;
	int		len;

	counter = 0;
	len = ft_strlen(s);
	while (counter <= len)
	{
		if (s[counter] == c)
			return (counter);
		counter++;
	}
	return (-1);
}
