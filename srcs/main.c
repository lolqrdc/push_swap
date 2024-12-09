/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:49:46 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/09 15:17:11 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	
	stack_a = init_stack();
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (FAILURE);
	}
	if (write_error(argc, argv) == FAILURE)
		return (FAILURE);
	printf("stack A:\n");
		print_stack(stack_a);
	
	if (!stack_a)
		return(ft_putstr_fd("Error\n", 2), FAILURE);
	free(stack_a);
	return (SUCCESS);
}
void	print_stack(t_stack *stack)
{
	t_node *current = stack->head;

    if (!current)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack contents: ");
    while (current)
    {
        printf("%d", current->element);
        current = current->next;
    }
    printf("\n");
}
