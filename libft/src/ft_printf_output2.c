/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 22:42:39 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/10 13:16:15 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexa_count(unsigned long n, int upcase, int *count)
{
	int		tmp_count;
	char	*base;

	if (upcase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		tmp_count = ft_puthexa_count(n / 16, upcase, count);
		if (tmp_count == -1)
			return (-1);
	}
	tmp_count = ft_putchar_count(base[n % 16], count);
	if (tmp_count == -1)
		return (-1);
	return (0);
}

int	ft_puthexa_uint_count(unsigned int n, int upcase, int *count)
{
	int		tmp_count;
	char	*base;

	if (upcase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		tmp_count = ft_puthexa_count(n / 16, upcase, count);
		if (tmp_count == -1)
			return (-1);
	}
	tmp_count = ft_putchar_count(base[n % 16], count);
	if (tmp_count == -1)
		return (-1);
	return (0);
}

int	ft_put_hash_count(t_format *fmts, int *count)
{
	if (fmts->hash && fmts->type == 'x')
		if (ft_putstr_count("0x", 2, count) == -1)
			return (-1);
	if (fmts->hash && fmts->type == 'X')
		if (ft_putstr_count("0X", 2, count) == -1)
			return (-1);
	return (0);
}
