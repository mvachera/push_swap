/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:14:51 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/26 18:56:12 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

void				one_arg(t_list **lst, char *av1);
void				several_arg(t_list **lst, int ac, char **av);
char				**ft_split(char const *s, char c);
void				new_node(t_list **list, char *avi);
int					doublon(t_list *lst);
int					check(char *str);
t_list				*get_last_node(t_list *lst);
long int			ft_atoi(char *nptr);
void				free_lst(t_list *lst);
void				free_map(char **map_a_parser);
int					lstnb(t_list *all_line);
int					*create_tab(t_list *lst);
int					min_pos(t_list *lst);
void				min_top_5(t_list **lst, t_list **pileB);
void				min_top_4(t_list **lst, t_list **pileB);
void				sa(t_list **lst);
void				pa(t_list **pile1, t_list **pile2);
void				ra(t_list **lst);
void				rra(t_list **lst);
void				sb(t_list **lst);
void				pb(t_list **pile1, t_list **pile2);
void				rb(t_list **lst);
void				rrb(t_list **lst);
void				swap_pile(t_list **lst, t_list **pileB);
void				two_numbers(t_list **lst);
void				tree_numbers(t_list **lst);
void				five_numbers(t_list **lst, t_list **pileB);
int					check_lst(t_list *lst);
void				sort_int_tab(int *tab, t_list *lst);
void				push_swap(t_list **lst, t_list **pileB);
int					get_pos_node(t_list *lst, t_list *current);
void				push_to_pile_b(t_list **lst, t_list **pileB);
void				spa_facile(t_list **lst, t_list **pileB);
int					price(int taille_pile, int index);
int					second_price(t_list *lst, int content);
int					total_price(int price_a, int price_b);
void				push_to_pile_a(t_list **lst, t_list **pileB, int best_p_a,
						int best_p_b);
void				rr(t_list **lst, t_list **pileB);
void				rrr(t_list **lst, t_list **pileB);
void				put_min_top(t_list **lst);
int					get_min_pos(t_list *lst);
int					get_max_content(t_list *lst);
int					get_pos_max(t_list *lst);
void				help(t_list **lst, t_list **pileB, t_list *current);
void				help2(t_list **lst, t_list **pileB, int b_p_a);
void				help3(t_list **lst, t_list **pileB, int b_p_a);
void				help_final(t_list **lst, t_list **pileB, int *tmp,
						int *b_p);
int					get_min_content(t_list *lst);

#endif
