/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:03:27 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/20 09:44:18 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_back(t_stack *b, t_stack *a)
{
    int max_pos;
    int middle;
    int max;
    
    while (b->head)
    {
        max = ft_find_max(b);
        if (b->head->element == max)
        {
            push_pa(a, b);
            if (a->head->next && a->head->element > a->head->next->element)
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
    while (!is_sorted(a) && a->nbr_n > 0)
        rotate_ra(a);
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
