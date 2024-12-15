/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:42:08 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/15 18:33:52 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	return(argv + 1);
}
// Centralize all errors cases and write "Error\n".
int	valid_args(char **args, int nbr_args)
{
	int	i;
	
	i = 1;	
	while (i < nbr_args)
	{
		if (check_synthax(args[i]) == FAILURE)
			return(ft_putstr_fd("Error\n", 2), FAILURE);
		if (check_overflow(args[i]) == FAILURE)
			return(ft_putstr_fd("Error\n", 2), FAILURE);
		i++;
	}
	if (check_duplicates(nbr_args, args) == FAILURE)
		return(ft_putstr_fd("Error\n", 2), FAILURE);
	return(SUCCESS);
}

// Check if enough args and call valid_args.
int	check_arg(char **args, int nbr_args)
{
	if (nbr_args < 2)
		return (ft_putstr_fd("Error\n", 2), FAILURE);
	return (valid_args(args, nbr_args));
}
