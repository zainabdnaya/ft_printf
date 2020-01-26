/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool_funct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 01:58:52 by zdnaya            #+#    #+#             */
/*   Updated: 2020/01/14 22:02:37 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return ((char *)s + i);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n-- > 0 && (str1[i] || str2[i]))
	{
		if (str1[i] < str2[i])
			return (str1[i] - str2[i]);
		if (str1[i] > str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

int		operation(const char *str, long lenght, int sign)
{
	long	r;
	int		i;

	r = 0;
	i = 0;
	while (str[lenght] >= 48 && str[lenght] <= 57)
	{
		r = r * 10 + str[lenght] - '0';
		lenght++;
		i++;
	}
	if (i > 19)
	{
		if (sign > 0)
			return (-1);
		else
			return (0);
	}
	return (sign * r);
}

int		ft_atoi(const char *str)
{
	long	lenght;
	int		sign;

	lenght = 0;
	sign = 1;
	while (str[lenght] == ' ' || str[lenght] == '\n' || str[lenght] == '\t' ||
			str[lenght] == '\r' || str[lenght] == '\f' || str[lenght] == '\v')
		lenght++;
	if (str[lenght] == '-' || str[lenght] == '+')
	{
		if (str[lenght] == '-')
			sign *= -1;
		lenght++;
	}
	return (operation(str, lenght, sign));
}

char	*myalloc(char *arr, int n, int *sign)
{
	size_t len;

	len = ft_intlen(n);
	if (n >= 0)
	{
		if (!(arr = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		arr[len] = '\0';
	}
	else
	{
		if (!(arr = (char *)malloc(sizeof(char) * (len + 2))))
			return (NULL);
		*sign = 1;
		arr[0] = '-';
		arr[len + 1] = '\0';
	}
	return (arr);
}
