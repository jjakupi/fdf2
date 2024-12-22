/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjakupi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:28:10 by jjakupi           #+#    #+#             */
/*   Updated: 2024/10/25 12:38:08 by jjakupi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	printf_num(int number)
{
	int	count;

	count = 0;
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
		count = 1;
	}
	if (number >= 10)
	{
		count += printf_num(number / 10);
	}
	count += printf_char((number % 10) + '0');
	return (count);
}
