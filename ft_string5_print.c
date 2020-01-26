/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string5_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 03:08:59 by zdnaya            #+#    #+#             */
/*   Updated: 2020/01/18 11:01:44 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	strsize(t_print *str, int w, int p, char *string)
{
	str->size = mine_strlen(string);
	if (ft_strpoint(str->format, '.', str->oldindex) == 1)
	{
		strsize0(str, w, p, string);
	}
	else
		strsize1(str, w, p, string);
}

void	strsize0(t_print *str, int w, int p, char *string)
{
	int e;

	e = (p <= str->size) ? p : str->size;
	if (p == 0)
	{
		print_space(str, w, 1);
		ft_putstr_string(string, p);
		str->r += w < p ? p : w;
	}
	else
	{
		if (p < 0)
		{
			ft_putstr(string);
			str->r += str->size;
		}
		else
		{
			print_space(str, w - p, 1);
			ft_putstr_string(string, p);
			str->r += (w <= p) ? e : w;
		}
	}
}

void	strsize1(t_print *str, int w, int p, char *string)
{
	int size;

	size = mine_strlen(string);
	if (size >= w)
	{
		if (p == 0 && w != 0)
			ft_putstr(string);
		else if (w == 0 && size <= p)
		{
			print_space(str, w - p, 1);
			ft_putstr_string(string, p);
		}
		else
			ft_putstr(string);
		str->r += size;
	}
	else
	{
		print_space(str, w - p, 1);
		ft_putstr_string(string, p);
		str->r += w < p ? p : w;
	}
}

void	strnegative_width(t_print *str, int w, int p, char *string)
{
	int size;

	size = mine_strlen(string);
	if (size >= w)
	{
		if (p == 0)
		{
			if (ft_strpoint(str->format, '.', str->oldindex) == 1)
			{
				print_space(str, w, 1);
				str->r += w;
			}
			else
			{
				ft_putstr(string);
				str->r += (p == 0) ? size : w;
			}
		}
		else
			nextstrneg(str, w, p, string);
	}
	else
		negativestr1(str, w, p, string);
}

void	negativestr1(t_print *str, int w, int p, char *string)
{
	int size;
	int m;

	size = mine_strlen(string);
	m = p <= size ? p : size;
	if (ft_strpoint(str->format, '.', str->oldindex) == 1 && p != 0)
	{
		if (p <= size)
		{
			ft_putstr_string(string, p);
			print_space(str, w - p, 1);
		}
		else
		{
			ft_putstr(string);
			print_space(str, w - size, 1);
		}
		str->r += (w <= size) ? m : w;
	}
	else
		nextstrneg(str, w, p, string);
}
