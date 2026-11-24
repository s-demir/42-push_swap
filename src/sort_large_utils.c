/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedemir <sedemir@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:00:00 by sedemir          #+#    #+#             */
/*   Updated: 2026/11/24 19:00:00 by sedemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_in_b(t_stack *b, int val_a)
{
	t_stack	*curr;
	int		best_val;
	int		pos;
	int		best_pos;

	best_val = INT_MIN;
	best_pos = -1;
	pos = 0;
	curr = b;
	while (curr)
	{
		if (curr->val < val_a && (best_pos == -1 || curr->val > best_val))
		{
			best_val = curr->val;
			best_pos = pos;
		}
		pos++;
		curr = curr->next;
	}
	if (best_pos == -1)
		return (find_pos_val(b, stack_max(b)));
	return (best_pos);
}

static void	set_single_cost(t_stack *curr, int pos_a, int sz_a, int sz_b)
{
	curr->above_mid_a = (pos_a <= sz_a / 2);
	if (curr->above_mid_a)
		curr->cost_a = pos_a;
	else
		curr->cost_a = sz_a - pos_a;
	curr->above_mid_b = (curr->target_pos <= sz_b / 2);
	if (curr->above_mid_b)
		curr->cost_b = curr->target_pos;
	else
		curr->cost_b = sz_b - curr->target_pos;
}

void	calculate_costs_a_to_b(t_stack *a, t_stack *b)
{
	t_stack	*curr;
	int		sz_a;
	int		sz_b;
	int		pos_a;

	sz_a = stack_size(a);
	sz_b = stack_size(b);
	curr = a;
	pos_a = 0;
	while (curr)
	{
		curr->target_pos = find_target_in_b(b, curr->val);
		set_single_cost(curr, pos_a, sz_a, sz_b);
		pos_a++;
		curr = curr->next;
	}
}

static int	node_total_cost(t_stack *node)
{
	if (node->above_mid_a == node->above_mid_b)
	{
		if (node->cost_a > node->cost_b)
			return (node->cost_a);
		return (node->cost_b);
	}
	return (node->cost_a + node->cost_b);
}

t_stack	*find_cheapest_node(t_stack *a)
{
	t_stack	*curr;
	t_stack	*best;
	int		cost;
	int		min_cost;

	best = a;
	min_cost = INT_MAX;
	curr = a;
	while (curr)
	{
		cost = node_total_cost(curr);
		if (cost < min_cost)
		{
			min_cost = cost;
			best = curr;
		}
		curr = curr->next;
	}
	return (best);
}
