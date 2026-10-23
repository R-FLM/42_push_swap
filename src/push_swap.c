/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:48:52 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/15 18:06:14 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc > 1)
	{
		stack_a = ft_parse_stack(argv);
		if (!stack_a)
			return (ft_putstr_fd("Error\n", 2), 1);
		stack_b = ft_initialize_stack_b(stack_a);
		if (!stack_b)
			return (ft_free_stack(stack_a), 1);
		ft_convert(stack_a);
		ft_sort(stack_a, stack_b);
		return (ft_free_stack(stack_a), ft_free_stack(stack_b), 0);
	}
	return (0);
}
