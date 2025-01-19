/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:32:51 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/19 15:56:10 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    small_sorting(t_stack *a, t_stack *b)
{
    if (a->nbr_n == 2)
        sorting_2(a);
    else if (a->nbr_n == 3)
        sorting_3(a);
    else
        sorting_5(a, b);
}
void    sorting_2(t_stack *a)
{
    if (a->head->element > a->head->next->element)
        swap_sa(a);
}
void    sorting_3(t_stack *a)
{
    int first;
    int second;
    int third;
    
    first = a->head->element;
    second = a->head->next->element;
    third = a->head->next->next->element;
    if (first > second && second > third)
	{
		swap_sa(a);
		reverse_rra(a);
	}
	else if (first > second && third > first)
		swap_sa(a);
	else if (first > third && second > third)
		reverse_rra(a);
	else if (first > third && third > second)
		rotate_ra(a);
	else if (second > first && second > third)
	{
		swap_sa(a);
		rotate_ra(a);
	}
}
void    sorting_5(t_stack *a, t_stack *b)
{
    if (!a || !b)
        return ;
    push_min_to_b(a, b);
    sort_to_merge(a, b);
}