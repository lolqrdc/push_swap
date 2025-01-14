/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_onev1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:35:51 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/14 15:40:18 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Init: calculing all necessaries values to create the chunk.
t_chunk	*init_chunk(t_stack *a)
{
	t_chunk	*chunk;
	int		*reference;
	
	reference = sorted_reference(a);
	chunk = malloc(sizeof(t_chunk));
	if (!chunk)
		return(free(chunk), NULL);
	if (a->nbr_n <= 10)
		chunk->n = 5;
	else if (a->nbr_n <= 150)
		chunk->n = 10;
	else
		chunk->n = 18;
	chunk->reference = reference;
	chunk->stack_size = a->nbr_n;
	chunk->chunk_size = (chunk->stack_size + chunk->n - 1) / chunk->n;
	chunk->mid = chunk->reference[chunk->stack_size / 2];
	chunk->current_chunk = 0;
	chunk->start = chunk->reference[0];
	chunk->end = chunk->reference[chunk->chunk_size - 1];
	return(chunk);
}
// Transfert: push element (in the chunk) from a->b.
void	transfert_chunk(t_stack *a, t_stack *b)
{
	t_chunk	*chunk;
	t_node	*node;
	
	chunk = init_chunk(a);
	while (a->head != NULL)
	{
		node = a->head;
		if (node->element >= chunk->start && node->element <= chunk->end)
		{
			push_pb(b, a);
				if (b->head && b->head->element < chunk->mid)
					rotate_rb(b);
		}
		else
			rotate_ra(a);
		if (check_chunk(chunk, a) == 0)
		{
			update_chunk(chunk);
			if (chunk->start == chunk->end)
				break;
		}
	}
	free(chunk);
}
// Check: verify if there is still elements between start and end.
int	check_chunk(t_chunk *chunk, t_stack *a)
{
	t_node *tmp;
	
	tmp = a->head;
	while (tmp)
	{
		if (tmp->element >= chunk->start && tmp->element <= chunk->end)
			return(1);
		tmp = tmp->next;
	}
	return (0);
}
// Update: no more element in the chunk, update to create a new chunk.
void	update_chunk(t_chunk *chunk)
{
	int start_i;
	int	end_i;
	
	chunk->current_chunk++;
	start_i = chunk->current_chunk * chunk->chunk_size;
	end_i = start_i + chunk->chunk_size - 1;
	if (start_i >= chunk->stack_size)
	{
		chunk->start = chunk->end = chunk->reference[chunk->stack_size - 1];
		return;
	}
	if (end_i >= chunk->stack_size)
		end_i = chunk->stack_size - 1;
	chunk->start = chunk->reference[start_i];
	chunk->end = chunk->reference[end_i];
	printf("New chunk: %d // %d\n", chunk->start, chunk->end);
}

