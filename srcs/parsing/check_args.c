/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:54:44 by loribeir          #+#    #+#             */
/*   Updated: 2025/01/16 13:38:29 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool    is_it_valid(char **args, int nbr_args)
{
    int i;

    i = 0;
    if (nbr_args == 2)
    args = split_args(nbr_args, args);
    while (args[nbr_args] != NULL)
        nbr_args++;
    while (i < nbr_args)
    {
        if (!check_syntax(args[i]))
            return (false);
        if (!check_overflow(args[i]))
            return (false);
        i++;
    }
    if (!check_duplicates(nbr_args, args))
        return(false);
    return(true);
}
