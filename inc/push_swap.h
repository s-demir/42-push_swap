/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedemir <sedemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:12:59 by sedemir           #+#    #+#             */
/*   Updated: 2025/03/06 14:06:29 by sedemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	int					above_median;
	int					cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack;

int				error_syntax(char *str_n);
int				error_duplicate(t_stack *a, int n);
void			free_stack(t_stack **stack);
void			free_errors(t_stack **a, char **args, int flag);
void			put_error(void);
void			destroy_args(char **args);

void			init_stack_a(t_stack **a, char **argv, int flag);

void			init_nodes_a(t_stack *a, t_stack *b);
void			init_nodes_b(t_stack *a, t_stack *b);
void			current_index(t_stack *stack);
void			set_cheapest(t_stack *stack);
t_stack			*get_cheapest(t_stack *stack);
void			prep_for_push(t_stack **s, t_stack *n, char c);

int				stack_len(t_stack *stack);
t_stack			*find_last(t_stack *stack);
int				stack_sorted(t_stack *stack);
t_stack			*find_min(t_stack *stack);
t_stack			*find_max(t_stack *stack);

void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **b, t_stack **a);

void			sort_three(t_stack **a);
void			sort_stacks(t_stack **a, t_stack **b);
void			move_b_to_a(t_stack **a, t_stack **b);

#endif