/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:43:18 by rkander           #+#    #+#             */
/*   Updated: 2024/01/11 20:35:18 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printexa(unsigned int n, int *length, char *base)
{
	if (n < 16)
	{
		ft_putchar(base[n], length);
	}
	else
	{
		ft_printexa((n / 16), length, base);
		ft_printexa((n % 16), length, base);
	}
}
