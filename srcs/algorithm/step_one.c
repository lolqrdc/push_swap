/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:33:12 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/24 08:09:02 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_push(t_stack *a, t_stack *b)
{
	t_chunk	chunk;
	int		chunk_n;
	int		count;
	int		min;
	int		max;

	chunk_n = 0;
	count = 0;
	chunk = handle_chunk(a);
	min = ft_find_min(a);
	max = ft_find_max(a);
	while (a->head)
	{
		chunk.start = min + chunk_n * chunk.chunk_size;
		chunk.end = min + (chunk_n + 1) * chunk.chunk_size;
		if (chunk.end > max + 1)
			chunk.end = max + 1;
		if (count_element_chunk(a, chunk.start, chunk.end) == 0)
		{
			chunk_n++;
			continue ;
		}
		handle_element(a, b, &chunk, &count);
	}
}

t_chunk	handle_chunk(t_stack *a)
{
	t_chunk	chunk;
	int		range;
	int		min;
	int		max;

	min = ft_find_min(a);
	max = ft_find_max(a);
	range = max - min + 1;
	if (a->nbr_n <= 50)
		chunk.chunk_size = 10;
	else if (a->nbr_n <= 100)
		chunk.chunk_size = 20;
	else if (a->nbr_n <= 500)
		chunk.chunk_size = 50;
	chunk.start = min;
	chunk.end = min + (range * chunk.chunk_size / a->nbr_n);
	return (chunk);
}

void	handle_element(t_stack *a, t_stack *b, t_chunk *chunk, int *count)
{
	int	element;
	int	pos;

	if (!a->head)
		return ;
	element = a->head->element;
	if (element >= chunk->start && element < chunk->end)
	{
		push_pb(b, a);
		(*count)++;
		if (b->head)
		{
			if (b->head->element < (chunk->start + chunk->chunk_size / 2))
				rotate_rb(b);
		}
	}
	else
	{
		pos = find_element_pos(a, chunk->start, chunk->end);
		if (pos > a->nbr_n / 2)
			reverse_rra(a);
		else
			rotate_ra(a);
	}
}

int	find_element_pos(t_stack *stack, int start, int end)
{
	t_node	*current;
	int		pos;

	pos = 0;
	current = stack->head;
	while (current)
	{
		if (current->element >= start && current->element < end)
			return (pos);
		pos++;
		current = current->next;
	}
	return (-1);
}

int	count_element_chunk(t_stack *stack, int start, int end)
{
	t_node	*current;
	int		count;

	if (!stack || !stack->head)
		return (0);
	count = 0;
	current = stack->head;
	while (current)
	{
		if (current->element >= start && current->element < end)
			count++;
		current = current->next;
	}
	return (count);
}
