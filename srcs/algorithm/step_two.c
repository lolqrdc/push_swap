/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:41:27 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/13 11:53:17 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    sort_b_to_a(t_stack *a, t_stack *b)
{
    int down_a;
    int max_index;

    down_a = 0;
    while (b->head || down_a > 0)
    {
        max_index = find_max(b);
        if (max_index == -1)
        {
            reverse_rra(a);
            down_a--;
        }
    }
}
int find_max(t_stack *b)
{
    t_node *node;
    int     i;
    
}
int tail_elem(t_stack *stack)
{
    t_node *tail;
    
    tail = stack->head;
    while (tail->element)
        tail = tail->next;
    return (tail->element);
}
