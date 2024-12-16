/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:49:35 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/16 14:20:59 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	int		nbr_args;
	char	**args;
	int		i;

	nbr_args = 0;
	args = str_arg(argc, argv);
	if (args == NULL || !args)
		return (free(args), ft_putstr_fd("Error\n", 2), FAILURE);
	while (args[nbr_args] != NULL)
		nbr_args++;
	if (valid_args(args, nbr_args) == FAILURE)
		return (free(args), FAILURE);
	i = 0;
	while (i < nbr_args)
	{
		printf("Argument %d: %s\n", i + 1, args[i]);
		i++;
	}
	return (SUCCESS);
}
