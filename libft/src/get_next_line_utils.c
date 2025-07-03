/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:09:41 by iazmi             #+#    #+#             */
/*   Updated: 2024/06/04 17:26:27 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Singleton Buffer Initializer and Freer. Sets passed buffer to NULL on 1.
 * @param buffer the pointer to the pointer to the buffer
 * @param tofree option to run free check. 1 runs check, 0 initializes.
 *
 */
char	*buffer_util(char **buffer, int tofree)
{
	if (*buffer == NULL)
	{
		*buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (*buffer == NULL)
			return (NULL);
		(*buffer)[0] = '\0';
	}
	if (*buffer != NULL && tofree == 1)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (*buffer);
}

/**
 * Append strs and free's dest string. Returns '\0' string always.
 * @param dest
 * Old malloc'd string || Empty string
 * @param src
 * New string to append
 * @return
 * Pointer to new string.
 */
char	*str_append_safe(char *dest, char *src)
{
	char	*result;
	int		dest_len;
	int		src_len;

	if (!dest)
	{
		dest = (char *)malloc(1);
		if (dest == NULL)
			return (NULL);
		dest[0] = '\0';
	}
	dest_len = str_len(dest);
	src_len = str_len(src);
	result = (char *)malloc(1 * (dest_len + src_len + 1));
	if (result == NULL)
		return (NULL);
	str_cpy(result, dest);
	str_cat(result, src);
	if (dest != NULL)
		free(dest);
	return (result);
}

int	str_len(char *src)
{
	int	i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
		i++;
	return (i);
}

void	str_cpy(char *dest, char *src)
{
	int	i;

	if (!src)
		return ;
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	str_cat(char *dest, char *src)
{
	int	i;
	int	dest_len;

	if (!src || !dest)
		return ;
	i = 0;
	dest_len = str_len(dest);
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
}
