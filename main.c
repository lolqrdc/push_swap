/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:16:07 by lolq              #+#    #+#             */
/*   Updated: 2025/01/17 21:47:45 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    
    a = init_stack();
    if (!a || !is_it_valid(argc, argv, a))
        exit_error(a, NULL, 1);
    if (!check_duplicates(a) || !is_sorted(a))
        exit_error(a, NULL, 1);
    b = init_stack();
    if (!b)
        exit_error(a, b, 1);
}