/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:09:47 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/05 11:33:33 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Initialize the chunk structure.
t_chunk	*init_chunk(t_stack *a)
{
    t_chunk *chunk;
    int     *sorted_ref;
    
    sorted_ref = sorted_reference(a);
    chunk = malloc(sizeof(t_chunk));
    if (!chunk)
        return(free(sorted_ref), NULL);

    if (a->nbr_n <= 10)
		chunk->n = 5;
	else if (a->nbr_n <= 150)
		chunk->n = 8;
	else
		chunk->n = 18;
    chunk->mid = sorted_ref[a->nbr_n / 2];
    chunk->chunk_size = a->nbr_n / chunk->n;
    chunk->start = sorted_ref[chunk->mid - chunk->chunk_size];
    chunk->end = sorted_ref[chunk->mid + chunk->chunk_size];
    free(sorted_ref);
    return (chunk);
}
// Transfert elements from chunk stack a to stack b.
void    transfert_chunk(t_stack *a, t_stack *b, t_chunk *chunk)
{
    int transfered;
    
    transfered = 0;
    while (a->head && transfered < chunk->chunk_size)
    {
        if (a->head->element >= chunk->start && a->head->element <= chunk->end)
        {
            push_pb(b, a);
            if (b->head->element < chunk->mid)
                rotate_rb(b);
        }
    }
}
// Update the 'start' and 'end'.
void    update_chunk(t_chunk *chunk, int *sorted_ref, int size)
{
    int new_start;
    int new_end;
    int i;
    
    i = 0;
    new_start = 0;
    while (new_start < size && sorted_ref[new_start] < chunk->start)
        new_start++;
    if (new_start >= size)
        return;
    chunk->start = sorted_ref[new_start];
    new_end = new_start + chunk->chunk_size - 1;
    if (new_end >= size)
        new_end = size - 1;
    chunk->end = sorted_ref[new_end];
}
// Prepare the next chunk.
void    next_chunk(t_stack *a, t_chunk *chunk)
{
    int *sorted_ref;
    
    sorted_ref = sorted_reference(a);
    update_chunk(chunk, sorted_ref, a->nbr_n);
    free(sorted_ref);
}
