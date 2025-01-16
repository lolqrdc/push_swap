/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:21:36 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/16 13:50:16 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    
    if (argc < 2)
        return(handle_exit(1, NULL, NULL), 1);
    if (!is_it_valid(argv, argc))
        return(handle_exit(1, NULL, NULL), 1);    
    return (0);
}