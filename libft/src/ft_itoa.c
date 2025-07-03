/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:53:36 by iazmi             #+#    #+#             */
/*   Updated: 2025/03/21 17:20:06 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

/*
Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.

Args
n: int.

Return
The string representing the integer.
NULL if the allocation fails.
*/
char	*ft_itoa(int n)
{
	int		str_len;
	char	*str;
	int		start;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	str_len = numlen(n);
	str = (char *)malloc((str_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	start = 0;
	if (n < 0)
	{
		str[start++] = '-';
		n *= -1;
	}
	str[str_len] = '\0';
	while (--str_len >= start)
	{
		str[str_len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
