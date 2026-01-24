/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:44:54 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/24 18:13:03 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// ============================================================================
// INCLUDES
// ============================================================================

# include "../libft/inc/libft.h"
# include "../libft/inc/printf.h"

# include <limits.h>

// ============================================================================
// STRUCTURES
// ============================================================================

typedef struct s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*operations;
	t_list	*optimisation;
}	t_stacks;

// ============================================================================
// PROTOTYPES
// ============================================================================

// Core functions
void    error_msg();
int		push_swap(t_stacks *stacks, int ac, char **av);	
int		main(int ac, char **av);

// Parsing
void    make_stack(t_stacks *stacks, int ac, char **av);
int		sort_check(t_stacks *stacks);

// Operations
void	ft_sa(t_stacks *stacks);
void	ft_sb(t_stacks *stacks);
void	ft_ss(t_stacks *stacks);

void	ft_pa(t_stacks *stacks);
void	ft_pb(t_stacks *stacks);

void	ft_ra(t_stacks *stacks);
void	ft_rb(t_stacks *stacks);
void	ft_rr(t_stacks *stacks);

void	ft_rra(t_stacks *stacks);
void	ft_rrb(t_stacks *stacks);
void	ft_rrr(t_stacks *stacks);

// Optimisation
void	assign_index(t_list *stack);

void	move_to_top_a(t_stacks *stacks, t_list *target);
void	move_to_top_b(t_stacks *stacks, t_list *target);

void	add_operation(t_stacks *stacks, char *op);
t_list	*optimise_ops(t_list *ops);
int		isrr(char *op1, char *op2);
void	merge_rr(t_list  **ops);
int		isrrr(char *op1, char *op2);
void	merge_rrr(t_list  **ops);
int		redundancy(t_list *op1, t_list *op2);
void	print_ops(t_list *ops);

// Sorting
void	simple_sort(t_stacks *stacks, int stack_size);
void	range_presort(t_stacks *stacks);
void	range_sort(t_stacks *stacks);

#endif
