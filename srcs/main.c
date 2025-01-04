/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:49:35 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/04 11:24:34 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	int		*sorted_ref;
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
}

// Utils function to check step of the program:
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
void	print_sorted_reference(int *sorted_ref, int size)
{
	int	i = 0;
	while (i < size)
	{
		ft_printf("%d ", sorted_ref[i]);
		i++;
	}
	ft_printf("\n");
}

