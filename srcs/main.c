/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:49:35 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/15 18:10:26 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	int	i;
	
	i = 1;
	if (valid_args(argv, argc) == FAILURE)
		return (FAILURE);
	while (i < argc)
	{	
		printf("Argument %d: %s\n", i, argv[i]);
		i++;
	}
	return (SUCCESS);
}
