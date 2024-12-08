/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:46:05 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/08 17:12:24 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_stack(t_stack *stack_a)
{
	stack_a->head = NULL;
	stack_a->nbr_n = 0;

	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	return (stack_a);
}
