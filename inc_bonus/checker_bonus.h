/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:57:50 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/15 20:17:48 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "libft.h"
# include "push_swap.h"

size_t	ft_push_a_bonus(t_stack *stack_a, t_stack *stack_b);
size_t	ft_push_b_bonus(t_stack *stack_b, t_stack *stack_a);

size_t	ft_swap_a_bonus(t_stack *stack_a);
size_t	ft_swap_b_bonus(t_stack *stack_b);
size_t	ft_swap_both_bonus(t_stack *stack_a, t_stack *stack_b);

size_t	ft_rotate_a_bonus(t_stack *stack_a);
size_t	ft_rotate_b_bonus(t_stack *stack_b);
size_t	ft_rotate_both_bonus(t_stack *stack_a, t_stack *stack_b);

size_t	ft_rrotate_a_bonus(t_stack *stack_a);
size_t	ft_rrotate_b_bonus(t_stack *stack_b);
size_t	ft_rrotate_both_bonus(t_stack *stack_a, t_stack *stack_b);

#endif
