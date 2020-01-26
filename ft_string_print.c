/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 02:17:07 by zdnaya            #+#    #+#             */
/*   Updated: 2020/01/18 11:03:53 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_string_print(t_print *str3)
{
	char *string;

	if (str3->z == 's')
	{
		if (!(string = va_arg(str3->ap, char *)))
			string = "(null)";
		str3->r += mine_strlen(string);
		ft_putstr(string);
		str3->j++;
	}
	return (1);
}

void	ft_flags_string(t_print *str)
{
	char	type;
	int		w;
	int		p;
	char	*string;
	int		j;

	j = str->j;
	str->oldindex = j;
	w = ft_check_number(str);
	p = ft_check_number(str);
	type = str->type;
	string = va_arg(str->ap, char *);
	if (str->format[j] == '0' && string != NULL)
		ft_zero_string(str, w, p, string);
	else if (string != NULL)
		flag_condtion(str, w, p, string);
	else
	{
		if (str->format[j] == '0')
		{
			ft_zero_string(str, w, p, string);
		}
		else
			print_null(str, w, p, "(null)");
	}
}

void	flag_condtion(t_print *str, int w, int p, char *string)
{
	int size;

	size = mine_strlen(string);
	if (w >= 0)
	{
		if (size <= w)
			strpositive_width(str, w, p, string);
		else if (size >= w)
			strsize(str, w, p, string);
	}
	else if (w <= 0)
	{
		w *= -1;
		if (p >= 0)
			strnegative_width(str, w, p, string);
		else if (p <= 0)
			strnegative(str, w, p, string);
	}
	else if (p <= 0 && w >= 0)
		strnegative_presi(str, w, p, string);
}

void	strpositive_width(t_print *str, int w, int p, char *string)
{
	int size;

	size = mine_strlen(string);
	if (ft_strpoint(str->format, '.', str->oldindex) == 1 && p == 0 && w != 0)
	{
		print_space(str, w, 1);
		str->r += w;
	}
	else if (p != 0)
	{
		if (p <= 0)
			p = size;
		print_space(str, w - (p >= size ? size : p), 1);
		ft_putstr_string(string, p);
		str->r += w;
	}
	else
		strpositive_width1(str, w, p, string);
}

void	strpositive_width1(t_print *str, int w, int p, char *string)
{
	int size;

	size = mine_strlen(string);
	if (p == 0 && ft_strpoint(str->format, '-', str->oldindex) == 1)
	{
		ft_putstr(string);
		print_space(str, w - size, 1);
		str->r += w;
	}
	else
	{
		print_space(str, w - size, 1);
		ft_putstr(string);
		str->r += w;
	}
}
