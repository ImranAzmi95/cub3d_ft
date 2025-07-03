/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:06:41 by iazmi             #+#    #+#             */
/*   Updated: 2023/11/10 21:14:16 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Finds first instance of substring within larger string up to n characters
Args
- char *hay
- char *needle
- size_t n
Return
- * to first occurance of substring
- or NULL
*/
char	*ft_strnstr(const char *hay, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	if ((!hay || !needle) && !n)
		return (0);
	if (!needle[0])
		return ((char *)hay);
	i = 0;
	while (hay[i] && i < n)
	{
		j = 0;
		while (hay[i + j] && needle[j] && i + j < n && hay[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char *)(hay + i));
		i++;
	}
	return (NULL);
}
