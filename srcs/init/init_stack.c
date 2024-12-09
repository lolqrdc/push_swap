/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:46:05 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/09 09:26:44 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// creer une pile a vide
t_stack	*init_stack(void)
{
	t_stack	*stack_a;
	
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	stack_a->head = NULL;
	stack_a->nbr_n = 0;
	return (stack_a);
}
t_stack *add_to_stack(t_stack *stack_a, int argv)
{
	t_node *new_node;
	
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (FAILURE);
	new_node->element = argv;
	new_node->next = stack_a->head;
	new_node->prev = NULL;
	if (stack_a->head)
		stack_a->head->prev = new_node;
	stack_a->head = new_node;
	stack_a->nbr_n++;
	return (SUCCESS);
}