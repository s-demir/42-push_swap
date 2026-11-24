/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedemir <sedemir@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:00:00 by sedemir          #+#    #+#             */
/*   Updated: 2026/11/24 19:00:00 by sedemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	stack_min(t_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->val;
	while (stack)
	{
		if (stack->val < min)
			min = stack->val;
		stack = stack->next;
	}
	return (min);
}

int	stack_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->val;
	while (stack)
	{
		if (stack->val > max)
			max = stack->val;
		stack = stack->next;
	}
	return (max);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	error_exit(t_stack **a, t_stack **b, char **split)
{
	free_stack(a);
	free_stack(b);
	free_split(split);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
