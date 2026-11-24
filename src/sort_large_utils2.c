/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedemir <sedemir@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:00:00 by sedemir          #+#    #+#             */
/*   Updated: 2026/11/24 19:00:00 by sedemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both_same_dir(t_stack **a, t_stack **b, t_stack *node)
{
	while (node->cost_a > 0 && node->cost_b > 0)
	{
		if (node->above_mid_a)
			op_rr(a, b, 1);
		else
			op_rrr(a, b, 1);
		node->cost_a--;
		node->cost_b--;
	}
}

void	move_cheapest_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*node;

	node = find_cheapest_node(*a);
	if (node->above_mid_a == node->above_mid_b)
		rotate_both_same_dir(a, b, node);
	while (node->cost_a > 0)
	{
		if (node->above_mid_a)
			op_ra(a, 1);
		else
			op_rra(a, 1);
		node->cost_a--;
	}
	while (node->cost_b > 0)
	{
		if (node->above_mid_b)
			op_rb(b, 1);
		else
			op_rrb(b, 1);
		node->cost_b--;
	}
	op_pb(a, b, 1);
}

static int	find_target_in_a(t_stack *a, int val_b)
{
	t_stack	*curr;
	int		best_val;
	int		pos;
	int		best_pos;

	best_val = INT_MAX;
	best_pos = -1;
	pos = 0;
	curr = a;
	while (curr)
	{
		if (curr->val > val_b && (best_pos == -1 || curr->val < best_val))
		{
			best_val = curr->val;
			best_pos = pos;
		}
		pos++;
		curr = curr->next;
	}
	if (best_pos == -1)
		return (find_pos_val(a, stack_min(a)));
	return (best_pos);
}

void	push_all_b_to_a(t_stack **a, t_stack **b)
{
	int	tgt;
	int	sz;
	int	cost;
	int	above_mid;

	while (*b)
	{
		tgt = find_target_in_a(*a, (*b)->val);
		sz = stack_size(*a);
		above_mid = (tgt <= sz / 2);
		if (above_mid)
			cost = tgt;
		else
			cost = sz - tgt;
		while (cost-- > 0)
		{
			if (above_mid)
				op_ra(a, 1);
			else
				op_rra(a, 1);
		}
		op_pa(a, b, 1);
	}
}

void	final_rotate_a(t_stack **a)
{
	int	min_pos;
	int	sz;
	int	cost;
	int	above_mid;

	sz = stack_size(*a);
	min_pos = find_pos_val(*a, stack_min(*a));
	above_mid = (min_pos <= sz / 2);
	if (above_mid)
		cost = min_pos;
	else
		cost = sz - min_pos;
	while (cost-- > 0)
	{
		if (above_mid)
			op_ra(a, 1);
		else
			op_rra(a, 1);
	}
}
