/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:52:23 by iazmi             #+#    #+#             */
/*   Updated: 2024/11/10 19:02:22 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Args
- const char *str
- int c

Return
- char *str
last instance of matched character

Similar strchr but instead of first instance, it returns the last
*/
char	*ft_strrchr(char *str, int c)
{
	char	*ptr;
	size_t	i;

	i = ft_strlen(str);
	while (1)
	{
		ptr = &str[i];
		if (str[i] == (unsigned char)c)
			return (ptr);
		if (i == 0)
			return (0);
		i--;
	}
	return (0);
}
