/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 01:06:49 by iazmi             #+#    #+#             */
/*   Updated: 2024/09/22 21:58:37 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Compares s1 and s2 and returns the difference in s1 and s2, checks up to n
*/
int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int		count;
	const unsigned char	*u_s1;
	const unsigned char	*u_s2;

	u_s1 = (const unsigned char *)s1;
	u_s2 = (const unsigned char *)s2;
	count = 0;
	while (count < n && (u_s1[count] != '\0' || u_s2[count] != '\0'))
	{
		if (u_s1[count] != u_s2[count])
			return (u_s1[count] - u_s2[count]);
		else
			count++;
	}
	return (0);
}
