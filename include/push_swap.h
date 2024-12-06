/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:47:46 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/06 15:34:38 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"

// structure pour chaque noeud de la liste.
typedef struct s_node 
{
	int	element; // le chiffre a trier.
	struct s_node *next;
	struct s_node *prev;
} t_node;

// structure de controle pour ma stack.
typedef struct s_stack
{
	t_node *head; // ptr vers le 1er noeud.
	int nbr_n; // nombre de noeuds present dans la stack.
} t_stack;

// les instructions obligatoire.
void	swap(t_stack *stack);
void	swap_sa(t_stack *stack_a);
void	swap_sb(t_stack *stack_b);
void 	swap_ss(t_stack *stack_a, t_stack *stack_b);
//
void	push_pa(t_stack *stack_a, t_stack *stack_b);

#endif
