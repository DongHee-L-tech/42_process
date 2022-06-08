/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donlee <donlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:33:17 by donlee            #+#    #+#             */
/*   Updated: 2022/01/15 12:41:49 by donlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**malloc_is_free(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static unsigned int	ft_strscount(char const *s, char c)
{
	unsigned int	i;
	unsigned int	strs_count;

	if (!s[0])
		return (0);
	i = 0;
	strs_count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			strs_count++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		strs_count++;
	return (strs_count);
}

static void	ft_str_start(char **str_start, unsigned int *str_len, char c)
{
	unsigned int	i;

	*str_start += *str_len;
	*str_len = 0;
	i = 0;
	while (**str_start && **str_start == c)
		(*str_start)++;
	while ((*str_start)[i])
	{
		if ((*str_start)[i] == c)
			return ;
		(*str_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	char			*str_start;
	unsigned int	str_len;
	unsigned int	strs_count;
	unsigned int	i;

	if (!s)
		return (NULL);
	strs_count = ft_strscount(s, c);
	tab = (char **)malloc(sizeof(char *) * (strs_count + 1));
	if (!tab)
		return (NULL);
	i = 0 - 1;
	str_len = 0;
	str_start = (char *)s;
	while (++i < strs_count)
	{
		ft_str_start(&str_start, &str_len, c);
		tab[i] = (char *)malloc(sizeof(char) * (str_len + 1));
		if (!tab[i])
			return (malloc_is_free(tab));
		ft_strlcpy(tab[i], str_start, str_len + 1);
	}
	tab[i] = NULL;
	return (tab);
}
