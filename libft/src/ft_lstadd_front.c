/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:30:33 by iazmi             #+#    #+#             */
/*   Updated: 2024/06/18 17:10:44 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Adds the node ’new_lst’ at the beginning of the list.
lst is the head pointer, it is set to new_lst to update the address of the head.
*/
void	ft_lstadd_front(t_list **lst, t_list *new_lst)
{
	if (lst && new_lst)
	{
		new_lst->next = *lst;
		*lst = new_lst;
	}
}
