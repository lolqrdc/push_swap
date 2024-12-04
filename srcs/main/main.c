/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:39:06 by lolq              #+#    #+#             */
/*   Updated: 2024/12/04 12:00:29 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char  **argv)
{
    int i;

    i = 1;
    if (argc < 2)
    {
        ft_printf("Veuillez entrer au moins un argument\n");
        return (1);
    }
    while (i < argc)
    {
        if (syntax_error(&argv[i]))
		{
			return (1);
		}
		else 
		{
			ft_printf("L'argument est valide\n", i);
		}
		i++;
    }
    return (0);
}