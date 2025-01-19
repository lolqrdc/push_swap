/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:48:31 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/19 15:09:47 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_find_min(t_stack *stack)
{
    t_node  *current;
    int     min;

    if (!stack || !stack->head)
        return (-1);
    current = stack->head;
    min = current->element;
    while (current)
    {
        if (current->element < min)
            min = current->element;
        current = current->next;
    }
    return (min);
}

void    push_min_to_b(t_stack *a, t_stack *b)
{
    int min;
    int pos;
    
    while (a->nbr_n > 3)
    {
        min = ft_find_min(a);
        pos = ft_find_pos(a, min);
        if (pos <= a->nbr_n / 2)
        {
            while (a->head->element != min)
                rotate_ra(a);
        }
        else
        {
            while (a->head->element != min)
                reverse_rra(a);
        }
        push_pb(b, a);
    }
}

int ft_find_pos(t_stack *stack, int value)
{
    t_node *current;
    int     pos;

    pos = 0;
    if (!stack || !stack->head)
        return (-1);
    current = stack->head;
    while (current)
    {
        if (current->element == value)
            return (pos);
        current = current->next;
        pos++;
    }
    return (-1);
}

void    sort_to_merge(t_stack *a, t_stack *b)
{
    if (!a || !a->head || !a->head->next || !a->head->next->next)
        return ;
    if (a->head->element > a->head->next->element)
        swap_sa(a);
    if (a->head->element > a->head->next->next->element)
    {
        reverse_rra(a);
        if (a->head->element > a->head->next->element)
            swap_sa(a);
    }
    while (b->nbr_n > 0)
    {
        push_pa(a, b);
        if (a->head->element > a->head->next->element)
            swap_sa(a);
    }
}

