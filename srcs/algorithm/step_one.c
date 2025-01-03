/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:09:39 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/03 16:37:04 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Initialization of each chunk and handle malloc error case.
t_chunk	*init_chunk(int stack_size)
{
	t_chunk	*chunk;
	int		mid;

	chunk = malloc(sizeof(t_chunk));
	if (!chunk)
		return (NULL);
	if (stack_size <= 10)
		chunk->n = 5;
	else if (stack_size <= 150)
		chunk->n = 8;
	else
		chunk->n = 18;
	chunk->size = stack_size / chunk->n;
	mid = stack_size / 2;
	chunk->start = mid - chunk->size;
	chunk->end = mid + chunk->size;
	if (chunk->start < 0)
		chunk->start = 0;
	if (chunk->end >= stack_size)
		chunk->end = stack_size - 1;
	return (chunk);
}
// Function to handle chunks until there are elements in stack A.
void	chunk_sort(t_stack *a, t_stack *b)
{
	int 	*sorted_ref;
	t_chunk	*chunk;
	
	sorted_ref = sorted_reference(a);
	if (!sorted_ref)
		return;
	chunk = init_chunk(a->nbr_n);
	if (!chunk)
		return(free(sorted_ref));
	while (a->nbr_n > 0)
	{
		process_chunk(a, b, chunk, sorted_ref);
		update_chunk(chunk, a->nbr_n);
	}
	free(sorted_ref);
	free(chunk);
}

// Function to check stack A and move on element from chunk to stack B.
void	process_chunk(t_stack *a, t_stack *b, t_chunk *chunk, int *sorted_ref)
{
	t_node	*current;
	int		mid;
	
	current = a->head;
	mid = sorted_ref[a->nbr_n / 2];
	while (current)
	{
		if (current->element >= sorted_ref[chunk->start] 
			&& current->element <= sorted_ref[chunk->end])
		{
			push_pa(a, b);
			if (b->head->element < mid)
				rotate_ra(b);
			current = a->head;
		}
		else 
			current = current->next;
	}
}
// Function to update the chunk after all elements added to stack B.
void	update_chunk(t_chunk *chunk, int size_stack)
{
	chunk->start += chunk->size;
	chunk->end += chunk->size;
	if (chunk->start >= size_stack)
		chunk->start = size_stack - 1;
	if (chunk->end >= size_stack)
		chunk->end = size_stack - 1;
}
