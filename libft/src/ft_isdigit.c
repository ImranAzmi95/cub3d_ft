/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:17:40 by iazmi             #+#    #+#             */
/*   Updated: 2023/10/24 17:46:30 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Args - string

Returns 1 if every character in the string is numeric
*/

int	ft_isdigit(int character)
{
	if (character < '0' || character > '9')
		return (0);
	return (1);
}
