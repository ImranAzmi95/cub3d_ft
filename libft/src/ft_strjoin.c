/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 00:04:55 by iazmi             #+#    #+#             */
/*   Updated: 2024/11/21 23:40:54 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_composer(char *ret, char const *s, size_t *j)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		ret[*j] = s[i];
		i++;
		(*j)++;
	}
}

/*
Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.
Args
- s1: The prefix string
- s2: The suffix string
Return
- s1 + s2
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	total_length;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	total_length = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc((total_length + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	j = 0;
	ft_composer(ret, s1, &j);
	ft_composer(ret, s2, &j);
	ret[j] = '\0';
	return (ret);
}
