/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:23:31 by atursun           #+#    #+#             */
/*   Updated: 2024/10/24 10:48:14 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_unit;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!(new_unit = ft_lstnew(content)))
			return (ft_lstclear(&new_lst, del), del(content), NULL);
		ft_lstadd_back(&new_lst, new_unit);
		lst = lst->next;
	}
	return (new_lst);
}
