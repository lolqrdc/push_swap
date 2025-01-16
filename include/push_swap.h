/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:21:26 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/16 13:46:53 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// MY LIBFT
# include "../libft/include/libft.h" 
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"

// LIBRARIES
# include <unistd.h>
# include <stdlib.h> 
# include <limits.h>
# include <stdbool.h>

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

// 

int main(int argc, char **argv);

// PARSING: functions to check for any errors.
bool    is_it_valid(char **args, int nbr_args);
bool    check_duplicates(int argc, char **argv);
bool    check_syntax(char *arg);
bool    check_overflow(char *str);
//bool    check_sorted(t_stack *a);
char	**split_args(int argc, char **argv);
void    handle_exit(int i, t_stack *a, t_stack *b);
//
void    free_stack(t_stack **stack);
//void    free_args();
// INSTRUCTIONS: swap, push, rotate & reverse.
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