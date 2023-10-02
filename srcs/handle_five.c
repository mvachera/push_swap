/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:07:26 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/12 19:14:05 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_pos(t_list *lst)
{
	t_list	*current;
	t_list	*min;
	int		i;
	int		j;

	current = lst;
	min = lst;
	i = 0;
	j = 0;
	while (current)
	{
		if (min->content > current->content)
		{
			min = current;
			j = i;
		}
		current = current->next;
		i++;
	}
	return (j);
}

void	min_top_5(t_list **lst, t_list **pileB)
{
	int	min;

	min = min_pos(*lst);
	if (lstnb(*lst) == 5)
	{
		if (min == 0)
			return (pb(pileB, lst));
		if (min == 1)
			return (ra(lst), pb(pileB, lst));
		if (min == 2)
			return (ra(lst), ra(lst), pb(pileB, lst));
		if (min == 3)
			return (rra(lst), rra(lst), pb(pileB, lst));
		if (min == 4)
			return (rra(lst), pb(pileB, lst));
	}
}

void	min_top_4(t_list **lst, t_list **pileB)
{
	int	min;

	min = min_pos(*lst);
	if (lstnb(*lst) == 4)
	{
		if (min == 0)
			return (pb(pileB, lst));
		if (min == 1)
			return (ra(lst), pb(pileB, lst));
		if (min == 2)
			return (ra(lst), ra(lst), pb(pileB, lst));
		if (min == 3)
			return (rra(lst), pb(pileB, lst));
	}
}
