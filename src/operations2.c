/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedemir <sedemir@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:00:00 by sedemir          #+#    #+#             */
/*   Updated: 2026/11/24 19:00:00 by sedemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pb(t_stack **a, t_stack **b, int print)
{
	t_stack	*node;

	if (!a || !*a)
		return ;
	node = stack_pop_front(a);
	stack_push_front(b, node);
	if (print)
		ft_putstr_fd("pb\n", 1);
}

static void	rotate(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = stack_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
}

void	op_ra(t_stack **a, int print)
{
	rotate(a);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	op_rb(t_stack **b, int print)
{
	rotate(b);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	op_rr(t_stack **a, t_stack **b, int print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_putstr_fd("rr\n", 1);
}
