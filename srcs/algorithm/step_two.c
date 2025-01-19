/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:03:27 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/19 23:22:26 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_back(t_stack *b, t_stack *a)
{
    int max;
    int max_pos;
    int middle;
    int limit_rotate = a->nbr_n;
    
    while (b->head)
    {
        max = ft_find_max(b);
        if (b->head->element == max)
        {
            push_pa(a, b);
            if (a->head->next && 
                a->head->element > a->head->next->element)
                swap_sa(a);
        }
        else
        {
            max_pos = ft_find_pos(b, max);
            middle = b->nbr_n / 2;
            if (max_pos <= middle)
                rotate_rb(b);
            else
                reverse_rrb(b);
        }
    }
    printf("Debut du tri final:\n");
    while (!is_sorted(a) && limit_rotate > 0)
    {
        printf("Rotation, reste %d\n", limit_rotate);
        rotate_ra(a);
        limit_rotate--;
    }
}

bool optimize_sort(t_stack *a, int element)
{
    t_node  *current;
    t_node  *next;

    if (!a->head)
        return (true);
    current = a->head;
    next = a->head->next;
    if (!next)
        return (true);
    return(element < current->element && element > next->element);
}
bool    is_sorted(t_stack *stack)
{
    t_node *current;

    current = stack->head;
    while (current && current->next)
    {
        if (current->element > current->next->element)
            return (false);
        current = current->next;
    }
    return (true);
}