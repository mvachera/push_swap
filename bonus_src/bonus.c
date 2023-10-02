/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:32:38 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/27 21:32:46 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	r_p_s2(t_list **lst, t_list **pileB, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa2(lst);
	else if (!ft_strcmp(line, "pa\n"))
		pa2(lst, pileB);
	else if (!ft_strcmp(line, "ra\n"))
		ra2(lst);
	else if (!ft_strcmp(line, "rra\n"))
		rra2(lst);
	else if (!ft_strcmp(line, "sb\n"))
		sb2(pileB);
	else if (!ft_strcmp(line, "pb\n"))
		pb2(pileB, lst);
	else if (!ft_strcmp(line, "rb\n"))
		rb2(pileB);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb2(pileB);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(lst, pileB);
	else if (!ft_strcmp(line, "rr\n"))
		rr2(lst, pileB);
	else
		error(lst, pileB, line);
}

int	read_push_swap(t_list **lst, t_list **pileB)
{
	char	*line;
	int		fd;

	fd = 0;
	while (1)
	{
		line = get_next_line(fd, 0);
		if (!line)
			return (0);
		if (*line == '\n' || *line == '\0')
			return (free(line), 1);
		r_p_s2(lst, pileB, line);
		free(line);
	}
	return (0);
}

int	checker(t_list *lst, t_list *pileB)
{
	if (lstnb(pileB) != 0)
		return (free_lst(pileB), 0);
	if (check_lst(lst) == 0)
		return (0);
	return (1);
}

void	look_arg(int ac, char **av, t_list **lst)
{
	if (ac < 2)
		return (write(2, "Error\n", 6), exit(0));
	if (ac == 2)
	{
		one_arg(lst, av[1]);
		if (doublon(*lst) == 0 || lstnb(*lst) == 1)
			return (free_lst(*lst), exit(0));
	}
	else if (ac > 2)
	{
		several_arg(lst, ac, av);
		if (doublon(*lst) == 0)
			return (free_lst(*lst), exit(0));
	}
}

int	main(int ac, char **av)
{
	static t_list	*lst;
	static t_list	*pile_b;

	lst = NULL;
	pile_b = NULL;
	look_arg(ac, av, &lst);
	if (read_push_swap(&lst, &pile_b))
	{
		free_lst(lst);
		free_lst(pile_b);
		write(2, "Error\n", 6);
		get_next_line(0, 1);
		return (1);
	}
	if (checker(lst, pile_b) == 0)
		write(2, "KO\n", 3);
	else
		write(2, "OK\n", 3);
	free_lst(lst);
	return (0);
}
