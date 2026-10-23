/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_small.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 23:58:06 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/15 16:06:12 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_small(t_stack *stack_a, t_stack *stack_b)
{
	int	pushed;

	if (stack_a->index == 2 && stack_a->stack[0] > stack_a->stack[1])
		ft_swap_a(stack_a);
	else if (stack_a->index == 3)
		ft_sort_three_a(stack_a);
	else if (stack_a->index <= 5)
	{
		pushed = 0;
		while (stack_a->index > 3)
		{
			if (!ft_pos_min_stack(stack_a))
			{
				ft_push_b(stack_b, stack_a);
				pushed++;
			}
			else if (ft_pos_min_stack(stack_a) <= stack_a->index / 2)
				ft_rotate_a(stack_a);
			else
				ft_rrotate_a(stack_a);
		}
		ft_sort_three_a(stack_a);
		while (pushed-- > 0)
			ft_push_a(stack_a, stack_b);
	}
}

void	ft_sort_three_a(t_stack *stack_a)
{
	if (stack_a->stack[0] > stack_a->stack[1]
		&& stack_a->stack[1] < stack_a->stack[2]
		&& stack_a->stack[0] < stack_a->stack[2])
		ft_swap_a(stack_a);
	else if (stack_a->stack[0] > stack_a->stack[1]
		&& stack_a->stack[1] > stack_a->stack[2])
	{
		ft_swap_a(stack_a);
		ft_rrotate_a(stack_a);
	}
	else if (stack_a->stack[0] > stack_a->stack[1]
		&& stack_a->stack[1] < stack_a->stack[2]
		&& stack_a->stack[0] > stack_a->stack[2])
		ft_rotate_a(stack_a);
	else if (stack_a->stack[0] < stack_a->stack[1]
		&& stack_a->stack[1] > stack_a->stack[2]
		&& stack_a->stack[0] < stack_a->stack[2])
	{
		ft_swap_a(stack_a);
		ft_rotate_a(stack_a);
	}
	else if (stack_a->stack[0] < stack_a->stack[1]
		&& stack_a->stack[1] > stack_a->stack[2]
		&& stack_a->stack[0] > stack_a->stack[2])
		ft_rrotate_a(stack_a);
}
