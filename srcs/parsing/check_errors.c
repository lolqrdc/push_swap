/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:02:06 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/16 16:02:11 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_synthax(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] == ' ')
		i++;
	if (arg[i] == '\0')
		return (false);
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	check_overflow(char *str)
{
	long	result;
	long	sign;
	int		i;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		result = (result * 10) + (str[i] - '0');
		if ((result * sign > INT_MAX || result * sign < INT_MIN))
			return (false);
		i++;
	}
	return (true);
}

bool	check_duplicates(int argc, char **argv)
{
	long	nbr1;
	long	nbr2;
	int		j;
	int		i;

	i = 0;
	while (i < argc)
	{
		nbr1 = ft_atoi(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			nbr2 = ft_atoi(argv[j]);
			if (nbr1 == nbr2)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
