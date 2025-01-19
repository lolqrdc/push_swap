/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:39:26 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/19 16:23:29 by loribeir         ###   ########.fr       */
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

typedef struct s_chunk
{
	int start;
	int end;
	int chunk_size;
	
}	t_chunk;

/* CONSTRUCT: */
int main (int argc, char **argv);
//
t_stack *init_stack(int argc, char **argv);
t_node  *add_node(int element);
void    link_nodes(t_node *current, t_node *node);
void	print_stack(t_stack *stack);

/* ALGORITHM: chunk sort. */
// stack <= 5.
void    small_sorting(t_stack *a, t_stack *b);
void    sorting_2(t_stack *a);
void    sorting_3(t_stack *a);
void    sorting_5(t_stack *a, t_stack *b);
// stack > 5.

// utils functions.
int 	ft_find_max(t_stack *stack);
int		ft_find_min(t_stack *stack);
int		ft_find_pos(t_stack *stack, int value);
void    push_min_to_b(t_stack *a, t_stack *b);
void    sort_to_merge(t_stack *a, t_stack *b);

// PARSING: check args, write error, and free.
bool    valid_input(int ac, char **arg);
bool    single_arg(char *arg);
bool 	check_syntax(const char *arg);
bool 	check_overflow(char *arg);
bool    check_doublon(int ac, char **arg);
//
void    exit_error(t_stack *a, t_stack *b, int i);
void    free_split(char **split);
void    free_stack(t_stack **stack);

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