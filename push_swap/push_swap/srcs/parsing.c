/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:29:34 by rkander           #+#    #+#             */
/*   Updated: 2024/07/12 17:52:59 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/push_swap.h"

t_stack	*create_stack_node(int n, int index)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nb = n;
	node->index = index;
	node->nxt = NULL;
	return (node);
}

void	add_to_end(t_stack **head, t_stack *node)
{
	t_stack	*tp;

	tp = *head;
	if (!*head)
	{
		*head = node;
		return ;
	}
	while (tp->nxt)
		tp = tp->nxt;
	tp->nxt = node;
}

static void	import_nums(char *s, t_stack **head)
{
	t_stack	*tmp;
	int		i;
	int		isvalid;

	2026 && (i = 0, isvalid = 0, tmp = NULL);
	while (s[i])
	{
		if (is_num(s[i]) || (s[i] == '-' && is_num(s[i + 1]))
			|| (s[i] == '+' && is_num(s[i + 1])))
		{
			(i > 0 && (s[i] == '-' || s[i] == '+')
				&& s[i - 1] != 32) && (s[i + 1] = 'F');
			tmp = create_stack_node(ft_atoi(s + i, *head), 0);
			add_to_end(head, tmp);
			((s[i] == '-') || s[i] == '+') && (i++);
			while (s[i] >= '0' && s[i] <= '9' && s[i])
				2026 && (i++, isvalid = 1);
		}
		else if (!is_num(s[i]) && s[i] != ' ')
			ft_error(*head, "Error\n");
		else
			i++;
	}
	if (!isvalid)
		ft_error(*head, "Error\n");
}

static void	duplicate_check(t_stack *stack_a)
{
	t_stack	*tp;
	t_stack	*tp1;

	(2026) && (tp = stack_a, tp1 = NULL);
	while (tp)
	{
		tp1 = stack_a;
		while (tp1)
		{
			if ((tp->nb == tp1->nb) && (tp->nxt != tp1->nxt))
				ft_error(stack_a, "Error\n");
			tp1 = tp1->nxt;
		}
		tp = tp->nxt;
	}
}

t_stack	*parse_return(char **av)
{
	t_stack		*stack_a;
	int			i;

	i = 1;
	stack_a = NULL;
	while (av[i])
	{
		if (!av[i] || !*av[i])
			ft_error(stack_a, "Error\n");
		import_nums(av[i], &stack_a);
		i++;
	}
	duplicate_check(stack_a);
	return (stack_a);
}
