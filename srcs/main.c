/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:49:46 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/10 12:12:18 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		num;
	int		i;

	i = 1;
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
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (add_to_stack(stack_a, num) == FAILURE)
		{
			free_stack(stack_a);
			return (ft_putstr_fd("Error\n", 2), FAILURE);
		}
		i++;
	}
	printf("stack A:\n");
	print_stack(stack_a);
	free_stack(stack_a);
	return (SUCCESS);
}
