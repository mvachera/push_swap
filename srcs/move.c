/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:45:15 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/19 19:06:16 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_min_top(t_list **lst)
{
	if (get_min_pos(*lst) <= lstnb(*lst) / 2)
	{
		while (get_min_pos(*lst) != 0)
			ra(lst);
	}
	else
	{
		while (get_min_pos(*lst) != 0)
			rra(lst);
	}
}

int	get_min_pos(t_list *lst)
{
	t_list	*current;
	t_list	*min_node;
	int		i;
	int		j;

	current = lst;
	min_node = lst;
	i = 0;
	j = 0;
	while (current)
	{
		if (min_node->content > current->content)
		{
			j = i;
			min_node = current;
		}
		current = current->next;
		i++;
	}
	return (j);
}

void	rr(t_list **lst, t_list **pileB)
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
	ft_printf("rr\n");
}

void	rrr(t_list **lst, t_list **pileB)
{
	t_list	*last;
	t_list	*tmp;
	t_list	*last2;
	t_list	*tmp2;

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
	if (*pileB && (*pileB)->next)
	{
		last2 = get_last_node(*pileB);
		tmp2 = *pileB;
		while (tmp2->next != last2)
			tmp2 = tmp2->next;
		tmp2->next = NULL;
		last2->next = *pileB;
		*pileB = last2;
	}
}
