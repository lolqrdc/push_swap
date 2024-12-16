/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:49:35 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/16 17:40:33 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_node	*current;
	char	**args;
	
	stack_a = NULL;
	stack_b = NULL;
	init_stacks(stack_a, stack_b);
	args = str_arg(argc, argv);
	if (args == NULL || !args)
		return (free_all(stack_a, stack_b), free(args), ft_putstr_fd("Error\n", 2), FAILURE);
	if (valid_args(args, argc) == FAILURE)
		return (free(args), free_all(stack_a, stack_b), FAILURE);
	build_stack_a(stack_a, args);
	current = stack_a->head;
	printf("Stack A:\n");
	while (current != NULL)
	{
		printf("%d\n", current->element);
		current = current->next;
	}
	free_stack(stack_a);
	return (SUCCESS);
}

/*int	main(int argc, char **argv)
{
	int		nbr_args;
	char	**args;
	int		i;

	nbr_args = 0;
	args = str_arg(argc, argv);
	if (args == NULL || !args)
		return (free(args), ft_putstr_fd("Error\n", 2), FAILURE);
	while (args[nbr_args] != NULL)
		nbr_args++;
	if (valid_args(args, nbr_args) == FAILURE)
		return (free(args), FAILURE);
	i = 0;
	while (i < nbr_args)
	{
		printf("Argument %d: %s\n", i + 1, args[i]);
		i++;
	}
	return (SUCCESS);
}*/
