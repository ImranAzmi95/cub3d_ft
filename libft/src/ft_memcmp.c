/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:47:38 by iazmi             #+#    #+#             */
/*   Updated: 2023/10/25 18:38:23 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Compares the n bytes of 2 blocks of memory

Args
- const void *ptr1
- const void *ptr2
- size_t n

Return
returns the char diff or 0 if no diff
*/

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	c1 = (unsigned char *)ptr1;
	c2 = (unsigned char *)ptr2;
	i = 0;
	while (i < n)
	{
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
		i++;
	}
	return (0);
}
