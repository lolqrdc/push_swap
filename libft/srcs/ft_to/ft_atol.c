/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:48:03 by lolq              #+#    #+#             */
/*   Updated: 2025/01/18 20:59:08 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int    ft_atol(const char *str)
{
    long int    result;
    int         sign;
    int         i;

    i = 0;
    sign = 1;
    result = 0;
    while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}
