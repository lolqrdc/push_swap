/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:57:18 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/16 10:13:54 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// PUSH: first element of src push to dest.
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

// PUSH PA: 1er element sommet de b et le met sur a.
void	push_pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

// PUSH PB: 1er element sommet de a et le met sur b.
void	push_pb(t_stack *stack_b, t_stack *stack_a)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
