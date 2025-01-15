	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reference.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:11:46 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/02 12:20:44 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Reference: Create a sorted array to use it as reference for chunks.
int	*sorted_reference(t_stack *a)
{
	t_node	*current;
	int		*sorted;
	int		size;
	int		i;
	
	size = a->nbr_n;
	current = a->head;
	i = 0;
	sorted = malloc(sizeof(int)*size);
	if (!sorted)
		return(free(sorted), NULL);
	while (current)
	{
		sorted[i] = current->element;
		current = current->next;
		i++;
	}
	/*printf("Avant tri: ");
	for (int j = 0; j < size; j++)
	{
		printf("%d, ", sorted[j]);
	}
	printf("\n");
	quicksort(sorted, 0, size - 1);
	printf("Apres tri: ");
	for (int j = 0; j < size; j++)
	{
		printf("%d, ", sorted[j]);
	}
	printf("\n");*/
	//free(sorted);
	return (sorted);
}

// Quicksort: algorithm choosed to sort the reference.
void	quicksort(int *array, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[(low + high) / 2];
	i = low;
	j = high;
	while (i <= j)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i <= j)
		{
			arr_swap(&array[i], &array[j]);
			i++;
			j--;
		}
	}
	if (low < j)
		quicksort(array, low, j);
	if (i < high)
		quicksort(array, i, high);
}

// Util: a swap function for the quicksort.
void	arr_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
