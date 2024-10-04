/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:42:44 by rkander           #+#    #+#             */
/*   Updated: 2024/01/11 17:14:18 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	ft_putchar(char c, int *length);
void	ft_putstr(char *s, int *length);
void	ft_putnbr(int n, int *length);
void	ft_printexa(unsigned int n, int *length, char *base);
void	ft_print_address(unsigned long long add, int *length);
void	ft_print_u(unsigned int n, int *length);

#endif