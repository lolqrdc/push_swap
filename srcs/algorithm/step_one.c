/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:09:39 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/15 10:09:54 by loribeir         ###   ########.fr       */
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
    chunk->end = chunk->mid + chunk->chunk_size;
    return (chunk);
}
void    transfert_chunk(t_chunk *chunk, t_stack *a, t_stack *b)
{
    t_node  *node;
    
    if (!chunk)
        return;
    while (a->nbr_n > 3)
    {
        node = a->head;
        if (node->element >= chunk->start && node->element <= chunk->end)
        {
            push_pb(b, a);
            if (b->head->element < chunk->mid)
            {
                push_pb(b, a);
                rotate_rb(b);
            }
        }
        else
            rotate_ra(a);
        update_chunk(chunk, a);
    }
    free(chunk);
}
void    update_chunk(t_chunk *chunk, t_stack *a)
{
    if (check_chunk(chunk, a) == 0)
    {
        if (chunk->start - chunk->chunk_size < 0)
            chunk->start -= chunk->start;
        else
            chunk->start -= chunk->chunk_size;
        if (chunk->end + chunk->chunk_size > chunk->stack_size)
            chunk->end = chunk->stack_size - 1;
        else
            chunk->end += chunk->chunk_size;
    }
}
int check_chunk(t_chunk *chunk, t_stack *a)
{
    int     j;
    int     i;
    t_node  *tmp;
    
    j = 0;
    tmp = a->head;
    while (j < chunk->stack_size)
    {
        i = chunk->start;
        while (i < chunk->end)
        {
            if (tmp->element == chunk->reference[i])
                return (1);
            i++;
        }
        tmp = tmp->next;
        j++;
    }
    return (0);   
}
