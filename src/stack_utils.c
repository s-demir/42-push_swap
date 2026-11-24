/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedemir <sedemir@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:00:00 by sedemir          #+#    #+#             */
/*   Updated: 2026/11/24 19:00:00 by sedemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int val)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->val = val;
	node->cost_a = 0;
	node->cost_b = 0;
	node->above_mid_a = 0;
	node->above_mid_b = 0;
	node->target_pos = 0;
	node->next = NULL;
	return (node);
}

void	stack_push_front(t_stack **stack, t_stack *node)
{
	if (!node)
		return ;
	node->next = *stack;
	*stack = node;
}

t_stack	*stack_pop_front(t_stack **stack)
{
	t_stack	*node;

	if (!stack || !*stack)
		return (NULL);
	node = *stack;
	*stack = (*stack)->next;
	node->next = NULL;
	return (node);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	stack_is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->val > stack->next->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}
