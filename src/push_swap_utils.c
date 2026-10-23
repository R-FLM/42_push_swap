/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:57:43 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/15 17:13:47 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_convert(t_stack *stack_a)
{
	int		i;
	int		j;
	int		pos;
	t_stack	*conv;

	i = 0;
	j = 0;
	pos = 0;
	conv = ft_initialize_stack_b(stack_a);
	while (i < stack_a->index)
	{
		while (j < stack_a->index)
			if (stack_a->stack[i] > stack_a->stack[j++])
				pos++;
		conv->stack[i++] = pos;
		j = 0;
		pos = 0;
	}
	i = 0;
	while (i < stack_a->index)
	{
		stack_a->stack[i] = conv->stack[i];
		i++;
	}
	ft_free_stack(conv);
}

void	ft_free_stack(t_stack *stack_a)
{
	if (!stack_a)
		return ;
	if (stack_a->stack)
		free(stack_a->stack);
	free(stack_a);
}

int	ft_min_stack(t_stack *stack_a)
{
	int	res;
	int	i;

	res = INT_MAX;
	i = 0;
	while (i < stack_a->index)
	{
		if (res > stack_a->stack[i])
			res = stack_a->stack[i];
		i++;
	}
	return (res);
}

int	ft_pos_min_stack(t_stack *stack_a)
{
	int	min;
	int	i;

	min = ft_min_stack(stack_a);
	i = 0;
	while (i < stack_a->index)
	{
		if (stack_a->stack[i] == min)
			return (i);
		i++;
	}
	return (0);
}

void	ft_print_stacks(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	ft_printf("Stack A : |");
	while (i < a->index)
		ft_printf("%5i |", a->stack[i++]);
	ft_printf("\n");
	i = 0;
	ft_printf("Stack B : |");
	while (i < b->index)
		ft_printf("%5i |", b->stack[i++]);
	ft_printf("\n");
}
