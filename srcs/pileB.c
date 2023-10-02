/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pileB.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:36:28 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/26 18:11:08 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list **lst)
{
	t_list	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		tmp->next = (*lst)->next;
		(*lst)->next = tmp;
		ft_printf("sb\n");
	}
}

void	pb(t_list **pile1, t_list **pile2)
{
	t_list	*tmp;

	if (*pile2)
	{
		tmp = *pile2;
		*pile2 = (*pile2)->next;
		tmp->next = *pile1;
		*pile1 = tmp;
		ft_printf("pb\n");
	}
}

void	rb(t_list **lst)
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
		ft_printf("rb\n");
	}
}

void	rrb(t_list **lst)
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
		ft_printf("rrb\n");
	}
}

int	get_min_content(t_list *lst)
{
	t_list	*current;
	int		min;

	current = lst;
	min = 2147483647;
	while (current)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	return (min);
}
