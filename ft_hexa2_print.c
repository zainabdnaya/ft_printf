/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa2_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 03:04:44 by zdnaya            #+#    #+#             */
/*   Updated: 2020/01/18 11:39:54 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hexazero_flag(t_print *str, int w, int p, int size)
{
	if (size <= w)
	{
		if (w < 0)
			hexazero_flag1(str, w, p, size);
		else
		{
			print_space(str, w - size, 0);
			ft_putstr(str->strg);
			str->r += w;
		}
	}
	else
	{
		ft_putstr(str->strg);
		str->r += size;
	}
}

void	hexazero_flag1(t_print *str, int w, int p, int size)
{
	w *= -1;
	if (size <= w)
	{
		ft_putstr(str->strg);
		print_space(str, w - size, 1);
		str->r += w;
	}
	else
	{
		if (size <= p)
		{
			print_space(str, p - size, 0);
			ft_putstr(str->strg);
			str->r += p;
		}
	}
}

void	ft_precesion_h1(t_print *str, int w, int p, int j)
{
	char *string;

	string = NULL;
	if (str->ud == 0 && p == 0)
	{
		if (ft_search(str, j) == 0)
		{
			string = " ";
			str->size = 1;
		}
		else if (ft_search(str, j) == 1)
		{
			string = "0";
			str->size = 1;
		}
	}
	else
	{
		string = ft_itoa_base(str->ud, 16, str->chr);
		str->size = mine_strlen(string);
	}
	ft_precesion_h3(str, w, p, string);
	free(string);
}

void	ft_precesion_h3(t_print *str, int w, int p, char *string)
{
	int m;

	m = str->size > p ? str->size : p;
	if (str->size <= w || str->size <= p)
	{
		if (w <= p)
		{
			print_space(str, p - str->size, 0);
			ft_putstr(string);
			str->r += p;
		}
		else
		{
			str->r += w;
			print_space(str, w - m, 1);
			print_space(str, p - str->size, 0);
			ft_putstr(string);
		}
	}
	else
	{
		ft_putstr(string);
		str->r += str->size;
	}
}

void	ft_precesion_h2(t_print *str, int w, int p, int j)
{
	char *string;

	string = NULL;
	if (str->d == 0 && p != 0)
		string = "0";
	if (str->ud == 0 && p == 0)
	{
		if (ft_search(str, j) == 0)
		{
			string = " ";
			str->size = 1;
		}
		else if (ft_search(str, j) == 1)
		{
			string = "0";
			str->size = 1;
		}
	}
	else
	{
		string = ft_itoa_base(str->ud, 16, str->chr);
		str->size = mine_strlen(string);
	}
	ft_precesion_h4(str, w, p, string);
	free(string);
}
