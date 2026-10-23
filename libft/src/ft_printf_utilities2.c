/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:52:47 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/09 13:32:35 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_addressnull(t_format *fmts, int *count)
{
	if (fmts->minus == 0)
	{
		if (ft_width(fmts->width - 5, 0, 0, count) == -1)
			return (-1);
		if (ft_putstr_count("(nil)", 5, count) == -1)
			return (-1);
	}
	else
	{
		if (ft_putstr_count("(nil)", 5, count) == -1)
			return (-1);
		if (ft_width(fmts->width - 5, 0, 0, count) == -1)
			return (-1);
	}
	return (*count);
}

int	ft_ptrnull(t_format *fmts, int *count)
{
	if (fmts->precision == -1 && fmts->dot == 1)
		fmts->precision = 0;
	if (fmts->minus == 0)
	{
		if (fmts->precision > 5 || fmts->precision == -1)
			if (ft_width(fmts->width - 6, 0, 0, count) == -1)
				return (-1);
		if (fmts->precision >= 0 && fmts->precision < 6)
			if (ft_width(fmts->width, 0, 0, count) == -1)
				return (-1);
		if (fmts->precision > 5 || fmts->precision == -1)
			if (ft_putstr_count("(null)", 6, count) == -1)
				return (-1);
	}
	else
	{
		if (fmts->precision > 5 || fmts->precision == -1)
			if (ft_putstr_count("(null)", 6, count) == -1)
				return (-1);
		if (ft_width(fmts->width - *count, 0, 0, count) == -1)
			return (-1);
	}
	return (*count);
}
