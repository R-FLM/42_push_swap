/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifiers3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 19:22:59 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/09 13:32:27 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_spe_hexa(t_format *fmts, va_list args, int upcase)
{
	unsigned int	n;
	int				count;
	int				digits;

	count = 0;
	n = va_arg(args, int);
	digits = ft_count_digits(n, 16, fmts);
	if (fmts->type == 'X')
		upcase = 1;
	if (!n)
		fmts->hash = 0;
	if (!fmts->zero || (fmts->precision > -1 && fmts->precision < fmts->width))
		if (ft_width(fmts->width - ft_max(digits, fmts->precision)
				- (2 * fmts->hash), 0, 0, &count) == -1)
			return (-1);
	if (ft_put_hash_count(fmts, &count) == -1)
		return (-1);
	if (fmts->zero && (fmts->precision < 0))
		if (ft_width(fmts->width - ft_max(digits, fmts->precision)
				- (2 * fmts->hash), 0, fmts->zero, &count) == -1)
			return (-1);
	if (ft_hexa_uint_precision(n, upcase, fmts, &count) == -1)
		return (-1);
	return (count);
}

int	ft_spe_hexa_minus(t_format *fmts, va_list args, int upcase)
{
	unsigned int	n;
	int				count;

	count = 0;
	n = va_arg(args, int);
	if (fmts->type == 'X')
		upcase = 1;
	if (!n)
		fmts->hash = 0;
	if (ft_put_hash_count(fmts, &count) == -1)
		return (-1);
	if (ft_hexa_uint_precision(n, upcase, fmts, &count) == -1)
		return (-1);
	if (ft_width(fmts->width - count, 0, 0, &count) == -1)
		return (-1);
	return (count);
}

int	ft_spe_percent(t_format *fmts)
{
	int	count;

	count = 0;
	if (fmts->type == '%')
		if (ft_putchar_count('%', &count) == -1)
			return (-1);
	return (count);
}
