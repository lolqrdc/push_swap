/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:09:39 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/04 11:32:01 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Initialize a chunk.
t_chunk	*init_chunk(t_stack *a, t_stack *b)
{
	t_chunk	*chunk;
	int		tab_ref;
	int		size_stack;

	tab_ref = sorted_reference(a);
	size_stack = ft_strlen(tab_ref);
	chunk = malloc(sizeof(t_chunk));
	if (!chunk)
		return (NULL);
	if (size_stack <= 10)
		chunk->n = 5;
	else if (size_stack <= 150)
		chunk->n = 8;
	if (size_stack > 150)
		chunk->n = 18;
	chunk->size = size_stack / chunk->n;
	chunk->mid = size_stack / 2;
	chunk->start = chunk->mid / chunk->size;
	chunk->end = chunk->mid + chunk->size;
	return (chunk); 
}

void	transfert_chunk(t_stack *a, t_stack *b)
{
	t_chunk	*chunk;
		
}
