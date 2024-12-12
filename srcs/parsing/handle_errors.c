/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:18:05 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/12 13:48:07 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_synthax(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != NULL)
	{
		j = 0;
		if (str[i][j] == '+' || str[i][j] == '-')
			j++;
		if (!str[i][j])
			return (FAILURE);
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_overflow(char *str)
{
	long	result;
	long	sign;
	int		i;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		result = result * 10 + (str[i] - '0');
		if ((result * sign > INT_MAX || result * sign < INT_MIN))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_duplicate(int argc, char **argv)
{
	long	nbr1;
	long	nbr2;
	int		i;
	int		j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			nbr1 = ft_atoi(argv[i]);
			nbr2 = ft_atoi(argv[j]);
			if (nbr1 == nbr2)
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	write_error(int argc, char **argv)
{
	char	**str;
	int		num;
	int		i;
	int		j;

	i = 1;
	if (check_duplicate(argc, argv) == FAILURE)
		return (ft_putstr_fd("Error\n", 2), FAILURE);
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		j = 0;
		while (str[j])
		{
			if ((check_overflow(str[j]) == 1) || (check_synthax(str) == 1))
				return (ft_putstr_fd("Error\n", 2), FAILURE);
			num = ft_atoi(str[j]);
			if (num > INT_MAX || num < INT_MIN)
				return (ft_putstr_fd("Error\n", 2), FAILURE);
			j++;
		}
		i++;
		free(str);
	}
	return (SUCCESS);
}
