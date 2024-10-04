/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:44:28 by rkander           #+#    #+#             */
/*   Updated: 2024/01/11 17:13:15 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_address(unsigned long long add, int *length)
{
	char	*hexad;

	hexad = "0123456789abcdef";
	if (add < 16)
	{
		ft_putchar(hexad[add], length);
	}
	else
	{
		ft_print_address((add / 16), length);
		ft_print_address((add % 16), length);
	}
}
