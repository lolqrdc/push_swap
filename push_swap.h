/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:46:40 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/03 11:26:06 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include 

// base struct
typedef struct s_node
{
	int	data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// stack struct
typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
} t_stack;

// instruction functions
void swap_sa(t_stack *stack_a);
void swap_sb(t_stack *stack_b);

// handle errors
// algorithm functions

#endif