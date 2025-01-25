/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:21:27 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/25 12:46:51 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (!valid_input(argc, argv))
		exit_error(NULL, NULL, 1);
	a = init_stack(argc, argv);
	if (!a)
		exit_error(a, NULL, 0);
	if (is_sorted(a))
		return (free_stack(&a), 0);
	b = malloc(sizeof(t_stack));
	if (!b)
		exit_error(NULL, b, 1);
	b->head = NULL;
	b->nbr_n = 0;
	sorting_stack(a, b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
