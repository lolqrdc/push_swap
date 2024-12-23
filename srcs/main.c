/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:49:35 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/18 17:44:14 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	int		nbr_args;
	char	**args;
	t_stack	*a;
	t_stack	*b;
	int		i;

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
	free_stack(&a);
	free_stack(&b);
}
void	print_stack(t_stack *a)
{
	t_node	*current;
	
	current = a->head;
	while (current)
	{
		ft_printf("%d\n", current->element);
		current = current->next;
	}
	ft_printf("\n");
}
/*void	print_array(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d\n", arr[i]);
	printf("\n");
}*/
