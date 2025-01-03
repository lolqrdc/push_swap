/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:48:19 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/03 11:12:02 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Initialize the stack and handle the error case if malloc error.
t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->nbr_n = 0;
	return (stack);
}

// Add nodes to stack A.
void	add_to_stack(t_stack *a, int arg)
{
	t_node	*node;
	int		i;

	i = 0;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->element = arg;
	node->next = a->head;
	node->prev = NULL;
	if (a->head)
		a->head->prev = node;
	a->head = node;
	a->nbr_n++;
}

// Build the stack by adding all args to the stack A.
void	build_stack(t_stack *a, char **arg, int nbr_args)
{
	int	i;

	i = nbr_args - 1;
	while (i >= 0)
	{
		add_to_stack(a, ft_atoi(arg[i]));
		i--;
	}
}

// Free the stack struct and all noes.
void	free_stack(t_stack **stack)
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
