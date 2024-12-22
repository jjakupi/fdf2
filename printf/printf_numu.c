/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_numu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjakupi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:42:53 by jjakupi           #+#    #+#             */
/*   Updated: 2024/10/25 12:38:16 by jjakupi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	printf_numu(unsigned int number)

{
	int	count;

	count = 0;
	if (number >= 10)
	{
		count += printf_numu(number / 10);
	}
	count += printf_char(number % 10 + '0');
	return (count);
}
