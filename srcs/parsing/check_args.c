/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:53:34 by lolq              #+#    #+#             */
/*   Updated: 2025/01/19 16:01:09 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool valid_input(int ac, char **arg)
{
    int i;

    if (ac < 2)
        exit_error(NULL, NULL, 1);
    if (ac == 2)
        return (single_arg(arg[1]));
    else
    {
        i = 1;
        while (i < ac)
        {
            if (!check_syntax(arg[i]) || !check_overflow(arg[i]))
                return (false);
            i++;
        }
        return (check_doublon(ac - 1, arg + 1));
    }
}

bool single_arg(char *arg)
{
    char    **args;
    int     i;
    
    i = 0;
    args = ft_split(arg, ' ');
    if (!args)
        return (false);
    while (args[i])
    {
        if (!check_syntax(args[i]) || !check_overflow(args[i]))
            return(free_split(args), false);
        i++;
    }
    if (!check_doublon(i, args))
        return(free_split(args), false);
    free_split(args);
    return (true);
}

bool check_syntax(const char *arg)
{
    int i;

    i = 0;
    while (arg[i] == ' ')
        i++;
    if (arg[i] == '\0')
        return (false);
    if (arg[i] == '-' || arg[i] == '+')
        i++;
    while (arg[i] != '\0')
    {
        if (!ft_isdigit(arg[i]))
            return (false);
        i++;
    }
    return (true);
}

bool check_overflow(char *arg)
{
    long    result;
    int     sign;
    int     i;
    
    sign = 1;
    result = 0;
    i = 0;
    while ((arg[i] == ' ' || (arg[i] >= 9 && arg[i] <= 13)))
        i++;
    if (arg[i] == '-' || arg[i] == '+')
    {
        if (arg[i] == '-')
            sign = -1;
        i++;
    }
    while (arg[i] != '\0')
    {
        result = (result * 10) + (arg[i] - '0');
        if ((result * sign > INT_MAX || result * sign < INT_MIN))
            return (false);
        i++;
    }
    return (true);
}

bool    check_doublon(int ac, char **arg)
{
    long    compare;
    int     i;
    int     j;

    i = 0;
    while (i < ac)
    {
        compare = ft_atol(arg[i]);
        j = i + 1;
        while (j < ac)
        {
            if (compare == ft_atol(arg[j]))
                return (false);
            j++;
        }
        i++;
    }
    return (true);
}
