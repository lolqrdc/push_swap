/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:49:35 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/03 09:49:29 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	int		*sorted_arr;
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
	ft_printf("Stack A d'origine:\n");
	print_stack(a);
	sorted_arr = sorted_reference(a);
	if (sorted_arr)
	{
		print_sorted_arr(sorted_arr, a->nbr_n);
		free(sorted_arr);
	}
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
void	print_sorted_arr(int *arr, int size)
{
	int	i;

	i = 0;
	if (arr == NULL || arr <= 0)
	{
		ft_printf("Error: Tableau vide ou invalide.\n");
		return;
	}
	ft_printf("Sorted stack A:\n");
	while (i < size)
	{
		ft_printf("%d\n", arr[i]);
		i++;
	}
	ft_printf("\n");
}
