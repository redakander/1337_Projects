/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reste.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:29:42 by rkander           #+#    #+#             */
/*   Updated: 2024/07/12 11:30:35 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/push_swap.h"

static int	find_minimum(t_stack **lst, int *pos)
{
	t_stack		*tmp;
	int			min;

	if (!lst || !*lst)
		return (0);
	min = (*lst)->nb;
	tmp = *lst;
	while (tmp)
	{
		if (tmp->nb <= min)
		{
			min = tmp->nb;
			*pos = tmp->pos;
		}
		tmp = tmp->nxt;
	}
	return (min);
}

void	norm_sort(t_stack **stack_a, int *min, int *ps)
{
	rra(stack_a);
	position(stack_a);
	*min = find_minimum(stack_a, ps);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	int		med;
	int		ps;

	position(stack_a);
	min = find_minimum(stack_a, &ps);
	med = get_stack_size(*stack_a) / 2;
	while (get_stack_size(*stack_a))
	{
		if (ps >= med)
			norm_sort(stack_a, &min, &ps);
		else
		{
			ra(stack_a);
			position(stack_a);
			min = find_minimum(stack_a, &ps);
		}
		if ((*stack_a)->nb == min)
		{
			pb(stack_a, stack_b);
			sort_3(stack_a);
			pa(stack_a, stack_b);
			break ;
		}
	}
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	int		med;
	int		ps;

	position(stack_a);
	min = find_minimum(stack_a, &ps);
	med = get_stack_size(*stack_a) / 2;
	while (get_stack_size(*stack_a))
	{
		if (ps >= med)
			norm_sort(stack_a, &min, &ps);
		else
		{
			ra(stack_a);
			position(stack_a);
			min = find_minimum(stack_a, &ps);
		}
		if ((*stack_a)->nb == min)
		{
			pb(stack_a, stack_b);
			sort_4(stack_a, stack_b);
			pa(stack_a, stack_b);
			break ;
		}
	}
}

void	sort_2(t_stack **stack_a)
{
	if ((*stack_a)->nb > (*stack_a)->nxt->nb)
		sa(stack_a);
}
