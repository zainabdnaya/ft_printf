/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool2_funct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 02:02:55 by zdnaya            #+#    #+#             */
/*   Updated: 2020/01/15 19:27:55 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n)
{
	int				r;
	unsigned int	len;
	char			*arr;
	int				sign;

	sign = 0;
	len = ft_intlen(n);
	arr = NULL;
	arr = (char *)myalloc(arr, n, &sign);
	if (arr == NULL)
		return (NULL);
	while (0 < len)
	{
		if (n < 0)
			r = (n % 10) * (-1);
		else
			r = n % 10;
		arr[len + sign - 1] = r + '0';
		n = n / 10;
		len--;
	}
	return (arr);
}

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dup = (char *)malloc(sizeof(char) * i + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int		mine_strlen(char *s)
{
	int j;

	j = 0;
	while (s[j])
	{
		j++;
	}
	return (j);
}

int		ft_uintlen(unsigned int n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

size_t	ft_intlen(int n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
