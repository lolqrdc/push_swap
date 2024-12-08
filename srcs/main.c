/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:49:46 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/09 18:41:35 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = init_stack();
	if (!stack_a)
		return(ft_putstr_fd("Error\n", 2), FAILURE);
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (FAILURE);
	}
	if (write_error(argc, argv) == FAILURE)
	{
		free_stack(stack_a);
		return (FAILURE);
	}
	printf("stack A:\n");
	print_stack(stack_a);
	free_stack(stack_a);
	return (SUCCESS);
}
