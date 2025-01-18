/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:57:19 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/18 15:27:25 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
    t_stack *a;
    
    if (!is_it_valid(argc, argv))
        exit_error(NULL, NULL, 1);
    a = init_stack(argc, argv);
    if (!a || (!check_duplicates(a)))
        exit_error(a, NULL, 1);
    if (is_sorted(a))
    {
        print_stack(a);
        exit_error(a, NULL, 0);
    }
    print_stack(a);
    return (0);
}
