/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:33:23 by flomulle          #+#    #+#             */
/*   Updated: 2025/11/12 10:12:13 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	slen;
	size_t	i;
	char	*ns;

	if (!s || !f)
		return (NULL);
	slen = 0;
	while (s[slen])
		slen++;
	if (slen > ~(unsigned int)0)
		return (NULL);
	ns = (char *)malloc((slen + 1) * sizeof(*ns));
	if (!ns)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		ns[i] = f((unsigned int)i, s[i]);
		i++;
	}
	ns[slen] = '\0';
	return (ns);
}
