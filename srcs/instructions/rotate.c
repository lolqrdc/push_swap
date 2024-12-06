/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:07:16 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/06 19:20:44 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// ROTATE: le premier devient le dernier. 
void	rotate(t_stack *stack)
{
	t_node *first;
	t_node	*last;
	if (stack == NULL  || stack->nbr_n < 2)
		return;
	first = stack->head;
	stack->head = first->next;
	if (stack->head != NULL) // si plus d'un element dans la stack
	{
		stack->head->prev = NULL;
		last = first;
		while (last->next != NULL) // trouver le dernier node
		{
			last = last->next;
		}
		last->next = first; // le dernier node ptr le premier
		first->prev = last; // le premier node ptr le dernier
		first->next = NULL; // le premier devient dernier, doit ptr next NULL
	}
	else
	{
		first->next = NULL;
		first->prev = NULL;
	}
}
// ROTATE RA:
void	rotate_ra(t_stack *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}
// ROTATE RB:
void	rotate_rb(t_stack *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}
// ROTATE RR:
void	rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}