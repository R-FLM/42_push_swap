/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rev_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:05:36 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/15 17:18:12 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_rrotate_a(t_stack *stack_a)
{
	int	tmp;
	int	i;

	if (stack_a->index < 2)
		return (0);
	tmp = stack_a->stack[stack_a->index - 1];
	i = stack_a->index - 1;
	while (i > 0)
	{
		stack_a->stack[i] = stack_a->stack[i - 1];
		i--;
	}
	stack_a->stack[0] = tmp;
	ft_printf("rra\n");
	return (1);
}

size_t	ft_rrotate_b(t_stack *stack_b)
{
	int	tmp;
	int	i;

	if (stack_b->index < 2)
		return (0);
	tmp = stack_b->stack[stack_b->index - 1];
	i = stack_b->index - 1;
	while (i > 0)
	{
		stack_b->stack[i] = stack_b->stack[i - 1];
		i--;
	}
	stack_b->stack[0] = tmp;
	ft_printf("rrb\n");
	return (1);
}

size_t	ft_rrotate(t_stack *stack_a)
{
	int	tmp;
	int	i;

	if (stack_a->index < 2)
		return (0);
	tmp = stack_a->stack[stack_a->index - 1];
	i = stack_a->index - 1;
	while (i > 0)
	{
		stack_a->stack[i] = stack_a->stack[i - 1];
		i--;
	}
	stack_a->stack[0] = tmp;
	ft_printf("rr%c\n", stack_a->name);
	return (1);
}

size_t	ft_rrotate_both(t_stack *stack_a, t_stack *stack_b)
{
	int	tmp;
	int	i;

	if (stack_a->index < 2 || stack_b->index < 2)
		return (0);
	tmp = stack_a->stack[stack_a->index - 1];
	i = stack_a->index - 1;
	while (i > 0)
	{
		stack_a->stack[i] = stack_a->stack[i - 1];
		i--;
	}
	stack_a->stack[0] = tmp;
	tmp = stack_b->stack[stack_b->index - 1];
	i = stack_b->index - 1;
	while (i > 0)
	{
		stack_b->stack[i] = stack_b->stack[i - 1];
		i--;
	}
	stack_b->stack[0] = tmp;
	ft_printf("rrr\n");
	return (1);
}
