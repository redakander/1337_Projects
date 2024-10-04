/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:29:19 by rkander           #+#    #+#             */
/*   Updated: 2024/07/12 12:21:14 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/push_swap.h"

void	sa(t_stack **stack_a)
{
	int		tmp;

	if ((*stack_a) && (*stack_a)->nxt)
	{
		tmp = (*stack_a)->nb;
		(*stack_a)->nb = (*stack_a)->nxt->nb;
		(*stack_a)->nxt->nb = tmp;
		write_to_fd("sa\n", STDOUT_FILENO);
	}
}

void	ra(t_stack **stack_a)
{
	t_stack	*tmp;

	if (*stack_a)
	{
		tmp = (*stack_a);
		while (tmp->nxt)
			tmp = tmp->nxt;
		tmp->nxt = create_stack_node((*stack_a)->nb, (*stack_a)->index);
		tmp = (*stack_a);
		(*stack_a) = (*stack_a)->nxt;
		free(tmp);
		write_to_fd("ra\n", STDOUT_FILENO);
	}
}

void	rra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		tp;

	if (get_stack_size(*stack_a) > 2)
	{
		tmp = (*stack_a);
		while (tmp->nxt->nxt)
			tmp = tmp->nxt;
		tmp2 = tmp->nxt;
		tmp->nxt = NULL;
		tmp2->nxt = (*stack_a);
		(*stack_a) = tmp2;
		write_to_fd("rra\n", STDOUT_FILENO);
	}
	else if (get_stack_size(*stack_a) == 2)
	{
		tp = (*stack_a)->nb;
		(*stack_a)->nb = (*stack_a)->nxt->nb;
		(*stack_a)->nxt->nb = tp;
		write_to_fd("rra\n", STDOUT_FILENO);
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*stack_b)
	{
		tmp2 = (*stack_b);
		tmp = (*stack_a);
		(*stack_b) = (*stack_b)->nxt;
		tmp2->nxt = (*stack_a);
		(*stack_a) = tmp2;
		write_to_fd("pa\n", STDOUT_FILENO);
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*stack_a)
	{
		tmp2 = (*stack_a);
		tmp = (*stack_b);
		(*stack_a) = (*stack_a)->nxt;
		tmp2->nxt = (*stack_b);
		(*stack_b) = tmp2;
		write_to_fd("pb\n", STDOUT_FILENO);
	}
}
