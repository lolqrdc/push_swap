/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_reference.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:11:46 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/18 17:44:28 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*int		*sorted_reference(t_stack *a)
{
	t_node	*node;
	int		size;
	int		*tab;
	int		i;

	i = 0;
	node = a->head;
	size = a->nbr_n;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	while (i < size)
	{
		tab[i] = (node->element);
		node = node->next;
		i++;
	}
	quick_sort(tab, 0, size - 1);
	return (tab);
}
void	quick_sort(int *array, int lower, int upper)
{
	int	pivot;

	if (lower < upper)
	{
		pivot = partitions(array, lower, upper);
		quick_sort(array, lower, pivot - 1);
		quick_sort(array, pivot + 1, upper);
	}
}
int	partitions(int *array, int lower, int upper)
{
	int	pivot;
	int	temp;
	int	i;
	int	j;

	pivot = array[upper];
	i = lower - 1;
	j = lower;
	while (j < upper)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[upper];
	array[upper] = temp;
	return (i + 1);
}*/

/*
PLAN FOR THE ALGO:
1 : Create a sorted array of stack A's elements with an quick sort algo.

2 : Create an struct for chunk contain:
	- n (a constant helping the calc of the chunk size)
	- mid (the middle of the sorted array)
	- size (the size of a chunk)
	- start (the begin of the range that will be pushed, it is an index in the array)
	- end (the end of the range that will be pushed, it is an index in the array)

3 : Create a function that will transfer from stack A to stack B, starting from
	'start' index to the 'end' index of the reference array. When the whole chunk
	is moved, update indexes 'start' and 'end'.
		* check if the nb is in the chunk start-end, if yes push to B. 
		* check if the nb is upper or lower of the mid, if lower rotate (rb).
		else, rotate of A (ra).
		* when all nb from a chunk is pushed, update the indexes.

4 : Optimize point to think about: 
		- rather than updating start and end after reading a whole chunk, update one by one. 
		- rather than handle 'n' and 'mid' in memory, directly add the calc when necessary.
*/
