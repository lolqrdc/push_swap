/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:49:21 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/18 08:19:08 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Handle the case of only 2 number.
void	sort_two(t_stack *a)
{
	if (a->head->element > a->head->next->element)
		swap_sa(a);
}

// Handle the case of only 3 number.
void	sort_three(t_stack *a)
{
	int	first;
	int	third;
	int	second;

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
