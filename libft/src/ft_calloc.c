/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:41:16 by iazmi             #+#    #+#             */
/*   Updated: 2023/10/25 18:27:31 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
calloc initializes memory with zeros

Args
- size_t num
- size_t bytes

Return
- void *
*/
void	*ft_calloc(size_t elem, size_t size)
{
	void	*big;
	size_t	total_mem;

	if ((size != 0 && elem > UINT_MAX / size) || (elem != 0 && size > UINT_MAX
			/ elem))
		return (0);
	total_mem = elem * size;
	big = malloc(total_mem);
	if (!big)
		return (0);
	ft_bzero(big, elem * size);
	return (big);
}
