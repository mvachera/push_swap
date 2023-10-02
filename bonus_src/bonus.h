/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:11:58 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/27 21:15:28 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

void				look_arg(int ac, char **av, t_list **lst);
int					checker(t_list *lst, t_list *pileB);
int					read_push_swap(t_list **lst, t_list **pileB);
void				r_p_s2(t_list **lst, t_list **pileB, char *line);
int					ft_strcmp(char *st1, char *st2);
void				sa2(t_list **lst);
void				pa2(t_list **pile1, t_list **pile2);
void				ra2(t_list **lst);
void				rra2(t_list **lst);
void				sb2(t_list **lst);
void				pb2(t_list **pile1, t_list **pile2);
void				rb2(t_list **lst);
void				rrb2(t_list **lst);
void				rr2(t_list **lst, t_list **pileB);

void				one_arg(t_list **lst, char *av1);
void				several_arg(t_list **lst, int ac, char **av);
char				**ft_split(char const *s, char c);
void				new_node(t_list **list, char *avi);
int					doublon(t_list *lst);
int					check(char *str);
t_list				*get_last_node(t_list *lst);
long int			ft_atoi(char *nptr);
void				free_lst(t_list *lst);
int					lstnb(t_list *all_line);
void				rrr(t_list **lst, t_list **pileB);
int					check_lst(t_list *lst);
void				free_map(char **map_a_parser);
void				print_lst(t_list *lst);
void				error(t_list **lst, t_list **pileB, char *line);

#endif
