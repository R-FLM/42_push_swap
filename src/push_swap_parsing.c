/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:12:01 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/15 16:05:55 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_initialize_stack_b(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = (t_stack *)malloc(sizeof(*stack_b));
	if (!stack_b)
		return (NULL);
	stack_b->size = stack_a->size;
	stack_b->index = 0;
	stack_b->name = 'b';
	stack_b->stack = (int *)malloc(stack_b->size * sizeof(*(stack_b->stack)));
	if (!(stack_b->stack))
		return (free(stack_b), NULL);
	return (stack_b);
}

size_t	ft_check_duplicates(t_stack *stack_a)
{
	int	i;
	int	j;

	if (!(stack_a->size) || stack_a->size == 1)
		return (1);
	i = 0;
	j = 1;
	while (i < stack_a->size - 1)
	{
		while (j < stack_a->size)
		{
			if (stack_a->stack[i] == stack_a->stack[j++])
				return (0);
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	ft_size_stack(char **argv)
{
	char	**s;
	char	**tmp;
	int		count;

	count = 0;
	while (*(++argv))
	{
		s = ft_split(*argv, ' ');
		tmp = s;
		if (!s)
			return (0);
		while (*s)
		{
			if (!(**s))
				;
			else if (!ft_isint(*s))
				return (ft_free_array_strs(tmp), 0);
			else
				count++;
			s++;
		}
		ft_free_array_strs(tmp);
	}
	return (count);
}

t_stack	*ft_fill_stack(char **argv, t_stack *stack_a)
{
	char	**s;
	char	**tmp;
	int		n;
	int		i;

	i = 0;
	while (*(++argv))
	{
		s = ft_split(*argv, ' ');
		tmp = s;
		if (!s)
			return (ft_free_stack(stack_a), NULL);
		while (*s)
		{
			n = ft_atoi(*(s++));
			stack_a->stack[i++] = n;
		}
		ft_free_array_strs(tmp);
	}
	return (stack_a);
}

t_stack	*ft_parse_stack(char **argv)
{
	t_stack	*stack_a;

	stack_a = (t_stack *)malloc(sizeof(*stack_a));
	if (!stack_a)
		return (NULL);
	stack_a->size = ft_size_stack(argv);
	if (!(stack_a->size))
		return (ft_free_stack(stack_a), NULL);
	stack_a->stack = (int *)malloc(stack_a->size * sizeof(*(stack_a->stack)));
	if (!(stack_a->stack))
		return (ft_free_stack(stack_a), NULL);
	stack_a = ft_fill_stack(argv, stack_a);
	if (!(stack_a))
		return (NULL);
	if (!ft_check_duplicates(stack_a))
		return (ft_free_stack(stack_a), NULL);
	stack_a->index = stack_a->size;
	stack_a->name = 'a';
	return (stack_a);
}
