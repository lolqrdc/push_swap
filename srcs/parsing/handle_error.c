/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:06:23 by lolq              #+#    #+#             */
/*   Updated: 2025/01/17 21:43:05 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool is_it_valid(int argc, char **argv, t_stack *a)
{
    int i;

    if (argc < 2)
        return (false);
    i = 1;
    while (i < argc)
    {
        if (!check_syntax(argv[i] || !check_range(argv[i])))
            return (false);
        if ()
    }
    if (!check_duplicates(a))
        return (false);
    return (true);
}
void    exit_error(t_stack *a, t_stack *b, int i)
{
    if (a)
        free_stack(&a);
    if (b)
        free_stack(&b);
    if (i == 1)
        write(2, "Error\n", 6);
    exit(1);
}
void    free_stack(t_stack **stack)
{
    t_node  *current;
    t_node  *next;

    if (!stack || !*stack)
        return ;
    current = (*stack)->head;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(*stack);
    *stack = NULL;
}
