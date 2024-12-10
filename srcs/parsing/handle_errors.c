/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:18:05 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/10 16:16:19 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_synthax(int argc, char **argv)
{
	int	i;
	int	j;
	
	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (!argv[i][j])
			return(FAILURE);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
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
int		check_duplicate(int argc, char **argv)
{
	int	i;
	int	j;
	
	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (compare_nbr(argv[j], argv[i]))
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
int		compare_nbr(char *s1, char *s2)
{
	int	nbr1;
	int	nbr2;
	
	nbr1 = ft_atoi(s1);
	nbr2 = ft_atoi(s2);
	return (nbr1 == nbr2);
}
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
