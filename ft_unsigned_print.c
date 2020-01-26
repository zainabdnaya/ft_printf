/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 01:45:21 by zdnaya            #+#    #+#             */
/*   Updated: 2020/01/18 10:55:25 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_usignedint_print(t_print *str4)
{
	unsigned int	num;

	num = 0;
	if (str4->z == 'u')
	{
		num = va_arg(str4->ap, unsigned int);
		if (num == 0)
		{
			ft_putstr("0");
			str4->r += 1;
		}
		else
		{
			ft_putnbr_u(num);
			str4->r += ft_uintlen(num);
		}
		str4->j++;
	}
	return (1);
}

void	ft_flags_unsigned(t_print *str)
{
	int		w;
	int		p;

	str->oldindex = str->j;
	w = ft_check_number(str);
	p = ft_check_number(str);
	str->d = va_arg(str->ap, unsigned int);
	str->size = ft_uintlen(str->d);
	if (str->d == 0)
	{
		if (str->format[str->oldindex] == '0'
				&& ft_search(str, str->oldindex) == 1)
		{
			if (w != 0)
				print_space(str, w, 0);
			else
				ft_putchar('0');
			str->r += w != 0 ? w : 1;
		}
		else
			null_uprint(str, w, p, str->oldindex);
	}
	else
		ft_flags_unsigned1(str, w, p, str->oldindex);
}

void	ft_flags_unsigned1(t_print *str, int w, int p, int j)
{
	char	type;

	type = str->type;
	if (str->format[j] == '0' && ft_search(str, j) == 1)
	{
		ft_zero_print_u(str, w, p, str->d);
	}
	else
	{
		if (w >= 0)
			ft_uprecesion_u1(str, w, p);
		else
			ft_precesion_u2(str, w * (-1), p);
	}
}

void	ft_zero_print_u(t_print *str, int w, int p, unsigned int k)
{
	str->size = ft_uintlen(k);
	if (p != 0)
	{
		print_space(str, w - p, 1);
		print_space(str, p, 0);
		ft_putnbr_u(k);
		if (w > p)
			str->r += w;
		else
			str->r += p;
	}
	else
	{
		print_space(str, w - str->size, 0);
		ft_putnbr_u(k);
		str->r += w;
	}
}

void	null_uprint(t_print *str, int w, int p, int j)
{
	if (p < 0 && str->etoile == 1)
		p = 0;
	if (ft_strpoint(str->format, '.', j) == 1)
	{
		if (w < 0)
		{
			w *= -1;
			if (w >= p)
			{
				ft_ipd(str, w, p);
			}
			else
			{
				print_space(str, w, 0);
				print_space(str, p - w, 1);
				str->r += p;
			}
		}
		else
			null_uprint_next1(str, w, p);
	}
	else
		null_uprint_next2(str, w);
}
