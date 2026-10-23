/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:59:12 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/10 13:16:09 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_parse_specifier(const char **format, t_format *fmts)
{
	if (**format && ft_strchr("cspdiuxX%", **format))
	{
		fmts->type = **format;
		(*format)++;
		return (1);
	}
	return (0);
}

void	ft_parse_precision(const char **format, t_format *fmts)
{
	if (**format == '.')
	{
		fmts->dot = 1;
		(*format)++;
		if (ft_isdigit(**format))
		{
			fmts->precision = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
	}
	if (fmts->dot == 1 && fmts->precision == -1)
		fmts->precision = 0;
}

void	ft_parse_width(const char **format, t_format *fmts)
{
	if (ft_isdigit(**format))
	{
		fmts->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

void	ft_parse_flags(const char **format, t_format *fmt)
{
	while (**format && ft_strchr("-0# +", **format))
	{
		if (**format == '-')
			fmt->minus = 1;
		else if (**format == '0')
			fmt->zero = 1;
		else if (**format == '#')
			fmt->hash = 1;
		else if (**format == ' ')
			fmt->space = 1;
		else if (**format == '+')
			fmt->plus = 1;
		(*format)++;
	}
}

int	ft_parse_format(const char *format, va_list args)
{
	t_format	fmts;
	int			tmp_count;
	int			count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_init_fmts(&fmts);
			ft_parse_flags(&format, &fmts);
			ft_parse_width(&format, &fmts);
			ft_parse_precision(&format, &fmts);
			if (!ft_parse_specifier(&format, &fmts))
				continue ;
			tmp_count = ft_specifiers(&fmts, args);
			if (tmp_count == -1)
				return (-1);
			count += tmp_count;
		}
		else
			count += ft_putchar_count(*format++, &count);
	}
	return (count);
}
