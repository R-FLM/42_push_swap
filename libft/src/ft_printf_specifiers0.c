/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifiers0.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:31:39 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/09 13:32:12 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_fmts(t_format *fmts)
{
	fmts->width = -1;
	fmts->precision = -1;
	fmts->minus = 0;
	fmts->zero = 0;
	fmts->dot = 0;
	fmts->hash = 0;
	fmts->space = 0;
	fmts->plus = 0;
	fmts->type = 0;
}

int	ft_specifiers(t_format *fmts, va_list args)
{
	if (fmts->type == 'c')
		return (ft_spe_char(fmts, args));
	else if (fmts->type == 's' && fmts->minus == 0)
		return (ft_spe_string(fmts, args));
	else if (fmts->type == 's' && fmts->minus > 0)
		return (ft_spe_string_minus(fmts, args));
	else if (fmts->type == 'p' && fmts->minus == 0)
		return (ft_spe_pointer(fmts, args));
	else if (fmts->type == 'p' && fmts->minus > 0)
		return (ft_spe_pointer_minus(fmts, args));
	else if ((fmts->type == 'd' || fmts->type == 'i') && !fmts->minus)
		return (ft_spe_int(fmts, args));
	else if ((fmts->type == 'd' || fmts->type == 'i') && fmts->minus)
		return (ft_spe_int_minus(fmts, args));
	else if (fmts->type == 'u' && fmts->minus == 0)
		return (ft_spe_uint(fmts, args));
	else if (fmts->type == 'u' && fmts->minus > 0)
		return (ft_spe_uint_minus(fmts, args));
	else if ((fmts->type == 'x' || fmts->type == 'X') && !fmts->minus)
		return (ft_spe_hexa(fmts, args, 0));
	else if ((fmts->type == 'x' || fmts->type == 'X') && fmts->minus)
		return (ft_spe_hexa_minus(fmts, args, 0));
	else if (fmts->type == '%')
		return (ft_spe_percent(fmts));
	return (0);
}
