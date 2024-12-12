/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:07:16 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/12 09:18:12 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// ROTATE:  
void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack == NULL || stack->nbr_n < 2)
		return ;
	first = stack->head;
	stack->head = first->next;
	if (stack->head != NULL)
	{
		stack->head->prev = NULL;
		last = first;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = first;
		first->prev = last;
		first->next = NULL;
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
