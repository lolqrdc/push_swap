/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:35:43 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/09 18:23:45 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	write_error(int	argc, char **argv)
{
	t_stack	*stack_a;
	int		num;
	int		i;
	
	i = 1;
	stack_a = init_stack();
	if (!stack_a)
		return(ft_putstr_fd("Error\n", 2), FAILURE);
	if (check_duplicate(argc, argv) == FAILURE)
		return(ft_putstr_fd("Error\n", 2), FAILURE);
	while (i < argc)
	{
		if ((check_overflow(argv[i]) == FAILURE) || (check_synthax(argc, argv) == FAILURE))
		{
			ft_putstr_fd("Error\n", 2);
			return (FAILURE);
		}
		num = ft_atoi(argv[i]);
		if (add_to_stack(stack_a, num) == FAILURE)
			return(ft_putstr_fd("Error\n", 2), FAILURE);
		i++;
	}
	return (SUCCESS);
}