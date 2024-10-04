/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:29:51 by rkander           #+#    #+#             */
/*   Updated: 2024/07/12 14:50:47 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/push_swap.h"

void	sort_3(t_stack **stack_a)
{
	if ((*stack_a)->nb > (*stack_a)->nxt->nb
		&& (*stack_a)->nb < (*stack_a)->nxt->nxt->nb)
		sa(stack_a);
	else if ((*stack_a)->nb > (*stack_a)->nxt->nb
		&& (*stack_a)->nxt->nb > (*stack_a)->nxt->nxt->nb)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->nb > (*stack_a)->nxt->nb
		&& (*stack_a)->nb > (*stack_a)->nxt->nxt->nb)
		ra(stack_a);
	else if ((*stack_a)->nb < (*stack_a)->nxt->nb
		&& (*stack_a)->nb < (*stack_a)->nxt->nxt->nb
		&& (*stack_a)->nxt->nb > (*stack_a)->nxt->nxt->nb)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->nb < (*stack_a)->nxt->nb
		&& (*stack_a)->nb > (*stack_a)->nxt->nxt->nb)
		rra(stack_a);
}

void	position(t_stack **stack)
{
	t_stack		*tmp;
	int			i;

	i = 0;
	tmp = *stack;
	if (!tmp || !stack)
		return ;
	while (tmp)
	{
		tmp->pos = i++;
		tmp = tmp->nxt;
	}
}

void	tri_a_bulle(int *arr, int n)
{
	int		i;
	int		tmp;

	i = 0;
	if (n == 1)
		return ;
	while (i < n - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
		}
		i++;
	}
	tri_a_bulle(arr, n - 1);
}

void	indexing_2(t_stack **stack_a, int *tab, int n)
{
	t_stack		*tmp;
	int			i;

	tmp = *stack_a;
	i = 0;
	while (tmp)
	{
		i = 0;
		while (i < n)
		{
			if (tab[i] == tmp->nb)
				tmp->index = i;
			i++;
		}
		tmp = tmp->nxt;
	}
	free(tab);
	tab = NULL;
}

void	indexing_1(t_stack **stack_a)
{
	t_stack		*tmp;
	int			*tab;
	int			i;
	int			s;

	if (!stack_a || !*stack_a)
		return ;
	i = 0;
	tmp = *stack_a;
	s = get_stack_size(*stack_a);
	tab = malloc(s * sizeof(int));
	if (!tab)
		ft_error(*stack_a, "Error while mallocing.\n");
	while (i < s && tmp)
	{
		tab[i] = tmp->nb;
		i++;
		tmp = tmp->nxt;
	}
	tmp = *stack_a;
	tri_a_bulle(tab, s);
	indexing_2(stack_a, tab, s);
}
