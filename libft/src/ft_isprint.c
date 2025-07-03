/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 00:28:21 by iazmi             #+#    #+#             */
/*   Updated: 2023/10/25 18:45:20 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Checks if value exists within printable ascii range 32 to 126
*/
int	ft_isprint(int c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}
