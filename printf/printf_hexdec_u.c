/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hexdec_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjakupi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:41:01 by jjakupi           #+#    #+#             */
/*   Updated: 2024/10/25 12:37:40 by jjakupi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	ft_len_hex(unsigned int num)
{
	int	len;

	if (num == 0)
		return (1);
	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_hex(unsigned int num)
{
	if (num >= 16)
	{
		ft_put_hex (num / 16);
		ft_put_hex (num % 16);
	}
	else
	{
		if (num <= 9)
			printf_char(num + '0');
		else
			printf_char((num - 10) + 'A');
	}
}

int	printf_hexdec_u(unsigned int num)
{
	int	len;

	len = ft_len_hex(num);
	if (num == 0)
		write(1, "0", 1);
	else
		ft_put_hex(num);
	return (len);
}
