/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muballou <muballou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 18:41:58 by muballou          #+#    #+#             */
/*   Updated: 2026/11/03 19:08:51 by muballou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*s;

	if (count == 0 || size == 0)
	{
		size = 1;
		count = 1;
	}
	if ((count * size) / size != count)
		return (NULL);
	s = malloc((count * size));
	if (!s)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}
