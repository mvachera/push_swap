/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:14:07 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/26 15:03:51 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_lst(t_list *lst)
{
	t_list	*current;
	t_list	*next;

	current = lst;
	next = lst->next;
	while (next)
	{
		if (current->content > next->content)
			return (1);
		current = current->next;
		next = next->next;
	}
	return (0);
}

void	sort_int_tab(int *tab, t_list *lst)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < lstnb(lst) - 1)
	{
		j = i + 1;
		while (j < lstnb(lst))
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	get_pos_node(t_list *lst, t_list *current)
{
	t_list	*actuel;
	int		i;

	actuel = lst;
	i = 0;
	while (actuel && (actuel->content != current->content))
	{
		i++;
		actuel = actuel->next;
	}
	return (i);
}

void	push_to_pile_b(t_list **lst, t_list **pileB)
{
	int		*tab;
	int		size;
	int		mediane;
	t_list	*current;

	current = *lst;
	tab = create_tab(*lst);
	sort_int_tab(tab, *lst);
	mediane = tab[lstnb(*lst) / 2];
	size = lstnb(*lst);
	while (size > 5)
	{
		if ((*lst)->content >= mediane)
		{
			free(tab);
			pb(pileB, lst);
			size--;
			tab = create_tab(*lst);
			sort_int_tab(tab, *lst);
			mediane = tab[lstnb(*lst) / 7 * 5];
		}
		else
			ra(lst);
	}
	free(tab);
}

void	help(t_list **lst, t_list **pileB, t_list *current)
{
	int	pos;
	int	all_size;
	int	half_size;

	pos = get_pos_node(*lst, current);
	all_size = lstnb(*lst);
	half_size = lstnb(*lst) / 2;
	if (pos > half_size)
	{
		while (pos != all_size)
		{
			rra(lst);
			pos++;
		}
	}
	else if (pos <= half_size)
	{
		while (pos != 0)
		{
			ra(lst);
			pos--;
		}
	}
	pb(pileB, lst);
}
