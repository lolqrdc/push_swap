/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:49:46 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/06 16:59:47 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_a = malloc(sizeof(t_stack));
	t_stack	*stack_b = malloc(sizeof(t_stack));
	
	if (!stack_a || !stack_b)
	{
		ft_printf("Erreur d'allocation memoire.\n");
		return 1;
	}
	stack_a->head = NULL;
	stack_a->nbr_n = 0;
	stack_b->head = NULL;
	stack_b->nbr_n = 0;

	free(stack_a);
	free(stack_b);
	return (0);
}