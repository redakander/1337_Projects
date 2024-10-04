/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:28:56 by rkander           #+#    #+#             */
/*   Updated: 2024/07/12 12:21:10 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/push_swap.h"

void	rb(t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_b)
	{
		tmp = (*stack_b);
		while (tmp->nxt)
			tmp = tmp->nxt;
		tmp->nxt = create_stack_node((*stack_b)->nb, (*stack_b)->index);
		tmp = (*stack_b);
		(*stack_b) = (*stack_b)->nxt;
		free(tmp);
		write_to_fd("rb\n", STDOUT_FILENO);
	}
}

void	rrb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		tp;

	if (get_stack_size(*stack_b) > 2)
	{
		tmp = (*stack_b);
		while (tmp->nxt->nxt)
			tmp = tmp->nxt;
		tmp2 = tmp->nxt;
		tmp->nxt = NULL;
		tmp2->nxt = (*stack_b);
		(*stack_b) = tmp2;
		write_to_fd("rrb\n", STDOUT_FILENO);
	}
	else if (get_stack_size(*stack_b) == 2)
	{
		tp = (*stack_b)->nb;
		(*stack_b)->nb = (*stack_b)->nxt->nb;
		(*stack_b)->nxt->nb = tp;
		write_to_fd("rrb\n", STDOUT_FILENO);
	}
}
