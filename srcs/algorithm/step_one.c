/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:09:39 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/14 11:55:39 by loribeir         ###   ########.fr       */
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
	chunk->stack_size = a->nbr_n;
	chunk->chunk_size = chunk->stack_size / chunk->n;
	chunk->mid = a->nbr_n / 2;
	chunk->reference = reference;
	chunk->start = chunk->reference[0];
	chunk->end = chunk->reference[chunk->chunk_size];
	return(chunk);
}
// Transfert: push element (in the chunk) from a->b.
void	transfert_chunk(t_stack *a, t_stack *b)
{
	t_chunk	*chunk;
	t_node	*node;
	
	chunk = init_chunk(a);
	while (a->head->next != NULL)
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
			update_chunk(chunk, a);
	}
	node = node->next;
	free(chunk);
}
// Check: verify if there is still elements between start and end.
int	check_chunk(t_chunk *chunk, t_stack *a)
{
	t_node *tmp;
	int	i;
	
	tmp = a->head;
	while (tmp)
	{
		i  = chunk->start;
		while (i < chunk->end && i < chunk->chunk_size)
		{
			if (tmp->element == chunk->reference[i])
				return (1);
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}
// Update: no more element in the chunk, update to create a new chunk.
void	update_chunk(t_chunk *chunk, t_stack *a)
{
	if (check_chunk(chunk, a) == 0)
	{
		if (chunk->start > chunk->chunk_size)
			chunk->start = chunk->end;
		else
			chunk->start = chunk->end;
		if (chunk->end + chunk->chunk_size > chunk->stack_size)
			chunk->end = chunk->stack_size - 1;
		else
			chunk->end += chunk->chunk_size;
	}
	printf("%d // %d\n", chunk->start, chunk->end);
}
