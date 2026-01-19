/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:44:54 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/19 18:29:42 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// ============================================================================
// INCLUDES
// ============================================================================

# include "../libft/inc/libft.h"
# include "../libft/inc/printf.h"

// ============================================================================
// STRUCTURES
// ============================================================================

typedef struct s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*operations;
}	t_stacks;

typedef struct s_biggest
{
	t_list  *p1;
	t_list  *p2;
	t_list  *p3;
	int		d1;
	int		d2;
	int		d3;
}	t_biggest;

typedef struct s_chunk
{
	int	size;
	int	min;
	int	max;
}	t_chunk;

// ============================================================================
// PROTOTYPES
// ============================================================================

// Core functions
void	push_swap(t_stacks *stacks);
int		main(int ac, char **av);

// Parsing
int		sort_check(t_stacks *stacks);
void	get_tokens(t_stacks *stacks, char *s);

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

// Sorting
void	assign_index(t_list *stack);

t_list	*find_smallest(t_list *stack);
t_list	*find_biggest(t_list *stack);
t_list	*find_second_biggest(t_list *stack);
t_list	*find_third_biggest(t_list *stack);
t_list  *find_best_target(t_list *stack, int min, int max, t_biggest *b);

void	move_to_top_a(t_stacks *stacks, t_list *target);
void	move_to_top_b(t_stacks *stacks, t_list *target);

void	add_operation(t_stacks *stacks, char *op);
void	merge_rr(t_list  *ops);
void	merge_rrr(t_list  *ops);
void	rm_redundancy(t_list **ops);
void	optimise_ops(t_stacks *stacks);
void	print_ops(t_stacks *stacks);

void	sort_two(t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	sort_four(t_stacks *stacks);
void	sort_five(t_stacks *stacks);

void	simple_sort(t_stacks *stacks);
void	chunk_presort(t_stacks *stacks);
void	chunk_sort(t_stacks *stacks);

#endif
