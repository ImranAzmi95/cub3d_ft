/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:50:03 by iazmi             #+#    #+#             */
/*   Updated: 2024/09/01 19:25:13 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * • %c Prints a single character.
 * • %s Prints a string (as defined by the common C convention).
 * • %p The void * pointer argument has to be printed in hexadecimal format.
 * • %d Prints a decimal (base 10) number.
 * • %i Prints an integer in base 10.
 * • %u Prints an unsigned decimal (base 10) number.
 * • %x Prints a number in hexadecimal (base 16) lowercase format.
 * • %X Prints a number in hexadecimal (base 16) uppercase format.
 * • %% Prints a percent sign.
 */
int	file_spec_handler(va_list args, int file_spec)
{
	int	byte_count;

	byte_count = 0;
	if (file_spec == 'c')
		byte_count += fspec_char(args);
	else if (file_spec == 's')
		byte_count += fspec_str(args);
	else if (file_spec == 'p')
		byte_count += fspec_p(args);
	else if (file_spec == 'd')
		byte_count += fspec_d(args);
	else if (file_spec == 'i')
		byte_count += fspec_d(args);
	else if (file_spec == 'u')
		byte_count += fspec_uint(args);
	else if (file_spec == 'x')
		byte_count += fspec_hex(args, 1);
	else if (file_spec == 'X')
		byte_count += fspec_hex(args, 0);
	else if (file_spec == '%')
	{
		ft_putchar_fd('%', 1);
		byte_count += 1;
	}
	return (byte_count);
}

int	fspec_char(va_list args)
{
	ft_putchar_fd(va_arg(args, int), FD);
	return (1);
}

/**
 * • %c Prints a single character.
 * • %s Prints a string (as defined by the common C convention).
 * • %p The void * pointer argument has to be printed in hexadecimal format.
 * • %d Prints a decimal (base 10) number.
 * • %i Prints an integer in base 10.
 * • %u Prints an unsigned decimal (base 10) number.
 * • %x Prints a number in hexadecimal (base 16) lowercase format.
 * • %X Prints a number in hexadecimal (base 16) uppercase format.
 * • %% Prints a percent sign.
 */
int	ft_printf(const char *text, ...)
{
	va_list	args;
	int		i;
	int		byte_count;

	va_start(args, text);
	i = 0;
	byte_count = 0;
	while (text[i])
	{
		if (text[i] == '%')
		{
			i++;
			byte_count += file_spec_handler(args, text[i]);
		}
		else
		{
			ft_putchar_fd(text[i], 1);
			byte_count++;
		}
		i++;
	}
	va_end(args);
	return (byte_count);
}
