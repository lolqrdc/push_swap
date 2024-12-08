/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:18:05 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/08 16:49:20 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	synthax_error(int argc, char **argv)
{
	int	i;
	int	j;
	long num;
	
	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (!argv[i][j])
			return(FAILURE);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (FAILURE);
			j++;
		}
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
int	duplicate_error(t_stack *stack_a)
{
	t_node	*current;
	t_node	*check_next;
	
	current = stack_a->head;
	while (current != NULL)
	{
		check_next = current->next;
		while (check_next != NULL)
		{
			if (current->element == check_next->element)
				return (FAILURE);
			check_next = check_next->next;
		}
		current = current->next;
	}
	return (SUCCESS);
}
int	overflow_error(char *str)
{
	long	result;
	long	sign;
	int		i;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		result = result * 10 + str[i] - '0';
		if ((result * sign > INT_MAX || result * sign < INT_MIN))
			return (FAILURE);
		i++;
	}
	return (result * sign);
}
