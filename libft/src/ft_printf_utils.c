/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:06:47 by iazmi             #+#    #+#             */
/*   Updated: 2024/06/04 17:28:06 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuint(unsigned int number, int *byte_count)
{
	if (number >= 10)
	{
		ft_putuint(number / 10, byte_count);
		ft_putuint(number % 10, byte_count);
	}
	else if (number < 10)
	{
		ft_putchar_fd(number + '0', FD);
		(*byte_count)++;
	}
}

void	ft_puthex(unsigned long hex_num, int *byte_count, int lowercase)
{
	int	gap;

	gap = ('a' - 'A') * lowercase;
	if (hex_num >= 16)
	{
		ft_puthex(hex_num / 16, byte_count, lowercase);
		ft_puthex(hex_num % 16, byte_count, lowercase);
	}
	else if (hex_num < 10)
	{
		ft_putchar_fd(hex_num + '0', FD);
		(*byte_count)++;
	}
	else
	{
		ft_putchar_fd((hex_num - 10) + ('A') + gap, FD);
		(*byte_count)++;
	}
}

int	ft_count_digit(int d)
{
	int	byte_count;

	byte_count = 0;
	if (d == 0)
		byte_count++;
	while (d)
	{
		if (d == -2147483648)
		{
			byte_count = 11;
			break ;
		}
		if (d < 0)
		{
			d = -d;
			byte_count++;
		}
		d /= 10;
		byte_count++;
	}
	return (byte_count);
}
