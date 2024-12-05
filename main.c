/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:39:06 by lolq              #+#    #+#             */
/*   Updated: 2024/12/05 11:11:20 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char  **argv)
{
	t_stack	*stack_a;
	int		i;
	
	if (argc < 2)
		ft_printf("Entrer a minima deux arguments\n", 2);
	
	while (argv[i])
	{
		if (syntax_error(&argv[i]))
			return (1);
	}
	
}