/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:28:24 by iazmi             #+#    #+#             */
/*   Updated: 2023/10/25 18:58:48 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Args
- const char *str
- int c

return
- char *
pointer to first instance of matched character

searches for the first occurrence of the character c (an unsigned char) 
in the string pointed to by the argument str
*/
char	*ft_strchr(char *str, int c)
{
	char	*ptr;

	ptr = str;
	while (*ptr)
	{
		if (*ptr == (unsigned char) c)
			return (ptr);
		ptr++;
	}
	return (0);
}
