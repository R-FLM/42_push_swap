/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:24:51 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/15 20:02:05 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_swap_a_bonus(t_stack *stack_a)
{
	int	tmp;

	if (stack_a->index < 2)
		return (0);
	tmp = stack_a->stack[0];
	stack_a->stack[0] = stack_a->stack[1];
	stack_a->stack[1] = tmp;
	return (1);
}

size_t	ft_swap_b_bonus(t_stack *stack_b)
{
	int	tmp;

	if (stack_b->index < 2)
		return (0);
	tmp = stack_b->stack[0];
	stack_b->stack[0] = stack_b->stack[1];
	stack_b->stack[1] = tmp;
	return (1);
}

size_t	ft_swap_both_bonus(t_stack *stack_a, t_stack *stack_b)
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
	return (1);
}
