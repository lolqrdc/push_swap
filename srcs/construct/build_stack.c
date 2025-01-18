/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:31:33 by lolq              #+#    #+#             */
/*   Updated: 2025/01/18 14:21:20 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack(int argc, char **argv)
{
    t_stack *stack;
    int     i;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->head = NULL;
    stack->nbr_n = 0;
    i = argc - 1;
    while (i > 0)
    {
        if (!add_to_stack(stack, ft_atoi(argv[i])))
        {
            free_stack(&stack);
            return (NULL);
        }
        i--;
    }
    return (stack);
}
bool    add_to_stack(t_stack *stack, int arg)
{
    t_node  *node;

    node = malloc(sizeof(t_node));
    if (!node)
        return (false);
    node->element = arg;
    node->next = stack->head;
    node->prev = NULL;
    if (stack->head)
        stack->head->prev = node;
    stack->head = node;
    stack->nbr_n++;
    return (true);
}
void	print_stack(t_stack *stack)
{
	t_node	*current;

    if (!stack || !stack->head)
        return ;
    current = stack->head;
	while (current)
	{
		ft_printf("%d", current->element);
        if (current->next)
            ft_printf(" ");
		current = current->next;
	}
	ft_printf("\n");
}
