/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string4_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 03:06:25 by zdnaya            #+#    #+#             */
/*   Updated: 2020/01/18 11:00:48 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zero_string(t_print *str, int w, int p, char *string)
{
	int		m;

	m = 0;
	if (string != NULL)
	{
		if (w >= 0)
			p >= 0 ? zeropositive_width(str, w, p, string)
				: strnegative_presi(str, w, p, string);
		else if (w < 0)
			p > 0 ? zeronegative_width(str, w, p, string)
				: strnegative(str, w, p, string);
	}
	else
	{
		str->size = 6;
		ft_zero_string1(str, w, p, "(null)");
	}
}

void	ft_zero_string1(t_print *str, int w, int p, char *string)
{
	int		m;

	if (w >= 0)
	{
		if (p < 0 && str->etoile == 1)
			p = str->size;
		else
			p = p < 0 ? p * (-1) : p;
		m = str->size > p ? p : str->size;
		print_space(str, w - (p < str->size ? p : str->size), 0);
		ft_putstr_string(string, p);
		str->r += w > p ? w : m;
	}
	else
	{
		if (p < 0 && str->etoile == 1)
			p = str->size;
		ft_putstr_string(string, p);
		p = p < 0 ? p * (-1) : p;
		print_space(str, w * (-1) - (p < str->size ? p : str->size), 1);
		str->r += w * (-1);
	}
}

void	zeropositive_width(t_print *str, int w, int p, char *string)
{
	int size;
	int k;

	size = mine_strlen(string);
	k = w > p ? w : size;
	if (size <= w)
	{
		if (p > 0 && p <= size)
		{
			print_space(str, w - p, 0);
			ft_putstr_string(string, p);
		}
		else
		{
			print_space(str, w - size, 0);
			ft_putstr(string);
		}
		str->r += w;
	}
	else
		zeropositive_width1(str, w, p, string);
}

void	zeropositive_width1(t_print *str, int w, int p, char *string)
{
	int size;

	size = mine_strlen(string);
	if (size > w && p == 0 && w == 0)
	{
		ft_putstr(string);
		str->r += size;
	}
	else if (size <= p)
	{
		if (w > p)
		{
			print_space(str, w - p, 0);
			ft_putstr_string(string, p);
			str->r += w;
		}
		else
		{
			ft_putstr_string(string, p);
			str->r += p;
		}
	}
	else
		zeropositive1_width1(str, w, p, string);
}

void	zeronegative_width(t_print *str, int w, int p, char *string)
{
	int size;

	size = mine_strlen(string);
	w *= -1;
	if (size <= w)
	{
		if (size <= p)
		{
			ft_putstr(string);
			print_space(str, w - size, 1);
			str->r += w;
		}
		else
		{
			ft_putstr_string(string, p);
			print_space(str, w - p, 1);
			str->r += w;
		}
	}
	else
		zeronegative_width1(str, p, string);
}
