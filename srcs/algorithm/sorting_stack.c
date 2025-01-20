/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:33:02 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/20 09:17:09 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sorting_stack(t_stack *a, t_stack *b)
{
    if (a->nbr_n <= 5)
        small_sorting(a, b);
    if (a->nbr_n > 5)
    {
        chunk_push(a, b);
        push_back(b, a);
    }
}
