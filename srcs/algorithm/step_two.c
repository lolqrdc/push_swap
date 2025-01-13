/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:41:27 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/13 15:39:59 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    transfert_back(t_stack *b, t_stack *a)
{
    int stack_tail;
    int down;
    int max;
    int max_i;

    down = 0;
    while (b->head || down > 0)
    {
        stack_tail = tail_stack(a);
        max = find_max(b, &max_i);
        if (b->head->element == max)
            push_pa(a, b);
        else if (down == 0 || b->head->element > stack_tail)
        {
            push_pa(a, b);
            rotate_ra(a);
            down++;
        }
        else
        {
            if (max_i <= b->nbr_n / 2)
                rotate_rb(b);
            else
                reverse_rrb(b);
        }
    }
}
int find_max(t_stack *b, int *max_i)
{
    t_node  *node;
    int     max_v;
    int     i;
    
    node = b->head;
    max_v = node->element;
    *max_i = 0;
    i = 0;
    while (node)
    {
        if (node->element > max_v)
        {
            max_v = node->element;
            *max_i = i;
        }
        node = node->next;
        i++;
    }
    return (max_v);
}

int tail_stack(t_stack *stack)
{
    t_node *tail;
    
    if (!stack->head)
        return (FAILURE);
    tail = stack->head;
    while (tail->next)
        tail = tail->next;
    return (tail->element);
}
