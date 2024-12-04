/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:33:51 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/04 18:32:07 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	syntax_error(char **arg)
{
	int	i;
	
	i = 0;
	if (!arg || !**arg)
		return (1);
	if (*arg[i] == '-' || *arg[i] == '+')
		i++;
	while (*arg[i] == 32)
		i++;
	while (*arg[i])
	{
		if (!ft_isdigit(*arg[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
int	duplicate_error(t_stack *stack_a)
{
	if (!stack_a)
		return (1);
	while (stack_a)
	{
		if (stack_a ==)
	}
}