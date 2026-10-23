/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:47:58 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/15 16:11:10 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_check_sorted_b(t_stack *stack_b)
{
	int	i;

	if (!stack_b->index)
		return (1);
	i = 1;
	while (i < stack_b->index && stack_b->stack[i - 1] > stack_b->stack[i])
		i++;
	if (i == stack_b->index)
		return (1);
	return (0);
}

size_t	ft_check_sorted_a(t_stack *stack_a)
{
	int	i;

	i = 1;
	while (i < stack_a->index && stack_a->stack[i - 1] < stack_a->stack[i])
		i++;
	if (i == stack_a->index)
		return (1);
	return (0);
}

size_t	ft_check_full_sorted_a(t_stack *stack_a)
{
	int	i;

	i = 1;
	while (i < stack_a->index && stack_a->stack[i - 1] < stack_a->stack[i])
		i++;
	if (i == stack_a->size)
		return (1);
	return (0);
}
