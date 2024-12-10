/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:49:46 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/10 18:51:59 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	char	**numbers;
	t_stack	*stack_a;
	int		num;
	int		i;

	num = 0;
	i = 1;
	numbers = handle_str(argc, argv);
	if (!numbers)
		return (ft_putstr_fd("Error\n", 2), FAILURE);
	stack_a = init_stack();
	if (!stack_a)
	{
		free(numbers);
		return(ft_putstr_fd("Error\n", 2), FAILURE);
	}
	if (argc < 2)
	{
		free(numbers);
		free_stack(stack_a);
		ft_putstr_fd("Error\n", 2);
		return (FAILURE);
	}
	if (write_error(count_split_elements(numbers), numbers) == FAILURE)
	{
		free(numbers);
		free_stack(stack_a);
		return (FAILURE);
	}
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (add_to_stack(stack_a, num) == FAILURE)
		{
			free(numbers);
			free_stack(stack_a);
			return (ft_putstr_fd("Error\n", 2), FAILURE);
		}
		i++;
	}
	printf("stack A:\n");
	print_stack(stack_a);
	free_stack(stack_a);
	return (SUCCESS);
}
/*char	**handle_str(int argc, char **argv)
{
	char	**str;
	int		i;

	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		if (!str)
			return (NULL);
	}
	else
	{
		str = malloc(sizeof(char *) * argc);
		if (!str)
			return (NULL);
	}
	i = 1;
	while (i < argc)
	{
		str[i - 1] = ft_strdup(argv[i]);
		if (!str[i - 1])
		{
			while (--i > 0)
				free(str[i - 1]);
			free (str);
			return (NULL);
		}
		i++;
	}
	str[argc - 1] = NULL;
	return (str);
}*/