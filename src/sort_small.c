/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedemir <sedemir@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:00:00 by sedemir          #+#    #+#             */
/*   Updated: 2026/11/24 19:00:00 by sedemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->val > (*a)->next->val)
		op_sa(a, 1);
}

void	sort_three(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->val;
	mid = (*a)->next->val;
	bot = (*a)->next->next->val;
	if (top > mid && top > bot && mid < bot)
		op_ra(a, 1);
	else if (top > mid && top > bot && mid > bot)
	{
		op_ra(a, 1);
		op_sa(a, 1);
	}
	else if (top < mid && mid > bot && top > bot)
		op_rra(a, 1);
	else if (top > mid && top < bot)
		op_sa(a, 1);
	else if (top < mid && mid > bot && top < bot)
	{
		op_sa(a, 1);
		op_ra(a, 1);
	}
}

static int	find_pos(t_stack *a, int val)
{
	int	pos;

	pos = 0;
	while (a && a->val != val)
	{
		pos++;
		a = a->next;
	}
	return (pos);
}

static void	rotate_to_top(t_stack **a, int val)
{
	int	pos;
	int	size;

	size = stack_size(*a);
	pos = find_pos(*a, val);
	if (pos <= size / 2)
	{
		while ((*a)->val != val)
			op_ra(a, 1);
	}
	else
	{
		while ((*a)->val != val)
			op_rra(a, 1);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	size;
	int	min;

	size = stack_size(*a);
	while (size > 3)
	{
		min = stack_min(*a);
		rotate_to_top(a, min);
		op_pb(a, b, 1);
		size--;
	}
	sort_three(a);
	while (*b)
		op_pa(a, b, 1);
}
