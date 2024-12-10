/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:35:43 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/10 18:59:36 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**handle_str(int ac, char **av)
{
	char	**element;
	int		i;

	i = 1;
	if (ac == 2)
	{
		element = ft_split(av[1], ' ');
		if (!element)
			return (NULL);
		return(element);
	}
	else
	{
		element = malloc(sizeof(char *)*(ac));
		if (!element)
			return (NULL);
		i = 1;
		while (i < ac)
		{
			element[i - 1] = ft_strdup(av[i]);
			if (!element[i - 1])
			{
				while (--i > 0)
					free(element[i - 1]);
				free(element);
				return (NULL);
			}
			i++;
		}
		element[ac - 1] = NULL;
	}
	return (element);
}
int	count_split_element(char **split)
{
	int	count;

	count = 0;
	while (split[count] != NULL)
		count++;
	return (count);
}
