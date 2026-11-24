/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedemir <sedemir@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:00:00 by sedemir          #+#    #+#             */
/*   Updated: 2026/11/24 19:00:00 by sedemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos_val(t_stack *stack, int val)
{
	int	pos;

	pos = 0;
	while (stack && stack->val != val)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

void	sort_large(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size > 3)
		op_pb(a, b, 1);
	if (size > 4)
		op_pb(a, b, 1);
	while (stack_size(*a) > 3)
	{
		calculate_costs_a_to_b(*a, *b);
		move_cheapest_a_to_b(a, b);
	}
	sort_three(a);
	push_all_b_to_a(a, b);
	final_rotate_a(a);
}
