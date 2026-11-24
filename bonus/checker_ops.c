/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedemir <sedemir@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:00:00 by sedemir          #+#    #+#             */
/*   Updated: 2026/11/24 19:00:00 by sedemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	cmp_str(const char *a, const char *b)
{
	while (*a && *b && *a == *b)
	{
		a++;
		b++;
	}
	return (*a == *b);
}

static int	apply_swap(t_stack **a, t_stack **b, char *line)
{
	if (cmp_str(line, "sa\n"))
		op_sa(a, 0);
	else if (cmp_str(line, "sb\n"))
		op_sb(b, 0);
	else if (cmp_str(line, "ss\n"))
		op_ss(a, b, 0);
	else
		return (0);
	return (1);
}

static int	apply_push(t_stack **a, t_stack **b, char *line)
{
	if (cmp_str(line, "pa\n"))
		op_pa(a, b, 0);
	else if (cmp_str(line, "pb\n"))
		op_pb(a, b, 0);
	else
		return (0);
	return (1);
}

static int	apply_rotate(t_stack **a, t_stack **b, char *line)
{
	if (cmp_str(line, "ra\n"))
		op_ra(a, 0);
	else if (cmp_str(line, "rb\n"))
		op_rb(b, 0);
	else if (cmp_str(line, "rr\n"))
		op_rr(a, b, 0);
	else if (cmp_str(line, "rra\n"))
		op_rra(a, 0);
	else if (cmp_str(line, "rrb\n"))
		op_rrb(b, 0);
	else if (cmp_str(line, "rrr\n"))
		op_rrr(a, b, 0);
	else
		return (0);
	return (1);
}

int	apply_command(t_stack **a, t_stack **b, char *line)
{
	if (apply_swap(a, b, line))
		return (1);
	if (apply_push(a, b, line))
		return (1);
	if (apply_rotate(a, b, line))
		return (1);
	return (0);
}
