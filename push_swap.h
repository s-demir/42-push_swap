/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedemir <sedemir@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:00:00 by sedemir          #+#    #+#             */
/*   Updated: 2026/11/24 19:00:00 by sedemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				val;
	int				cost_a;
	int				cost_b;
	int				above_mid_a;
	int				above_mid_b;
	int				target_pos;
	struct s_stack	*next;
}	t_stack;

/* utils */
int		ft_isdigit(int c);
int		ft_isspace(int c);
int		ft_strlen(const char *s);
long	ft_atol(const char *s);
char	**ft_split(const char *s, char c);
void	ft_putstr_fd(const char *s, int fd);

/* stack utils */
t_stack	*new_node(int val);
void	stack_push_front(t_stack **stack, t_stack *node);
t_stack	*stack_pop_front(t_stack **stack);
int		stack_size(t_stack *stack);
int		stack_is_sorted(t_stack *stack);

/* stack utils 2 */
t_stack	*stack_last(t_stack *stack);
int		stack_min(t_stack *stack);
int		stack_max(t_stack *stack);
void	free_stack(t_stack **stack);
void	free_split(char **split);

/* operations */
void	op_sa(t_stack **a, int print);
void	op_sb(t_stack **b, int print);
void	op_ss(t_stack **a, t_stack **b, int print);
void	op_pa(t_stack **a, t_stack **b, int print);
void	op_pb(t_stack **a, t_stack **b, int print);

/* operations 2 */
void	op_ra(t_stack **a, int print);
void	op_rb(t_stack **b, int print);
void	op_rr(t_stack **a, t_stack **b, int print);
void	op_rra(t_stack **a, int print);
void	op_rrb(t_stack **b, int print);

/* operations 3 */
void	op_rrr(t_stack **a, t_stack **b, int print);

/* parse */
t_stack	*parse_args(int argc, char **argv);

/* parse utils */
int		is_valid_number(const char *s);
int		has_duplicate(t_stack *stack, int val);

/* sort small */
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);

/* sort large */
void	sort_large(t_stack **a, t_stack **b);

/* sort large utils */
int		find_pos_val(t_stack *stack, int val);
int		find_target_in_b(t_stack *b, int val_a);
void	calculate_costs_a_to_b(t_stack *a, t_stack *b);
t_stack	*find_cheapest_node(t_stack *a);

/* sort large utils 2 */
void	move_cheapest_a_to_b(t_stack **a, t_stack **b);
void	push_all_b_to_a(t_stack **a, t_stack **b);
void	final_rotate_a(t_stack **a);

/* error */
void	error_exit(t_stack **a, t_stack **b, char **split);

#endif
