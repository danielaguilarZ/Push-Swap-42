/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:28:54 by daguilar          #+#    #+#             */
/*   Updated: 2023/10/02 13:30:48 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*noodle;
	t_list	*new;

	new = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		noodle = ft_lstnew(0);
		if (!noodle)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		noodle->content = f(lst->content);
		ft_lstadd_back(&new, noodle);
		lst = lst->next;
	}
	return (new);
}
