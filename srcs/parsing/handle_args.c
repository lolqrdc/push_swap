/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:42:08 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/16 15:40:23 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**str_arg(int argc, char **argv)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (NULL);
		return (args);
	}
	return (argv + 1);
}

int	valid_args(char **args, int nbr_args)
{
	int	i;

	i = 0;
	while (i < nbr_args)
	{
		if (check_synthax(args[i]) == 1)
			return (ft_putstr_fd("Error\n", 2), 1);
		if (check_overflow(args[i]) == 1)
			return (ft_putstr_fd("Error\n", 2), 1);
		i++;
	}
	if (check_duplicates(nbr_args, args) == 1)
		return (ft_putstr_fd("Error\n", 2), 1);
	return (0);
}

int	check_arg(char **args, int nbr_args)
{
	if (nbr_args < 2)
		return (ft_putstr_fd("Error\n", 2), 1);
	return (valid_args(args, nbr_args));
}
