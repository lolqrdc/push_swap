/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:57:18 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/16 15:36:58 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dest)
{
	t_node	*node_move;

	if (src->nbr_n == 0)
		return ;
	node_move = src->head;
	src->head = src->head->next;
	src->nbr_n--;
	if (src->nbr_n > 0)
		src->head->prev = node_move->prev;
	node_move->next = dest->head;
	if (dest->nbr_n > 0)
	{
		dest->head->prev = node_move;
	}
	node_move->prev = NULL;
	dest->head = node_move;
	dest->nbr_n++;
}

void	push_pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	push_pb(t_stack *stack_b, t_stack *stack_a)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
