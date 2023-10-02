/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:15:33 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/26 18:10:52 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_content(t_list *lst)
{
	t_list	*current;
	int		max;

	current = lst;
	max = 0;
	while (current)
	{
		if (current->content > max)
			max = current->content;
		current = current->next;
	}
	return (max);
}

int	get_pos_max(t_list *lst)
{
	t_list	*current;
	int		max;
	int		i;
	int		j;

	current = lst;
	max = get_max_content(lst);
	i = 0;
	j = 0;
	while (current)
	{
		if (current->content == max)
			j = i;
		i++;
		current = current->next;
	}
	return (j);
}

void	help2(t_list **lst, t_list **pileB, int b_p_a)
{
	if (b_p_a > 0)
	{
		rrr(lst, pileB);
		ft_printf("rrr\n");
	}
	else
		rra(lst);
}

void	help3(t_list **lst, t_list **pileB, int b_p_a)
{
	if (b_p_a < 0)
		rr(lst, pileB);
	else
		ra(lst);
}

void	help_final(t_list **lst, t_list **pileB, int *tmp, int *b_p)
{
	t_list	*current;
	int		price_a;
	int		price_b;
	int		max;
	int		i;

	current = *pileB;
	max = 2147483647;
	i = 0;
	tmp[0] = lstnb(*pileB);
	tmp[1] = lstnb(*lst);
	while (current)
	{
		price_a = price(tmp[0], i);
		price_b = price(tmp[1], second_price(*lst, current->content));
		tmp[2] = total_price(price_a, price_b);
		if (max > tmp[2])
		{
			max = tmp[2];
			b_p[0] = price_a;
			b_p[1] = price_b;
		}
		i++;
		current = current->next;
	}
}
