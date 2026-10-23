/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:36:06 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/15 17:08:38 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_push_a(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (!(stack_b->index))
		return (0);
	stack_a->index++;
	i = stack_a->index - 1;
	while (i > 0)
	{
		stack_a->stack[i] = stack_a->stack[i - 1];
		i--;
	}
	stack_a->stack[0] = stack_b->stack[0];
	stack_b->index--;
	i = 0;
	while (i < stack_b->index)
	{
		stack_b->stack[i] = stack_b->stack[i + 1];
		i++;
	}
	ft_printf("pa\n");
	return (1);
}

size_t	ft_push_b(t_stack *stack_b, t_stack *stack_a)
{
	int	i;

	if (!(stack_a->index))
		return (0);
	stack_b->index++;
	i = stack_b->index - 1;
	while (i > 0)
	{
		stack_b->stack[i] = stack_b->stack[i - 1];
		i--;
	}
	stack_b->stack[0] = stack_a->stack[0];
	stack_a->index--;
	i = 0;
	while (i < stack_a->index)
	{
		stack_a->stack[i] = stack_a->stack[i + 1];
		i++;
	}
	ft_printf("pb\n");
	return (1);
}

size_t	ft_push(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (!(stack_b->index))
		return (0);
	stack_a->index++;
	i = stack_a->index - 1;
	while (i > 0)
	{
		stack_a->stack[i] = stack_a->stack[i - 1];
		i--;
	}
	stack_a->stack[0] = stack_b->stack[0];
	stack_b->index--;
	i = 0;
	while (i < stack_b->index)
	{
		stack_b->stack[i] = stack_b->stack[i + 1];
		i++;
	}
	ft_printf("p%c\n", stack_a->name);
	return (1);
}
