/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:29:29 by rkander           #+#    #+#             */
/*   Updated: 2024/07/12 15:23:08 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/push_swap.h"

int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

void	ft_free(t_stack *stack)
{
	t_stack	*tmp;

	tmp = NULL;
	if (stack)
	{
		tmp = stack;
		while (tmp)
		{
			tmp = stack->nxt;
			free(stack);
			stack = tmp;
		}
	}
}

void	is_sorted(t_stack **stack_a)
{
	t_stack		*tmp;

	tmp = *stack_a;
	while (tmp && tmp->nxt)
	{
		if (tmp->nb > tmp->nxt->nb)
			return ;
		tmp = tmp->nxt;
	}
	ft_free(*stack_a);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (EXIT_SUCCESS);
	stack_a = parse_return(av);
	is_sorted(&stack_a);
	if (get_stack_size(stack_a) == 3)
		sort_3(&stack_a);
	else if (get_stack_size(stack_a) == 2)
		sort_2(&stack_a);
	else if (get_stack_size(stack_a) == 4)
		sort_4(&stack_a, &stack_b);
	else if (get_stack_size(stack_a) == 5)
		sort_5(&stack_a, &stack_b);
	else if (get_stack_size(stack_a) > 5)
	{
		tri_et_transfert(&stack_a, &stack_b);
		sorting_stacking(&stack_a, &stack_b);
	}
	ft_free(stack_a);
}
