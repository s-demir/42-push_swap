/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedemir <sedemir@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:00:00 by sedemir          #+#    #+#             */
/*   Updated: 2026/11/24 19:00:00 by sedemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	op_sa(t_stack **a, int print)
{
	swap_top(a);
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	op_sb(t_stack **b, int print)
{
	swap_top(b);
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	op_ss(t_stack **a, t_stack **b, int print)
{
	swap_top(a);
	swap_top(b);
	if (print)
		ft_putstr_fd("ss\n", 1);
}

void	op_pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*node;

	if (!b || !*b)
		return ;
	node = stack_pop_front(b);
	stack_push_front(a, node);
	if (print)
		ft_putstr_fd("pa\n", 1);
}
