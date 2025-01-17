/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:39:26 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/17 22:23:53 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// MY LIBRARY
# include "../libft/include/libft.h" 
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"\

// LIBRAIRIES
# include <unistd.h>
# include <stdlib.h> 
# include <limits.h>
# include <stdbool.h>
# include <ctype.h>

typedef struct s_node
{
	int				element;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		nbr_n;
}	t_stack;


// PARSING: error handling, check args and free.
bool	check_duplicates(t_stack *a);
bool    is_sorted(t_stack *a);
bool	check_syntax(const char *arg);
bool 	check_range(const char *arg);
bool 	is_it_valid(int argc, char **argv, t_stack *a);
void    exit_error(t_stack *a, t_stack *b, int i);
void    free_stack(t_stack **stack);

// BUILDING: initialize the stack & chunks.


// INSTRUCTION: swap, push, rotate, reverse.
void	swap(t_stack *stack);
void	swap_sa(t_stack *stack_a);
void	swap_sb(t_stack *stack_b);
void	swap_ss(t_stack *stack_a, t_stack *stack_b);
//
void	push(t_stack *src, t_stack *dest);
void	push_pa(t_stack *stack_a, t_stack *stack_b);
void	push_pb(t_stack *stack_b, t_stack *stack_a);
//
void	rotate(t_stack *stack);
void	rotate_ra(t_stack *stack_a);
void	rotate_rb(t_stack *stack_b);
void	rotate_rr(t_stack *stack_a, t_stack *stack_b);
//
void	reverse(t_stack *stack_a);
void	reverse_rra(t_stack *stack_a);
void	reverse_rrb(t_stack *stack_b);
void	reverse_rrr(t_stack *stack_a, t_stack *stack_b);

# endif