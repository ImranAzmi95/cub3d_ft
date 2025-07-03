/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 23:14:56 by iazmi             #+#    #+#             */
/*   Updated: 2023/10/24 17:39:57 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Takes a character and returns the result of isalpha or isdigit.
Would be a 1 if character is a digit or alphabet
*/
int	ft_isalnum(int character)
{
	return ((ft_isalpha(character) || ft_isdigit(character)));
}
