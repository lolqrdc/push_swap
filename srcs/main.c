/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:49:46 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/12 08:08:56 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**str;
	int		num;
	int		i;
	int		j;
	
	i = 1;
	stack_a = init_stack();
	if (!stack_a)
		return (ft_putstr_fd("Error\n", 2), FAILURE);
	if (write_error(argc, argv) == FAILURE)
	{
		free_stack(stack_a);
		return(FAILURE);
	}
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		j = 0;
		while (str[j])
		{
			num = ft_atoi(str[j]);
			if (add_to_stack(stack_a, num) == FAILURE)
			{
				free_stack(stack_a);
				return (FAILURE);
			}
			j++;
		}
		i++;
	}
	ft_printf("stack A:\n");
	print_stack(stack_a);
	free_stack(stack_a);
	return (SUCCESS);
}

