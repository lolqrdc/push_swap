/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:28:26 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/06 15:34:06 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// fonction pour swap
void	swap(t_stack *stack)
{
	int	temp;
	if (stack == NULL || stack->nbr_n < 2)
		return;
	temp = stack->head->element;
	stack->head->element = stack->head->next->element;
	stack->head->next->element = temp;
}
// fonction swap a
void	swap_sa(t_stack *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}
// fonction swap b
void	swap_sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}
// fonction swap ss
void swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
