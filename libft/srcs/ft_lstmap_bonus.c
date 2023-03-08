/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <sylducam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:58:24 by sylducam          #+#    #+#             */
/*   Updated: 2021/08/12 17:36:56 by sylducam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**alst;
	t_list	*tmp;
	t_list	*test;

	if (!lst || !f || !*f)
		return (NULL);
	tmp = NULL;
	alst = &tmp;
	while (lst)
	{
		test = ft_lstnew(f(lst->content));
		if (test == NULL)
		{
			ft_lstclear(alst, del);
			return (NULL);
		}
		else
		{
			ft_lstadd_back(alst, test);
			lst = lst->next;
		}
	}
	return (*alst);
}
