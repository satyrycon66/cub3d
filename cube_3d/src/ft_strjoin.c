/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siroulea <siroulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:35:51 by siroulea          #+#    #+#             */
/*   Updated: 2024/03/26 11:05:39 by siroulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strcopie(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strcat(char *dst, const char *src)
{
	size_t	lendest;
	size_t	lensrc;
	size_t	i2;

	if (!src || !dst)
		return (0);
	i2 = 0;
	lendest = ft_strlen(dst);
	lensrc = ft_strlen((char *)src);
	while (((char *)src)[i2])
	{
		dst[lendest] = ((char *)src)[i2];
		lendest++;
		i2++;
	}
	dst[lendest] = 0;
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;

	if (!s1)
		return (NULL);
	dest = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (dest == NULL)
		return (0);
	ft_strcopie(dest, (char *)s1);
	ft_strcat(dest, (char *)s2);
	return (dest);
}
