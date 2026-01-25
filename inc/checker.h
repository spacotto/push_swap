/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:49:49 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/25 18:16:14 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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
int		main(int ac, char **av);

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

#endif
