/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:47:34 by rkander           #+#    #+#             */
/*   Updated: 2024/01/11 17:12:18 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *length)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar('-', length);
		nb = -n;
	}
	else
		nb = n;
	if (nb > 9)
	{
		ft_putnbr((nb / 10), length);
		nb %= 10;
	}
	ft_putchar((nb + '0'), length);
}
