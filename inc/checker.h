/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:49:49 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/26 16:28:51 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

// ============================================================================
// INCLUDES
// ============================================================================

# include "push_swap.h"

// ============================================================================
// PROTOTYPES
// ============================================================================

// Core functions
int		checker(t_stacks *stacks, int ac, char **av);

// Operations
void	ft_sa_bonus(t_stacks *stacks);
void	ft_sb_bonus(t_stacks *stacks);
void	ft_ss_bonus(t_stacks *stacks);

void	ft_pa_bonus(t_stacks *stacks);
void	ft_pb_bonus(t_stacks *stacks);

void	ft_ra_bonus(t_stacks *stacks);
void	ft_rb_bonus(t_stacks *stacks);
void	ft_rr_bonus(t_stacks *stacks);

void	ft_rra_bonus(t_stacks *stacks);
void	ft_rrb_bonus(t_stacks *stacks);
void	ft_rrr_bonus(t_stacks *stacks);

#endif
