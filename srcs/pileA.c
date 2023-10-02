/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:54:34 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/11 16:29:41 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **lst)
{
	t_list	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		tmp->next = (*lst)->next;
		(*lst)->next = tmp;
		ft_printf("sa\n");
	}
}

void	pa(t_list **pile1, t_list **pile2)
{
	t_list	*tmp;

	if (*pile2)
	{
		tmp = *pile2;
		*pile2 = (*pile2)->next;
		tmp->next = *pile1;
		*pile1 = tmp;
		ft_printf("pa\n");
	}
}

void	ra(t_list **lst)
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
		ft_printf("ra\n");
	}
}

void	rra(t_list **lst)
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
		ft_printf("rra\n");
	}
}
