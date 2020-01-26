/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_print1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 01:50:14 by zdnaya            #+#    #+#             */
/*   Updated: 2020/01/18 10:56:10 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	null_uprint_next1(t_print *str, int w, int p)
{
	if (w > p)
	{
		str->r += w;
		print_space(str, w - p, 1);
		print_space(str, p, 0);
	}
	else
	{
		print_space(str, p, 0);
		str->r += p;
	}
}

void	null_uprint_next2(t_print *str, int w)
{
	if (w > 0)
	{
		print_space(str, w - 1, 1);
		ft_putchar('0');
		str->r += w;
	}
	else
	{
		ft_putchar('0');
		print_space(str, w * (-1) - 1, 1);
		str->r += w * -1;
	}
}

void	ft_uprecesion_u1(t_print *str, int w, int p)
{
	if (str->size <= w || str->size <= p)
	{
		if (w <= p)
		{
			print_space(str, p - str->size, 0);
			ft_putnbr_u(str->d);
			str->r += p;
		}
		else
		{
			print_space(str, w - ((str->size <= p) ? p : str->size), 1);
			print_space(str, p - str->size, 0);
			ft_putnbr_u(str->d);
			str->r += w;
		}
	}
	else
	{
		ft_putnbr_u(str->d);
		str->r += str->size;
	}
}

void	ft_precesion_u2(t_print *str, int w, int p)
{
	if (p < 0 && str->etoile == 1)
		p = 0;
	if (str->size <= p || str->size <= w)
	{
		if (w <= p)
		{
			print_space(str, p - str->size, 0);
			ft_putnbr_u(str->d);
			str->r += p;
		}
		else
		{
			print_space(str, p - str->size, 0);
			ft_putnbr_u(str->d);
			print_space(str, w - ((str->size <= p) ? p : str->size), 1);
			str->r += w;
		}
	}
	else
	{
		ft_putnbr_u(str->d);
		str->r += str->size;
	}
}
