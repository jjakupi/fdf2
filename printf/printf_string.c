/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjakupi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:07:41 by jjakupi           #+#    #+#             */
/*   Updated: 2024/10/23 19:00:59 by jjakupi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	printf_string(char *str)
{
	unsigned int	char_counter;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd (str, 1);
	char_counter = ft_strlen(str);
	return (char_counter);
}
