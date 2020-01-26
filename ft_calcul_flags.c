/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:05:12 by zdnaya            #+#    #+#             */
/*   Updated: 2020/01/18 11:48:26 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_check_number(t_print *str)
{
	int sign;
	int j;

	sign = 1;
	j = str->j - 1;
	while (ft_strchr(".cspdiuxX%", str->format[++j]) == NULL)
	{
		if (str->format[j] == '-')
			sign = -1;
		(sign < 0 ? j++ : 0);
		if (str->format[j] == '*')
		{
			str->etoile = 1;
			if (str->format[j + 1] == '.')
				j += 2;
			else
				j += 1;
			str->j = j;
			str->d = (va_arg(str->ap, int));
			return ((str->d < 0 ? 1 : sign) * str->d);
		}
	}
	j = str->j;
	return (ft_stock_nbr(str, str->j));
}

int			ft_stock_nbr(t_print *str, int j)
{
	char	arr[20];
	int		t;
	int		sign;

	sign = 1;
	t = 0;
	arr[0] = 0;
	while ((str->format[j] == '0' || str->format[j] == '-') &&
			ft_search(str, j) == 0)
	{
		zapper_zero(str->format, &j, &sign);
	}
	while (!ft_strchr(".cspdiuxX%", str->format[j]))
	{
		arr[t] = str->format[j];
		t++;
		j++;
	}
	arr[t] = '\0';
	if (str->format[j] == '.')
		j++;
	str->j = j;
	return (sign * ft_atoi(arr));
}

void		zapper_zero(char *str, int *i, int *sign)
{
	int c;

	c = *i;
	while (str[c] == '0' || str[c] == '-')
	{
		(str[c] == '-') ? *sign = -1 : 0;
		c++;
	}
	*i = c;
}

int			ft_search(t_print *str, int i)
{
	while (str->format[i] != '\0' && !ft_strchr("cspdiuxX%", str->format[i]))
	{
		if (str->format[i] == '.' || str->format[i] == '-')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
