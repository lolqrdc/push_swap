/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:17:14 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/19 19:56:13 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

int main (int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    
    if (!valid_input(argc, argv))
        exit_error(NULL, NULL, 1);
    a = init_stack(argc, argv);
    if (!a)
        exit_error(a, NULL, 1);
    b = malloc(sizeof(t_stack));
    if (!b)
        exit_error(NULL, b, 1);
    b->nbr_n = 0;
    b->head = NULL;
    if (a->nbr_n <= 5)
        small_sorting(a, b);
    else
        chunk_push(a, b);
    printf("Pile A apres tri :\n");
    print_stack(a);
    printf("Pile B apres le tri:\n");
    print_stack(b);
    free_stack(&a);
    free_stack(&b);
    return (0);   
}
