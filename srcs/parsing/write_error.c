/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:35:43 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/10 11:46:15 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	write_error(int	argc, char **argv)
{
	int		num;
	int		i;
	
	i = 1;
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
		if (num > INT_MAX || num < INT_MIN)
			return(ft_putstr_fd("Error\n", 2), FAILURE);
		i++;
	}
	return (SUCCESS);
}