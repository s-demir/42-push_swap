/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedemir <sedemir@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:00:00 by sedemir          #+#    #+#             */
/*   Updated: 2026/11/24 19:00:00 by sedemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	run_checker(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!apply_command(a, b, line))
		{
			free(line);
			free_stack(a);
			free_stack(b);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	b = NULL;
	a = parse_args(argc, argv);
	if (!a)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	run_checker(&a, &b);
	if (stack_is_sorted(a) && !b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
