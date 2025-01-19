/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:33:12 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/19 20:13:58 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    chunk_push(t_stack *a, t_stack *b)
{
    t_chunk chunk;
    int     chunk_n;
    int     count;
    int     min;

    chunk_n = 0;
    count = 0;
    printf("Debug: Init chunk_push\n");
    chunk = handle_chunk(a);
    min = ft_find_min(a);
    printf("Debug: min = %d, chunk_size = %d\n", min, chunk.chunk_size);
    while (count < a->nbr_n)
    {
        chunk.start = min + chunk_n * chunk.chunk_size;
        chunk.end = min + (chunk_n + 1) * chunk.chunk_size;
        printf("Debug: chunk_n = %d, start = %d, end = %d\n", chunk_n, chunk.start, chunk.end);
        if (count_element_chunk(a, chunk.start, chunk.end) == 0)
        {
            chunk_n++;
            continue;
        }
        handle_element(a, b, &chunk, &count);
    }
}

t_chunk    handle_chunk(t_stack *a)
{
    t_chunk chunk;
    int     range;
    int     min;
    int     max;

    min = ft_find_min(a);
    max = ft_find_max(a);
    range = max - min + 1;
    if (a->nbr_n <= 100)
        chunk.chunk_size = 20;
    else if (a->nbr_n <= 500)
        chunk.chunk_size = 40;
    else
        chunk.chunk_size = 60;
    chunk.start = min;
    chunk.end = min + (range * chunk.chunk_size / a->nbr_n);
    return (chunk);    
}

void    handle_element(t_stack *a, t_stack *b, t_chunk *chunk, int *count)
{
    int element;
    int pos;
    
    if (!a->head)
        return ;
    element = a->head->element;
    if (element >= chunk->start && element < chunk->end)
    {
        printf("Debug: element in chunk range, pushing to b\n");
        push_pb(b, a);
        printf("Debug: push completed\n");
        (*count)++;
        printf("Debug: count incremented to %d\n", *count);
        if (b->head)
        {
            printf("Debug: checking B head element %d\n", b->head->element);
            if (b->head->element < (chunk->start + chunk->chunk_size / 2))
            {
                printf("Debug: rotating B\n");
                rotate_rb(b);
            }
        }
    }
    else
    {
        pos = find_element_pos(a, chunk->start, chunk->end);
        if (pos > a->nbr_n / 2)
            reverse_rra(a);
        else
            rotate_ra(a);
    }
}
int find_element_pos(t_stack *stack, int start, int end)
{
    t_node *current;
    int     pos;
    
    pos = 0;
    current = stack->head;
    while (current)
    {
        if (current->element >= start && current->element < end)
            return (pos);
        pos++;
        current = current->next;
    }
    return (-1);
}
int count_element_chunk(t_stack *stack, int start, int end)
{
    t_node *current;
    int     count;
    
    if (!stack || !stack->head)
        return (0);
    count = 0;
    current = stack->head;
    while (current)
    {
        if (current->element >= start && current->element < end)
            count++;
        current = current->next;
    }
    return (count);
}

