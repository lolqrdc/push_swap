/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:09:39 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/15 17:43:35 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_chunk *init_chunk(t_stack *a)
{
    t_chunk *chunk;

    chunk = malloc(sizeof(t_chunk));
    if (!chunk)
        return (NULL);
    chunk->reference = sorted_reference(a);
    chunk->stack_size = a->nbr_n;
    chunk->mid = (chunk->stack_size / 2);
    if (a->nbr_n <= 10)
        chunk->n = 5;
    else if (a->nbr_n <= 150)
        chunk->n = 10;
    else
        chunk->n = 18;
    chunk->chunk_size = chunk->stack_size / chunk->n;
    chunk->start = chunk->mid - chunk->chunk_size;
    chunk->end = chunk->mid + chunk->chunk_size - 1;
    return (chunk);
}
void    transfert_chunk(t_stack *a, t_stack *b)
{
    t_chunk *chunk; 
    t_node  *node;
    
    chunk = init_chunk(a);
    if (!chunk)
        return;
    while (a->nbr_n > 3)
    {
        node = a->head;
        printf("Current chunk: start=%d, end=%d\n", chunk->start, chunk->end);
        if (chunk->start < chunk->stack_size && chunk->end < chunk->stack_size)
        {
            if (node->element >= chunk->reference[chunk->start] && node->element <= chunk->reference[chunk->end])
            {
                push_pb(b, a);
                printf("Pushed to B: %d\n", b->head ? b->head->element : - 1);
                if (b->head->element < chunk->mid)
                    rotate_rb(b);
            }
            else
                rotate_ra(a);
        }
        if (check_chunk(chunk, a) == 0)
            update_chunk(chunk);
    }
}
void    update_chunk(t_chunk *chunk)
{
    chunk->start += chunk->chunk_size;
    chunk->end += chunk->chunk_size;
    if (chunk->end > chunk->stack_size)
        chunk->end = chunk->stack_size - 1;
}

int check_chunk(t_chunk *chunk, t_stack *a)
{
    t_node *tmp;

    tmp = a->head;
    while (tmp)
    {
        if (tmp->element >= chunk->reference[chunk->start] && tmp->element <= chunk->reference[chunk->end])
                return(1);
        tmp = tmp->next;
    }
    return (0);
}
