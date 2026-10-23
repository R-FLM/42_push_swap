/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:24:51 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/15 19:55:53 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_swap_a(t_stack *stack_a)
{
	int	tmp;

	if (stack_a->index < 2)
		return (0);
	tmp = stack_a->stack[0];
	stack_a->stack[0] = stack_a->stack[1];
	stack_a->stack[1] = tmp;
	ft_printf("sa\n");
	return (1);
}

size_t	ft_swap_b(t_stack *stack_b)
{
	int	tmp;

	if (stack_b->index < 2)
		return (0);
	tmp = stack_b->stack[0];
	stack_b->stack[0] = stack_b->stack[1];
	stack_b->stack[1] = tmp;
	ft_printf("sb\n");
	return (1);
}

size_t	ft_swap(t_stack *stack_a)
{
	int	tmp;

	if (stack_a->index < 2)
		return (0);
	tmp = stack_a->stack[0];
	stack_a->stack[0] = stack_a->stack[1];
	stack_a->stack[1] = tmp;
	ft_printf("s%c\n", stack_a->name);
	return (1);
}

size_t	ft_swap_both(t_stack *stack_a, t_stack *stack_b)
{
	int	tmp;

	if (stack_a->index < 2 || stack_b->index < 2)
		return (0);
	tmp = stack_a->stack[0];
	stack_a->stack[0] = stack_a->stack[1];
	stack_a->stack[1] = tmp;
	tmp = stack_b->stack[0];
	stack_b->stack[0] = stack_b->stack[1];
	stack_b->stack[1] = tmp;
	ft_printf("ss\n");
	return (1);
}
