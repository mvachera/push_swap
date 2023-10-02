/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:04:33 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/26 20:19:59 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	new_node(t_list **lst, char *avi)
{
	t_list		*new;
	t_list		*last;
	long int	tmp;

	tmp = ft_atoi(avi);
	if (!(tmp >= -2147483648 && tmp <= 2147483647))
	{
		write(2, "Error\n", 6);
		free_lst(*lst);
		exit(0);
		return ;
	}
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->content = tmp;
	new->next = NULL;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = get_last_node(*lst);
	last->next = new;
}

int	doublon(t_list *lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = lst;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->content == tmp2->content)
				return (write(2, "Error\n", 6), 0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int	check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '-')
		{
			return (write(2, "Error\n", 6),
				0);
		}
		i++;
		if (str[i] == '-')
			return (write(2, "Error\n", 6),
				0);
	}
	return (1);
}

t_list	*get_last_node(t_list *lst)
{
	t_list	*last;

	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

long int	ft_atoi(char *nptr)
{
	long int	i;
	long int	num;
	long int	sign;

	i = 0;
	num = 0;
	sign = 1;
	if (nptr[i] == '\0')
		return (0);
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			return (2147483648);
		i++;
	}
	return (sign * num);
}
