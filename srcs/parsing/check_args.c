/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:53:34 by lolq              #+#    #+#             */
/*   Updated: 2025/01/18 15:25:08 by loribeir         ###   ########.fr       */
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
    while (arg[i] != '\0')
    {
        if (!ft_isdigit(arg[i]))
            return (false);
        i++;
    }
    return (true);
}
bool check_overflow(char *arg)
{
    long    result;
    int     sign;
    int     i;
    
    sign = 1;
    result = 0;
    i = 0;
    while ((arg[i] == ' ' || (arg[i] >= 9 && arg[i] <= 13)))
        i++;
    if (arg[i] == '-' || arg[i] == '+')
    {
        if (arg[i] == '-')
            sign = -1;
        i++;
    }
    while (arg[i] != '\0')
    {
        result = (result * 10) + (arg[i] - '0');
        if ((result * sign > 2147483647 || result * sign < -2147483648))
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

