/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 23:06:55 by iazmi             #+#    #+#             */
/*   Updated: 2024/11/12 19:22:18 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
copies up to size src to dst
returns length of result
*/
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	size_t	count;

	count = 0;
	if (size == 0)
	{
		while (src[count] != '\0')
			count++;
		return (count);
	}
	while (count < size - 1 && src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	while (src[count] != '\0')
		count++;
	return (count);
}
