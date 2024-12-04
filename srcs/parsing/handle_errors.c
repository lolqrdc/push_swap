/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:33:51 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/04 09:59:18 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	syntax_error(char **arg)
{
	int	i;
	
	i = 0;
	if (!arg || !**arg)
		return (1);
	if (*arg[i] == '-' || *arg[i] == '+')
		i++;
	while (*arg[i] == 32)
	{
		i++;
	}
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
/*int	overflow_error(const char *nptr)
{
	long nbr;
	int	sign;
	int	i;
	
	sign = 1;
	i = 0;
	nbr = 0;
	while((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nbr = nbr * 10 + (nptr[i] - '0');
		if (sign == 1 && nbr > INT_MAX || sign == -1 && -nbr < INT_MIN)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		i++;
	}
	return(0);
}*/