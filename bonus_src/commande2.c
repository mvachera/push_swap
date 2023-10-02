/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:11:51 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/23 17:24:26 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	sa2(t_list **lst)
{
	t_list	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		tmp->next = (*lst)->next;
		(*lst)->next = tmp;
	}
}

void	pa2(t_list **pile1, t_list **pile2)
{
	t_list	*tmp;

	if (*pile2)
	{
		tmp = *pile2;
		*pile2 = (*pile2)->next;
		tmp->next = *pile1;
		*pile1 = tmp;
	}
}

void	ra2(t_list **lst)
{
	t_list	*last;
	t_list	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = *lst;
		last = get_last_node(*lst);
		last->next = tmp;
		*lst = tmp->next;
		tmp->next = NULL;
	}
}

void	rra2(t_list **lst)
{
	t_list	*last;
	t_list	*tmp;

	if (*lst && (*lst)->next)
	{
		last = get_last_node(*lst);
		tmp = *lst;
		while (tmp->next != last)
			tmp = tmp->next;
		tmp->next = NULL;
		last->next = *lst;
		*lst = last;
	}
}

void	rr2(t_list **lst, t_list **pileB)
{
	t_list	*last;
	t_list	*tmp;
	t_list	*last2;
	t_list	*tmp2;

	if (*lst && (*lst)->next)
	{
		tmp = *lst;
		last = get_last_node(*lst);
		last->next = tmp;
		*lst = tmp->next;
		tmp->next = NULL;
	}
	if (*pileB && (*pileB)->next)
	{
		tmp2 = *pileB;
		last2 = get_last_node(*pileB);
		last2->next = tmp2;
		*pileB = tmp2->next;
		tmp2->next = NULL;
	}
}
