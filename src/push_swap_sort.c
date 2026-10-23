/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 09:23:21 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/15 17:17:57 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *a, t_stack *b)
{
	if (ft_check_sorted_a(a) && b->index == 0)
		return ;
	if (a->index <= 5)
		ft_sort_small(a, b);
	else
		ft_sort_a(a, b);
	while (b->index > 0)
		ft_push_a(a, b);
	while (a->stack[0] != 0)
	{
		if (ft_index(a, 0) < a->index / 2)
			ft_rotate_a(a);
		else
			ft_rrotate_a(a);
	}
}

void	ft_sort_a(t_stack *a, t_stack *b)
{
	int	n;

	if (ft_check_sorted_a(a))
		return ;
	if (a->index <= 5)
		return (ft_sort_small(a, b));
	n = a->index;
	while (a->index > 5)
	{
		if (a->stack[0] == (n - 1) || a->stack[0] == (n / 5)
			|| a->stack[0] == (n * 2 / 5)
			|| a->stack[0] == (n * 3 / 5)
			|| a->stack[0] == (n * 4 / 5))
			ft_rotate_a(a);
		else if (a->stack[0] >= ((n - 1) / 2))
			ft_push_b(b, a);
		else
		{
			ft_push_b(b, a);
			ft_rotate_b(b);
		}
	}
	ft_sort_small(a, b);
	ft_sort_b(a, b);
}

void	ft_sort_b(t_stack *a, t_stack *b)
{
	int	i;
	int	index_b;
	int	index_a;

	while (b->index > 0)
	{
		i = 0;
		index_b = ft_closest(a, b);
		index_a = ft_index_closest_value(a, b->stack[index_b]);
		while (i++ < ft_min(index_b, b->index - index_b))
		{
			if (ft_min(index_b, b->index - index_b) == index_b)
				ft_rotate_b(b);
			else
				ft_rrotate_b(b);
		}
		ft_sort_bis(a, b, index_a);
	}
}

void	ft_sort_bis(t_stack *a, t_stack *b, int index_a)
{
	int	i;

	i = 0;
	while (i++ < ft_min(index_a, a->index - index_a))
	{
		if (ft_min(index_a, a->index - index_a) == index_a)
			ft_rotate_a(a);
		else
			ft_rrotate_a(a);
	}
	if (a->stack[0] > b->stack[0])
		ft_push_a(a, b);
	else
	{
		ft_push_a(a, b);
		ft_swap_a(a);
	}
}
