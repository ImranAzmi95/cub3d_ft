/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:18:43 by iazmi             #+#    #+#             */
/*   Updated: 2023/11/10 20:58:53 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Parameters:
Returns: dest point

Copies over n number of src to dest
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		count;
	char		*d;
	const char	*s;

	s = (const char *)src;
	d = (char *)dest;
	if (!dest && !src)
		return (NULL);
	count = 0;
	while (count < n)
	{
		*(d + count) = *(s + count);
		count++;
	}
	return (d);
}
