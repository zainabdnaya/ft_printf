/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer2_funct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 02:23:05 by zdnaya            #+#    #+#             */
/*   Updated: 2020/01/18 05:34:41 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_null1(t_print *str, int w)
{
	if (w < 0)
	{
		w *= -1;
		ft_putstr(str->srt);
		print_space(str, w - str->size, 1);
		str->r += (w > str->size ? w : str->size);
	}
	else
	{
		ft_putstr(str->srt);
		str->r += mine_strlen(str->srt);
	}
}

void		ft_precesion_p1(t_print *str, int w, int p, char *srt)
{
	int size;

	size = str->size;
	if (w >= p)
	{
		print_space(str, w - (size < p ? p : size), 1);
		ft_putstr("0x");
		print_space(str, p - size, 0);
		ft_putstr(srt);
		str->r += (w > size ? w : size);
	}
	else
	{
		ft_putstr("0x");
		print_space(str, (size <= p) ? (p - size + 2) : (2 + size - p), 0);
		ft_putstr(srt);
		str->r += p + 2;
	}
}

void		ft_precesion_p2(t_print *str, int w, int p, char *srt)
{
	int size;

	size = str->size;
	if (w >= p)
	{
		ft_putstr("0x");
		print_space(str, p - size, 0);
		ft_putstr(srt);
		print_space(str, w - (size < p ? p : size), 1);
		str->r += (w > size ? w : size);
	}
}
