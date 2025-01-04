/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:39:26 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/04 12:18:15 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h" 
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include <unistd.h>
# include <stdlib.h> 
# include <limits.h>

# define FAILURE 1
# define SUCCESS 0

// STRUCT 1: each node contains.
typedef struct s_node
{
	int				element;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// STRUCT 2: number of noes.
typedef struct s_stack
{
	t_node	*head;
	int		nbr_n;
}	t_stack;

// STRUCT 3: each chunk contains.
typedef struct s_chunk
{
	int	n;
	int mid;
	int	size;
	int	start;
	int	end;
} t_chunk;

// PARSING: functions for handling error cases and valid input.
int		check_synthax(char *arg);
int		check_overflow(char *str);
int		check_duplicates(int argc, char **argv);
//
char	**str_arg(int argc, char **argv);
int		valid_args(char **args, int nbr_args);
int		check_arg(char **args, int nbr_args);

// BUILD: functions for constructing the stack.
t_stack	*init_stack(void);
void	add_to_stack(t_stack *a, int arg);
void	build_stack(t_stack *a, char **arg, int nbr_args);
void	free_stack(t_stack **stack);

// ALGORITHM: functions implementing the sorting algorithm.
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
//
int		*sorted_reference(t_stack *a);
void	quicksort(int *array, int low, int high);
void	arr_swap(int *a, int *b);
//
t_chunk	*init_chunk(t_stack *a);
void	transfert_chunk(t_stack *a, t_stack *b);
void	update_chunk(t_stack *a, t_chunk *chunk);

// RULES: functions for executing instructions on the stacks.
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

// MAIN: entry point of the program.
int 	main(int argc, char **argv);
void	print_stack(t_stack *a);
void	print_sorted_reference(int *sorted_ref, int size);

# endif