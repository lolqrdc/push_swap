/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:49:35 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/09 17:49:22 by loribeir         ###   ########.fr       */
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
	ft_printf("Etat initial:\n");
	print_stack(a);
	print_stack(b);
	ft_printf("Etat apres transfert:\n");
	transfert_chunk(a, b);
	print_stack(a);
	print_stack(b);
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
		ft_printf("%d, ", current->element);
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

