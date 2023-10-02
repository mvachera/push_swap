/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:38:54 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/27 20:57:37 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	several_arg(t_list **lst, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!av[i] || !*av[i])
		{
			write(2, "Error\n", 6);
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
			write(2, "Error\n", 6);
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
		return (free_map(arg), write(2, "Error\n", 6), exit(0));
	free_map(arg);
}

void	print_lst(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current)
	{
		ft_printf("%d\n", current->content);
		current = current->next;
	}
}

void	error(t_list **lst, t_list **pileB, char *line)
{
	if (lstnb(*lst) != 0)
		free_lst(*lst);
	if (lstnb(*pileB) != 0)
		free_lst(*pileB);
	free(line);
	get_next_line(0, 1);
	write(2, "Error\n", 6);
	exit (1);
}
