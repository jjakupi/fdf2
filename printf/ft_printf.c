/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjakupi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:29:06 by jjakupi           #+#    #+#             */
/*   Updated: 2024/10/25 12:36:32 by jjakupi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len = printf_char(va_arg(args, int));
	else if (format == 's')
		print_len = printf_string(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		print_len = printf_num(va_arg(args, int));
	else if (format == 'u')
		print_len = printf_numu(va_arg(args, unsigned int));
	else if (format == 'x')
		print_len = printf_hexdec_l(va_arg(args, unsigned long int));
	else if (format == 'X')
		print_len = printf_hexdec_u(va_arg(args, unsigned long int));
	else if (format == 'p')
		print_len = printf_ptr(va_arg(args, void *));
	else if (format == '%')
		print_len = printf_perce();
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		print_len;

	print_len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			print_len += ft_formats(args, str[i]);
		}
		else
		{
			print_len += printf_char(str[i]);
		}
		i++;
	}
	va_end (args);
	return (print_len);
}
