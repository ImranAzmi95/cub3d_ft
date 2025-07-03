/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:16:43 by iazmi             #+#    #+#             */
/*   Updated: 2024/06/18 16:43:25 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FD 1

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putuint(unsigned int number, int *byte_count);
void	ft_puthex(unsigned long hex_num, int *byte_count, int lowercase);
int		ft_count_digit(int d);

int		fspec_str(va_list args);
int		fspec_uint(va_list args);
int		fspec_hex(va_list args, int lowercase);
int		fspec_p(va_list args);
int		fspec_d(va_list args);

int		fspec_char(va_list args);
int		file_spec_handler(va_list args, int file_spec);
int		ft_printf(const char *format, ...);

#endif