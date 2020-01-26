/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 05:46:48 by zdnaya            #+#    #+#             */
/*   Updated: 2020/01/18 11:22:13 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_zero_print2(t_print *str, int w, int p, int k)
{
	int		y;
	int		f;

	y = k < 0 ? 1 : 0;
	f = str->size < p ? p : str->size;
	if (p < 0)
	{
		print_nge(&k);
		print_space(str, w - f - y, 0);
		ft_putnbr(k);
		str->r += w;
	}
	else
	{
		print_space(str, w - f - y, 1);
		print_nge(&k);
		print_space(str, p - str->size, 0);
		ft_putnbr(k);
		if (w > p)
			str->r += w;
		else
			str->r += p + y;
	}
}

void		ft_initialization(t_print *v)
{
	v->n = 0;
	v->l = 0;
	v->z = 0;
	v->size = 0;
	v->d = 0;
	v->ud = 0;
	v->chr = 0;
	v->o = 0;
	v->oldindex = 0;
	v->k = 0;
	v->a = 0;
	v->q = 0;
	v->m = 0;
	v->kl = 0;
	v->etoile = 0;
	v->z = '\0';
	v->type = '\0';
	v->chr = '\0';
}

void		print_dd(t_print *str, int w, int p, int k)
{
	if (str->size < p || str->size < w)
	{
		if (w <= p)
		{
			str->r += p + str->q;
			print_nge(&k);
			print_space(str, str->m, 0);
			ft_putnbr(k);
		}
		else
		{
			str->r += w;
			print_nge(&k);
			print_space(str, str->m, 0);
			ft_putnbr(k);
			print_space(str, str->a, 1);
		}
	}
	else
	{
		str->r += str->size + str->q;
		print_nge(&k);
		ft_putnbr(k);
	}
}

void		zeropositive1_width1(t_print *str, int w, int p, char *string)
{
	int size;

	size = mine_strlen(string);
	print_space(str, w - size, 0);
	if (p == 0)
		p = size;
	ft_putstr_string(string, p);
	str->r += size > p ? p : size;
}

void		zeronegative_width1(t_print *str, int p, char *string)
{
	int size;

	size = mine_strlen(string);
	if (size >= p)
	{
		ft_putstr_string(string, p);
		str->r += p;
	}
	else
	{
		ft_putstr(string);
		str->r += size;
	}
}
