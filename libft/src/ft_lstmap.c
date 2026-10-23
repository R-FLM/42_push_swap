/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:26:23 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/10 13:16:28 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newcurrent;
	void	*newcontent;

	if (!lst)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		newcontent = f(lst->content);
		newcurrent = ft_lstnew(newcontent);
		if (!newcurrent)
		{
			del(newcontent);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newcurrent);
		lst = lst->next;
	}
	return (newlst);
}
