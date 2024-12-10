/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:47:46 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/10 17:51:36 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"

# define SUCCESS 0
# define FAILURE 1

// STRUCT1: EACH NODE.
typedef struct s_node 
{
	int	element;
	struct s_node *next;
	struct s_node *prev;
} t_node;

// STRUCT2: NUMBER OF NOES.
typedef struct s_stack
{
	t_node *head;
	int nbr_n;
} t_stack;

// PARSING: ERROR CASES.
int		check_synthax(int argc, char **argv);
int		check_duplicate(int argc, char **argv);
int		check_overflow(char *str);
int		write_error(int argc, char **argv);
int		compare_nbr(char *s1, char *s2);
char	**handle_str(int argc, char **argv);

// BUILD: STACK MANAGEMENT.
t_stack	*init_stack(void);
int		add_to_stack(t_stack *stack, int element);
void	print_stack(t_stack *stack);
void	free_stack(t_stack *stack);

// RULES: 11 INSTRUCTIONS.
void	swap(t_stack *stack);
void	swap_sa(t_stack *stack_a);
void	swap_sb(t_stack *stack_b);
void 	swap_ss(t_stack *stack_a, t_stack *stack_b);
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

// test
int 	main(int argc, char **argv);

#endif