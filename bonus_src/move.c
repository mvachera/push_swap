/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:45:15 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/26 20:53:06 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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

int	check_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	free_map(char **map_a_parser)
{
	int	i;

	i = 0;
	while (map_a_parser[i])
	{
		free(map_a_parser[i]);
		i++;
	}
	free(map_a_parser);
}

void	free_lst(t_list *lst)
{
	t_list	*current;
	t_list	*next;

	current = lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int	lstnb(t_list *lst)
{
	t_list	*current;
	int		i;

	current = lst;
	i = 0;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}
