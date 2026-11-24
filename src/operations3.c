/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedemir <sedemir@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:00:00 by sedemir          #+#    #+#             */
/*   Updated: 2026/11/24 19:00:00 by sedemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = *stack;
	while (prev->next && prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	op_rra(t_stack **a, int print)
{
	rrotate(a);
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	op_rrb(t_stack **b, int print)
{
	rrotate(b);
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	op_rrr(t_stack **a, t_stack **b, int print)
{
	rrotate(a);
	rrotate(b);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}
