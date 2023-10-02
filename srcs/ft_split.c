/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:17:43 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/08 17:21:29 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		m;

	i = 0;
	count = 0;
	m = 0;
	while (s[i])
	{
		if (s[i] != c && m == 0)
		{
			count++;
			m = 1;
		}
		if (s[i] == c)
			m = 0;
		i++;
	}
	return (count);
}

static size_t	lword(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_cpy(char const *s, char c)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc(sizeof(char) * (lword(s, c) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < lword(s, c))
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	**liberer_les_reufs(char const *s, char c, char **result)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			result[i] = ft_cpy(s, c);
			if (!result[i])
			{
				while (i >= 0)
					free(result[i--]);
				return (NULL);
			}
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	result[i] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	result = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!result || !s)
		return (NULL);
	return (liberer_les_reufs(s, c, result));
}
