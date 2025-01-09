/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:09:39 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/09 18:23:16 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_chunk	*init_chunk(t_stack *a)
{
	t_chunk	*chunk;
	int		*tab_ref;

	tab_ref = arr_reference(a);
	chunk = malloc(sizeof(t_chunk));
	if (!chunk)
		return (NULL);
	if (a->nbr_n <= 10)
		chunk->n = 5;
	else if (a->nbr_n <= 150)
		chunk->n = 8;
	else
		chunk->n = 18;
	chunk->chunk_size = a->nbr_n / chunk->n;
	chunk->mid = a->nbr_n / 2;
	chunk->start = chunk->mid - chunk->chunk_size;
	chunk->end = chunk->mid + chunk->chunk_size;
	return(chunk);
}
// fonction qui parcourt ta stack et qui verifie si ya encore des valeurs start et end

void	transfert_chunk(t_stack *a, t_stack *b)
{
	t_chunk	*chunk;
	t_node	*node;
	
	chunk = init_chunk(a);
	node = a->head;

	while (node)
	{
		if (node->element >= chunk->start && node->element <= chunk->end)
			push_pb(b, a);
				if (b->head && b->head->element < chunk->mid)
					rotate_rb(b);
		else
			node = a->head;
		update_chunk(a, chunk);
	}
	node = a->head;
	free(chunk);
}

void	update_chunk(t_stack *a, t_chunk *chunk)
{
	int	size_stack;
	size_stack = a->nbr_n;
	
	chunk->start -= chunk->chunk_size;
	chunk->end += chunk->chunk_size;
	if(chunk->start >= size_stack)
		chunk->start = size_stack - 1;
	if (chunk->end >= size_stack)
		chunk->end = size_stack - 1;
}
