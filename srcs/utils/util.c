/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 07:20:09 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/02 17:11:54 by rkanmado         ###   ########.fr       */
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

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	abs(int a)
{
	if (a < 0)
		return (a * -1);
	else
		return (a);
}

// char	*int_to_hex(int color)
// {
// 	int		n;
// 	char	*res;

// 	n = 1;
// 	while (color / 16 > 0)
// 		n++;
// 	res = malloc((n + 1) * sizeof(int));
// 	if (res == NULL)
// 		return (NULL);
// 	while (color > 0)
// 	{
// 		if (n % 16 > 9)
// 			res[n--] = n % 16 + 'A' - 10;
// 		else
// 			res[n--] = n % 16 + '0';
// 		color /= 16;
// 	}
// 	return (res);
// }
