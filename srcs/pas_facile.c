/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pas_facile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:57:37 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/26 18:01:31 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	spa_facile(t_list **lst, t_list **pileB)
{
	int		size;
	int		tmp[3];
	int		best_price[2];

	size = lstnb(*pileB);
	while (size > 0)
	{
		help_final(lst, pileB, tmp, best_price);
		push_to_pile_a(lst, pileB, best_price[0], best_price[1]);
		size--;
	}
}

int	price(int taille_pile, int index)
{
	int	price;

	price = 0;
	if (index > taille_pile / 2)
		price = taille_pile - index;
	else
		price = -index;
	return (price);
}

int	second_price(t_list *lst, int content)
{
	t_list	*current;
	t_list	*prev;
	int		i;
	int		index;

	current = lst;
	prev = get_last_node(lst);
	i = 0;
	index = 0;
	if (content > get_max_content(lst) || content < get_min_content(lst))
		return (get_min_pos(lst));
	while (current)
	{
		if (content < current->content && content > prev->content)
			index = i;
		i++;
		prev = current;
		current = current->next;
	}
	return (index);
}

int	total_price(int price_a, int price_b)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (price_a < 0)
		a = price_a * -1;
	else if (price_a > 0)
		a = price_a;
	if (price_b < 0)
		b = price_b * -1;
	else if (price_b > 0)
		b = price_b;
	if ((price_a < 0 && price_b < 0) || (price_a > 0 && price_b > 0))
	{
		if (a >= b)
			return (a);
		return (b);
	}
	return (a + b);
}

void	push_to_pile_a(t_list **lst, t_list **pileB, int b_p_a, int b_p_b)
{
	while (b_p_b > 0)
	{
		help2(lst, pileB, b_p_a);
		if (b_p_a > 0)
			b_p_a--;
		b_p_b--;
	}
	while (b_p_a > 0)
	{
		rrb(pileB);
		b_p_a--;
	}
	while (b_p_b < 0)
	{
		help3(lst, pileB, b_p_a);
		if (b_p_a < 0)
			b_p_a++;
		b_p_b++;
	}
	while (b_p_a < 0)
	{
		rb(pileB);
		b_p_a++;
	}
	pa(lst, pileB);
}
