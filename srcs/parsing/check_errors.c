/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:02:06 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/15 18:07:40 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Check if the string is a valid number.
int check_synthax(char *arg)
{
	int	i;
	
	i = 0;
	while (arg[i] == ' ')
		i++;
	if (arg[i] == '\0')
		return (FAILURE);
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

// Check if the number is between the min & max of a int. 
int	check_overflow(char *str)
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
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

// Check for duplicate.
int	check_duplicates(int argc, char **argv)
{
	long	nbr1;
	long	nbr2;
	int		i;
	int		j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		nbr1 = ft_atoi(argv[i]);
		while (j < argc)
		{
			nbr2 = ft_atoi(argv[j]);
			if (nbr1 == nbr2)
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
