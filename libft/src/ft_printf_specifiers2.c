/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifiers2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:43:47 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/09 13:32:23 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_spe_int(t_format *fmts, va_list args)
{
	long	n;
	int		count;
	int		digits;
	int		sign;

	count = 0;
	sign = 0;
	n = (long)va_arg(args, int);
	digits = ft_count_digits(n, 10, fmts);
	if (n < 0 || fmts->plus || fmts->space)
		sign = 1;
	if (!fmts->zero || (fmts->precision > -1 && fmts->precision < fmts->width))
		if (ft_width(fmts->width - ft_max(digits, fmts->precision) - sign,
				0, 0, &count) == -1)
			return (-1);
	if (ft_int_sign(n, fmts, &count) == -1)
		return (-1);
	if (fmts->zero && fmts->precision < 0)
		if (ft_width(fmts->width - ft_max(digits, fmts->precision) - sign,
				0, fmts->zero, &count) == -1)
			return (-1);
	if (ft_int_precision(n, fmts, &count) == -1)
		return (-1);
	return (count);
}

int	ft_spe_int_minus(t_format *fmts, va_list args)
{
	long	n;
	int		count;

	count = 0;
	n = (long)va_arg(args, int);
	if (ft_int_sign(n, fmts, &count) == -1)
		return (-1);
	if (ft_int_precision(n, fmts, &count) == -1)
		return (-1);
	if (ft_width(fmts->width - count, 0, 0, &count) == -1)
		return (-1);
	return (count);
}

int	ft_spe_uint(t_format *fmts, va_list args)
{
	long	n;
	int		count;
	int		digits;

	count = 0;
	n = (long)va_arg(args, unsigned int);
	digits = ft_count_digits(n, 10, fmts);
	if (!fmts->zero || (fmts->precision > -1 && fmts->precision < fmts->width))
		if (ft_width(fmts->width - ft_max(digits, fmts->precision),
				0, 0, &count) == -1)
			return (-1);
	if (fmts->zero && fmts->precision < 0)
		if (ft_width(fmts->width - ft_max(digits, fmts->precision),
				0, fmts->zero, &count) == -1)
			return (-1);
	if (ft_int_precision(n, fmts, &count) == -1)
		return (-1);
	return (count);
}

int	ft_spe_uint_minus(t_format *fmts, va_list args)
{
	long	n;
	int		count;

	count = 0;
	n = (long)va_arg(args, unsigned int);
	if (ft_int_precision(n, fmts, &count) == -1)
		return (-1);
	if (ft_width(fmts->width - count, 0, 0, &count) == -1)
		return (-1);
	return (count);
}
