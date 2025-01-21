/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:03:27 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/21 17:56:15 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_stack *b, t_stack *a)
{
	int	max_pos;
	int	middle;
	int	max;

	while (b->head)
	{
		max = ft_find_max(b);
		if (b->head->element == max)
		{
			push_pa(a, b);
				continue ;
			if (a->head->next && a->head->element > a->head->next->element)
				swap_sa(a);
		}
		else
		{
			max_pos = ft_find_pos(b, max);
			middle = b->nbr_n / 2;
			if (max_pos <= middle)
				rotate_rb(b);
			else
				reverse_rrb(b);
		}
	}
	while (!is_sorted(a) && a->nbr_n > 0)
		rotate_ra(a);
}

bool	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current && current->next)
	{
		if (current->element > current->next->element)
			return (false);
		current = current->next;
	}
	return (true);
}

/*int	optimize_b(t_stack *b, int max)
{
	int		max_pos;
	int		middle;

	max_pos = ft_find_pos(b, max);
	middle = b->nbr_n / 2;
	if (max_pos <= middle)
	{
		while (b->head->element != max)
			rotate_rb(b);
	}
	else
	{
		while (b->head->element != max)
			reverse_rrb(b);
	}
	return (0);
}*/

