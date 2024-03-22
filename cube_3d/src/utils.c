/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siroulea <siroulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:26:11 by siroulea          #+#    #+#             */
/*   Updated: 2024/03/22 11:12:48 by siroulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strlenj(char **str)
{
	int	j;

	j = 0;
	if (!str)
		return (0);
	while (str[j])
		j++;
	return (j);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	else
		return (NULL);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(nitems * size);
	if (ptr == NULL)
		return (NULL);
	while (i < (nitems * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

void	*ft_free(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (NULL);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;
	int	i;

	i = 0;
	res = 0;
	sign = 1;
	if (!str)
		return (0);
	while (((str[i] != '\0' && str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if ((str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] != '\0' && str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	res *= sign;
	return (res);
}

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
