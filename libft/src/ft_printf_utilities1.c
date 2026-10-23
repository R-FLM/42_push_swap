/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:39:14 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/09 13:32:31 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_digits(long n, int base, t_format *fmts)
{
	int	count;

	count = 0;
	if (n == 0 && fmts->dot == 1 && fmts->precision <= 0 && fmts->type != 'p')
		return (0);
	else if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		count++;
		n /= base;
	}
	return (count);
}

int	ft_count_udigits(unsigned long n, int base, t_format *fmts)
{
	int	count;

	count = 0;
	if (n == 0 && fmts->dot == 1 && fmts->precision <= 0 && fmts->type != 'p')
		return (0);
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n /= base;
	}
	return (count);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min_if_pos(int a, int b)
{
	if (a < 0)
		return (b);
	if (b < 0)
		return (a);
	if (a < b)
		return (a);
	return (b);
}
