/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:30:23 by rkander           #+#    #+#             */
/*   Updated: 2024/07/12 15:22:55 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				nb;
	int				pos;
	int				index;
	struct s_stack	*nxt;
}			t_stack;

size_t		ft_strlen(char *s);
void		write_to_fd(char *s, int fd);
int			is_num(char c);
int			ft_atoi(char *s, t_stack *stack_a);
void		ft_error(t_stack *stack_a, char *message);
t_stack		*create_stack_node(int n, int index);
void		add_to_end(t_stack **head, t_stack *node);
t_stack		*parse_return(char **av);
void		is_sorted(t_stack **stack_a);
void		sa(t_stack **stack_a);
void		ra(t_stack **stack_a);
void		rra(t_stack **stack_a);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		rb(t_stack **stack_b);
void		rrb(t_stack **stack_b);
int			get_stack_size(t_stack *lst);
void		sort_3(t_stack **stack_a);
void		position(t_stack **stack_a);
void		indexing_1(t_stack **stack_a);
void		tri_et_transfert(t_stack **stack_a, t_stack **stack_b);
void		sorting_stacking(t_stack **stack_a, t_stack **stack_b);
int			find_maximum(t_stack **lst, int *pos);
void		sort_5(t_stack **stack_a, t_stack **stack_b);
void		sort_4(t_stack **stack_a, t_stack **stack_b);
void		sort_2(t_stack **stack_a);
#endif