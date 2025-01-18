/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:57:19 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/18 22:20:18 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    
    b = NULL;
    if (!valid_input(argc, argv))
        exit_error(NULL, NULL, 1);
    a = init_stack(argc, argv);
    print_stack(a);
        exit_error(a, NULL, 0);
    return (0);
}
