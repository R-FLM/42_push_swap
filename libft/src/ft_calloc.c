/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 08:39:56 by flomulle          #+#    #+#             */
/*   Updated: 2025/11/11 09:34:32 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((nmemb != 0) && (size > (~(size_t)0) / nmemb))
		return (NULL);
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		p[i] = '\0';
		i++;
	}
	return ((void *)p);
}
