/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muballou <muballou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 10:49:37 by muballou          #+#    #+#             */
/*   Updated: 2026/11/03 19:12:06 by muballou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_neg(long nb)
{
	if (nb < 0)
		return (-1);
	return (1);
}

static size_t	count_len(long nb)
{
	size_t	len;

	len = 0;
	if (nb == 0)
	{
		len++;
		return (len);
	}
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static void	ft_fill(char *str, int len, long nb)
{
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	int		x;
	long	nb;

	nb = (long)n;
	len = 0;
	x = ft_neg(nb);
	if (x == -1)
	{
		nb *= -1;
		len++;
	}
	len += count_len(nb);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ft_fill(str, len, nb);
	if (x == -1)
		str[0] = '-';
	return (str);
}
