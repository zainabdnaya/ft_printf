/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 02:07:13 by zdnaya            #+#    #+#             */
/*   Updated: 2020/01/18 11:39:02 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_space(t_print *str, int size, int b)
{
	int count;

	count = size;
	(void)str;
	while (count > 0)
	{
		b == 1 ? ft_putchar(' ') : ft_putchar('0');
		count--;
	}
}

void	print_nge(int *k)
{
	if (*k < 0)
	{
		*k *= -1;
		ft_putchar('-');
	}
}

void	ft_zero_print(t_print *str, int w, int p, int k)
{
	int l;

	l = w < 0 ? 1 : 0;
	str->size = ft_intlen(k);
	w = w < 0 ? (w * (-1)) : w;
	if (str->size < w || str->size <= p)
	{
		if (p == 0)
			ft_zero_print0(str, w, l, str->size);
		else
			ft_zero_print1(str, w, p, k);
	}
	else
		ft_zero_print1(str, w, p, k);
}

void	ft_zero_print0(t_print *str, int w, int l, int size)
{
	int k;
	int y;

	k = str->o;
	y = k < 0 ? 1 : 0;
	if (l == 1)
	{
		print_nge(&k);
		ft_putnbr(k);
		print_space(str, w - size - y, 1);
	}
	else
	{
		print_nge(&k);
		print_space(str, w - size - y, 0);
		ft_putnbr(k);
	}
	str->r += w;
}

void	ft_zero_print1(t_print *str, int w, int p, int k)
{
	if (str->size < w || str->size <= p)
		ft_zero_print2(str, w, p, k);
	else
	{
		ft_putnbr(k);
		str->r += str->size + (k < 0 ? 1 : 0);
	}
}
