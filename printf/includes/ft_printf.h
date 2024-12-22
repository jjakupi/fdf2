/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjakupi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:35:42 by jjakupi           #+#    #+#             */
/*   Updated: 2024/12/19 14:43:19 by jjakupi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		printf_char(int c);
int		printf_string(char *str);
int		printf_hexdec_l(unsigned int num);
int		printf_hexdec_u(unsigned int num);
int		printf_perce(void);
int		printf_num(int num);
int		printf_numu(unsigned int num);
int		printf_ptr(void *ptr);

#endif
