/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_funct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 02:21:50 by zdnaya            #+#    #+#             */
/*   Updated: 2020/01/18 11:37:44 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pointerprint(t_print *str6)
{
	char *srt;

	if (str6->z == 'p')
	{
		srt = convert(va_arg(str6->ap, void *));
		if ((ft_strncmp(srt, "\0", 1) == 0) || ft_strncmp(srt, "0", 1) == 0)
		{
			ft_putstr("0x0");
			str6->r += mine_strlen("0x0");
		}
		else
		{
			ft_putstr("0x");
			ft_putstr(srt);
			str6->r += mine_strlen(srt) + 2;
		}
	}
	str6->j++;
	return (1);
}

char	test_hex(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

char	*convert(void *p)
{
	uintptr_t	quot;
	char		*hex;
	char		*tmp;
	int			i;
	int			c;

	i = 64;
	quot = (uintptr_t)p;
	hex = malloc(20);
	c = 0;
	while (i > 0)
	{
		i = i - 4;
		hex[c] = test_hex(quot >> i & 15);
		c++;
	}
	hex[c] = '\0';
	c = 0;
	while (hex[c] == '0')
		c++;
	tmp = hex;
	hex = &hex[c];
	free(tmp);
	return ((hex));
}

void	ft_flags_pointer(t_print *str)
{
	int w;
	int p;

	str->oldindex = str->j;
	w = ft_check_number(str);
	p = ft_check_number(str);
	str->srt = convert(va_arg(str->ap, void *));
	if ((ft_strncmp(str->srt, "\0", 1) == 0) ||
			ft_strncmp(str->srt, "0", 1) == 0)
		ft_null(str, w, p);
	else
	{
		str->size = mine_strlen(str->srt) + 2;
		if (w > 0)
			ft_precesion_p1(str, w, p, str->srt);
		else if (w < 0)
			ft_precesion_p2(str, w * (-1), p, str->srt);
		else
		{
			ft_putstr("0x");
			ft_putstr(str->srt);
			str->r += mine_strlen(str->srt) + 2;
		}
	}
}

void	ft_null(t_print *str, int w, int p)
{
	if (ft_strpoint(str->format, '.', str->oldindex) == 1)
		str->srt = "0x";
	else
		str->srt = "0x0";
	str->size = mine_strlen(str->srt);
	if (w > 0)
	{
		if (w > p)
		{
			print_space(str, w - str->size, 1);
			ft_putstr(str->srt);
			str->r += ((w > str->size) ? w : str->size);
		}
		else
		{
			ft_putstr(str->srt);
			print_space(str, p, 0);
			str->r += p + 2;
		}
	}
	else
		ft_null1(str, w);
}
