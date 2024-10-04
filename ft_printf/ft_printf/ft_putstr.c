/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:38:31 by rkander           #+#    #+#             */
/*   Updated: 2024/01/11 17:12:05 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *length)
{
	if (s == NULL)
	{
		ft_putstr("(null)", length);
		return ;
	}
	while (*s)
	{
		ft_putchar(*s, length);
		s++;
	}
}
