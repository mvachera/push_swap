/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:22:18 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/23 17:07:35 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	one_arg(t_list **lst, char *av1)
{
	char	**arg;
	int		i;

	i = 0;
	arg = ft_split(av1, ' ');
	if (!arg)
		return (free_map(arg), free_lst(*lst), exit(0));
	while (arg[i])
	{
		if (!arg[i] || !*arg[i])
		{
			ft_printf("Error\n");
			return (free_map(arg), free_lst(*lst), exit(0));
		}
		if (check(arg[i]) == 0)
			return (free_map(arg), free_lst(*lst), exit(0));
		new_node(lst, arg[i]);
		if (!lst)
			return (free_map(arg), free_lst(*lst));
		i++;
	}
	if (lstnb(*lst) == 0)
		return (free_map(arg), ft_printf("Error\n"), exit(0));
	free_map(arg);
}

void	several_arg(t_list **lst, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!av[i] || !*av[i])
		{
			ft_printf("Error\n");
			return (free_lst(*lst), exit(0));
		}
		if (check(av[i]) == 0)
			return (free_lst(*lst), exit(0));
		new_node(lst, av[i]);
		if (!lst)
			return (free_lst(*lst));
		i++;
	}
}

int	main(int ac, char **av)
{
	static t_list	*lst;
	static t_list	*pile_b;

	lst = NULL;
	pile_b = NULL;
	if (ac < 2)
		return (ft_printf("Error\n"), 0);
	else if (ac == 2)
	{
		one_arg(&lst, av[1]);
		if (doublon(lst) == 0 || lstnb(lst) == 1)
			return (free_lst(lst), 0);
	}
	else if (ac > 2)
	{
		several_arg(&lst, ac, av);
		if (doublon(lst) == 0)
			return (free_lst(lst), 0);
	}
	push_swap(&lst, &pile_b);
	free_lst(lst);
	return (0);
}
