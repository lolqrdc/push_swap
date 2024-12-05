/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:33:51 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/05 11:58:40 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	syntax_error(char **arg) // function to check if there is a letter.
{
	int	i;
	
	i = 0;
	if (!arg || !**arg)
		return (0);
	if (*arg[i] == '-' || *arg[i] == '+')
		i++;
	while (*arg[i] == 32)
		i++;
	while (*arg[i])
	{
		if (!ft_isdigit(*arg[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}
int	duplicate_error(t_stack *stack_a) // function to check if there is a duplicate number.
{
	t_node *cmp;
	t_node *index;

	if (stack_a == NULL ||stack_a-> top == NULL)
		return (0);
	cmp = stack_a->top;
	while (cmp != NULL)
	{
		index = cmp->next;
		while (index != NULL)
		{
			if (index->data == cmp->data)
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			}
			index = index->next;
		}
		cmp = cmp->next;
	}
	return (0);	
}