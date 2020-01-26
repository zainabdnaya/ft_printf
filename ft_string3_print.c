/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string3_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 02:19:45 by zdnaya            #+#    #+#             */
/*   Updated: 2020/01/18 11:06:35 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strpoint(char *str, char c, int index)
{
	while (!ft_strchr("cspdiuxX%", str[index]))
	{
		if (c == str[index])
		{
			return (1);
		}
		index++;
	}
	return (0);
}

void	zeronegative_presi(t_print *str, int w, int p, char *string)
{
	int size;

	size = mine_strlen(string);
	p *= -1;
	if (size <= w && size <= p)
	{
		print_space(str, w - size, 0);
		ft_putstr(string);
		str->r += w;
	}
	else
	{
		ft_putstr(string);
		str->r += size;
	}
}

void	print_null(t_print *str, int w, int p, char *string)
{
	int size;

	size = mine_strlen(string);
	if (w >= 0 && p < 0 && str->etoile == 1)
	{
		print_space(str, w - size, 1);
		ft_putstr("(null)");
		str->r += w > size ? w : size;
	}
	else if (w >= 0 && p >= 0)
	{
		if (size <= w)
			strpositive_width(str, w, p, string);
		else if (size >= w)
			strsize(str, w, p, string);
	}
	else if (w <= 0)
	{
		if (p >= 0)
			strnegative_width(str, w * (-1), p, string);
		else if (p <= 0)
			strnegative(str, w * (-1), p, string);
	}
	else if (p <= 0 && w >= 0)
		strnegative_presi(str, w, p, string);
}

void	ft_ipd(t_print *str, int w, int p)
{
	if (p <= 0 && str->etoile == 1)
	{
		ft_putchar('0');
		print_space(str, w - 1, 1);
		str->r += w > 0 ? w : 1;
	}
	else
	{
		print_space(str, p, 0);
		print_space(str, w - p, 1);
		str->r += w;
	}
}
