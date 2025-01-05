/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:09:39 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/05 10:05:37 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_chunk	*init_chunk(t_stack *a)
{
	t_chunk	*chunk;
	int		*tab_ref;
	int		size_stack;

	tab_ref = sorted_reference(a);
	size_stack = a->nbr_n;
	chunk = malloc(sizeof(t_chunk));
	if (!chunk)
		return (NULL);
	if (size_stack <= 10)
		chunk->n = 5;
	else if (size_stack <= 150)
		chunk->n = 8;
	else
		chunk->n = 18;
	chunk->size = size_stack / chunk->n;
	chunk->mid = tab_ref[size_stack / 2];
	return(chunk);
	
}

void	transfert_chunk(t_stack *a, t_stack *b)
{
	t_chunk	*chunk;
	t_node	*node;
	
	chunk = init_chunk(a);
	node = a->head;
	
	printf("Chunk initial: start=%d, end=%d, mid=%d\n", chunk->start, chunk->end, chunk->mid);
	while (node)
	{
		printf("Élément actuel: %d, start: %d, end: %d\n", node->element, chunk->start, chunk->end);
		if (node->element >= chunk->start && node->element <= chunk->end)
		{
			printf("Transfert de l'élément: %d\n", node->element);
			push_pb(b, a);
				if (b->head && b->head->element < chunk->mid)
					rotate_rb(b);
		}
		else
		{
			node = node->next;
		}
	}
	node = a->head;
	update_chunk(a, chunk);
	free(chunk);
}

void	update_chunk(t_stack *a, t_chunk *chunk)
{
	int	size_stack;
	size_stack = a->nbr_n;
	
	chunk->start += chunk->size;
	chunk->end += chunk->size;
	if(chunk->start >= size_stack)
		chunk->start = size_stack - 1;
	if (chunk->end >= size_stack)
		chunk->end = size_stack - 1;
}
