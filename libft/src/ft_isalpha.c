/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 00:32:27 by iazmi             #+#    #+#             */
/*   Updated: 2023/10/25 18:41:28 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Args string
Takes a character and checks is a character
*/

int	ft_isalpha(int character)
{
	if ((character < 'A' || character > 'Z') && (character < 'a'
			|| character > 'z'))
		return (0);
	return (1);
}
