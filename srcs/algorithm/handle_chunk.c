/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:09:39 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/03 11:27:39 by loribeir         ###   ########.fr       */
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
// Function to add element from stack A to chunk.
void	add_to_chunk(t_stack *a, t_stack *b, int *sorted_ref, t_chunk *chunk)
{
	int		mid_value;
	t_node	*current;
	
	current = a->head;
	mid_value = sorted_ref[a->nbr_n / 2];
	while (current)
	{
		if (current->element >= sorted_ref[chunk->start] && current->element <= sorted_ref[chunk->end])
		
	}
	
}
// Function to update the chunk.
void	update_chunk(t_stack *a, t_chunk *chunk)
{
	
}