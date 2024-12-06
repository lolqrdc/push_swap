/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:57:18 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/06 16:14:42 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack *src, t_stack *dest)
{
	t_node *to_move_n;
	
	if (src->nbr_n == 0)
		return;
}
void	push_pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}
void	push_pb(t_stack *stack_b, t_stack *stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}