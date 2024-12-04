/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:46:40 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/04 09:59:37 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"

//** handle errors
int	syntax_error(char **arg);
int	overflow_error(char *);
int	duplicate_error();
//** instruction
void	swap_sa();
void	swap_sb();
void	swap_ss();
void	push_pa();
void	push_pb();
void	rotate_ra();
void	rotate_rb();
void	rotate_rr();
void	reverse_rotate_ra();
void	reverse_rotate_rb();
void	reverse_rotate_rrr();
//** algorithm functions

#endif