/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:30:50 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/10 13:16:18 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_count(char c, int *count)
{
	int	tmp_count;

	tmp_count = write(1, &c, 1);
	if (tmp_count == -1)
		return (-1);
	*count += tmp_count;
	return (0);
}

int	ft_putstr_count(char *s, int slen, int *count)
{
	int	i;
	int	tmp_count;

	if (!s)
		return (ft_putstr_count("(null)", 6, count));
	i = 0;
	while (i < slen)
	{
		tmp_count = ft_putchar_count(s[i], count);
		if (tmp_count == -1)
			return (-1);
		*count += tmp_count;
		i++;
	}
	return (0);
}

int	ft_putnbr_count(long n, int *count)
{
	int	tmp_count;

	if (n < 0)
	{
		n *= -1;
		tmp_count = ft_putchar_count('-', count);
		if (tmp_count == -1)
			return (-1);
	}
	if (n > 9)
	{
		tmp_count = ft_putnbr_count(n / 10, count);
		if (tmp_count == -1)
			return (-1);
	}
	tmp_count = ft_putchar_count((n % 10) + '0', count);
	if (tmp_count == -1)
		return (-1);
	return (0);
}
