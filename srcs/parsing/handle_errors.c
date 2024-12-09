/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:18:05 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/09 15:23:33 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_synthax(int argc, char **argv)
{
	int	i;
	int	j;
	
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
		i++;
	}
	return (SUCCESS);
}
int	check_duplicate(t_stack *stack_a)
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
int	check_overflow(char *str)
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
		result = result * 10 + (str[i] - '0');
		if ((result * sign > INT_MAX || result * sign < INT_MIN))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
int	write_error(int argc, char **argv)
{
	t_stack *stack_a;
	int		num;
	int		i;
	
	i = 1;
	stack_a = init_stack();
	if (!stack_a)
		return (ft_putstr_fd("Error\n", 2), FAILURE);
	if (check_synthax(argc, argv) == FAILURE)
		return (ft_putstr_fd("Error\n", 2), FAILURE);
	while (i < argc)
	{
		if (check_overflow(argv[i]) == FAILURE)
			return (ft_putstr_fd("Error\n", 2), FAILURE);
		num = ft_atoi(argv[i]);
		if (add_to_stack(stack_a, num))
		{
			free_stack(stack_a);
			return(ft_putstr_fd("Error\n", 2), FAILURE);
		}
		i++;
	}
	if (check_duplicate(stack_a) == FAILURE)
		return (ft_putstr_fd("Error\n", 2), FAILURE);
	return (SUCCESS);
}
