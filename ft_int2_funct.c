/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int2_funct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 02:14:49 by zdnaya            #+#    #+#             */
/*   Updated: 2020/01/18 11:35:24 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_d(t_print *str)
{
	int		w;
	int		p;
	int		j;

	j = str->j;
	w = ft_check_number(str);
	p = ft_check_number(str);
	str->o = va_arg(str->ap, int);
	if (str->o == 0 && p == 0)
	{
		if (str->format[j] == '0' && ft_search(str, j) == 1)
			ft_zero_print(str, w, 0, 0);
		else
			null_dprint(str, w, p, j);
	}
	else
	{
		str->size = ft_intlen(str->o);
		if (str->format[j] == '0' && ft_search(str, j) == 1)
			ft_zero_print(str, w, p, str->o);
		else if (str->format[j] == '0' && str->etoile == 1)
			ft_zero_print(str, w, p, str->o);
		else
			ft_precesion_d1(str, w, p, str->o);
	}
}

void	pres_002(t_print *str, int k)
{
	print_space(str, str->a, str->q);
	print_nge(&k);
	print_space(str, str->m, 0);
	ft_putnbr(k);
}

void	pres_001(t_print *str, int p, int w, int k)
{
	if (str->size < p || str->size < w)
	{
		if (w <= p)
		{
			str->r += p + (k < 0 ? 1 : 0);
			print_nge(&k);
			print_space(str, str->m, 0);
			ft_putnbr(k);
		}
		else
			str->r += w;
	}
	else
	{
		ft_putnbr(k);
		str->r += str->size + k < 0 ? 1 : 0;
	}
}

void	print_01d(t_print *str, int k, int p, int w)
{
	if (p <= 0 && str->etoile == 1)
	{
		print_space(str, w - str->size - str->kl, 1);
		print_nge(&k);
		ft_putnbr(k);
	}
	else
	{
		print_space(str, str->a, 1);
		print_nge(&k);
		print_space(str, str->m, str->q);
		ft_putnbr(k);
	}
	str->r += w;
}

void	pret(t_print *str, int k, int w, int p)
{
	if (str->size < p || str->size < w)
	{
		if (w <= p)
		{
			str->r += p + (k < 0 ? 1 : 0);
			print_nge(&k);
			print_space(str, str->m, 0);
			ft_putnbr(k);
		}
		else
			print_01d(str, k, p, w);
	}
	else
	{
		ft_putnbr(k);
		str->r += str->size + str->kl;
	}
}
