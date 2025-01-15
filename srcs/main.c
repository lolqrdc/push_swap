/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:49:35 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/15 17:01:12 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	int		nbr_args;
	char	**args;
	int		i;
	t_stack	*a;
	t_stack	*b;
	
	nbr_args = 0;
	i = 0;
	a = init_stack();
	b = init_stack();
	args = str_arg(argc, argv); // change single string to multiple args.
	if (args == NULL || !args)
		return (free(a), free(b), free(args), ft_putstr_fd("Error\n", 2), FAILURE);
	while (args[nbr_args] != NULL) // keep count of args.
		nbr_args++;
	if (valid_args(args, nbr_args) == FAILURE) // checking if args are valid.
		return (free(a), free(b), free(args), FAILURE);
	build_stack(a, args, nbr_args);
	ft_printf("Etat initial de A:\n");
	print_stack(a);
	/*int *arr = sorted_reference(a);
	if (arr)
	{
		ft_printf("Returned array by sorted_reference:\n");
		for (int i = 0; i < a->nbr_n; i++)
			ft_printf("%d ", arr[i]);
		ft_printf("\n");
	}*/
	ft_printf("Transfert A vers B:\n");
	transfert_chunk(a, b);
	ft_printf("Etat stack B:\n");
	print_stack(b);
	ft_printf("Transfert back:\n");
	transfert_back(b, a);
	print_stack(a);
	free_stack(&a);
	free_stack(&b);
	free(args);
	return (SUCCESS);
}

void	print_stack(t_stack *stack)
{
	t_node	*current;
	
	current = stack->head;
	if (!current)
		return;
	while (current)
	{
		ft_printf("%d ", current->element);
		current = current->next;
	}
	ft_printf("\n");
}

