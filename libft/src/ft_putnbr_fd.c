/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:52:26 by iazmi             #+#    #+#             */
/*   Updated: 2023/11/01 13:08:15 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Outputs the integer ’n’ to the given file
descriptor.
n: The integer to output.
fd: The file descriptor on which to write.
*/
void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		is_neg;
	long	n_long;
	char	temp[11];

	i = 0;
	is_neg = 0;
	n_long = (long)n;
	if (n_long == 0)
		write(fd, "0", 1);
	if (n_long < 0)
	{
		is_neg = 1;
		n_long = -n_long;
	}
	while (n_long)
	{
		temp[i++] = (n_long % 10) + '0';
		n_long /= 10;
	}
	if (is_neg)
		temp[i++] = '-';
	while (i--)
		write(fd, &temp[i], 1);
}
