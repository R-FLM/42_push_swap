/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:48:52 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/15 20:18:23 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker_bonus.h"
#include "libft.h"

static int	ft_execute(t_stack *a, t_stack *b, char *instruction)
{
	if (ft_strncmp(instruction, "sa\n", 4) == 0)
		ft_swap_a_bonus(a);
	else if (ft_strncmp(instruction, "sb\n", 4) == 0)
		ft_swap_b_bonus(b);
	else if (ft_strncmp(instruction, "ss\n", 4) == 0)
		ft_swap_both_bonus(a, b);
	else if (ft_strncmp(instruction, "pa\n", 4) == 0)
		ft_push_a_bonus(a, b);
	else if (ft_strncmp(instruction, "pb\n", 4) == 0)
		ft_push_b_bonus(b, a);
	else if (ft_strncmp(instruction, "ra\n", 4) == 0)
		ft_rotate_a_bonus(a);
	else if (ft_strncmp(instruction, "rb\n", 4) == 0)
		ft_rotate_b_bonus(b);
	else if (ft_strncmp(instruction, "rr\n", 4) == 0)
		ft_rotate_both_bonus(a, b);
	else if (ft_strncmp(instruction, "rra\n", 5) == 0)
		ft_rrotate_a_bonus(a);
	else if (ft_strncmp(instruction, "rrb\n", 5) == 0)
		ft_rrotate_b_bonus(b);
	else if (ft_strncmp(instruction, "rrr\n", 5) == 0)
		ft_rrotate_both_bonus(a, b);
	else
		return (0);
	return (1);
}

static int	ft_process(t_stack *a, t_stack *b)
{
	char	*line;
	int		r;

	while (1)
	{
		line = ft_get_next_line(0);
		if (!line)
			break ;
		r = ft_execute(a, b, line);
		free(line);
		if (r == 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc > 1)
	{
		a = ft_parse_stack(argv);
		if (!a)
			return (ft_putstr_fd("Error\n", 2), 1);
		b = ft_initialize_stack_b(a);
		if (!b)
			return (ft_free_stack(a), 1);
		ft_convert(a);
		if (!ft_process(a, b))
			return (ft_free_stack(a), ft_free_stack(b), 1);
		if (ft_check_sorted_a(a) && !b->index)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		return (ft_free_stack(a), ft_free_stack(b), 0);
	}
	return (0);
}
