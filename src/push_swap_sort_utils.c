/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:14:24 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/15 16:06:15 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_index_closest_value(t_stack *a, int b)
{
	int	i;
	int	index;
	int	gap;

	i = 0;
	index = 0;
	gap = INT_MAX;
	while (i < a->index)
	{
		if (ft_abs(a->stack[i] - b) < gap && a->stack[i] > b)
		{
			gap = ft_abs(a->stack[i] - b);
			index = i;
		}
		i++;
	}
	return (index);
}

int	ft_distance_to_closest(t_stack *a, t_stack *b, int n)
{
	int	i;
	int	distance;

	i = 0;
	while (i < b->index)
	{
		if (b->stack[i] == n)
			break ;
		i++;
	}
	distance = ft_min(ft_index_closest_value(a, n),
			a->index - ft_index_closest_value(a, n));
	i = ft_min(i, b->index - i);
	return (i + distance + 1);
}

int	ft_closest(t_stack *a, t_stack *b)
{
	int	closest;
	int	index;
	int	i;

	i = 0;
	closest = INT_MAX;
	index = 0;
	while (i < b->index)
	{
		if (ft_distance_to_closest(a, b, b->stack[i]) < closest)
		{
			closest = ft_distance_to_closest(a, b, b->stack[i]);
			index = i;
		}
		i++;
	}
	return (index);
}

int	ft_index(t_stack *a, int n)
{
	int	i;

	i = 0;
	while (a->stack[i] != n)
		i++;
	return (i);
}
