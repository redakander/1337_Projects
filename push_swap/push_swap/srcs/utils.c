/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:29:59 by rkander           #+#    #+#             */
/*   Updated: 2024/07/12 17:54:14 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/push_swap.h"

size_t	ft_strlen(char *s)
{
	if (!*s || !s)
		return (0);
	return (1 + ft_strlen(s + 1));
}

void	write_to_fd(char *s, int fd)
{
	if (!s || !*s)
		return (write_to_fd("(null)\n", STDERR_FILENO));
	write(fd, s, ft_strlen(s));
}

int	ft_atoi(char *s, t_stack *stack_a)
{
	int		i;
	long	res;
	long	tmp;
	long	sign;

	(2026) && (sign = 1, tmp = 0, res = 0, i = 0);
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9' && s[i])
	{
		tmp = res;
		res = (res * 10) + (s[i] - 48);
		if ((res / 10) != tmp)
			ft_error(stack_a, "Error\n");
		i++;
	}
	if (res * sign > INT32_MAX || res * sign < INT32_MIN)
		ft_error(stack_a, "Error\n");
	return ((int)res * sign);
}

void	ft_error(t_stack *stack_a, char *message)
{
	t_stack	*tmp;

	tmp = NULL;
	if (stack_a)
	{
		tmp = stack_a;
		while (tmp)
		{
			tmp = stack_a->nxt;
			free(stack_a);
			stack_a = tmp;
		}
	}
	write_to_fd(message, STDERR_FILENO);
	exit(EXIT_SUCCESS);
}

int	get_stack_size(t_stack *lst)
{
	int		size;
	t_stack	*reda;

	if (!lst)
		return (0);
	size = 0;
	reda = lst;
	while (reda != NULL)
	{
		size++;
		reda = reda->nxt;
	}
	return (size);
}
