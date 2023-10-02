/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:33:36 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/26 18:10:02 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **lst, t_list **pileB)
{
	t_list	*tmp;

	tmp = *pileB;
	if (check_lst(*lst) == 0)
		return ;
	if (lstnb(*lst) <= 5)
		swap_pile(lst, pileB);
	else
	{
		push_to_pile_b(lst, pileB);
		five_numbers(lst, pileB);
		spa_facile(lst, pileB);
		put_min_top(lst);
	}
}

void	swap_pile(t_list **lst, t_list **pileB)
{
	int	size;

	size = lstnb(*lst);
	if (size == 2)
		two_numbers(lst);
	else if (size == 3)
		tree_numbers(lst);
	else if (size == 4 || size == 5)
		five_numbers(lst, pileB);
}

void	two_numbers(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	first = *lst;
	second = (*lst)->next;
	if (second->content < first->content)
		return (sa(lst));
}

void	tree_numbers(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	first = *lst;
	second = (*lst)->next;
	last = get_last_node(*lst);
	if (first->content > second->content && first->content < last->content)
		return (sa(lst));
	else if (first->content > second->content
		&& second->content > last->content)
		return (sa(lst), rra(lst));
	else if (first->content > second->content && second->content < last->content
		&& first->content > last->content)
		return (ra(lst));
	else if (second->content > last->content && last->content > first->content)
		return (sa(lst), ra(lst));
	else if (first->content < second->content && second->content > last->content
		&& first->content > last->content)
		return (rra(lst));
}

void	five_numbers(t_list **lst, t_list **pileB)
{
	min_top_5(lst, pileB);
	min_top_4(lst, pileB);
	tree_numbers(lst);
	pa(lst, pileB);
	pa(lst, pileB);
}
