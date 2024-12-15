/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:49:35 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/15 18:49:48 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	int		nbr_args;
	char	**args;
	int		i;
	
	i = 0;
	nbr_args = 0;
	args = str_arg(argc, argv);
	if (args == NULL || !args)
		return(free(args), ft_putstr_fd("Error\n", 2), FAILURE);
	while (args[nbr_args] != NULL)
		nbr_args++;
	if (valid_args(args, nbr_args) == FAILURE)
		return(free(args), FAILURE);
	while (i < nbr_args)
	{
		printf("Argument %d: %s\n", i + 1, args[i]);
		i++;
	}
	free(args);
	return (SUCCESS);
}
/*int main(int argc, char **argv)
{
	int		nbr_args;
	char	**args;
	int		i;

	i = 0;
	nbr_args = 0;
	args = str_arg(argc, argv);
	if (!args)
		return(ft_putstr_fd("Error\n", 2), FAILURE);
	while(args[nbr_args] != NULL) 
		nbr_args++;
	if (valid_args(args, nbr_args) == FAILURE)
		return (FAILURE);
	while (i < nbr_args)
	{	
		printf("Argument %d: %s\n", i + 1, args[i]);
		i++;
	}
	return (SUCCESS);
}*/
