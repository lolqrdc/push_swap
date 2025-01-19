/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:17:14 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/19 15:18:54 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

int main (int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    
    a = init_stack(argc, argv);
    b = malloc(sizeof(t_stack));
    if (!valid_input(argc, argv))
        exit_error(NULL, NULL, 1);
    if (!a)
        exit_error(a, NULL, 1);
    if (!b)
        exit_error(NULL, b, 1);
    b->nbr_n = 0;
    b->head = NULL;
    if (a->nbr_n <= 5)
        small_sorting(a, b);
    free_stack(&a);
    free_stack(&b);
    return (0);   
}
