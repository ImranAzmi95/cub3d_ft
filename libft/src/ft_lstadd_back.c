/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:51:31 by iazmi             #+#    #+#             */
/*   Updated: 2024/06/18 16:56:41 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Adds the node ’new_lst’ at the end of the list.
*/
void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	t_list	*tmp;

	if (lst && new_lst)
	{
		if (*lst)
		{
			tmp = ft_lstlast(*lst);
			tmp->next = new_lst;
		}
		else
			*lst = new_lst;
	}
}
