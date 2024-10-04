/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:43:45 by rkander           #+#    #+#             */
/*   Updated: 2024/01/11 17:10:08 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print(int *length, va_list args, char c)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), length);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), length);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), length);
	else if (c == 'x')
		ft_printexa(va_arg(args, unsigned int), length, "0123456789abcdef");
	else if (c == 'X')
		ft_printexa(va_arg(args, unsigned int), length, "0123456789ABCDEF");
	else if (c == '%')
		ft_putchar(c, length);
	else if (c == 'p')
	{
		ft_putstr("0x", length);
		ft_print_address(va_arg(args, unsigned long long), length);
	}
	else if (c == 'u')
		ft_print_u(va_arg(args, unsigned int), length);
	else if (c != '\0')
		ft_putchar(c, length);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		length;
	char	c;

	va_start(args, s);
	length = 0;
	if (write(1, NULL, 0) < 0)
		return (-1);
	while (*s)
	{
		while (*s != '%' && *s)
		{
			ft_putchar(*(s++), &length);
		}
		if (*s == '%' && *s)
		{
			s++;
			c = *s;
			if (*s)
				s++;
			ft_print(&length, args, c);
		}
	}
	va_end(args);
	return (length);
}
