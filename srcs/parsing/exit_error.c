/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:12:24 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/16 13:44:37 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    handle_exit(int i, t_stack *a, t_stack *b)
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
	t_node	*current;
	t_node	*next;

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