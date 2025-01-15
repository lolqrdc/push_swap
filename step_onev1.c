/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_onev1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:35:51 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/15 15:46:08 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_chunk	*init_chunk(t_stack *a)
{
	t_chunk *chunk;

	chunk = malloc(sizeof(t_chunk));
	if (!chunk)
		return (NULL);
	if (a->nbr_n <= 10)
        chunk->n = 5;
    else if (a->nbr_n <= 150)
        chunk->n = 10;
	else
		chunk->n = 18;
	chunk->reference = sorted_reference(a);
	chunk->stack_size = a->nbr_n;
	chunk->mid = (chunk->stack_size / 2);
	chunk->min_value = chunk->reference[0];
	chunk->max_value = chunk->reference[chunk->stack_size - 1];
	return (chunk);
}

void	transfert_chunk(t_chunk *chunk, t_stack *a, t_stack *b)
{
	t_node *node;

	if (!chunk)
		return;
	while (a->nbr_n > 3)
	{
		node = a->head;
		printf("Current values: min=%d, max=%d\n", chunk->min_value, chunk->max_value);
		printf("Top of stack A: %d\n", node->element);
		if (node->element >= chunk->min_value && node->element <= chunk->max_value)
		{
			push_pb(b, a);
			printf("Pushed to B: %d\n", b->head->element);
			if (b->head && b->head->element < chunk->mid)
				rotate_rb(b);
		}
		else
		{
			rotate_ra(a);
			printf("Rotated A: %d\n", a->head->element);
		}
		update_chunk(chunk);

	}
}
void update_chunk(t_chunk *chunk)
{
	int range;

	range = (chunk->max_value - chunk->min_value) / chunk->n;
	chunk->min_value += range;
	chunk->max_value += range;
	if (chunk->max_value > chunk->reference[chunk->stack_size - 1])
		chunk->max_value = chunk->reference[chunk->stack_size - 1];
}
