/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muballou <muballou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 10:52:25 by muballou          #+#    #+#             */
/*   Updated: 2026/10/31 19:59:37 by muballou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*n;

	if (!s || !f)
		return (NULL);
	n = ft_strdup(s);
	if (!n)
		return (NULL);
	i = 0;
	while (n[i])
	{
		n[i] = f(i, s[i]);
		i++;
	}
	return (n);
}
