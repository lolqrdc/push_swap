/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:39:06 by lolq              #+#    #+#             */
/*   Updated: 2024/12/04 10:00:16 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char  **argv)
{
    int i;

    i = 0;
    if (argc < 2)
    {
        ft_printf("Veuillez entrer au moins un argument\n");
        return (1);
    }
    while (i < argc)
    {
        if (syntax_error(&argv[i]))
            continue;
        //if (overflow_error(argv[i]))
        //    continue;
    }
    return (0);
}