/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 01:43:05 by zdnaya            #+#    #+#             */
/*   Updated: 2020/01/18 11:46:01 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_char_print(t_print *str2)
{
	char	cht;

	cht = va_arg(str2->ap, int);
	ft_putchar(cht);
	str2->j++;
	str2->r++;
	return (1);
}

void		ft_flags_char(t_print *str)
{
	char	type;
	int		w;
	int		l;

	w = ft_check_number(str);
	ft_check_number(str);
	type = str->type;
	str->d = va_arg(str->ap, int);
	l = (str->format[str->j] == '0' && ft_search(str, str->j) == 0) ? 0 : 1;
	if (w < 0)
	{
		ft_putchar(str->d);
		print_space(str, w * (-1) - 1, 1);
		str->r += w * (-1);
	}
	else
	{
		print_space(str, w - 1, l);
		ft_putchar(str->d);
		if (ft_search(str, str->j) == 0 || w == 0)
			str->r += w + 1;
		else
			str->r += w;
	}
}

void		ft_percentage_flag(t_print *str)
{
	int		w;
	int		j;

	j = str->j;
	w = ft_check_number(str);
	ft_check_number(str);
	if (str->format[j] == '0')
	{
		if (w >= 0)
		{
			print_space(str, w - 1, 0);
			ft_putchar('%');
		}
		else
		{
			ft_putchar('%');
			print_space(str, w - 1, 1);
		}
		str->r += w == 0 ? 1 : w;
	}
	else
		ft_percentage_flag1(str, w);
}

void		ft_percentage_flag1(t_print *str, int w)
{
	if (w < 0)
	{
		w *= -1;
		ft_putchar('%');
		print_space(str, w - 1, 1);
		str->r += w;
	}
	else
	{
		print_space(str, w - 1, 1);
		ft_putchar('%');
		str->r += w + (w < 1 ? 1 : 0);
	}
}
