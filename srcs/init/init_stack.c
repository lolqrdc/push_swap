/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:46:05 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/09 18:35:08 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// creer une pile a vide
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

// ajouter un nouveau noeud et l'ajoute en debut de stack_a
int		add_to_stack(t_stack *stack, int element)
{
	t_node *new_node;
	
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (FAILURE);
	new_node->element = element;
	new_node->next = stack->head;
	new_node->prev = NULL;
	if (stack->head)
		stack->head->prev = new_node;
	stack->head = new_node;
	stack->nbr_n++;
	return (SUCCESS);
}
void	print_stack(t_stack *stack)
{
	t_node *current = stack->head;

    if (!current)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack contents: ");
    while (current)
    {
        printf("%d", current->element);
        current = current->next;
    }
    printf("\n");
}
void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;
	
	current = stack->head;
	if (!current)
		return;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
