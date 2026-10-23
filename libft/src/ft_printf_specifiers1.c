/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifiers1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:27:18 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/09 13:32:18 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_spe_char(t_format *fmts, va_list args)
{
	char	c;
	int		count;
	int		tmp_count;

	count = 0;
	c = (char)va_arg(args, int);
	if (fmts->minus)
	{
		tmp_count = ft_putchar_count(c, &count);
		if (tmp_count == -1)
			return (-1);
		tmp_count = ft_width(fmts->width - 1, 0, 0, &count);
	}
	else
	{
		tmp_count = ft_width(fmts->width - 1, 0, 0, &count);
		if (tmp_count == -1)
			return (-1);
		tmp_count = ft_putchar_count(c, &count);
	}
	if (tmp_count == -1)
		return (-1);
	return (count);
}

int	ft_spe_string(t_format *fmts, va_list args)
{
	char	*s;
	int		count;
	int		len;

	count = 0;
	s = va_arg(args, char *);
	if (!s)
		return (ft_ptrnull(fmts, &count));
	len = ft_strlen(s);
	if (fmts->dot > 0 && fmts->precision < len && fmts->precision >= 0)
		len = fmts->precision;
	if (ft_width(fmts->width - len, 0, 0, &count) == -1)
		return (-1);
	if (ft_putstr_count(s, len, &count) == -1)
		return (-1);
	return (count);
}

int	ft_spe_string_minus(t_format *fmts, va_list args)
{
	char	*s;
	int		count;
	int		len;

	count = 0;
	s = va_arg(args, char *);
	if (!s)
		return (ft_ptrnull(fmts, &count));
	len = ft_strlen(s);
	if (fmts->dot > 0 && fmts->precision < len && fmts->precision >= 0)
		len = fmts->precision;
	if (ft_putstr_count(s, len, &count) == -1)
		return (-1);
	if (ft_width(fmts->width - len, 0, 0, &count) == -1)
		return (-1);
	return (count);
}

int	ft_spe_pointer(t_format *fmts, va_list args)
{
	unsigned long	address;
	int				count;
	int				len;

	count = 0;
	address = (unsigned long)(va_arg(args, void *));
	len = ft_count_udigits(address, 16, fmts) + 2;
	if (!address)
		return (ft_addressnull(fmts, &count));
	if (!fmts->zero || (fmts->precision != -1 && fmts->precision < len))
		if (ft_width(fmts->width - len - ft_max(fmts->plus, fmts->space),
				0, 0, &count) == -1)
			return (-1);
	if (ft_plus_space(fmts, &count) == -1)
		return (-1);
	if (ft_putstr_count("0x", 2, &count) == -1)
		return (-1);
	if (fmts->zero && (fmts->precision == -1 || fmts->precision > len))
		if (ft_width(fmts->width - len - ft_max(fmts->plus, fmts->space),
				0, fmts->zero, &count) == -1)
			return (-1);
	if (ft_puthexa_count(address, 0, &count) == -1)
		return (-1);
	return (count);
}

int	ft_spe_pointer_minus(t_format *fmts, va_list args)
{
	unsigned long	address;
	int				count;
	int				len;

	count = 0;
	address = (unsigned long)va_arg(args, void *);
	len = ft_count_udigits(address, 16, fmts) + 2;
	if (!address)
		return (ft_addressnull(fmts, &count));
	if (ft_plus_space(fmts, &count) == -1)
		return (-1);
	if (ft_putstr_count("0x", 2, &count) == -1)
		return (-1);
	if (ft_puthexa_count(address, 0, &count) == -1)
		return (-1);
	if (ft_width(fmts->width - len - ft_max(fmts->plus, fmts->space),
			0, 0, &count) == -1)
		return (-1);
	return (count);
}
