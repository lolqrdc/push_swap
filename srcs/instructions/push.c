/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:57:18 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/06 16:48:53 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// PUSH: prendre le 1er element au sommet de src et le push dans dest.
void	push(t_stack *src, t_stack *dest)
{
	t_node *node_move;
	
	if (src->nbr_n == 0) // verifier si stack src est vide
		return;
	node_move = src->head;
	src->head = src->head->next; // le head de src devient le 2eme element
	src->nbr_n--;
	if (src->nbr_n > 0) // si apres stockage la pile src n'est pas vide 
		src->head->prev = node_move->prev;
	node_move->next = dest->head;
	if (dest->nbr_n > 0)
	{
		dest->head->prev = node_move; // update le prev de l'ancien sommet
	}
	node_move->prev = NULL; // node_move devient le nouveau sommet son prev doit etre NULL
	dest->head = node_move;
	dest->nbr_n++;
}
// PUSH PA
void	push_pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}
// PUSH PB
void	push_pb(t_stack *stack_b, t_stack *stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}