/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:32:43 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/26 15:32:00 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	sb2(t_list **lst)
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

void	pb2(t_list **pile1, t_list **pile2)
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

void	rb2(t_list **lst)
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

void	rrb2(t_list **lst)
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

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while ((str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return (1);
	i++;
	}
	return (0);
}
