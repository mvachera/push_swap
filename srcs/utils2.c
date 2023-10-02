/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:02:58 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/26 14:40:20 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	*create_tab(t_list *lst)
{
	int		*tab;
	int		i;
	t_list	*current;

	i = 0;
	current = lst;
	tab = malloc(sizeof(int) * lstnb(lst));
	if (!tab)
	{
		free_lst(lst);
		exit(0);
	}
	while (current)
	{
		tab[i] = current->content;
		current = current->next;
		i++;
	}
	return (tab);
}
