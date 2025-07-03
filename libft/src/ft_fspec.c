/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fspec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:07:31 by iazmi             #+#    #+#             */
/*   Updated: 2024/06/04 17:20:11 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fspec_str(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	ft_putstr_fd(str, FD);
	return (ft_strlen(str));
}

int	fspec_uint(va_list args)
{
	unsigned int	ui;
	int				byte_count;

	byte_count = 0;
	ui = va_arg(args, unsigned int);
	ft_putuint(ui, &byte_count);
	return (byte_count);
}

/**
 * @param args
 * @param lowercase 1 if lowercase and 0 if not
 */
int	fspec_hex(va_list args, int lowercase)
{
	int				byte_count;

	byte_count = 0;
	ft_puthex(va_arg(args, unsigned int), &byte_count, lowercase);
	return (byte_count);
}

int	fspec_p(va_list args)
{
	unsigned long	p_address;
	int				byte_count;

	byte_count = 2;
	p_address = (unsigned long)va_arg(args, void *);
	ft_putstr_fd("0x", FD);
	ft_puthex(p_address, &byte_count, 1);
	return (byte_count);
}

int	fspec_d(va_list args)
{
	int	d;
	int	byte_count;

	byte_count = 0;
	d = va_arg(args, int);
	ft_putnbr_fd(d, FD);
	byte_count = ft_count_digit(d);
	return (byte_count);
}
