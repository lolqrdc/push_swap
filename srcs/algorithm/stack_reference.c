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

int	sorted_reference(t_stack *a)
{
	t_node	*current;
	int		*sorted;
	int		size;
	int		i;
	
	size = a->nbr_n;
	current = a->head;
	i = 0;
	sorted = malloc(sizeof(t_node));
	if (!sorted)
		return (NULL);
	while (current)
	{
		sorted = current->element;
		current = current->next;
		i++;
	}
	quicksort(sorted, 0, size - 1);
	return (sorted);

}

void	quicksort(int *sorted, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	
	pivot = sorted[high];
	i = low;
	j = high;
	while (i < j)
	{
		
	}
}

void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


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
