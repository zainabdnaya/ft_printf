/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool3_funct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 02:04:37 by zdnaya            #+#    #+#             */
/*   Updated: 2020/01/16 09:00:06 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int i;

	i = mine_strlen(s);
	write(1, s, mine_strlen(s));
}

void	ft_putnbr(int n)
{
	if (n == INT_MIN)
	{
		ft_putstr("2147483648");
	}
	else if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	if (n >= 0)
	{
		if (n >= 10)
		{
			ft_putnbr(n / 10);
			ft_putchar(n % 10 + '0');
		}
		else
			ft_putchar(n + '0');
	}
}

void	ft_putnbr_u(unsigned int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

void	ft_putstr_string(char *s, int p)
{
	int i;

	i = 0;
	if (!s)
	{
		s = "(null)";
	}
	else
	{
		while (i < p && s[i])
			write(1, &s[i++], 1);
	}
}
