/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:21:51 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/16 15:37:05 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_stack *stack)
{
	t_node	*first;
	t_node	*last;
	t_node	*second_last;

	if (stack == NULL || stack->nbr_n < 2)
		return ;
	first = stack->head;
	last = stack->head;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	stack->head = last;
}

void	reverse_rra(t_stack *stack_a)
{
	if (!stack_a)
		return ;
	reverse(stack_a);
	ft_printf("rra\n");
}

void	reverse_rrb(t_stack *stack_b)
{
	if (!stack_b)
		return ;
	reverse(stack_b);
	ft_printf("rrb\n");
}

//REVERSE RRR:
void	reverse_rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	reverse(stack_a);
	reverse(stack_b);
	ft_printf("rrr\n");
}
