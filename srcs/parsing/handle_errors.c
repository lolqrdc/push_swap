/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:33:51 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/03 18:54:52 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	syntax_error(char *arg)
{
	int	i;
	
	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			ft_putstr_fd("Error\n", 2);
			return (0);
		i++;
	}
	return (1);
}
int	overflow_error(const char *nptr)
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
	while (nptr[i] >= INT_MIN && nptr[i] <= INT_MAX)
	{
		nbr = nbr * 10 + (nptr[i] - '0');
		i++;
	}
	return (1);
}