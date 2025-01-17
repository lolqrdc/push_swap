/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:53:34 by lolq              #+#    #+#             */
/*   Updated: 2025/01/17 19:18:08 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool check_syntax(const char *arg)
{
    int i;

    i = 0;
    while (arg[i] == ' ')
        i++;
    if (arg[i] == '\0')
        return (false);
    if (arg[i] == '-' || arg[i] == '+')
        i++;
    if (!arg[i])
        return (false);
    while (arg[i])
    {
        if (!ft_isdigit(arg[i]))
            return (false);
        i++;
    }
    return (true);
}
bool check_range(const char *arg)
{
    long    num;
    int     sign;
    int     i;
    
    i = 0;
    num = 0;
    sign = 1;
    while (arg[i] == ' ')
    {
        num = (num * 10) + (arg[i] - '0');
        if ((num * sign > INT_MAX || num * sign < INT_MIN))
            return (false);
        i++;
    }
    return (true);
}
bool    check_duplicates(t_stack *a)
{
    t_node  *current;
    t_node  *next;

    current = a->head;
    while (current)
    {
        next = current->next;
        while (next)
        {
            if (current->element == next->element)
                return (false);
            next = next->next;
        }
        current = current->next;
    }
    return (true);
}
bool    is_sorted(t_stack *a)
{
    t_node  *current;
    
    current = a->head;
    while (current && current->next)
    {
        if (current->element > current->next->element)
            return (false);
        current = current->next;
    }
    return (true);
}

