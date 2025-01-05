/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:59:07 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/05 12:30:57 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void chunk_params(t_stack *a, t_chunk *chunk, int *arr_ref)
{
    arr_ref = sorted_array(a);
    if (a->nbr_n <= 10)
        chunk->n = 5;
    else if (a->nbr_n <= 150)
        chunk->n = 8;
    else
        chunk->n = 18;
    chunk->mid = arr_ref[a->nbr_n / 2];
    chunk->chunk_size = a->nbr_n / chunk->n;
    chunk->start = (a->nbr_n / 2) - chunk->chunk_size;
    chunk->end= (a->nbr_n / 2) + chunk->chunk_size;
    free(arr_ref);
}

void transfert_chunk(t_stack *a, t_stack *b, t_chunk *chunk, int arr_ref)
{
    t_node  *node;
    int     *j;

    j = chunk->start;
    while (j < chunk->end && j < a->nbr_n)
        node = a->head;
    while (node != NULL)
    {
        if (node->element == arr_ref[j])
        {
            push_pb(b, a);
            if (node->element < chunk->mid)
                rotate_rb(b);
        }
        node = node->next;
    }
    j++;
}
