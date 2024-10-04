/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:29:38 by rkander           #+#    #+#             */
/*   Updated: 2024/07/12 15:22:48 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/push_swap.h"

int	find_maximum(t_stack **lst, int *pos)
{
	t_stack		*tmp;
	int			max;

	if (!lst || !*lst)
		return (0);
	max = (*lst)->nb;
	tmp = *lst;
	while (tmp)
	{
		if (tmp->nb >= max)
		{
			max = tmp->nb;
			*pos = tmp->pos;
		}
		tmp = tmp->nxt;
	}
	return (max);
}

void	norm_sort_1(t_stack **stack_b, int *max, int *ps)
{
	rrb(stack_b);
	position(stack_b);
	*max = find_maximum(stack_b, ps);
}

void	sorting_stacking(t_stack **stack_a, t_stack **stack_b)
{
	int		max;
	int		ps;
	int		med_position;

	position(stack_b);
	max = find_maximum(stack_b, &ps);
	med_position = get_stack_size(*stack_b) / 2;
	while (get_stack_size(*stack_b))
	{
		if (ps >= med_position)
			norm_sort_1(stack_b, &max, &ps);
		else
		{
			rb(stack_b);
			position(stack_b);
			max = find_maximum(stack_b, &ps);
		}
		if ((*stack_b)->nb == max)
		{
			pa(stack_a, stack_b);
			position(stack_b);
			max = find_maximum(stack_b, &ps);
			med_position = get_stack_size(*stack_b) / 2;
		}
	}
}

void	tri_et_transfert(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		magic_number;

	i = 0;
	(get_stack_size(*stack_a) <= 100) && (magic_number = 15);
	(get_stack_size(*stack_a) > 100) && (magic_number = 33);
	indexing_1(stack_a);
	while (get_stack_size(*stack_a))
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + magic_number)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}
