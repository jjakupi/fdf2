/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjakupi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:02:51 by jjakupi           #+#    #+#             */
/*   Updated: 2024/10/25 13:07:09 by jjakupi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	ft_hexptr(unsigned long int number)
{
	int	count;
	int	hexnumber;

	count = 0;
	if (number >= 16)
		count += ft_hexptr(number / 16);
	hexnumber = number % 16;
	if (hexnumber < 10)
		count += printf_char(hexnumber + '0');
	else
		count += printf_char(hexnumber - 10 + 'a');
	return (count);
}

int	printf_ptr(void *ptr)
{
	int				count;
	unsigned long	num;

	num = (unsigned long)ptr;
	count = 0;
	count += printf_char('0');
	count += printf_char('x');
	if (!num)
		count += printf_char('0');
	else
		count += ft_hexptr(num);
	return (count);
}
