/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:02:50 by iazmi             #+#    #+#             */
/*   Updated: 2024/06/08 22:40:59 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Takes a void pointer and fills each position up to num with value.
the void pointer must be cast to a different type of pointer
Can buffer overflow
*/
void	*ft_memset(void *ptr, int value, size_t num)
{
	char	*point;
	size_t	count;

	point = (char *)ptr;
	count = 0;
	while (count < num)
	{
		*(point + count) = value;
		count++;
	}
	return (ptr);
}
