/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 03:02:49 by zdnaya            #+#    #+#             */
/*   Updated: 2020/01/18 11:42:52 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_hexadecimal_print(t_print *str5)
{
	unsigned int ud;

	if (str5->z == 'x' || str5->z == 'X')
	{
		ud = va_arg(str5->ap, unsigned int);
		if (ud == 0)
		{
			ft_putchar('0');
			str5->r += 1;
		}
		else if (ud == UINT_MAX)
		{
			ft_putstr(ft_itoa_base(UINT_MAX, 16, str5->z));
			str5->r += 8;
		}
		else
		{
			ft_putstr(ft_itoa_base(ud, 16, str5->z));
			str5->r += ft_digit_count(ud, 16);
		}
		str5->j++;
	}
	return (1);
}

size_t		ft_digit_count(long num, int base)
{
	size_t i;

	i = 0;
	while (num)
	{
		num /= base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(unsigned value, int base, int c)
{
	int		size;
	char	*res;

	size = ft_digit_count(value, base);
	res = malloc(sizeof(char) * size + 1);
	res[size] = '\0';
	while (size-- > 0)
	{
		if (c == 'X')
			res[size] = (value % base < 10)
				? (value % base + '0') : (value % base - 10 + 'A');
		else if (c == 'x')
			res[size] = (value % base < 10)
				? (value % base + '0') : (value % base - 10 + 'a');
		value /= base;
	}
	return (res);
}

void		ft_flags_hexa(t_print *str, char c)
{
	int w;
	int p;
	int j;

	j = str->j;
	w = ft_check_number(str);
	p = ft_check_number(str);
	str->chr = c;
	if (!(str->ud = va_arg(str->ap, unsigned int)))
		str->size = 0;
	str->strg = ft_itoa_base(str->ud, 16, str->chr);
	str->size = mine_strlen(str->strg);
	if (str->ud == 0)
	{
		if (str->format[j] == '0' && ft_search(str, j) == 1 && w != 0)
		{
			print_space(str, w, 0);
			str->r += w;
		}
		else
			null_dprint(str, w, p, j);
	}
	else
		ft_flags_hexa1(str, w, p, j);
	free(str->strg);
}

void		ft_flags_hexa1(t_print *str, int w, int p, int j)
{
	if (str->format[j] == '0' && ft_search(str, j) == 1)
		hexazero_flag(str, w, p, str->size);
	else
	{
		if (w >= 0)
		{
			if (p <= 0)
				ft_precesion_h1(str, w, 0, str->size);
			else
				ft_precesion_h1(str, w, p, str->ud);
		}
		else
			ft_precesion_h2(str, w * (-1), p, j);
	}
}
