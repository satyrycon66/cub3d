/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siroulea <siroulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:30:05 by siroulea          #+#    #+#             */
/*   Updated: 2023/06/14 15:59:36 by siroulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_itoa2(unsigned int nb, int len, long long i, int sign)
{
	char	*res;

	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	i = len - 1;
	while (i >= 0)
	{
		res[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	if (sign == -1)
		res[0] = '-';
	return (res);
}

char	*ft_itoa(int n)
{
	long long		i;
	int				len;
	char			*res;
	int				sign;
	unsigned int	nb;

	sign = 1;
	nb = n;
	if (n < 0)
	{
		sign = -1;
		nb = -n;
	}
	if (n <= 0)
		len = 1;
	else
		len = 0;
	i = nb;
	while (i > 0)
	{
		i /= 10;
		len++;
	}
	res = ft_itoa2(nb, len, i, sign);
	return (res);
}
