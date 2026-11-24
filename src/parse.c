/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedemir <sedemir@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:00:00 by sedemir          #+#    #+#             */
/*   Updated: 2026/11/24 19:00:00 by sedemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(const char *s)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicate(t_stack *stack, int val)
{
	while (stack)
	{
		if (stack->val == val)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static void	parse_one(t_stack **a, const char *s, char **split)
{
	long	n;
	t_stack	*node;
	t_stack	*last;

	if (!is_valid_number(s))
		error_exit(a, NULL, split);
	n = ft_atol(s);
	if (n > INT_MAX || n < INT_MIN)
		error_exit(a, NULL, split);
	if (has_duplicate(*a, (int)n))
		error_exit(a, NULL, split);
	node = new_node((int)n);
	if (!node)
		error_exit(a, NULL, split);
	if (!*a)
		*a = node;
	else
	{
		last = stack_last(*a);
		last->next = node;
	}
}

static void	append_arg(t_stack **a, char *arg)
{
	char	**split;
	int		i;

	split = ft_split(arg, ' ');
	if (!split || !split[0])
		error_exit(a, NULL, split);
	i = 0;
	while (split[i])
	{
		parse_one(a, split[i], split);
		i++;
	}
	free_split(split);
}

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		append_arg(&a, argv[i]);
		i++;
	}
	return (a);
}
