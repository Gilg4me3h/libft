/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muballou <muballou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 10:51:40 by muballou          #+#    #+#             */
/*   Updated: 2026/11/01 17:49:51 by muballou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (i == 0 && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
		{
			if (i != 0 && s[i - 1] == c && s[i] != c)
				count++;
			i++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (count);
}

static char	**ft_free(char **s, size_t c)
{
	size_t	i;

	i = 0;
	while (i < c)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static char	**ft_fill(char const *s, char **str, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			str[j] = ft_substr(s, start, i - start);
			if (!str[j])
				return (ft_free(str, j));
			j++;
		}
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	str = malloc(sizeof(char *) * (count + 1));
	if (!str)
		return (NULL);
	return (ft_fill(s, str, c));
}
