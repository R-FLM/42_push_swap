/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:48:50 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/15 17:14:59 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_stack
{
	int		size;
	int		index;
	int		*stack;
	char	name;
}			t_stack;

// PUSH_SWAP
int			main(int argc, char **argv);

// PUSH_SWAP_PARSING
t_stack		*ft_initialize_stack_b(t_stack *stack_a);
size_t		ft_check_duplicates(t_stack *stack_a);
int			ft_size_stack(char **argv);
t_stack		*ft_fill_stack(char **argv, t_stack *stack_a);
t_stack		*ft_parse_stack(char **argv);

// PUSH_SWAP_SORT_SMALL
void		ft_sort_small(t_stack *stack_a, t_stack *stack_b);
void		ft_sort_three_a(t_stack *stack_a);

// PUSH_SWAP_SORT
void		ft_sort(t_stack *stack_a, t_stack *stack_b);
void		ft_sort_a(t_stack *stack_a, t_stack *stack_b);
void		ft_sort_b(t_stack *stack_a, t_stack *stack_b);
void		ft_sort_bis(t_stack *a, t_stack *b, int index_a);

// PUSH_SWAP_SORT_UTILS
int			ft_index_closest_value(t_stack *a, int b);
int			ft_distance_to_closest(t_stack *a, t_stack *b, int n);
int			ft_closest(t_stack *a, t_stack *b);
int			ft_index(t_stack *a, int n);

// PUSH_SWAP_CHECK
size_t		ft_check_sorted_b(t_stack *stack_b);
size_t		ft_check_sorted_a(t_stack *stack_a);
size_t		ft_check_full_sorted_a(t_stack *stack_a);

// PUSH_SWAP_SWAP
size_t		ft_swap_a(t_stack *stack_a);
size_t		ft_swap_b(t_stack *stack_b);
size_t		ft_swap(t_stack *stack_a);
size_t		ft_swap_both(t_stack *stack_a, t_stack *stack_b);

// PUSH_SWAP_PUSH
size_t		ft_push_a(t_stack *stack_a, t_stack *stack_b);
size_t		ft_push_b(t_stack *stack_b, t_stack *stack_a);
size_t		ft_push(t_stack *stack_a, t_stack *stack_b);

// PUSH_SWAP_ROTATE
size_t		ft_rotate_a(t_stack *stack_a);
size_t		ft_rotate_b(t_stack *stack_b);
size_t		ft_rotate(t_stack *stack_a);
size_t		ft_rotate_both(t_stack *stack_a, t_stack *stack_b);

// PUSH_SWAP_REV_ROTATE
size_t		ft_rrotate_a(t_stack *stack_a);
size_t		ft_rrotate_b(t_stack *stack_b);
size_t		ft_rrotate(t_stack *stack_a);
size_t		ft_rrotate_both(t_stack *stack_a, t_stack *stack_b);

// PUSH_SWAP_UTILS
void		ft_convert(t_stack *stack_a);
void		ft_free_stack(t_stack *stack_a);
int			ft_min_stack(t_stack *stack_a);
int			ft_pos_min_stack(t_stack *stack_a);
void		ft_print_stacks(t_stack *a, t_stack *b);

#endif
