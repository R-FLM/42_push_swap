/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:04:14 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/10 13:16:44 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*lstfree;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		del(current->content);
		lstfree = current;
		current = current->next;
		free(lstfree);
	}
	*lst = NULL;
}
