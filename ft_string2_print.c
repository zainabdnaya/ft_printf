/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string2_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 02:17:47 by zdnaya            #+#    #+#             */
/*   Updated: 2020/01/18 11:20:44 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	strnegative(t_print *str, int w, int p, char *string)
{
	int size;

	size = mine_strlen(string);
	if (size <= w || size <= p)
	{
		ft_putstr(string);
		print_space(str, w - size, 1);
		str->r += w;
	}
	else
	{
		ft_putstr(string);
		str->r += size;
	}
}

void	zeronegative(t_print *str, int w, int p, char *string)
{
	int size;

	size = mine_strlen(string);
	w *= -1;
	p *= -1;
	if (size <= w || size <= p)
	{
		if (w > p || w <= p)
		{
			ft_putstr(string);
			print_space(str, w - size, 1);
			str->r += w;
		}
	}
	else if (size >= w)
	{
		ft_putstr(string);
		print_space(str, w - size, 1);
		str->r += w;
	}
	else
	{
		ft_putstr(string);
		str->r += size;
	}
}

void	ft_precesion_h4(t_print *str, int w, int p, char *string)
{
	if (str->size <= p || str->size <= w)
	{
		if (w <= p)
		{
			print_space(str, p - w + ((str->ud == 0) ? 1 : -1), 0);
			ft_putstr(string);
			str->r += p;
		}
		else
		{
			print_space(str, p - str->size, 0);
			if (string != NULL)
				ft_putstr(string);
			else
				ft_putstr("0");
			print_space(str, w - ((p < str->size) ? str->size : p), 1);
			str->r += w;
		}
	}
	else
	{
		ft_putstr(string);
		str->r += str->size;
	}
}

void	nextstrneg(t_print *str, int w, int p, char *string)
{
	int size;

	size = mine_strlen(string);
	if (size >= w)
	{
		ft_putstr_string(string, p);
		print_space(str, w - ((p == 0) ? size : p), 1);
		str->r += (p >= size) ? size : w;
	}
	else
	{
		if (ft_strpoint(str->format, '.', str->oldindex) == 1 && p == 0)
		{
			print_space(str, w, 1);
			str->r += w;
		}
		else
		{
			ft_putstr(string);
			print_space(str, w - size, 1);
			str->r += w;
		}
	}
}

void	strnegative_presi(t_print *str, int w, int p, char *string)
{
	int size;

	size = mine_strlen(string);
	p *= -1;
	if (size <= w)
	{
		print_space(str, w - size, 0);
		ft_putstr(string);
		str->r += w;
	}
	else if (size <= w && size <= p)
	{
		print_space(str, w - size, 1);
		ft_putstr(string);
		str->r += w;
	}
	else
	{
		ft_putstr(string);
		str->r += size;
	}
}
