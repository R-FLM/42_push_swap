/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:05:36 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/15 20:00:38 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_rotate_a_bonus(t_stack *stack_a)
{
	int	tmp;
	int	i;

	if (stack_a->index < 2)
		return (0);
	tmp = stack_a->stack[0];
	i = 0;
	while (i < stack_a->index - 1)
	{
		stack_a->stack[i] = stack_a->stack[i + 1];
		i++;
	}
	stack_a->stack[stack_a->index - 1] = tmp;
	return (1);
}

size_t	ft_rotate_b_bonus(t_stack *stack_b)
{
	int	tmp;
	int	i;

	if (stack_b->index < 2)
		return (0);
	tmp = stack_b->stack[0];
	i = 0;
	while (i < stack_b->index - 1)
	{
		stack_b->stack[i] = stack_b->stack[i + 1];
		i++;
	}
	stack_b->stack[stack_b->index - 1] = tmp;
	return (1);
}

size_t	ft_rotate_both_bonus(t_stack *stack_a, t_stack *stack_b)
{
	int	tmp;
	int	i;

	if (stack_a->index < 2 || stack_b->index < 2)
		return (0);
	tmp = stack_a->stack[0];
	i = 0;
	while (i < stack_a->index - 1)
	{
		stack_a->stack[i] = stack_a->stack[i + 1];
		i++;
	}
	stack_a->stack[stack_a->index - 1] = tmp;
	tmp = stack_b->stack[0];
	i = 0;
	while (i < stack_b->index - 1)
	{
		stack_b->stack[i] = stack_b->stack[i + 1];
		i++;
	}
	stack_b->stack[stack_b->index - 1] = tmp;
	return (1);
}
