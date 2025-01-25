/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:31:33 by lolq              #+#    #+#             */
/*   Updated: 2025/01/20 19:16:49 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*a;
	t_node	*node;
	int		i;

	i = 1;
	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->head = NULL;
	a->nbr_n = 0;
	while (i < argc)
	{
		node = add_node(ft_atoi(argv[i]));
		if (!node)
			return (free_stack(&a), NULL);
		if (a->head == NULL)
			a->head = node;
		else
			link_nodes(a->head, node);
		a->nbr_n++;
		i++;
	}
	return (a);
}

t_node	*add_node(int element)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->element = element;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	link_nodes(t_node *current, t_node *node)
{
	while (current->next)
		current = current->next;
	current->next = node;
	node->prev = current;
}
