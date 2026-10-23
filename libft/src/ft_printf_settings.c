/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_settings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:56:47 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/09 13:32:08 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_width(int width, int minus, int zero, int *count)
{
	int		tmp_count;
	int		i;

	i = 0;
	tmp_count = 0;
	while (i < width)
	{
		if (zero && !minus)
			tmp_count = ft_putchar_count('0', count);
		else
			tmp_count = ft_putchar_count(' ', count);
		if (tmp_count == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_plus_space(t_format *fmts, int *count)
{
	if (fmts->plus)
	{
		if (ft_putchar_count('+', count) == -1)
			return (-1);
	}
	else if (fmts->space)
	{
		if (ft_putchar_count(' ', count) == -1)
			return (-1);
	}
	return (0);
}

int	ft_int_sign(long n, t_format *fmts, int *count)
{
	int		tmp_count;

	if (n < 0)
		tmp_count = ft_putchar_count('-', count);
	else if (fmts->plus)
		tmp_count = ft_putchar_count('+', count);
	else if (fmts->space)
		tmp_count = ft_putchar_count(' ', count);
	else
		tmp_count = 0;
	if (tmp_count == -1)
		return (-1);
	return (0);
}

int	ft_int_precision(long n, t_format *fmts, int *count)
{
	int		digits;

	digits = ft_count_digits(n, 10, fmts);
	if (n < 0)
		n *= -1;
	if (fmts->dot && fmts->precision > digits)
	{
		while (digits++ < fmts->precision)
			if (ft_putchar_count('0', count) == -1)
				return (-1);
	}
	if (!(fmts->dot && fmts->precision == 0 && n == 0))
		if (ft_putnbr_count(n, count) == -1)
			return (-1);
	return (0);
}

int	ft_hexa_uint_precision(unsigned int n, int upcase, t_format *fmts,
	int *count)
{
	int		digits;

	digits = ft_count_digits(n, 16, fmts);
	if (fmts->dot && fmts->precision > digits)
	{
		while (digits++ < fmts->precision)
			if (ft_putchar_count('0', count) == -1)
				return (-1);
	}
	if (!(fmts->dot && fmts->precision == 0 && n == 0))
		if (ft_puthexa_uint_count(n, upcase, count) == -1)
			return (-1);
	return (0);
}
