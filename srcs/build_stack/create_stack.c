/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:29:04 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/16 17:42:12 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Init stack_a to add valid args.
void	init_stacks(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = malloc(sizeof(t_stack));
	*stack_b = malloc(sizeof(t_stack));
	if (*stack_a == NULL || *stack_b == NULL)
		return;
	(*stack_a)->head = NULL;
	(*stack_a)->nbr_n = 0;
	(*stack_b)->head = NULL;
	(*stack_b)->nbr_n = 0;
}

// Add valid args to stack_a.
void	add_to_stack(t_stack *stack_a, int arg)
{
	t_node	*new_node;
	t_node	*current;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return;
	new_node->element = arg;
	new_node->next = NULL;
	if (stack_a->head == NULL)
	{
		new_node->prev = NULL;
		stack_a->head = new_node;
	}
	else
	{
		current = stack_a->head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
	stack_a->nbr_n++;
}
// Scan valid args and call add_to_stack for each of them.
void	build_stack_a(t_stack *stack_a, char **arg)
{
	int	i;
	int	element;
	
	init_stacks(&stack_a, NULL);
	i = 0;
	while (arg[i] != NULL)
	{
		element = ft_atoi(arg[i]);
		add_to_stack(stack_a, element);
	}
	free_stack(stack_a);
}

// Free the stack.
void	free_stack(t_stack *stack_a)
{
	t_node	*current;
	t_node	*next;
	
	current = stack_a->head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack_a->head = NULL;
	stack_a->nbr_n = 0;
}
// Free all.
void	free_all(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free(stack_b);
	free(stack_a);
}
