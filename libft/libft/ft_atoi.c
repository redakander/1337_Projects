/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:09:24 by rkander           #+#    #+#             */
/*   Updated: 2023/12/19 20:01:12 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_w_space(char c)
{
	return (('\t' <= c && c <= '\r') || c == ' ');
}

int	ft_atoi(const char *str)
{
	long	resu;
	long	t;
	int		sign;
	int		i;

	resu = 0;
	i = 0;
	while (is_w_space(str[i]))
		i++;
	sign = 1 - (str[i] == '-') * 2;
	i += (str[i] == '+' || str[i] == '-');
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		t = resu;
		resu = resu * 10 + str[i++] - '0';
		if (resu < t)
		{
			if (sign == -1)
				return (0);
			if (sign == 1)
				return (-1);
		}
	}
	return (sign * (int)resu);
}
