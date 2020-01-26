/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:36:28 by zdnaya            #+#    #+#             */
/*   Updated: 2020/01/18 11:22:48 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_print v;

	v.j = 0;
	v.r = 0;
	ft_initialization(&v);
	v.format = (char *)format;
	va_start(v.ap, format);
	while (v.format[v.j] != '\0')
	{
		ft_initialization(&v);
		if (v.format[v.j] == '%')
		{
			ft_printcheck(&v, v.format);
		}
		else
		{
			ft_putchar(v.format[v.j]);
			v.r++;
			v.j++;
		}
	}
	va_end(v.ap);
	return (v.r);
}

int			ft_printcheck(t_print *str, char *format)
{
	int		j;

	j = str->j;
	format = str->format;
	if (format[str->j] == '%' && format[str->j + 1])
	{
		check_type(str);
		if (ft_strchr("cspdiuxX%", format[str->j + 1]))
		{
			str->z = format[str->j + 1];
			ft_printtype(str, str->z);
		}
		else
		{
			str->j++;
			ft_checknext(str);
		}
	}
	str->j++;
	return (1);
}

void		check_type(t_print *str)
{
	int		i;

	i = str->j + 1;
	while (!ft_strchr("cpsduipxX%", str->format[i]) && str->format[i] != '\0')
	{
		if (ft_strchr("cpsduipxX%", str->format[i + 1]) != NULL)
			str->type = str->format[i + 1];
		i++;
	}
}

void		ft_printtype(t_print *str, char c)
{
	c = str->z;
	if (c == 'u')
		ft_usignedint_print(str);
	else if (c == 'd' || c == 'i')
		ft_int_print(str);
	else if (c == 'c')
		ft_char_print(str);
	else if (c == '%')
	{
		ft_putchar('%');
		str->j++;
		str->r += 1;
	}
	else if (c == 's')
		ft_string_print(str);
	else if (c == 'x' || c == 'X')
		ft_hexadecimal_print(str);
	else if (c == 'p')
		ft_pointerprint(str);
}

void		ft_checknext(t_print *str)
{
	if (str->type == 'd' || str->type == 'i')
		ft_flags_d(str);
	else if (str->type == 'c')
		ft_flags_char(str);
	else if (str->type == 'u')
		ft_flags_unsigned(str);
	else if (str->type == 's')
		ft_flags_string(str);
	else if (str->type == 'x' || str->type == 'X')
		ft_flags_hexa(str, str->type);
	else if (str->type == 'p')
		ft_flags_pointer(str);
	else if (str->type == '%')
		ft_percentage_flag(str);
}
