/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:55:58 by spacotto          #+#    #+#             */
/*   Updated: 2026/01/06 15:08:46 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_arena	*arena_init(void)
{
	t_arena	*arena;
	void	*first_page;
	t_list	*first_node;

	arena = ft_calloc(1, sizeof(t_arena));
	if (!arena)
		return (NULL);
	first_page = ft_calloc(PAGE_SIZE, sizeof(char));
	if (!first_page)
	{
		free(arena);
		return (NULL);
	}
	first_node = ft_lstnew(first_page);
	if (!first_node)
	{
		free(first_page);
		free(arena);
		return (NULL);
	}
	arena->pages = first_node;
	arena->current_page = first_page;
	arena->used_mem = 0;
	return (arena);
}

void	*arena_alloc(t_arena *arena, size_t size)
{
	void	*free_mem;
	void	*new_page;
	t_list	*new_node;

	if (!arena || size == 0)
		return (NULL);
	if (arena->used_mem + size <= PAGE_SIZE)
	{
		free_mem = (char *)arena->current_page + arena->used_mem;
		arena->used_mem += size;
		return (free_mem);
	}
	new_page = ft_calloc(PAGE_SIZE, sizeof(char));
	if (!new_page)
		return (NULL);
	new_node = ft_lstnew(new_page);
	if (!new_node)
	{
		free(new_page);
		return (NULL);
	}
	ft_lstadd_back(&arena->pages, new_node);
	arena->current_page = new_page;
	arena->used_mem = size;
	return (new_page);
}

void	arena_free(t_arena *arena)
{
	if (!arena)
		return ;
	ft_lstclear(&arena->pages, del);
	free(arena);
}
