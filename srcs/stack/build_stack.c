/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:46:05 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/12 09:08:11 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// CREATE AN EMPTY STACK.
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

// ADD A NEW NODE + ADD IT TO THE HEAD OF STACK.
int	add_to_stack(t_stack *stack, int element)
{
	t_node	*new_node;
	t_node	*lst;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (FAILURE);
	new_node->element = element;
	new_node->next = NULL;
	if (stack->head == NULL)
	{
		new_node->prev = NULL;
		stack->head = new_node;
	}
	else
	{
		lst = stack->head;
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = new_node;
		new_node->prev = lst;
	}
	stack->nbr_n++;
	return (SUCCESS);
}

// PRINT THE STACK.
void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	if (current == 0)
	{
		ft_printf("La stack est vide.\n");
		return ;
	}
	while (current)
	{
		ft_printf("%d\n", current->element);
		current = current->next;
	}
	ft_printf("\n");
}

// FREE THE STACK.
void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->head;
	if (!current)
		return ;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
