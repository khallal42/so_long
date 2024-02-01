/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:19:30 by khallal           #+#    #+#             */
/*   Updated: 2022/12/28 21:46:08 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	cont(int k)
{
	int		i;
	long	l;

	l = k;
	i = 0;
	if (l == 0)
	{
		i++;
		return (i);
	}
	if (l < 0)
	{
		l *= (-1);
		i++;
	}
	while (l > 0)
	{
		l = l / 10;
		i++;
	}
	return (i);
}

static char	*min_int(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;

	i = cont(n);
	res = malloc(sizeof(char) * (cont(n) + 1));
	if (!res)
		return (0);
	if (n == -2147483648)
		return (min_int(res, "-2147483648"));
	if (n == 0)
		return (min_int(res, "0"));
	if (n < 0)
	{
		res[0] = '-';
		n *= (-1);
	}
	res[i--] = '\0';
	while (n > 0)
	{
		res[i--] = ((n % 10) + '0');
		n = n / 10;
	}
	return (res);
}
