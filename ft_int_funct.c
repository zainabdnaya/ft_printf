/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_funct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 02:10:52 by zdnaya            #+#    #+#             */
/*   Updated: 2020/01/18 11:34:48 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_int_print(t_print *str1)
{
	int intg;
	int m;

	intg = va_arg(str1->ap, int);
	m = intg < 0 ? 1 : 0;
	if (str1->z == 'd' || str1->z == 'i')
	{
		if (intg == 0)
		{
			ft_putstr("0");
			str1->r += 1;
		}
		else if (intg == INT_MIN)
		{
			ft_putstr("-2147483648");
			str1->r += mine_strlen("-2147483648");
		}
		else
		{
			ft_putnbr(intg);
			str1->r += ft_intlen(intg) + m;
		}
		str1->j++;
	}
	return (1);
}

void	null_dprint(t_print *str, int w, int p, int j)
{
	int r;

	r = (w == 0 ? 0 : w - 1);
	if (p == 0 && w == 0 && ft_strpoint(str->format, '.', j) == 1)
		str->r += 0;
	else if (w < 0)
	{
		if (p < 0)
		{
			ft_putchar('0');
			print_space(str, r = r < 0 ? r * (-1) : r, 1);
		}
		else
		{
			print_space(str, (p == 0 && !
						ft_strpoint(str->format, '.', j) ? 1 : p), 0);
			print_space(str, w * (-1) - (p == 0 && !
						ft_strpoint(str->format, '.', j) ? 1 : p), 1);
		}
		str->r += w < 0 ? w * (-1) : w;
	}
	else
		null_dprint1(str, w, p, j);
}

void	null_dprint1(t_print *str, int w, int p, int j)
{
	int r;

	r = 1 + w;
	if (w >= 0)
	{
		if (p < 0)
		{
			print_space(str, r, 1);
			ft_putchar('0');
		}
		else
		{
			print_space(str, w - (p == 0 && !
						ft_strpoint(str->format, '.', j) ? 1 : p), 1);
			print_space(str, (p == 0 && !
						ft_strpoint(str->format, '.', j) ? 1 : p), 0);
		}
		str->r += (w > p) ? w : p;
	}
}

void	ft_precesion_d1(t_print *str, int w, int p, int k)
{
	int n;

	str->q = p < 0 ? 1 : 0;
	str->kl = k < 0 ? 1 : 0;
	n = p < 0 ? str->size : 0;
	if (k < 0)
	{
		str->m = p - str->size;
		str->a = w - (str->size > p ? str->size : p) - 1 - n;
	}
	else
	{
		str->m = p - str->size;
		str->a = w - (str->size > p ? str->size : p);
	}
	if (w > 0)
		pret(str, k, w, p);
	else
		ft_precesion_d2(str, w * (-1), p, str->o);
}

void	ft_precesion_d2(t_print *str, int w, int p, int k)
{
	int n;

	str->q = k < 0 ? 1 : 0;
	n = p < 0 ? str->size : 0;
	if (k < 0)
	{
		str->m = p - str->size;
		if (str->etoile == 1 && p < 0)
			str->a = w - n - str->q;
		else
			str->a = w - (str->size > p ? str->size : p) - n - str->q;
	}
	else
	{
		str->m = p - str->size;
		str->a = w - (str->size > p ? str->size : p);
	}
	print_dd(str, w, p, k);
}
